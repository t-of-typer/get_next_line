#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_realloc(void *ptr, size_t size);

#endif
