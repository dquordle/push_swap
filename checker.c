#include "push_swap.h"
#include <stdio.h>

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

//int	main(int argc, char **argv)
//{
//	int	*stack_a;
//	int	*stack_b;
//	int check;
//	char *buf;
//
//	if (argc == 1)
//		exit(0);
////	check = 1;
////	while (argv[check])
////		printf("%s\n", argv[check++]);
//	stack_a = ft_create_stack(argc, argv);
//	stack_b = (int *)malloc(sizeof(int));
//	if (!stack_b)
//		ft_error(1);
//	*stack_b = 1;
////	int size_a = stack_a[0];
////	int i = 1;
////	while (i < size_a)
////		printf("%d\n", stack_a[i++]);
//	buf = NULL;
//	while (get_next_line(0, &buf))
//	{
////		printf("%s\n", buf);
//		buf = ft_strjoinf(buf, "\n");
//		ft_command(buf, &stack_a, &stack_b);
//		free(buf);
//		buf = NULL;
//	}
//	if (buf && buf[0])
//	{
////		printf("%s\n", buf);
////		printf("%s\n", buf);
////		printf("%s\n", buf);
//		buf = ft_strjoinf(buf, "\n");
//		ft_command(buf, &stack_a, &stack_b);
//		free(buf);
//	}
//	ft_okko(stack_a, stack_b);
//	return (0);
//}
