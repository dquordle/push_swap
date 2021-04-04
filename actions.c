#include "push_swap.h"

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
	new_stack_to[0] = (*stack_to)[0] + 1;
	new_stack_to[1] = (*stack_from)[1];
	i = 0;
	while (++i < (*stack_to)[0])
		new_stack_to[i + 1] = (*stack_to)[i];
	new_stack_from = (int *)malloc(sizeof(int) * ((*stack_from)[0] - 1));
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