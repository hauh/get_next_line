#include "get_next_line.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    char *line;
    int i;
	int j;
    int fd1;
	int fd2;

    i = 1;
	j = 1;
    if (argc > 1)
    {
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
        while (i + j > 0)
        {
            printf("gnl1:%d\n", i = get_next_line(fd1, &line));
            if (i > 0)
                printf("file1:<%s>\n", line);
			printf("gnl2:%d\n", j = get_next_line(fd2, &line));
            if (j > 0)
                printf("file2:<%s>\n", line);
        }
    }
    return (0);
}
