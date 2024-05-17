/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/17 21:01:35 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE_L
#  define SIZE_L 100
# endif

# ifndef SIZE_W
#  define SIZE_W 75
# endif

# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**allocate_map;
	char	**map;
	char	**map_1;
	char	**map_copy;
	char	**map_copy_1;
	int		x;
	int		y;
	int		*t;
	int		rows;
	int		cols;
	int		fd;
	int		compt_c;
	int		compt_e;
	int		compt_p;
	int		player_x;
	int		player_y;
	int		player_moves;
	int		n_l;
	int		inc;
	int		i;
	int		j;
	int		c;
}	t_game;

int		get_numline_map(t_game vars, char *name);
void	check_file_name(char *name);
void	check_map_shape(t_game var, char *name);
void	check_map_content(t_game *var);
void	check_map_wall(t_game var, char *name);
void	checker(t_game var, char *name);
char	**map_to_2d(char *name, t_game vars);
void	check_start_game(t_game vars, char *name);
void	check_file_name(char *name);
void	flood_fill_copy(t_game vars, int y, int x);
void	check_for_e_copy(t_game vars);
int		*get_exit_position(char **map_copy);
char	**get_game_copy(t_game var);
void	flood_fill(t_game vars, int y, int x);
void	check_for_c(t_game vars);
int		*get_player_position(char **map);
void	check_for_fill(char **map, t_game vars);
void	check_for_fill_copy(char **map_copy, t_game vars);
void	wall_map(t_game var);
void	to_x_plus_1(t_game *vars);
void	to_x_minus_1(t_game *vars);
void	to_y_plus_1(t_game *vars);
void	to_y_minus_1(t_game *vars);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		destroynotify(int keycode, t_game *var);
void	freed(char **map);
void	state_map_wall_1(t_game *var, int l, int w);
void	state_map_wall(t_game *var, int l, int w);
void	fill_line(t_game vars, char *str, int y);
void	fill_map(t_game *adr_var);
void	ft_exit(void);
int		ft_check_c_exit(t_game *var);
void	ft_compt_c(t_game *var);
void	assist_x_plus(t_game *vars);
void	assist_x_minus(t_game *vars);
void	assist_y_minus(t_game *vars);
void	assist_y_plus(t_game *vars);

#endif
