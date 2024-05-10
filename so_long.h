/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/10 12:13:03 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<mlx.h>

#ifndef SIZE_l
#define SIZE_l 100
#endif

#ifndef SIZE_w
#define SIZE_w 75
#endif

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char **allocate_map;
    char **map;
    char **map_1;
    char **map_copy;
    char **map_copy_1;
    int x;
    int y;
    int *t;
    int rows;
    int cols;
    int fd;
    int compt_C;
   int compt_E;
   int compt_P;
   int player_x;
   int player_y;
   int player_moves;
   int n_l;
}t_game;

int get_numline_map(t_game vars, char *name);
void check_file_name(char *name);
void check_map_shape(t_game var, char *name);
void check_map_content(t_game *var, char *name);
void check_map_wall(t_game var, char *name);
void checker(t_game var, char *name);
char **map_to_2d(char *name, t_game vars);
void check_start_game(t_game vars, char *name);
void check_file_name(char *name);
void flood_fill_copy(t_game vars, int y, int x);
void check_for_E_copy(t_game vars);
int *get_Exit_position(char **map_copy);
char **get_game_copy(t_game var);
void flood_fill(t_game vars, int y, int x);
void check_for_c(t_game vars);
int *get_player_position(char **map);
void check_for_fill(char **map, t_game vars);
void check_for_fill_copy(char **map_copy, t_game vars);
void wall_map(t_game var);
void to_x_plus_1(t_game *vars);
void to_x_minus_1(t_game *vars);
void to_y_plus_1(t_game *vars);
void to_y_minus_1(t_game *vars);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int kill_redcross(int keycode, t_game * var);

#endif
