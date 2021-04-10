/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:33:06 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:36:20 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include "../libftV3/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_all
{
	int				*stack_a;
	int				*stack_b;
	int				flag_c;
	int				flag_v;
	int				flag_f;
	int				flag_g;
	char			*file;
	int				fd;
	int				write;
	void			*mlx;
	void			*mlx_win;
	t_data			*img;
	int				max;
	int				min;
	int				width;
	pthread_mutex_t	mutex;
}				t_all;

void	ft_error(int err);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi_new(const char *str);
void	ft_validate(char **argv);
int		*ft_create_stack(int argc, char **argv);
void	ft_swap(int *stack);
void	ft_push(int **stack_to, int **stack_from);
void	ft_rotate(int *stack);
void	ft_reverse_rotate(int *stack);
int		*merge_sort(int *up, int *down, unsigned int left, unsigned int right);
void	ft_command(char *buf, int **stack_a, int **stack_b);
void	ft_exec_command(char *comm, t_all *all);
int		get_next_line(int fd, char **line);
char	*ft_strjoinf(char *s1, char *s2);
int		ft_check_flags(char **argv, t_all *all);
int		ft_is_flag(char *str);
int		ft_draw(t_all *all);
void	ft_graphic(t_all *all);
void	*ft_graphana(t_all *all);
int		ft_exit(void);
void	*ft_algos_2(void *all);
void	ft_first_three(int *stack, int *a, t_all *all);
void	ft_rev_three(int *stack, t_all *all);
void	ft_three(int *stack, t_all *all);
float	ft_get_median(int *array, int start, int end);
void	ft_pb_cycle(t_all *all, int *cut_a, int **partition);
int		ft_need_to_rb(int *stack_b, int buf, float median);
void	ft_pa_cycle(t_all *all, int *cut_a, int **partition);
int		*ft_delstart(int **array);
int		*ft_appstart(int **array, int num);
int		ft_need_to_ra(int *stack_a, int cut_a, float median);
int		ft_is_sorted(int *array, int start, int end);
void	ft_algos(t_all *all);

#endif
