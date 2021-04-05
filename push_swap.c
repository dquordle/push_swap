#include "push_swap.h"

void	ft_exec_command(char *comm, int **stack_a, int **stack_b)
{
	ft_command(comm, stack_a, stack_b);
	write(1, comm, ft_strlen(comm));
}

//void	ft_two(int *stack)
//{
//	if (stack[1] > stack[2])
//	{
//		ft_rotate(stack);
//		write(1, "ra\n", 3);
//	}
//}

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
			return;
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

#include <stdio.h>
float	ft_get_median(int *array, int start, int end)
{
	int *copy;
	int *buf;
	int *sorted;
	int i;
	float median;

	copy = (int *)malloc(sizeof(int) * (end - start));
	buf = (int *)malloc(sizeof(int) * (end - start));
	i = 0;
	while (start < end)
		copy[i++] = array[start++];
	sorted = merge_sort(copy, buf, 0, i - 1);
	if (i % 2 != 0)
		median = sorted[i / 2];
	else
		median = (sorted[i / 2 - 1] + sorted[i / 2]) / 2.0;
	free(copy);
	free(buf);
	return (median);
}

int	*ft_appstart(int **array, int num)
{
	int	i;
	int *new_array;

	i = 0;
	while ((*array)[i])
		i++;
	new_array = (int *)malloc(sizeof(int) * (i + 2));
	if (!new_array)
		ft_error(1);
	new_array[0] = num;
	while (i >= 0)
	{
		new_array[i + 1] = (*array)[i];
		i--;
	}
	free(*array);
	return (new_array);
}

int	*ft_delstart(int **array)
{
	int	i;
	int *new_array;

	i = 1;
	while ((*array)[i])
		i++;
	new_array = (int *)malloc(sizeof(int) * i);
	if (!new_array)
		ft_error(1);
	i++;
	while (--i > 0)
		new_array[i - 1] = (*array)[i];
	free(*array);
	return (new_array);
}

void	ft_first_three_2(int *stack, int *a)
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
			ft_first_three_2(stack, a);
	}
	*a = stack[0];
}

int	ft_pb_cycle_2(int **stack_a, int **stack_b, int cut_a, int **partition)
{
	float median;
	int buf;
	int count_a;
	int count;

	count_a = 0;
	count = 0;
	median = ft_get_median(*stack_a, cut_a, (*stack_a)[0]);
	buf = (*stack_a)[0] - cut_a;
	while (buf > 0)
	{
		if ((*stack_a)[1] <= median)
		{
			ft_exec_command("pb\n", stack_a, stack_b);
			count++;
		}
		else if (buf > 1)
		{
			ft_exec_command("ra\n", stack_a, stack_b);
			count_a++;
		}
		buf--;
	}
	*partition = ft_appstart(partition, count);
	return (count_a);
}

void	ft_pb_cycle(int **stack_a, int **stack_b,  int *cut_a, int **partition)
{
	int count_a;

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

void	ft_pa_cycle_2(int **stack_a, int **stack_b, int *cut_a, int **partition)
{
	float	median;
	int	buf;
	int	count;

	median = ft_get_median(*stack_b, 1, (*partition)[0] + 1);
	buf = (*partition)[0];
	count = 0;
	while (buf-- > 0)
	{
		if ((*stack_b)[1] >= median)
			ft_exec_command("pa\n", stack_a, stack_b);
		else
		{
			ft_exec_command("rb\n", stack_a, stack_b);
			count++;
		}
	}
	if ((*partition)[0] - count <= 3)
		ft_first_three(*stack_a, cut_a);
	(*partition)[0] = count;
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
	else if (((*partition)[0] > 0 && (*partition)[0] <= 3) ||
		ft_is_sorted(*stack_b, (*partition)[0],  1))
	{
		while ((*partition)[0]-- > 0)
			ft_exec_command("pa\n", stack_a, stack_b);
		*partition = ft_delstart(partition);
		ft_first_three(*stack_a, cut_a);
	}
	else if ((*stack_b)[0] > 1)
		ft_pa_cycle_2(stack_a, stack_b, cut_a, partition);
}

void	ft_algos(int **stack_a, int **stack_b)
{
	int *partition;
	int	cut_a;
	int init_size;

	partition = (int *)malloc(sizeof(int));
	partition[0] = 0;
	cut_a = 1;
	init_size = (*stack_a)[0];
	while (cut_a < init_size)
	{
		ft_pb_cycle(stack_a, stack_b, &cut_a, &partition);
		ft_pa_cycle(stack_a, stack_b, &cut_a, &partition);
	}
	free(partition);
}

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc <= 2)
		exit(0);
	stack_a = ft_create_stack(argc, argv);
	stack_b = (int *)malloc(sizeof(int));
	if (!stack_b)
		ft_error(1);
	*stack_b = 1;
	if (argc <= 4)
		ft_three(stack_a);
	else
		ft_algos(&stack_a, &stack_b);
//	write(1, "sa\n", 3);
//	while (1)
//		;

//	printf("stack_a\n");
//	int i = 1;
//	while (i < (*stack_a)[0])
//		printf("%d\n", (*stack_a)[i++]);
//	printf("stack_b\n");
//	i = 1;
//	while (i < (*stack_b)[0])
//		printf("%d\n", (*stack_b)[i++]);
//		printf("partition:\n");
//		i = 0;
//		while (partition[i])
//			printf("%d\n", partition[i++]);


//	printf("initial stack_a:\n");
//	int i = 1;
//	while (i < stack_a[0])
//		printf("%d\n", stack_a[i++]);
//	while (1)
//		;
//	ft_error(1);
//	stack_b = (int *)malloc(sizeof(int));
//	if (!stack_b)
//		ft_error(1);
//	*stack_b = 1;
	free(stack_a);
	free(stack_b);
}