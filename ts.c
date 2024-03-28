#include "get_next_line.h"
#include <stdio.h>

int main()
{
    static char *str;
	int fd = open("ts.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    
    str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
    str = get_next_line(fd);
	printf("%s", str);
	if (str)
		free(str);
	str = get_next_line(fd);
    printf("%s\n", str);
	if (str)
		free(str);
    close(fd);
    return 0;
}



