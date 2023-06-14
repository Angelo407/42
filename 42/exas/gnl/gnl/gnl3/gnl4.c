#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd)
{
    char *s = malloc(10000), *c = s;
    while (read(fd, c, 1) > 0 && *c++ != '\n');
    return c > s ? (*c = 0, s) : (free(s), NULL);
}

int main()
{
	int fd;

	fd = open("inter-subject.txt", O_RDONLY);
	printf("buf=%s", get_next_line(fd));
	printf("buf=%s", get_next_line(fd));
	printf("buf=%s", get_next_line(fd));
	printf("buf=%s", get_next_line(fd));


    return 0;
}