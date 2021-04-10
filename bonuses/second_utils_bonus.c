/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:39:22 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:39:24 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_flag(char *str)
{
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-c")
		|| !ft_strcmp(str, "-f") || !ft_strcmp(str, "-g"))
		return (1);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

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
