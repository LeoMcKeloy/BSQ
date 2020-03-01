#ifndef BSQ_H
# define BSQ_H
# define BUF_SIZE 14
# include "ft_map.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
void	square_corn(t_map *p_map, const int row,
const int pos, const int size);
void	find_square_gap(t_map *p_map, int pos, int gap_size, int row);
void	find_gap_row(t_map *p_map, const int row);
void	find_square(t_map *p_map);
void	add_square(t_map *p_map);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		map_valid_box(t_map *p_map);
int		valid_count_rows(t_map *p_map);
int		check_valid(t_map *p_map);
int		valid_head(char *fname);
t_map	*ft_create_map_standart(char *map);

#endif
