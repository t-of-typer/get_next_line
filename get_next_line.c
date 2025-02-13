#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    static size_t buffer_pos = 0;
    static ssize_t bytes_read = 0;
    char *line = NULL;
    size_t line_len = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (1)
    {
        if (buffer_pos >= (size_t)bytes_read)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (line_len > 0)
                    return (line);
                return (NULL);
            }
            buffer_pos = 0;
        }

        char current_char = buffer[buffer_pos++];
        line = ft_realloc(line, line_len + 1);
        if (!line)
            return (NULL);
        line[line_len++] = current_char;

        if (current_char == '\n')
            break;
    }

    line = ft_realloc(line, line_len + 1);
    if (!line)
        return (NULL);
    line[line_len] = '\0';

    return (line);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *result;
    size_t i;

    if (!s)
        return (NULL);

    if (start >= ft_strlen(s))
        return (ft_strdup(""));

    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);

    result = malloc(len + 1);
    if (!result)
        return (NULL);

    i = 0;
    while (i < len)
    {
        result[i] = s[start + i];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void *ft_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (!ptr)
        return (malloc(size));

    if (!size)
    {
        free(ptr);
        return (NULL);
    }

    new_ptr = malloc(size);
    if (!new_ptr)
        return (NULL);

    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}
