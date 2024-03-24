/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:14:03 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/03/24 18:31:35 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_result(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!str)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = handle_result(fd, str);
	if (!str)
		return (NULL);
	line = handle_line(str);
	str = handle_rest(str);
	return (line);
}
