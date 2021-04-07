
#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include <stdio.h>
#include <fcntl.h>
#include "../libftV3/libft.h"

typedef struct s_all
{
	int *stack_a;
	int *stack_b;
	int flag_c;
	int	flag_v;
	int flag_f;
	char	*file_read;
	int		fd_read;
	char	*file_write;
	int 	fd_write;
	int write;
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
int* merge_sort(int *up, int *down, unsigned int left, unsigned int right);
void	ft_command(char *buf, int **stack_a, int **stack_b);
void	ft_exec_command(char *comm, t_all *all);
int		get_next_line(int fd, char **line);
char	*ft_strjoinf(char *s1, char *s2);
int		ft_check_flags(char **argv, t_all *all);

#endif
