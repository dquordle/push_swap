/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_app_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:16:43 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:16:46 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*ft_appstart(int **array, int num)
{
	int	i;
	int	*new_array;

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
	int	*new_array;

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

int	ft_need_to_ra(int *stack_a, int cut_a, float median)
{
	int	i;
	int	buf;

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
