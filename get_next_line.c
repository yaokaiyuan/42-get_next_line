
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	characters[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	line = ft_strjoin(0, characters);
	if (ft_clean(characters) > 0)
		return (line);
	i = read(fd, characters, BUFFER_SIZE);
	if (i < 0)
	{
		free(line);
		return (NULL);
	}
	while (i > 0)
	{
		line = ft_strjoin(line, characters);
		if (ft_clean(characters) > 0)
			break ;
		i = read(fd, characters, BUFFER_SIZE);
	}
	return (line);
}
