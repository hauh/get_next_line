#include "get_next_line/get_next_line.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    char *line;
    int i;
    int fd1;

    i = 1;
    if (argc > 1)
    {
		fd1 = open(argv[1], O_RDONLY);
        while (i > 0)
        {
            i = get_next_line(fd1, &line);
            if (i > 0)
                printf("%s\n", line);
        }
    }
    return (0);
}
