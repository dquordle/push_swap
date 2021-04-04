
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libftV3/libft.h"

void	ft_error(int err);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi_new(const char *str);
void	ft_validate(char **argv);
int		*ft_create_stack(int argc, char **argv);
void	ft_swap(int *stack);
void	ft_push(int **stack_to, int **stack_from);
void	ft_rotate(int *stack);
void	ft_reverse_rotate(int *stack);
int* merge_sort(int *up, int *down, unsigned int left, unsigned int right);
void	ft_command(char *buf, int **stack_a, int **stack_b);

#endif
