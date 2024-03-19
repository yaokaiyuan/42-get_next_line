#include "get_next_line.h"
#include <stdio.h>

int main()
{
    static char str[20];
    for(int  i = 0; i < 20 ;i++)
        printf("%d ", str[i]);
    printf("\n");
    str = malloc(2);
    str[0] = 'h';
    str[1] = '\0';
    printf("%s\n",str);

    // int fd = open("get_next_line.c", O_RDONLY);
    // if (fd == -1)
    // {
    //     perror("Error opening file");
    //     return 1;
    // }
    
    // str = get_next_line(fd);
    // if (str == NULL)
    // {
    //     printf("Reached end of file or encountered an error\n");
    //     return 1;
    // }

    // printf("%s", str);
    // free(str);
    // close(fd);
    return 0;
}



