/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:15:47 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 15:15:49 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_command_2(char *buf, int **stack_a, int **stack_b)
{
	if (!ft_strcmp(buf, "rra\n"))
		ft_reverse_rotate(*stack_a);
	else if (!ft_strcmp(buf, "rrb\n"))
		ft_reverse_rotate(*stack_b);
	else if (!ft_strcmp(buf, "rrr\n"))
	{
		ft_reverse_rotate(*stack_a);
		ft_reverse_rotate(*stack_b);
	}
	else
		ft_error(0);
}

void	ft_command(char *buf, int **stack_a, int **stack_b)
{
	if (!ft_strcmp(buf, "sa\n"))
		ft_swap(*stack_a);
	else if (!ft_strcmp(buf, "sb\n"))
		ft_swap(*stack_b);
	else if (!ft_strcmp(buf, "ss\n"))
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	else if (!ft_strcmp(buf, "pa\n"))
		ft_push(stack_a, stack_b);
	else if (!ft_strcmp(buf, "pb\n"))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp(buf, "ra\n"))
		ft_rotate(*stack_a);
	else if (!ft_strcmp(buf, "rb\n"))
		ft_rotate(*stack_b);
	else if (!ft_strcmp(buf, "rr\n"))
	{
		ft_rotate(*stack_a);
		ft_rotate(*stack_b);
	}
	else
		ft_command_2(buf, stack_a, stack_b);
}

void	ft_exec_command(char *comm, int **stack_a, int **stack_b)
{
	ft_command(comm, stack_a, stack_b);
	write(1, comm, ft_strlen(comm));
}

int	ft_is_sorted(int *array, int start, int end)
{
	if (start < end)
	{
		while (start < end)
		{
			if (array[start] > array[start + 1])
				return (0);
			start++;
		}
	}
	else
	{
		while (start > end)
		{
			if (array[start] > array[start - 1])
				return (0);
			start--;
		}
	}
	return (1);
}

int	ft_need_to_ra(int *stack_a, int cut_a, float median)
{
	int	i;
	int	buf;

	buf = stack_a[0] - cut_a;
	i = 1;
	while (buf > 0)
	{
		if (stack_a[i] <= median)
			return (1);
		i++;
		buf--;
	}
	return (0);
}
