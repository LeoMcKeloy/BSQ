#include "bsq.h"

t_map	*ft_create_map(char *fname)
{
	t_map	*new_map;
	char	*symb;

	new_map = (t_map*)malloc(sizeof(new_map));
	if (new_map)
	{
		new_map->width = get_map_width(fname);
		symb = get_symbols(fname);
		new_map->empty = get_symbols(fname)[0];
		new_map->obstacle = get_symbols(fname)[1];
		new_map->full = get_symbols(fname)[2];
		new_map->height = get_map_height(fname);
		new_map->map = get_map(fname);
		new_map->max_pos = 0;
		new_map->max_size = 0;
	}
	return (new_map);
}

int		get_map_height(char *fname)
{
	int		height;
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
	i = 0;
	height = 0;
	while (i < ft_strlen(buf) - 3)
	{
		height += (buf[i] - '0');
		height *= 10;
		i++;
	}
	height /= 10;
	if (close(fd) == -1)
		return (0);
	return (height);
}

int		get_map_width(char *fname)
{
	char	c;
	int		width;
	int		fd;
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &c, 1) && c != '\n')
		i++;
	width = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		width++;
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (width);
}

char	*get_map(char *fname)
{
	char	*res;
	char	c;
	int		fd;
	int		i;

	i = 0;
	res = (char*)malloc((get_map_width(fname) + 1) * get_map_height(fname));
	if (!res)
		return (res);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) && c != '\n')
		i++;
	i = 0;
	while (read(fd, &c, 1))
	{
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (res);
}

char	*get_symbols(char *fname)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		i;
	char	*symb;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &buf[i], 1) && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	i = 0;
	if (close(fd) == -1)
		return (0);
	symb = (char*)malloc(4);
	ft_strcpy(symb, &buf[ft_strlen(buf) - 3]);
	return (symb);
}
