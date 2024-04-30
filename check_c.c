/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:49:58 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/30 15:49:01 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int *get_player_position(char **map)
{
    int *t;
    t = malloc(sizeof(int) * 2);
    int i;
    int j;
    j = 0;
    while(map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if (map[j][i] == 'P')
            {
                t[0] = j;
                t[1] = i;
            }
            i++;
        }
        j++;
    }
    return(t);
}

void flood_fill(char **map, int y, int x, int rows, int cols)
{
    if (y < 0 || y >= rows || x < 0 || x >= cols)
        return ;
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    if (map[y][x] == 'E')
    {
        map[y][x] = '1';
        return ;
    }
    map[y][x] = 'F';
    flood_fill(map, y + 1, x, rows, cols);
    flood_fill(map, y - 1, x, rows, cols);
    flood_fill(map, y, x + 1, rows, cols);
    flood_fill(map, y, x - 1, rows, cols);
}

void check_for_c(char **map)
{
    int j;
    int i;
    j = 0;
    while(map[j])
    {
        i = 0;
        while(map[j][i])
        {
            if (map[j][i] == 'c')
            {
                perror("error rest c !!!");
                exit(0);
            }
            i++;
        }
        j++;
    }
}
