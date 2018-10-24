#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../draw/draw.h"
#include "../wireframe/wireframe.h"
#include <stdio.h>

int		main(void)
{
	char *file_path = "test_maps/42.fdf";

	int x, y;
	int **surface;

	int fd = open((char *)file_path, O_RDONLY);
	if (fd < 2)
	{
		printf("can't open the map file");
		return (-1);
	}
	ft_count_x_y(fd, &x, &y);
	close(fd);

	fd = open((char *)file_path, O_RDONLY);
	ft_create_wireframe(fd, x, y, surface);
	close(fd);

	printf("spaces count : %d\n", x);
	printf("lignes count : %d\n", y);
	return (0);
}
