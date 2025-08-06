#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	    *ft_strchr(const char *s, int c);
char        *get_next_line(int fd);
static int  read_from_fd(int fd, char *general_buffer);


#endif