#include "bsq.h"

void	square_corner_2(t_map *p_map, const int pos, const int size, int s)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < s)
	{
		k = 0;
		j = 0;
		while (j < s)
		{
			if (p_map->map[pos + i * (p_map->width + 1) + k + j]
					== p_map->obstacle)
				return ;
			j++;
			if (j == s)
				k = p_map->width - size + 1 + j;
		}
		i++;
	}
	if (p_map->max_size < s)
	{
		p_map->max_size = s;
		p_map->max_pos = pos;
	}
}

void	square_corner(t_map *p_map, const int row,
const int pos, const int size)
{
	int s;

	s = 1;
	while (s <= size && (row + s) <= p_map->height)
	{
		square_corner_2(p_map, pos, size, s);
		s++;
	}
}

void	find_gap_row_2(t_map *p_map, const int row, int *it, int *gap_size)
{
	*gap_size = 0;
	*it = (p_map->width + 1) * row;
	if (*it == 0 && p_map->map[0] == p_map->empty)
	{
		while (p_map->map[*it] == p_map->empty)
		{
			(*gap_size)++;
			(*it)++;
		}
		find_square_gap(p_map, *it - *gap_size, *gap_size, row);
	}
	else if (*it == 0 && p_map->map[0] != p_map->empty)
		(*it)++;
}

void	find_gap_row(t_map *p_map, const int row)
{
	int it;
	int gap_size;

	find_gap_row_2(p_map, row, &it, &gap_size);
	while (p_map->map[it] != '\n')
	{
		if (p_map->map[it - 1] != p_map->empty &&
				p_map->map[it] == p_map->empty)
		{
			gap_size = 0;
			while (p_map->map[it] == p_map->empty)
			{
				gap_size++;
				it++;
			}
			find_square_gap(p_map, it - gap_size, gap_size, row);
		}
		else
			it++;
	}
}

void	find_square_gap(t_map *p_map, int pos, int gap_size, int row)
{
	int i;

	i = pos;
	while (i < i + gap_size)
	{
		if (gap_size <= p_map->max_size)
			return ;
		square_corner(p_map, row, i, gap_size);
		i++;
		gap_size--;
	}
}
