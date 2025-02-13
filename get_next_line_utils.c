#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);

    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);

    ft_memcpy(result, s1, len1);
    ft_memcpy(result + len1, s2, len2 + 1);
    return (result);
}

char *ft_strdup(const char *s)
{
    char *result;
    size_t len = ft_strlen(s);

    result = malloc(len + 1);
    if (!result)
        return (NULL);

    ft_memcpy(result, s, len + 1);
    return (result);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n--)
        *d++ = *s++;
    return (dest);
}
