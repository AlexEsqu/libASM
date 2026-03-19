#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// MANDATORY

size_t	ft_strlen(const char* str);
char*	ft_strcpy(char *restrict dst, const char *restrict src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char*	ft_strdup(const char *s);

// BONUS

int		ft_atoi_base(char *str, char *base);


// C functions equivalent (for testing/comparison)
size_t	ft_strlen_in_C(const char *str);
char*	ft_strcpy_in_C(char *restrict dst, const char *restrict src);
int		ft_strcmp_in_C(const char *s1, const char *s2);
char*	ft_strdup_in_C(const char *s);
ssize_t	ft_write_in_C(int fd, void *buf, size_t nbyte);
ssize_t	ft_read_in_C(int fd, void *buf, size_t nbyte);

int ft_atoi_base_in_C(char *str, char *base);

#endif
