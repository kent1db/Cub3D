/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:24:27 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/13 16:17:28 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void			*ft_c(size_t count, size_t size)
{
	void		*p;

	if (!(p = malloc(size * count)))
		return (NULL);
	ft_memset(p, 0, (count * size));
	return (p);
}

static int		ft_read(int *ret, int fd, char **buff)
{
	char		tmp[BUFFER_SIZE + 1];

	*ret = read(fd, tmp, BUFFER_SIZE);
	if (*ret >= 0)
		tmp[*ret] = '\0';
	if (!(*buff = ft_strjoin_free(*buff, tmp)))
		*ret = -1;
	if (*ret < 0)
	{
		free(*buff);
		*buff = NULL;
	}
	return (*ret);
}

static	int		ft_last_cpy(char **line, char **buff)
{
	int			len;

	len = ft_strlen(*buff);
	if (!(*line = ft_supstr(*buff, 0, len, 0)))
		return (-1);
	ft_memset(*buff, '\0', len);
	free(*buff);
	*buff = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	int			nl;
	static char	*t[OPEN_MAX];

	ret = 1;
	nl = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || (!t[fd] && !(t[fd] = ft_c(1, 1))))
		return (-1);
	while (ret)
	{
		if ((nl = ft_memchr_g(t[fd], '\n', ft_strlen(t[fd]))) != -1)
		{
			if (!(*line = ft_supstr(t[fd], 0, nl, 0)))
				return (-1);
			t[fd] = ft_supstr(t[fd], nl + 1, (ft_strlen(t[fd]) - (nl + 1)), 1);
			return (1);
		}
		if (ft_read(&ret, fd, &t[fd]) < 0)
			return (-1);
	}
	if (ret == 0)
		ft_last_cpy(line, &t[fd]);
	return (ret);
}
