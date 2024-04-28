/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:49:58 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/28 12:51:19 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_player_position(t_var  *vars)
{
    int i;
    int j;
    j = 0;
    while(vars->map[j])
    {
        i = 0;
        while(vars->map[j][i])
        {
            if (vars->map[j][i] == 'P')
            {
                vars->y_player = j;
                vars->x_player = i;
            }
            i++;
        }
        j++;
    }
}

void flood_fill(t_var   *vars, int y, int x)
{
    if (vars->map[y][x] == 'E')
        vars->map[y][x] = '1';
    if (vars->map[y][x] == '1')
        return;
    vars->map[y][x] = 'F';
    flood_fill(vars, y - 1, x);
    flood_fill(vars, y + 1, x);
    flood_fill(vars, y, x + 1);
    flood_fill(vars, y, x - 1);
}

void check_for_c(t_var    *vars)
{
    int j;
    int i;
    j = 0;
    while(vars->map[j])
    {
        i = 0;
        while(vars->map[j][i])
        {
            if (vars->map[j][i] == 'C')
            {
                perror("error rest c !!!");
                exit(0);
            }
            i++;
        }
        j++;
    }
}
