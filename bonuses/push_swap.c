#include "push_swap_bonus.h"


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
			return;
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

void	ft_first_three_2(int *stack, int *a, t_all *all)
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
			ft_first_three_2(all->stack_a, a, all);
	}
	*a = stack[0];
}

int ft_need_to_ra(int *stack_a, int cut_a, float median)
{
	int i;
	int buf;

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

int	ft_pb_cycle_2(t_all *all, int cut_a, int **partition)
{
	float median;
	int buf;
	int count_a;
	int count;

	count_a = 0;
	count = 0;
	median = ft_get_median(all->stack_a, 1, all->stack_a[0] - cut_a + 1);
	buf = all->stack_a[0] - cut_a;
	while (buf > 0)
	{
		if (all->stack_a[1] <= median)
		{
			ft_exec_command("pb\n", all);
			count++;
		}
		else if (ft_need_to_ra(all->stack_a, cut_a, median))
		{
			ft_exec_command("ra\n", all);
			count_a++;
		}
		buf--;
	}
	*partition = ft_appstart(partition, count);
	return (count_a);
}

void	ft_pb_cycle(t_all *all,  int *cut_a, int **partition)
{
	int count_a;

	while (all->stack_a[0] - *cut_a > 3)
	{
		if (ft_is_sorted(all->stack_a, 1, all->stack_a[0] - 1))
		{
			*cut_a = all->stack_a[0];
			break ;
		}
		count_a = ft_pb_cycle_2(all, *cut_a, partition);
		if (*cut_a > 1)
		{
			while (count_a--)
				ft_exec_command("rra\n", all);
		}
	}
	if (*cut_a == 1)
	{
		ft_three(all->stack_a, all);
		*cut_a = all->stack_a[0];
	}
	else
		ft_first_three(all->stack_a, cut_a, all);
}

int ft_need_to_rb(int *stack_b, int buf, float median)
{
	int i;

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

void	ft_pa_cycle_2(t_all *all, int *cut_a, int **partition)
{
	float	med;
	int	buf;
	int	count;
	int count_a;

	med = ft_get_median(all->stack_b, 1, (*partition)[0] + 1);
	buf = (*partition)[0];
	count = 0;
	count_a = 0;
	while (buf-- > 0)
	{
		if (all->stack_b[1] < med && ft_need_to_rb(all->stack_b, buf, med)
			&& ++count)
			ft_exec_command("rb\n", all);
		else if (all->stack_b[1] >= med && ++count_a && (*partition)[0]--)
			ft_exec_command("pa\n", all);
	}
	if (count_a <= 3)
		ft_first_three(all->stack_a, cut_a, all);
	if ((*partition)[1])
	{
		while (count-- > 0)
			ft_exec_command("rrb\n", all);
	}
}

void	ft_pa_cycle(t_all *all, int *cut_a, int **partition)
{
	if (all->stack_b[0] > 1 && all->stack_b[0] <= 4)
	{
		ft_rev_three(all->stack_b, all);
		while (all->stack_b[0] > 1)
			ft_exec_command("pa\n", all);
		*cut_a = all->stack_a[0];
		(*partition)[0] = 0;
	}
	else if (((*partition)[0] > 0 && (*partition)[0] <= 3) ||
		ft_is_sorted(all->stack_b, (*partition)[0],  1))
	{
		while ((*partition)[0]-- > 0)
			ft_exec_command("pa\n", all);
		*partition = ft_delstart(partition);
		ft_first_three(all->stack_a, cut_a, all);
	}
	else if (all->stack_b[0] > 1)
		ft_pa_cycle_2(all, cut_a, partition);
}

void	ft_algos(t_all *all)
{
	int *partition;
	int	cut_a;
	int init_size;

	partition = (int *)malloc(sizeof(int));
	if (!partition)
		ft_error(1);
	partition[0] = 0;
	cut_a = 1;
	init_size = (all->stack_a)[0];
	while (cut_a < init_size)
	{
		ft_pb_cycle(all, &cut_a, &partition);
		ft_pa_cycle(all, &cut_a, &partition);
	}
	free(partition);
}

int	ft_check_flags_p(char **argv, t_all *all)
{
	int		i;

	i = 0;
	if (!ft_strcmp(argv[1], "-v"))
	{
		all->flag_v += ++i;
		if (argv[2] && !ft_strcmp(argv[2], "-c"))
			all->flag_c += i++;
	}
	else if (!ft_strcmp(argv[1], "-c"))
	{
		all->flag_c += ++i;
		if (argv[2] && !ft_strcmp(argv[2], "-v"))
			all->flag_v += i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
//	int	*stack_a;
//	int	*stack_b;
	t_all	*all;
	int	shift;

	if (argc == 1)
		exit(0);
	all = (t_all *)malloc(sizeof(t_all));
	all->flag_c = 0;
	all->flag_v = 0;
	all->write = 1;
	shift = ft_check_flags_p(argv, all);
	all->stack_a = ft_create_stack(argc - shift, (argv + shift));
	if (argc == 2)
		exit(0);
	all->stack_b = (int *)malloc(sizeof(int));
	if (!all->stack_b)
		ft_error(1);
	*(all->stack_b) = 1;
	if (argc <= 4)
		ft_three(all->stack_a, all);
	else
		ft_algos(all);
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
//	printf("partition:\n");
//	i = 0;
//	while (partition[i])
//		printf("%d\n", partition[i++]);


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
	free(all->stack_a);
	free(all->stack_b);
}