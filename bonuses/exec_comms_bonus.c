/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_comms_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:22:22 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:22:25 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_print_stacks(int *stack_a, int *stack_b)
{
	int	i;

	i = 1;
	while (i < stack_a[0] || i < stack_b[0])
	{
		if (i < stack_a[0])
			printf("% 19d |", stack_a[i]);
		else
			write(1, "                    |", 21);
		if (i < stack_b[0])
			printf("% 19d |", stack_b[i]);
		printf("\n");
		i++;
	}
}

void	ft_exec_command(char *comm, t_all *all)
{
	if (all->flag_g)
	{
		usleep(100000);
		pthread_mutex_lock(&all->mutex);
	}
	ft_command(comm, &(all->stack_a), &(all->stack_b));
	if (all->flag_c)
		write(1, "\e[36m", 5);
	if (all->write)
		write(all->fd, comm, ft_strlen(comm));
	if (all->flag_v)
	{
		if (all->flag_c)
			write(1, "\e[35m", 5);
		write (1, "====================|====================\n"
			"     STACK_A        |        STACK_B     \n", 84);
		if (all->flag_c)
			write(1, "\e[33m", 5);
		ft_print_stacks(all->stack_a, all->stack_b);
	}
	if (all->flag_c)
		write(1, "\e[0m", 4);
	if (all->flag_g)
		pthread_mutex_unlock(&all->mutex);
}
