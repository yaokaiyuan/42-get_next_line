
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	str = ft_strjoin(0, line);
	if (ft_clean(line) > 0)
		return (str);
	i = read(fd, line, BUFFER_SIZE);
	if (i < 0)
	{
		free(str);
		return (NULL);
	}
	while (i > 0)
	{
		str = ft_strjoin(str, line);
		if (ft_clean(line) > 0)
			break ;
		i = read(fd, line, BUFFER_SIZE);
	}
	return (str);
}
