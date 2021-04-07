/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:49:51 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 14:49:54 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_send_command(int **stack_a, int **stack_b, char **buf)
{
	*buf = ft_strjoinf(*buf, "\n");
	ft_command(*buf, stack_a, stack_b);
	free(*buf);
	*buf = NULL;
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	char	*buf;

	if (argc == 1)
		exit(0);
	stack_a = ft_create_stack(argc, argv);
	stack_b = (int *)malloc(sizeof(int));
	if (!stack_b)
		ft_error(1);
	*stack_b = 1;
	buf = NULL;
	while (get_next_line(0, &buf))
		ft_send_command(&stack_a, &stack_b, &buf);
	if (buf && buf[0])
		ft_send_command(&stack_a, &stack_b, &buf);
	ft_okko(stack_a, stack_b);
	return (0);
}
