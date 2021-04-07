/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:16:36 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 15:16:38 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(int *stack)
{
	if (stack[0] == 3)
	{
		if (stack[1] > stack[2])
			ft_exec_command("sa\n", &stack, NULL);
	}
	else
	{
		if (stack[1] < stack[2] && stack[2] < stack[3])
			return ;
		if (stack[1] < stack[2])
		{
			ft_exec_command("rra\n", &stack, NULL);
			ft_three(stack);
		}
		else if (stack[1] < stack[3])
		{
			ft_exec_command("sa\n", &stack, NULL);
			ft_three(stack);
		}
		else
		{
			ft_exec_command("ra\n", &stack, NULL);
			ft_three(stack);
		}
	}
}

void	ft_rev_three(int *stack)
{
	if (stack[0] == 3)
	{
		if (stack[1] < stack[2])
			ft_exec_command("sb\n", NULL, &stack);
	}
	else
	{
		if (stack[1] > stack[2] && stack[2] > stack[3])
			return ;
		if (stack[1] > stack[2])
		{
			ft_exec_command("rrb\n", NULL, &stack);
			ft_rev_three(stack);
		}
		else if (stack[1] > stack[3])
		{
			ft_exec_command("sb\n", NULL, &stack);
			ft_rev_three(stack);
		}
		else
		{
			ft_exec_command("rb\n", NULL, &stack);
			ft_rev_three(stack);
		}
	}
}

void	ft_first_three_2(int *stack)
{
	if (stack[2] < stack[1] && stack[1] < stack[3])
		ft_exec_command("sa\n", &stack, NULL);
	else if (stack[3] < stack[1] && stack[1] < stack[2])
	{
		ft_exec_command("ra\n", &stack, NULL);
		ft_exec_command("sa\n", &stack, NULL);
		ft_exec_command("rra\n", &stack, NULL);
		ft_exec_command("sa\n", &stack, NULL);
	}
	else if (stack[2] < stack[3] && stack[3] < stack[1])
	{
		ft_exec_command("sa\n", &stack, NULL);
		ft_exec_command("ra\n", &stack, NULL);
		ft_exec_command("sa\n", &stack, NULL);
		ft_exec_command("rra\n", &stack, NULL);
	}
	else
	{
		ft_exec_command("sa\n", &stack, NULL);
		ft_exec_command("ra\n", &stack, NULL);
		ft_exec_command("sa\n", &stack, NULL);
		ft_exec_command("rra\n", &stack, NULL);
		ft_exec_command("sa\n", &stack, NULL);
	}
}

void	ft_first_three(int *stack, int *a)
{
	if (stack[0] - *a == 2)
	{
		if (stack[1] > stack[2])
			ft_exec_command("sa\n", &stack, NULL);
	}
	else
	{
		if (stack[1] < stack[3] && stack[3] < stack[2])
		{
			ft_exec_command("ra\n", &stack, NULL);
			ft_exec_command("sa\n", &stack, NULL);
			ft_exec_command("rra\n", &stack, NULL);
		}
		else if (stack[1] > stack[2] || stack[2] > stack[3])
			ft_first_three_2(stack);
	}
	*a = stack[0];
}
