#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char    *ft_strdup(char *s)
{
    int        i;
    char    *str;

    i = 0;
    while (s[i])
        i++;
    str = (char *) malloc(i + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strjoin(char *s, char c)
{
    char    *str;
    int        i;

    i = 0;
    while (s[i])
        i++;
    str = (char *) malloc(i + 2);
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = c;
    str[i + 1] = '\0';
    free(s);
    return (str);
}

// The given fd (File descriptor) indicates where
// read(3) function should read the line.

char    *get_next_line(int fd)
{
    char    buf;
    char    *line;
    int        ret;
    int        i;

    if (fd < 0)
        return (NULL);
    // Either methods works using strdup function would be more safe tho
    line = ft_strdup("");
    //line = malloc(10000);

    // read would read 1 character from the given fd and put it into buf
    // if so and everything goes OK it returns a value bigger than 0
    // in case of error it returns -1 I BELIEVE, RTFM anyway
    while ((ret = read(fd, &buf, 1)) > 0)
    {
        // Join buf (The character we just read) into line
        line = ft_strjoin(line, buf);
        if (buf == '\n')
            break ;
    }
    i = 0;
    while (line[i])
        i++;
    if (i == 0 || ret == -1)
    {
        free(line);
        line = NULL;
    }
    return (line);
}

int main(void)
{
    char *buffer;
    // While users tape on terminal read character by character
    // Ctrl+d to stop
    // Get_next_line will read from fd 0 which stands to
    // standard input aka terminal, into buffer.
    buffer = get_next_line(0);
    while (buffer)
    {
        printf("\nYour line: %s\n", buffer);
        // Don't forget to free what you read with gnl
        // after finished using it.
        free(buffer);
        // Read the next line
        buffer = get_next_line(0);
    }
}


