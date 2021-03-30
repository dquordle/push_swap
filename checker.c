#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi_new(const char *str)
{
	int			i;
	int			z;
	long int	a;

	i = 0;
	z = 0;
	if (str[i] == '-')
		z += str[i++];
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a *= 10;
		a += str[i++] - 48;
		if (a > 2147483648 || (a == 2147483648 && z == 0))
			ft_error();
	}
	if (a == 2147483648 && z)
		return (-2147483648);
	if (z)
		return ((int)a * (-1));
	return ((int)a);
}

void	ft_validate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j])
				ft_error();
		}
		i++;
	}
}

int	*ft_create_stack(int argc, char **argv)
{
	int	i;
	int	*arr;
	int j;

	ft_validate(argv);
	arr = (int *)malloc(sizeof(int) * (argc + 1));
	arr[0] = argc;
	i = 0;
	while (argv[++i])
		arr[i] = ft_atoi_new(argv[i]);
	while (i > 1)
	{
		j = i - 1;
		while (j >= 1)
		{
			if (arr[i] == arr[j])
				ft_error();
			j--;
		}
		i--;
	}
	return (arr);
}

void	ft_swap(int **stack)
{
	int buf;

	if ((*stack)[0] == 1 || (*stack)[0] == 2)
		return ;
	buf = (*stack)[1];
	(*stack)[1] = (*stack)[2];
	(*stack)[2] = buf;
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

void	ft_command(char *buf, int **stack_a, int **stack_b)
{
	if (!ft_strcmp(buf, "sa\n"))
		ft_swap(stack_a);
	else if (!ft_strcmp(buf, "sb\n"))
		ft_swap(stack_b);
	else if (!ft_strcmp(buf, "ss\n"))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
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
		ft_error();
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

	stack_a = ft_create_stack(argc, argv);
	stack_b = (int *)malloc(sizeof(int));
	if (!stack_b)
		exit(1);
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
