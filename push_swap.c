#include "push_swap.h"

//void	ft_exec_command(int *stack_a, int *stack_b, char *comm)
//{
//
//}

int* merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

	unsigned int middle = (left + right) / 2;

	// разделяй и сортируй
	int *l_buff = merge_sort(up, down, left, middle);
	int *r_buff = merge_sort(up, down, middle + 1, right);

	// слияние двух отсортированных половин
	int *target = l_buff == up ? down : up;

	unsigned int l_cur = left, r_cur = middle + 1;
	for (unsigned int i = left; i <= right; i++)
	{
		if (l_cur <= middle && r_cur <= right)
		{
			if (l_buff[l_cur] < r_buff[r_cur])
			{
				target[i] = l_buff[l_cur];
				l_cur++;
			}
			else
			{
				target[i] = r_buff[r_cur];
				r_cur++;
			}
		}
		else if (l_cur <= middle)
		{
			target[i] = l_buff[l_cur];
			l_cur++;
		}
		else
		{
			target[i] = r_buff[r_cur];
			r_cur++;
		}
	}
	return target;
}

void	ft_two(int *stack_a)
{
	if (stack_a[1] < stack_a[2])
		exit(0);
	else
	{
		ft_rotate(stack_a);
		write(1, "ra\n", 3);
		exit(0);
	}
}

void	ft_three(int *stack_a)
{
	if (stack_a[0] == 3)
		ft_two(stack_a);
	else
	{
		if (stack_a[1] < stack_a[2] && stack_a[2] < stack_a[3])
			return;
		if (stack_a[1] < stack_a[2])
		{
			ft_reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			ft_three(stack_a);
		}
		else if (stack_a[1] < stack_a[3])
		{
			ft_swap(stack_a);
			write(1, "sa\n", 3);
			ft_three(stack_a);
		}
		else
		{
			ft_rotate(stack_a);
			write(1, "ra\n", 3);
			ft_three(stack_a);
		}
	}
}

int	ft_get_median(int *array)
{
	int *buf;


}

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc <= 2)
		exit(0);
	stack_a = ft_create_stack(argc, argv);
	if (argc <= 4)
		ft_three(stack_a);
	else
	{

	}
//	ft_error(1);
//	stack_b = (int *)malloc(sizeof(int));
//	if (!stack_b)
//		ft_error(1);
//	*stack_b = 1;
}