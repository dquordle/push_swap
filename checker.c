#include "push_swap.h"
//#include <stdio.h>


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
	int size_a = (*stack_a)[0];
	int i = 1;
//	printf("stack_a\n");
//	while (i < size_a)
//		printf("%d\n", (*stack_a)[i++]);
//	printf("stack_b\n");
//	i = 1;
//	while (i < (*stack_b)[0])
//		printf("%d\n", (*stack_b)[i++]);
}

void	ft_okko(int *stack_a, int *stack_b)
{
	int	i;

	if (stack_b[0] != 1)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	i = 1;
	while (i < stack_a[0] - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		i++;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int check;
	char buf[5];

	if (argc == 1)
		exit(0);
	stack_a = ft_create_stack(argc, argv);
	stack_b = (int *)malloc(sizeof(int));
	if (!stack_b)
		ft_error(1);
	*stack_b = 1;
//	int size_a = stack_a[0];
//	int i = 1;
//	while (i < size_a)
//		printf("%d\n", stack_a[i++]);
	while ((check = read(0, buf, 4)))
	{
		buf[check] = 0;
		ft_command(buf, &stack_a, &stack_b);
	}
	ft_okko(stack_a, stack_b);
	return (0);
}
