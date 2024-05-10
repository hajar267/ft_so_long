/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:37 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/10 11:57:32 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_numline_map(t_game vars, char *name)
{
    int j=0;
    char *str;
    vars.fd = open(name, O_RDONLY);
    while((str = get_next_line(vars.fd)))
    {
        j++;
        free(str);
    }
    close(vars.fd);
    free(str);
    return(j);
}

void checker(t_game var, char *name)
{
    check_start_game(var, name);
    check_map_shape(var, name);
    check_map_content(&var, name);
    check_map_wall(var, name);
}

void check_file_name(char *name)
{
    int i = 0;
    while(name[i])
    {
        if (name[i] == '.' && name[i + 1] == 'b' 
        && name[i + 2] == 'e' && name[i + 3] == 'r')
            return ;
        i++;
    }
    perror("correct file's name haaa!!!");
    exit(0);
}

void check_for_fill(char **map, t_game vars)
{
    int *t;
    t = get_player_position(map);
    flood_fill(vars,t[0],t[1]);
    check_for_c(vars);
}

void check_for_fill_copy(char **map_copy, t_game vars)
{
    int *t_copy;
    
    t_copy = get_Exit_position(map_copy);
    flood_fill_copy(vars, t_copy[0], t_copy[1]);
    check_for_E_copy(vars);
}