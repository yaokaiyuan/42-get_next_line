
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	characters[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (0);
	line = ft_strjoin(0, characters[fd]);
	if (ft_clean(characters[fd]) > 0)
		return (line);
	i = read(fd, characters[fd], BUFFER_SIZE);
	if (i < 0)
	{
		free(line);
		return (NULL);
	}
	while (i > 0)
	{
		line = ft_strjoin(line, characters[fd]);
		if (ft_clean(characters[fd]) > 0)
			break ;
		i = read(fd, characters[fd], BUFFER_SIZE);
	}
	return (line);
}
