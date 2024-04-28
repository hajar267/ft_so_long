/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/28 12:59:45 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<mlx.h>

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

int get_numline_map(t_var   *vars, int fd);
void check_file_name(char *name);
void check_map_shape(t_var  *vars, int fd);
void check_map_content(t_var    *vars, int fd);
void check_map_wall(t_var   *vars, int fd);
void checker(t_var  *vars, int fd);
void map_to_2d(t_var    *vars, int fd);
void check_start_map(t_var  *vars, int fd);
void check_file_name(char *name);
void flood_fill_copy(t_var   *vars, int y, int x);
void check_for_c_copy(t_var    *vars);
void get_Exit_position(t_var  *vars);
void get_map_copy(t_var *vars);
void flood_fill(t_var   *vars, int y, int x);
void check_for_c(t_var    *vars);
void get_player_position(t_var  *vars);

#endif
