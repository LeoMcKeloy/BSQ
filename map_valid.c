#include "bsq.h"

int		map_valid_box(t_map *p_map)
{
	int count_col;
	int i;

	i = 0;
	while (p_map->map[i] != '\n' && p_map->map != '\0')
		i++;
	if (p_map->map[i] == '\0')
		return (0);
	count_col = i;
	i = 0;
	while (p_map->map[i] != '\0')
	{
		if ((i + 1) % (count_col + 1) == 0 && p_map->map[i] != '\n')
			return (0);
		else if ((i + 1) % (count_col + 1) != 0 && p_map->map[i] == '\n')
			return (0);
		i++;
	}
	if (p_map->map[i - 1] != '\n')
		return (0);
	return (1);
}

int		valid_count_rows(t_map *p_map)
{
	int i;
	int count_rows;

	i = 0;
	count_rows = 0;
	while (p_map->map[i] != '\0')
	{
		if (p_map->map[i] == '\n')
			count_rows++;
		i++;
	}
	return (p_map->height == count_rows);
}

int		valid_symbols(t_map *p_map)
{
	int i;

	i = 0;
	if (p_map->map[0] == '\n')
		return (0);
	while (p_map->map[i] != '\0')
	{
		if (p_map->map[i] != p_map->obstacle && p_map->map[i]
				!= p_map->empty && p_map->map[i] != '\n')
			return (0);
		if (p_map->map[i - 1] == '\n' && p_map->map[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int		check_valid(t_map *p_map)
{
	if (!map_valid_box(p_map))
		return (0);
	if (!valid_count_rows(p_map))
		return (0);
	if (!valid_symbols(p_map))
		return (0);
	return (1);
}

int		valid_head(char *fname)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &buf[i], 1) && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	if (ft_strlen(buf) < 4)
		return (0);
	i = 0;
	while (i < ft_strlen(buf) - 3)
	{
		if (!(buf[i] >= '0' && buf[i] <= '9'))
			return (0);
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}
