/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:52:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/30 13:11:59 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_start_map(char *name)
{
    char *str;
    int fd;
    fd = open(name, O_RDONLY);
    str = get_next_line(fd);
    if (str[0] != '1')
    {
        printf("%c\n",str[0]);
        perror("error invalid map!!!");
        exit(0);
    }
    close(fd);
}

void check_map_wall(char **map, char *name)
{
    int i =0;
    int len = ft_strlen(map[0]);
    int j = get_numline_map(name) - 1;
    while(map[0][i] && map[j][i])
    {
        if(map[0][i] != '1' || map[j][i] != '1')
        { 
            perror("error!!!");
            exit(0);
        }
        i++;
    }
    i =0;
    while(j > 0)
    {
        if (map[j][0] != '1' || map[j][len - 1] != '1')
        {
            perror("error!!!");
            exit(0);
        }
        j--;
    }
}

void check_map_shape(char **map, char *name)
{
    int j = get_numline_map(name);
    int i= ft_strlen(map[0]);
    if (j == i)
    {
        perror("error invalid map_rectangle");
        exit(0);
    }
    while(j > 0)
    {
        if (i != ft_strlen(map[j -1]))
        {
            perror("error invalid map");
            exit(0);
        }
        j--;
    }
}

void check_map_content(char **map, char *name)
{
   int compt_C = 0;
   int compt_E = 0;
   int compt_P = 0;
    int x = 1;
    int y;
    int j = get_numline_map(name) - 1;
    int len;
    while(j - 1 > 0)
    {
        y = 1;
        len = ft_strlen(map[0]) - 1;
        while(len - 1 > 0)
        {
            if (map[x][y] == 'E')
                compt_E++;
            else if (map[x][y] == 'c')
                compt_C++;
            else if (map[x][y] == 'P')
                compt_P++;
            else if (map[x][y] != '0' && map[x][y] != '1')
            {
                perror("error somthing stranger hmmm!!! ");
                exit(0);
            }
            y++;
            len--;
        }
        x++;
        j--;
    }
        if (compt_E != 1 || compt_P != 1 || compt_C < 1)
        {
            perror("error more than E || P or less than one C !!!");
            exit(0);
        }
}
