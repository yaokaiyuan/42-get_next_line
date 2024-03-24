#include "get_next_line.h"
#include <stdio.h>

int main()
{
    static char *str;
	int fd = open("ts.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    
    str = get_next_line(fd);
    if (str == NULL)
    {
    	printf("Reached end of file or encountered an error\n");
        return 1;
    }

    printf("%s", str);
	free(str);
    close(fd);
    return 0;
}



