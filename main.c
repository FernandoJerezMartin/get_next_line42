#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

int	main(void)
{
	int fd = open("yo_mama.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}