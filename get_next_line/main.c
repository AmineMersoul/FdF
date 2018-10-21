#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int fd1;
	char *line;
	char *file_name1 = "file.txt";

	fd1 = open(file_name1, O_RDONLY);
	if (fd1 == -1)
	{
		printf("cant read %s\n", file_name1);
		return (-1);
	}
	while(get_next_line(fd1, &line))
        printf("line : |%s|\n", line);
	close(fd1);
	return (0);
}
