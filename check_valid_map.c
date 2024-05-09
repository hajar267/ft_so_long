/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:52:03 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/09 10:34:41 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_start_game(t_game vars, char *name)
{
    char *str;
    vars.fd = open(name, O_RDONLY);
    str = get_next_line(vars.fd);
    if (str[0] != '1')
    {
        perror("error invalid map!!!");
        exit(0);
    }
    close(vars.fd);
}

void check_map_wall(t_game var, char *name)
{
    int i =0;
    int len = ft_strlen(var.map[0]);
    int j = get_numline_map(var, name) - 1;
    while(var.map[0][i] && var.map[j][i])
    {
        if(var.map[0][i] != '1' || var.map[j][i] != '1')
        { 
            perror("error!!!");
            exit(0);
        }
        i++;
    }
    i =0;
    while(j > 0)
    {
        if (var.map[j][0] != '1' || var.map[j][len - 1] != '1')
        {
            perror("error!!!");
            exit(0);
        }
        j--;
    }
}

void check_map_shape(t_game var, char *name)
{
    int j = get_numline_map(var, name);
    int i= ft_strlen(var.map[0]);
    if (j == i)
    {
        perror("error invalid map_rectangle");
        exit(0);
    }
    while(j > 0)
    {
        if (i != ft_strlen(var.map[j -1]))
        {
            printf("%d--%zu\n", i, ft_strlen(var.map[j -1]));
            perror("error invalid map");
            exit(0);
        }
        j--;
    }
}

void check_map_content(t_game *var, char *name)
{
    int x;
    int y;
    int len;

    x = 1;
    while(var->rows - 1 > 0)
    {
        y = 1;
        len = var->cols - 1;
        while(len - 1 > 0)
        {
            if (var->map[x][y] == 'E')
                var->compt_E++;
            else if (var->map[x][y] == 'c')
                var->compt_C++;
            else if (var->map[x][y] == 'P')
                var->compt_P++;
            else if (var->map[x][y] != '0' && var->map[x][y] != '1')
            {
                perror("error somthing stranger hmmm!!! ");
                exit(0);
            }
            y++;
            len--;
        }
        x++;
        var->rows--;
    }
        if (var->compt_E != 1 || var->compt_P != 1 || var->compt_C < 1)
        {
            perror("error more than E || P or less than one C !!!");
            exit(0);
        }
}
