/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:14:07 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/03/28 17:37:09 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] != (char)c) && s[i])
		i++;
	if (s[i])
		return ((char *)&s[i]);
	else if (!s[i] && ((char)c) == 0)
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char *str, char *buff, int buff_len)
{
	int		i;
	int		j;
	char	*ptr;

	if (str == NULL || buff == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(str) + buff_len + 1));
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		ptr[i] = str[i];
	j = 0;
	while (j < buff_len)
		ptr[i++] = buff[j++];
	ptr[ft_strlen(str) + buff_len] = '\0';
	free(str);
	return (ptr);
}

char	*handle_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*handle_rest(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}
