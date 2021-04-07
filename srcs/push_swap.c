/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:10:20 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 15:10:52 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algorithm(int **stack_a, int **stack_b)
{
	int	*partition;
	int	cut_a;
	int	init_size;

	partition = (int *)malloc(sizeof(int));
	if (!partition)
		ft_error(1);
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

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc == 1)
		exit(0);
	stack_a = ft_create_stack(argc, argv);
	if (argc == 2)
		exit(0);
	stack_b = (int *)malloc(sizeof(int));
	if (!stack_b)
		ft_error(1);
	*stack_b = 1;
	if (argc <= 4)
		ft_three(stack_a);
	else
		ft_algorithm(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
}
