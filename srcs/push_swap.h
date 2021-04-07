/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:08:49 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/07 15:09:59 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftV3/libft.h"

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
float	ft_get_median(int *array, int start, int end);
void	ft_command(char *buf, int **stack_a, int **stack_b);
void	ft_exec_command(char *comm, int **stack_a, int **stack_b);
int		get_next_line(int fd, char **line);
char	*ft_strjoinf(char *s1, char *s2);
int		ft_is_sorted(int *array, int start, int end);
int		ft_need_to_ra(int *stack_a, int cut_a, float median);
int		ft_need_to_rb(int *stack_b, int buf, float median);
void	ft_pb_cycle(int **stack_a, int **stack_b, int *cut_a, int **partition);
void	ft_pa_cycle(int **stack_a, int **stack_b, int *cut_a, int **partition);
void	ft_three(int *stack);
void	ft_rev_three(int *stack);
void	ft_first_three(int *stack, int *a);
int		*ft_appstart(int **array, int num);
int		*ft_delstart(int **array);

#endif
