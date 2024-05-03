/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/03 18:17:34 by hfiqar           ###   ########.fr       */
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

typedef struct s_var
{
    int fd;
    int compt_E;
    int compt_C;
    int compt_P;
    int x_player;
    int y_player;
    int widht;
    int lenght;
    char **map;
    char **map_copy;
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
}t_var;

int get_numline_map(char *name);
void check_file_name(char *name);
void check_map_shape(char **map, char *name);
void check_map_content(char **map, char *name);
void check_map_wall(char **map, char *name);
void checker(char **map, char *name);
char **map_to_2d(char *name);
void check_start_map(char *name);
void check_file_name(char *name);
void flood_fill_copy(char **map_copy, int y, int x, int rows, int cols);
void check_for_E_copy(char **map_copy);
int *get_Exit_position(char **map_copy);
char **get_map_copy(char **map, int rows, int cols);
void flood_fill(char **map, int y, int x, int rows, int cols);
void check_for_c(char **map);
int *get_player_position(char **map);
void check_for_fill(char **map, int rows, int cols);
void check_for_fill_copy(char **map_copy, int rows, int cols);
void wall_map(char **map, void *mlx_ptr, void *img_ptr, void *win_ptr, int cols, int rows);

#endif
