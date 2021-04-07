#include "push_swap_bonus.h"

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
	else if (!ft_strcmp(buf, "rra\n"))
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
//	int size_a = (*stack_a)[0];
//	int i = 1;
//	printf("stack_a\n");
//	while (i < size_a)
//		printf("%d\n", (*stack_a)[i++]);
//	printf("stack_b\n");
//	i = 1;
//	while (i < (*stack_b)[0])
//		printf("%d\n", (*stack_b)[i++]);
}

void	ft_print_stacks(int *stack_a, int *stack_b)
{
	int i;

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
	ft_command(comm, &(all->stack_a), &(all->stack_b));
	if (all->flag_c)
		write(1, "\e[36m", 5);
	if (all->write)
		write(1, comm, ft_strlen(comm));
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
}


void	ft_swap(int *stack)
{
	int buf;

	if (stack[0] == 1 || stack[0] == 2)
		return ;
	buf = stack[1];
	stack[1] = stack[2];
	stack[2] = buf;
}

void	ft_push(int **stack_to, int **stack_from)
{
	int	i;
	int *new_stack_to;
	int *new_stack_from;

	if ((*stack_from)[0] == 1)
		return ;
	new_stack_to = (int *)malloc(sizeof(int) * ((*stack_to)[0] + 1));
	new_stack_from = (int *)malloc(sizeof(int) * ((*stack_from)[0] - 1));
	if (!new_stack_to || !new_stack_from)
		ft_error(1);
	new_stack_to[0] = (*stack_to)[0] + 1;
	new_stack_to[1] = (*stack_from)[1];
	i = 0;
	while (++i < (*stack_to)[0])
		new_stack_to[i + 1] = (*stack_to)[i];
	new_stack_from[0] = (*stack_from)[0] - 1;
	i = 0;
	while (++i < new_stack_from[0])
		new_stack_from[i] = (*stack_from)[i + 1];
	free(*stack_from);
	free(*stack_to);
	*stack_from = new_stack_from;
	*stack_to = new_stack_to;
}

void	ft_rotate(int *stack)
{
	int	buf;
	int i;

	if (stack[0] == 1 || stack[0] == 2)
		return ;
	buf = stack[1];
	i = 0;
	while (++i < stack[0] - 1)
		stack[i] = stack[i + 1];
	stack[i] = buf;
}

void	ft_reverse_rotate(int *stack)
{
	int	buf;
	int i;

	if (stack[0] == 1 || stack[0] == 2)
		return ;
	buf = stack[stack[0] - 1];
	i = stack[0];
	while (--i > 1)
		stack[i] = stack[i - 1];
	stack[1] = buf;
}