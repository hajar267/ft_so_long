/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/06 12:28:22 by hfiqar           ###   ########.fr       */
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

char **map_to_2d(char *name, t_game vars)
{
    int j;
    int x;
    int y;
    char *str;
    
    y = 0;
    j = get_numline_map(vars, name);
    vars.fd = open(name, O_RDONLY);
    vars.allocate_map = malloc(sizeof(char *) * (j + 1));
    while(j > y)
    {
        str = get_next_line(vars.fd);
        if (!str)
        {
            break;
        }
        vars.allocate_map[y] = malloc(ft_strlen(str) + 1);
        x = 0;
        while(str[x] != '\n' && str[x])
        {
            vars.allocate_map[y][x] = str[x];
            x++;
        }
        vars.allocate_map[y][x] = '\0';
        free(str);
        y++;
    }
    vars.allocate_map[j] = NULL;
    close(vars.fd);
    return(vars.allocate_map);
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
    vars.t = get_player_position(vars);
    flood_fill(vars,vars.t[0],vars.t[1]);
    check_for_c(vars);
}

void check_for_fill_copy(char **map_copy, int rows, int cols)
{
    int *t_copy;
    
    t_copy = get_Exit_position(map_copy);
    flood_fill_copy(map_copy, t_copy[0], t_copy[1], rows, cols);
    check_for_E_copy(map_copy);
}

int key_hook(int keycode, void *param) {
    // (void)data;
    printf("hello world %d", keycode);
    return 0;
}

int main(int ac, char **av)
{
    t_game var;
    if (ac != 2)
    {
        perror("error!!!");
        exit(0);
    }
    check_file_name(av[1]);
    var.map = map_to_2d(av[1], var);
    var.rows = get_numline_map(var, av[1]);
    var.cols = ft_strlen(var.map[0]);
    checker(var, av[1]);
    var.map_copy = get_game_copy(var);
    var.map_copy_1 = get_game_copy(var);
    check_for_fill(var.map, var);
    check_for_fill(var.map_copy, var);
    var.mlx_ptr = mlx_init();
    if(!var.mlx_ptr)
        return(0);
    var.win_ptr = mlx_new_window(var.mlx_ptr, SIZE_l * var.cols, SIZE_w * var.rows, "My Window");
    wall_map(var);
    mlx_loop(var.mlx_ptr);
    
}
