/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:52:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/28 12:56:11 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_start_map(t_var  *vars, int fd)
{
    char *str;
    str = get_next_line(fd);
    if (str[0] != 1)
    {
        perror("error invalid map!!!");
        exit(0);
    }
}

void check_map_wall(t_var   *vars, int fd)  //struct as a parametre
{
    int i =0;
    int len = ft_strlen(vars->map[0]);
    int j = get_numline_map(vars, fd);
    while(vars->map[0][i] && vars->map[j-1][i])
    {
        if(vars->map[0][i] != '1' || vars->map[j-1][i] != '1')
        { 
            perror("error!!!");
            exit(0);
        }
        i++;
    }
    i =0;
    while(j > 0)
    {
        if (vars->map[j][0] != '1' || vars->map[j][len - 1] != '1')
        {
            perror("error!!!");
            exit(0);
        }
        j--;
    }
}

void check_map_shape(t_var  *vars, int fd)
{
    int j = get_numline_map(vars, fd);
    int i= ft_strlen(vars->map[0]);
    if (j == i)
    {
        perror("error invalid map");
        exit(0);
    }
    while(j > 0)
    {
        if (i != ft_strlen(vars->map[j -1]))
        {
            perror("error invalid map");
            exit(0);
        }
        j--;
    }
}

void check_map_content(t_var    *vars, int fd)
{
   vars->compt_C = 0;
   vars->compt_E = 0;
   vars->compt_P = 0;
    int x = 1;
    int y;
    int j = get_numline_map(vars, fd) - 1;
    int len = ft_strlen(vars->map[0]) - 1;
    while(j - 1 > 0)
    {
        y = 1;
        while(len - 1 > 0)
        {
            if (vars->map[x][y] == 'E')
                vars->compt_E++;
            else if (vars->map[x][y] == 'C')
                vars->compt_C++;
            else if (vars->map[x][y] == 'P')
                vars->compt_P++;
            else if (vars->map[x][y] != '0' && vars->map[x][y] != '1')
            {
                perror("error somthing stranger hmmm!!! ");
                exit(0);
            }
            y++;
            len--;
        }
        if (vars->compt_E != 1 || vars->compt_P != 1 || vars->compt_C < 1)
        {
            perror("error more than E || P or less than one C !!!");
            exit(0);
        }
        x++;
        j--;
    }
}