#include "bsq.h"

void	find_square(t_map *p_map)
{
	int i;

	i = 0;
	while (i < p_map->height)
	{
		find_gap_row(p_map, i);
		i++;
	}
}

void	add_square(t_map *p_map)
{
	int i;
	int k;
	int j;

	i = 0;
	while (i < p_map->max_size)
	{
		k = 0;
		j = 0;
		while (j < p_map->max_size)
		{
			p_map->map[p_map->max_pos + i * (
					p_map->width + 1) + k + j] = p_map->full;
			j++;
			if (j == p_map->max_size)
				k = p_map->width - p_map->max_size + 1 + j;
		}
		i++;
	}
}
