#include "bsq.h"

void	print_result(char *fname, t_map *map)
{
	if (!valid_head(fname))
		write(2, "map error\n", 10);
	else
	{
		map = ft_create_map(fname);
		if (!check_valid(map))
		{
			write(2, "map error\n", 10);
		}
		else
		{
			find_square(map);
			add_square(map);
			ft_putstr(map->map);
			free(map->map);
			free(map);
		}
	}
}

void	standart_input(void)
{
	char	c;
	int		fd;
	t_map	*map;

	map = NULL;
	fd = open("our_standin", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	while (read(0, &c, 1))
		write(fd, &c, 1);
	if (!valid_head("our_standin"))
		write(2, "map error\n", 10);
	else
	{
		map = ft_create_map("our_standin");
		if (!check_valid(map))
			write(2, "map error\n", 10);
		else
		{
			find_square(map);
			add_square(map);
			ft_putstr(map->map);
			free(map->map);
			free(map);
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	map = NULL;
	if (argc >= 2)
		while (i < argc)
		{
			print_result(argv[i], map);
			i++;
		}
	else if (argc == 1)
		standart_input();
	return (0);
}
