/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:21:19 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:21:38 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_stacks(t_all *all, int i, int y)
{
	int	x;

	if (i < all->stack_a[0])
	{
		x = 0;
		while (x < (all->stack_a[i] - all->min) * 950
			/ (all->max - all->min))
			my_mlx_pixel_put(all->img, x++, y, 2936);
	}
	if (i < all->stack_b[0])
	{
		x = 970;
		while (x - 970 < (all->stack_b[i] - all->min) * 950
			/ (all->max - all->min))
			my_mlx_pixel_put(all->img, x++, y, 2936);
	}
}

int	ft_draw(t_all *all)
{
	int	i;
	int	x;
	int	y;

	pthread_mutex_lock(&all->mutex);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
			my_mlx_pixel_put(all->img, x++, y, 0);
		y++;
	}
	i = 1;
	y = 0;
	while (i < all->stack_a[0] || i < all->stack_b[0])
	{
		while (y < all->width * i)
			ft_draw_stacks(all, i, y++);
		i++;
	}
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img->img, 0, 0);
	pthread_mutex_unlock(&all->mutex);
	return (0);
}

void	ft_graphic(t_all *all)
{
	int		i;
	void	*mlx;
	void	*mlx_win;
	t_data	*img;

	mlx = mlx_init();
	img = (t_data *)malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "push_swap");
	i = 0;
	all->max = all->stack_a[1];
	all->min = all->stack_a[1];
	while (++i < all->stack_a[0])
	{
		if (all->stack_a[i] > all->max)
			all->max = all->stack_a[i];
		if (all->stack_a[i] < all->min)
			all->min = all->stack_a[i];
	}
	all->img = img;
	all->mlx = mlx;
	all->mlx_win = mlx_win;
	all->width = 1080 / (all->stack_a[0] - 1);
}

void	*ft_graphana(t_all *all)
{
	mlx_loop_hook(all->mlx, ft_draw, all);
	mlx_hook(all->mlx_win, 17, 0, ft_exit, NULL);
	mlx_loop(all->mlx);
	return (0);
}
