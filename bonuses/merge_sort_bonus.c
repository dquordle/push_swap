/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:25:12 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:25:13 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*merging(int *l_buff, int *r_buff, unsigned int lmr[3], int *target)
{
	unsigned int	l_cur;
	unsigned int	r_cur;
	unsigned int	i;

	l_cur = lmr[0];
	r_cur = lmr[1] + 1;
	i = lmr[0] - 1;
	while (++i <= lmr[2])
	{
		if (l_cur <= lmr[1] && r_cur <= lmr[2])
		{
			if (l_buff[l_cur] < r_buff[r_cur])
				target[i] = l_buff[l_cur++];
			else
				target[i] = r_buff[r_cur++];
		}
		else if (l_cur <= lmr[1])
			target[i] = l_buff[l_cur++];
		else
			target[i] = r_buff[r_cur++];
	}
	return (target);
}

int	*merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
	unsigned int	lmr[3];
	int				*l_buff;
	int				*r_buff;
	int				*target;

	if (left == right)
	{
		down[left] = up[left];
		return (down);
	}
	lmr[0] = left;
	lmr[1] = (left + right) / 2;
	lmr[2] = right;
	l_buff = merge_sort(up, down, left, lmr[1]);
	r_buff = merge_sort(up, down, lmr[1] + 1, right);
	target = up;
	if (l_buff == up)
		target = down;
	return (merging(l_buff, r_buff, lmr, target));
}

float	ft_get_median(int *array, int start, int end)
{
	int		*copy;
	int		*buf;
	int		*sorted;
	int		i;
	float	median;

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
