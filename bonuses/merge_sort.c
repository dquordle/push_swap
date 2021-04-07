#include "push_swap_bonus.h"

int	*merging(int *l_buff, int *r_buff, unsigned int lmr[3], int *target)
{
//	int 			*target;
	unsigned int	l_cur;
	unsigned int	r_cur;
//	unsigned int	middle;
	unsigned int	i;

//	middle = (lmr[0] + lmr[2]) / 2;
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
	return target;
}

int	*merge_sort(int *up, int *down, unsigned int left, unsigned int right)
{
	unsigned int lmr[3];
	int *l_buff;
	int *r_buff;
	int *target;

	if (left == right)
	{
		down[left] = up[left];
		return down;
	}

//	unsigned int middle = (left + right) / 2;
	lmr[0] = left;
	lmr[1] = (left + right) / 2;
	lmr[2] = right;
	// разделяй и сортируй
	l_buff = merge_sort(up, down, left, lmr[1]);
	r_buff = merge_sort(up, down, lmr[1] + 1, right);

	// слияние двух отсортированных половин
	target = up;
	if (l_buff == up)
		target = down;
//	target = l_buff == up ? down : up;

//	unsigned int l_cur = left, r_cur = middle + 1;
	return (merging(l_buff, r_buff, lmr, target));
//	for (unsigned int i = left; i <= right; i++)
//	{
//		if (l_cur <= middle && r_cur <= right)
//		{
//			if (l_buff[l_cur] < r_buff[r_cur])
//			{
//				target[i] = l_buff[l_cur];
//				l_cur++;
//			}
//			else
//			{
//				target[i] = r_buff[r_cur];
//				r_cur++;
//			}
//		}
//		else if (l_cur <= middle)
//		{
//			target[i] = l_buff[l_cur];
//			l_cur++;
//		}
//		else
//		{
//			target[i] = r_buff[r_cur];
//			r_cur++;
//		}
//	}
//	return target;
}
