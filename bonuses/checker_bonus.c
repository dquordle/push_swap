/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:15:09 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:15:10 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_okko(t_all *all)
{
	int	i;

	if ((all->stack_b)[0] != 1)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	i = 1;
	while (i < (all->stack_a)[0] - 1)
	{
		if ((all->stack_a)[i] > (all->stack_a)[i + 1])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		i++;
	}
	write(1, "OK\n", 3);
}

int	ft_check_flags_c(char **argv, t_all *all)
{
	int		i;

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
			all->file = argv[i++];
		}
	}
	return (i - 1);
}

t_all	*ft_setup_all_c(int argc, char **argv)
{
	t_all	*all;
	int		shift;

	all = (t_all *)malloc(sizeof(t_all));
	all->flag_c = 0;
	all->flag_v = 0;
	all->flag_f = 0;
	all->flag_g = 0;
	all->write = 0;
	all->fd = 0;
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
		all->fd = open(all->file, O_RDONLY);
		if (all->fd == -1)
			ft_error(2);
	}
	return (all);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	char	*buf;

	all = ft_setup_all_c(argc, argv);
	buf = NULL;
	while (get_next_line(all->fd, &buf))
	{
		buf = ft_strjoinf(buf, "\n");
		ft_exec_command(buf, all);
		free(buf);
		buf = NULL;
	}
	if (buf && buf[0])
	{
		buf = ft_strjoinf(buf, "\n");
		ft_exec_command(buf, all);
		free(buf);
	}
	if (all->flag_f)
		close(all->fd);
	ft_okko(all);
}
