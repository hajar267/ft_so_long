/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:38:52 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/28 12:40:36 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map_copy(t_var *vars)
{
    int i;
    int j;
    j = 0;
    while(vars->map[j])
    {
        i = 0;
        while(vars->map[j][i])
        {
            vars->map_copy[j][i] = vars->map[j][i];
            i++;
        }
        vars->map_copy[j][i] = '\0';
        j++;
    }
    vars->map_copy[j] = NULL;
}

void get_Exit_position(t_var  *vars)
{
    int i;
    int j;
    j = 0;
    while(vars->map[j])
    {
        i = 0;
        while(vars->map[j][i])
        {
            if (vars->map[j][i] == 'E')
            {
                vars->y_player = j;
                vars->x_player = i;
            }
            i++;
        }
        j++;
    }
}

void flood_fill_copy(t_var   *vars, int y, int x)
{
    if (vars->map_copy[y][x] == '1')
        return;
    vars->map_copy[y][x] = 'F';
    flood_fill_copy(vars, y - 1, x);
    flood_fill_copy(vars, y + 1, x);
    flood_fill_copy(vars, y, x + 1);
    flood_fill_copy(vars, y, x - 1);
}

void check_for_c_copy(t_var    *vars)
{
    int j;
    int i;
    j = 0;
    while(vars->map_copy[j])
    {
        i = 0;
        while(vars->map_copy[j][i])
        {
            if (vars->map_copy[j][i] == 'C')
            {
                perror("error rest c !!!");
                exit(0);
            }
            i++;
        }
        j++;
    }
}


