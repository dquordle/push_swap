/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquordle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:22:54 by dquordle          #+#    #+#             */
/*   Updated: 2021/04/10 20:22:56 by dquordle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	j = ft_strlen(s2);
	i = ft_strlen(s1);
	res = (char *)malloc(i + j + 1);
	if (!res)
		ft_error(1);
	res[0] = '\0';
	ft_strlcat(res, s1, i + 1);
	ft_strlcat(res, s2, i + j + 1);
	free(s1);
	return (res);
}

void	ft_trimstart(char *dst, char *src)
{
	int	i;

	if (src == NULL)
		return ;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

int	ft_reading(char **rem, char **line, int fd)
{
	char	*buf;
	int		check;

	buf = ft_strchr(*rem, '\n');
	while (!buf)
	{
		*line = ft_strjoinf(*line, *rem);
		check = read(fd, *rem, 9999);
		if (!check)
		{
			free(*rem);
			*rem = NULL;
			return (0);
		}
		(*rem)[check] = 0;
		buf = ft_strchr(*rem, '\n');
	}
	*buf = 0;
	*line = ft_strjoinf(*line, *rem);
	if (!(*line))
		return (-1);
	ft_trimstart(*rem, buf + 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*rem = NULL;
	char		*buf;
	int			check;

	buf = NULL;
	if (fd && read(fd, buf, 0) == -1)
		ft_error(0);
	*line = ft_strdup("");
	if (!(*line))
		ft_error(1);
	if (!rem)
	{
		rem = (char *)malloc(10000);
		if (!rem)
			ft_error(1);
		check = read(fd, rem, 9999);
		if (check == 0)
		{
			free(*line);
			*line = NULL;
			return (0);
		}
		rem[check] = 0;
	}
	return (ft_reading(&rem, line, fd));
}
