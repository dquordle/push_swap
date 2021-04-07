/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:13:30 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 15:14:08 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pb_cycle_2(int **stack_a, int **stack_b, int cut_a, int **partition)
{
	float	median;
	int		buf;
	int		count_a;
	int		count;

	count_a = 0;
	count = 0;
	median = ft_get_median(*stack_a, 1, (*stack_a)[0] - cut_a + 1);
	buf = (*stack_a)[0] - cut_a;
	while (buf > 0)
	{
		if ((*stack_a)[1] <= median)
		{
			ft_exec_command("pb\n", stack_a, stack_b);
			count++;
		}
		else if (ft_need_to_ra(*stack_a, cut_a, median))
		{
			ft_exec_command("ra\n", stack_a, stack_b);
			count_a++;
		}
		buf--;
	}
	*partition = ft_appstart(partition, count);
	return (count_a);
}

void	ft_pb_cycle(int **stack_a, int **stack_b, int *cut_a, int **partition)
{
	int	count_a;

	while ((*stack_a)[0] - *cut_a > 3)
	{
		if (ft_is_sorted(*stack_a, 1, (*stack_a)[0] - 1))
		{
			*cut_a = (*stack_a)[0];
			break ;
		}
		count_a = ft_pb_cycle_2(stack_a, stack_b, *cut_a, partition);
		if (*cut_a > 1)
		{
			while (count_a--)
				ft_exec_command("rra\n", stack_a, stack_b);
		}
	}
	if (*cut_a == 1)
	{
		ft_three(*stack_a);
		*cut_a = (*stack_a)[0];
	}
	else
		ft_first_three(*stack_a, cut_a);
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

void	ft_pa_cycle_2(int **stack_a, int **stack_b, int *cut_a, int **partition)
{
	float	median;
	int		buf;
	int		count;
	int		count_a;

	median = ft_get_median(*stack_b, 1, (*partition)[0] + 1);
	buf = (*partition)[0];
	count = 0;
	count_a = 0;
	while (buf-- > 0)
	{
		if ((*stack_b)[1] < median && ft_need_to_rb(*stack_b, buf, median)
			&& ++count)
			ft_exec_command("rb\n", stack_a, stack_b);
		else if ((*stack_b)[1] >= median && ++count_a && (*partition)[0]--)
			ft_exec_command("pa\n", stack_a, stack_b);
	}
	if (count_a <= 3)
		ft_first_three(*stack_a, cut_a);
	if ((*partition)[1])
	{
		while (count-- > 0)
			ft_exec_command("rrb\n", stack_a, stack_b);
	}
}

void	ft_pa_cycle(int **stack_a, int **stack_b, int *cut_a, int **partition)
{
	if ((*stack_b)[0] > 1 && (*stack_b)[0] <= 4)
	{
		ft_rev_three(*stack_b);
		while ((*stack_b)[0] > 1)
			ft_exec_command("pa\n", stack_a, stack_b);
		*cut_a = (*stack_a)[0];
		(*partition)[0] = 0;
	}
	else if (((*partition)[0] > 0 && (*partition)[0] <= 3)
			|| ft_is_sorted(*stack_b, (*partition)[0], 1))
	{
		while ((*partition)[0]-- > 0)
			ft_exec_command("pa\n", stack_a, stack_b);
		*partition = ft_delstart(partition);
		ft_first_three(*stack_a, cut_a);
	}
	else if ((*stack_b)[0] > 1)
		ft_pa_cycle_2(stack_a, stack_b, cut_a, partition);
}
