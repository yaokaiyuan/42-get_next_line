
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	line[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (0);
	str = ft_strjoin(0, line[fd]);
	if (ft_clean(line[fd]) > 0)
		return (next_line);
	i = read(fd, line[fd], BUFFER_SIZE);
	if (i < 0)
	{
		free(str);
		return (NULL);
	}
	while (i > 0)
	{
		str = ft_strjoin(str, line[fd]);
		if (ft_clean(line[fd]) > 0)
			break ;
		i = read(fd, line[fd], BUFFER_SIZE);
	}
	return (str);
}
