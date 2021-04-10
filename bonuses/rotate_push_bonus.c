/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:38:55 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:39:01 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_pb_cycle_2(t_all *all, int cut_a, int **partition)
{
	float	median;
	int		buf;
	int		count_a;
	int		count;

	count_a = 0;
	count = 0;
	median = ft_get_median(all->stack_a, 1, all->stack_a[0] - cut_a + 1);
	buf = all->stack_a[0] - cut_a;
	while (buf > 0)
	{
		if (all->stack_a[1] <= median)
		{
			ft_exec_command("pb\n", all);
			count++;
		}
		else if (ft_need_to_ra(all->stack_a, cut_a, median))
		{
			ft_exec_command("ra\n", all);
			count_a++;
		}
		buf--;
	}
	*partition = ft_appstart(partition, count);
	return (count_a);
}

void	ft_pb_cycle(t_all *all, int *cut_a, int **partition)
{
	int	count_a;

	while (all->stack_a[0] - *cut_a > 3)
	{
		if (ft_is_sorted(all->stack_a, 1, all->stack_a[0] - 1))
		{
			*cut_a = all->stack_a[0];
			break ;
		}
		count_a = ft_pb_cycle_2(all, *cut_a, partition);
		if (*cut_a > 1)
		{
			while (count_a--)
				ft_exec_command("rra\n", all);
		}
	}
	if (*cut_a == 1)
	{
		ft_three(all->stack_a, all);
		*cut_a = all->stack_a[0];
	}
	else
		ft_first_three(all->stack_a, cut_a, all);
}

int	ft_need_to_rb(int *stack_b, int buf, float median)
{
	int	i;

	i = 1;
	buf++;
	while (buf > 0)
	{
		if (stack_b[i] >= median)
			return (1);
		i++;
		buf--;
	}
	return (0);
}

void	ft_pa_cycle_2(t_all *all, int *cut_a, int **partition)
{
	float	med;
	int		buf;
	int		count;
	int		count_a;

	med = ft_get_median(all->stack_b, 1, (*partition)[0] + 1);
	buf = (*partition)[0];
	count = 0;
	count_a = 0;
	while (buf-- > 0)
	{
		if (all->stack_b[1] < med && ft_need_to_rb(all->stack_b, buf, med)
			&& ++count)
			ft_exec_command("rb\n", all);
		else if (all->stack_b[1] >= med && ++count_a && (*partition)[0]--)
			ft_exec_command("pa\n", all);
	}
	if (count_a <= 3)
		ft_first_three(all->stack_a, cut_a, all);
	if ((*partition)[1])
	{
		while (count-- > 0)
			ft_exec_command("rrb\n", all);
	}
}

void	ft_pa_cycle(t_all *all, int *cut_a, int **partition)
{
	if (all->stack_b[0] > 1 && all->stack_b[0] <= 4)
	{
		ft_rev_three(all->stack_b, all);
		while (all->stack_b[0] > 1)
			ft_exec_command("pa\n", all);
		*cut_a = all->stack_a[0];
		(*partition)[0] = 0;
	}
	else if (((*partition)[0] > 0 && (*partition)[0] <= 3)
			|| ft_is_sorted(all->stack_b, (*partition)[0], 1))
	{
		while ((*partition)[0]-- > 0)
			ft_exec_command("pa\n", all);
		*partition = ft_delstart(partition);
		ft_first_three(all->stack_a, cut_a, all);
	}
	else if (all->stack_b[0] > 1)
		ft_pa_cycle_2(all, cut_a, partition);
}
