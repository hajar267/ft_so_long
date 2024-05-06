/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:38:52 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/06 11:33:47 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **get_game_copy(t_game var)
{
    char **map_copy;
    int i;
    int j;
    j = 0;
    map_copy = malloc(sizeof(char *) * (var.rows + 1));
    while(var.map[j])
    {
        map_copy[j] = malloc(var.cols + 1);
        i = 0;
        while(var.map[j][i])
        {
            map_copy[j][i] = var.map[j][i];
            i++;
        }
        map_copy[j][i] = '\0';
        j++;
    }
    map_copy[j] = NULL;
    return(map_copy);
}

int *get_Exit_position(char **map_copy)
{
    int *t_copy;
    int i;
    int j;
    j = 0;
    t_copy = malloc(sizeof(int) * 2);
    while(map_copy[j])
    {
        i = 0;
        while(map_copy[j][i])
        {
            if (map_copy[j][i] == 'E')
            {
                t_copy[0] = j;
                t_copy[1] = i;
            }
            i++;
        }
        j++;
    }
    return(t_copy);
}

void flood_fill_copy(char **map_copy, int y, int x, int rows, int cols)
{
    if (y < 0 || y >= rows || x < 0 || x >= cols)
        return ;
    if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
        return;
    map_copy[y][x] = 'F';
    flood_fill_copy(map_copy, y - 1, x, rows, cols);
    flood_fill_copy(map_copy, y + 1, x, rows, cols);
    flood_fill_copy(map_copy, y, x + 1, rows, cols);
    flood_fill_copy(map_copy, y, x - 1, rows, cols);
}

void check_for_E_copy(char **map_copy)
{
    int j;
    int i;
    j = 0;
    while(map_copy[j])
    {
        i = 0;
        while(map_copy[j][i])
        {
            if (map_copy[j][i] == 'c' || map_copy[j][i] == 'P')
            {
                perror("error rest c || p!!!");
                exit(0);
            }
            i++;
        }
        j++;
    }
}
