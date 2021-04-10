/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplets_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:39:44 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:39:45 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_first_three_2(int *stack, t_all *all)
{
	if (stack[2] < stack[1] && stack[1] < stack[3])
		ft_exec_command("sa\n", all);
	else if (stack[3] < stack[1] && stack[1] < stack[2])
	{
		ft_exec_command("ra\n", all);
		ft_exec_command("sa\n", all);
		ft_exec_command("rra\n", all);
		ft_exec_command("sa\n", all);
	}
	else if (stack[2] < stack[3] && stack[3] < stack[1])
	{
		ft_exec_command("sa\n", all);
		ft_exec_command("ra\n", all);
		ft_exec_command("sa\n", all);
		ft_exec_command("rra\n", all);
	}
	else
	{
		ft_exec_command("sa\n", all);
		ft_exec_command("ra\n", all);
		ft_exec_command("sa\n", all);
		ft_exec_command("rra\n", all);
		ft_exec_command("sa\n", all);
	}
}

void	ft_first_three(int *stack, int *a, t_all *all)
{
	if (stack[0] - *a == 2)
	{
		if (stack[1] > stack[2])
			ft_exec_command("sa\n", all);
	}
	else
	{
		if (stack[1] < stack[3] && stack[3] < stack[2])
		{
			ft_exec_command("ra\n", all);
			ft_exec_command("sa\n", all);
			ft_exec_command("rra\n", all);
		}
		else if (stack[1] > stack[2] || stack[2] > stack[3])
			ft_first_three_2(all->stack_a, all);
	}
	*a = stack[0];
}

void	ft_three(int *stack, t_all *all)
{
	if (stack[0] == 3)
	{
		if (stack[1] > stack[2])
			ft_exec_command("sa\n", all);
	}
	else
	{
		if (stack[1] < stack[2] && stack[2] < stack[3])
			return ;
		if (stack[1] < stack[2])
		{
			ft_exec_command("rra\n", all);
			ft_three(stack, all);
		}
		else if (stack[1] < stack[3])
		{
			ft_exec_command("sa\n", all);
			ft_three(stack, all);
		}
		else
		{
			ft_exec_command("ra\n", all);
			ft_three(stack, all);
		}
	}
}

void	ft_rev_three(int *stack, t_all *all)
{
	if (stack[0] == 3)
	{
		if (stack[1] < stack[2])
			ft_exec_command("sb\n", all);
	}
	else
	{
		if (stack[1] > stack[2] && stack[2] > stack[3])
			return ;
		if (stack[1] > stack[2])
		{
			ft_exec_command("rrb\n", all);
			ft_rev_three(stack, all);
		}
		else if (stack[1] > stack[3])
		{
			ft_exec_command("sb\n", all);
			ft_rev_three(stack, all);
		}
		else
		{
			ft_exec_command("rb\n", all);
			ft_rev_three(stack, all);
		}
	}
}
