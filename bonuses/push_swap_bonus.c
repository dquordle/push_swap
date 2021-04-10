/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:28:58 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:28:59 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_algos(t_all *all)
{
	int	*partition;
	int	cut_a;
	int	init_size;

	if (all->stack_a[0] <= 4)
	{
		ft_three(all->stack_a, all);
		return ;
	}
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

void	*ft_algos_2(void *all)
{
	ft_algos((t_all *)all);
	return (NULL);
}

int	ft_check_flags_p(char **argv, t_all *all)
{
	int		i;

	i = 1;
	while (argv[i] && ft_is_flag(argv[i]))
	{
		if (!ft_strcmp(argv[i], "-v"))
			all->flag_v += ++i;
		else if (!ft_strcmp(argv[i], "-c"))
			all->flag_c += ++i;
		else if (!ft_strcmp(argv[i], "-g"))
			all->flag_g += ++i;
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

t_all	*ft_setup_all_p(int argc, char **argv)
{
	t_all	*all;
	int		shift;

	all = (t_all *)malloc(sizeof(t_all));
	all->flag_c = 0;
	all->flag_v = 0;
	all->flag_f = 0;
	all->flag_g = 0;
	all->write = 1;
	all->fd = 1;
	shift = ft_check_flags_p(argv, all);
	all->stack_a = ft_create_stack(argc - shift, (argv + shift));
	if (argc - shift == 2)
		exit(0);
	all->stack_b = (int *)malloc(sizeof(int));
	if (!all->stack_b)
		ft_error(1);
	*(all->stack_b) = 1;
	if (all->flag_f)
	{
		all->fd = open(all->file, O_WRONLY | O_CREAT, 00777);
		if (all->fd == -1)
			ft_error(2);
	}
	return (all);
}

int	main(int argc, char **argv)
{
	t_all		*all;
	pthread_t	thread;

	all = ft_setup_all_p(argc, argv);
	if (all->flag_g)
	{
		pthread_mutex_init(&all->mutex, NULL);
		ft_graphic(all);
		ft_draw(all);
		pthread_create(&thread, NULL, ft_algos_2, all);
		ft_graphana(all);
	}
	ft_algos(all);
	free(all->stack_a);
	free(all->stack_b);
	if (all->flag_f)
		close(all->fd);
	free(all);
	exit(0);
}
