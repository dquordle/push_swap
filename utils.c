#include "push_swap.h"

void	ft_error(int err)
{
	if (err == 0)
		write(2, "Error\n", 6);
	else if (err == 1)
		write(2, "Malloc error\n", 13);
	exit(1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi_new(const char *str)
{
	int			i;
	int			z;
	long int	a;

	i = 0;
	z = 0;
	if (str[i] == '-')
		z += str[i++];
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a *= 10;
		a += str[i++] - 48;
		if (a > 2147483648 || (a == 2147483648 && z == 0))
			ft_error(0);
	}
	if (a == 2147483648 && z)
		return (-2147483648);
	if (z)
		return ((int)a * (-1));
	return ((int)a);
}

void	ft_validate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			while (ft_isdigit(argv[i][j]))
				j++;
			if (argv[i][j])
				ft_error(0);
		}
		i++;
	}
}

int	*ft_create_stack(int argc, char **argv)
{
	int	i;
	int	*arr;
	int j;

	ft_validate(argv);
	arr = (int *)malloc(sizeof(int) * (argc + 1));
	if (!arr)
		ft_error(1);
	arr[0] = argc;
	i = 0;
	while (argv[++i])
		arr[i] = ft_atoi_new(argv[i]);
	while (--i > 1)
	{
		j = i - 1;
		while (j >= 1)
		{
			if (arr[i] == arr[j])
				ft_error(0);
			j--;
		}
	}
	return (arr);
}