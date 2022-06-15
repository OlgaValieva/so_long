/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:06:47 by carys             #+#    #+#             */
/*   Updated: 2022/02/19 15:06:50 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1);
	str = malloc(sizeof(char) * (len + ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free((void *)(s1 - len));
	return (str);
}

int	gnl(char **line, int fd)
{
	int		bytes_buf;
	char	buffer[2];

	bytes_buf = 0;
	*line = malloc(1);
	if (!(*line))
		return (-1);
	(*line)[0] = '\0';
	buffer[1] = '\0';
	while ((read(fd, buffer, 1)) > 0)
	{
		bytes_buf = 1;
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin((*line), buffer);
	}
	if (!bytes_buf)
		free(*line);
	return (bytes_buf);
}
