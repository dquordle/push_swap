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

int	ft_is_flag(char *str)
{
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str,  "-c") ||
		!ft_strcmp(str, "-f"))
		return (1);
	return (0);
}

int	ft_check_flags_c(char **argv, t_all *all)
{
	int		i;

//	i = 0;
//	if (!ft_strcmp(argv[1], "-v"))
//	{
//		all->flag_v += ++i;
//		if (argv[2] && !ft_strcmp(argv[2], "-c"))
//			all->flag_c += i++;
//	}
//	else if (!ft_strcmp(argv[1], "-c"))
//	{
//		all->flag_c += ++i;
//		if (argv[2] && !ft_strcmp(argv[2], "-v"))
//			all->flag_v += i++;
//	}
	i = 1;
	while (argv[i] && ft_is_flag(argv[i]))
	{
		if (!ft_strcmp(argv[i], "-v"))
			all->flag_v += ++i;
		else if (!ft_strcmp(argv[i], "-c"))
			all->flag_c += ++i;
		else if (!ft_strcmp(argv[i], "-f"))
		{
			all->flag_f += ++i;
			if (!argv[i])
				ft_error(0);
			all->file_read = argv[i++];
		}
	}
	return (i - 1);
}

int	main(int argc, char **argv)
{
//	int	*stack_a;
//	int	*stack_b;
	t_all	*all;
	int	shift;
	char	*buf;
//	char	**trimmed_argv;

	if (argc == 1)
		exit(0);
//	check = 1;
//	while (argv[check])
//		printf("%s\n", argv[check++]);

	all = (t_all *)malloc(sizeof(t_all));
	all->flag_c = 0;
	all->flag_v = 0;
	all->write = 0;
	all->flag_f = 0;
	all->fd_read = 0;
	shift = ft_check_flags_c(argv, all);
	if (argc - shift == 1)
		exit(0);
	all->stack_a = ft_create_stack(argc - shift, (argv + shift));
	all->stack_b = (int *)malloc(sizeof(int));
	if (!all->stack_b)
		ft_error(1);
	*(all->stack_b) = 1;
	if (all->flag_f)
	{
		all->fd_read = open(all->file_read, O_RDONLY);
		if (all->fd_read == -1)
			ft_error(2);
	}

//	int size_a = all->stack_a[0];
//	int i = 1;
//	while (i < size_a)
//		printf("%d\n", all->stack_a[i++]);
	buf = NULL;
	while (get_next_line(all->fd_read, &buf))
	{
		buf = ft_strjoinf(buf, "\n");
//		ft_command(buf, &(all->stack_a), &(all->stack_b));
		ft_exec_command(buf, all);
		free(buf);
		buf = NULL;
	}
	if (buf && buf[0])
	{
		buf = ft_strjoinf(buf, "\n");
//		ft_command(buf, &(all->stack_a), &(all->stack_b));
		ft_exec_command(buf, all);
		free(buf);
	}
	ft_okko((all->stack_a), (all->stack_b));
	if (all->flag_f)
		close(all->fd_read);
	return (0);
}
