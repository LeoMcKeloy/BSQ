#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct	s_map
{
	char		*map;
	char		empty;
	char		obstacle;
	char		full;
	int			width;
	int			height;
	int			max_size;
	int			max_pos;
}				t_map;

t_map			*ft_create_map(char *fname);
int				get_map_height(char *fname);
int				get_map_width(char *fname);
char			*get_map(char *fname);
char			*get_symbols(char *fname);

#endif
