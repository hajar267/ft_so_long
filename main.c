/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/10 21:42:41 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_line( t_game vars, char *str, int y)
{
    int x;

    x = 0;
     while (str[x] != '\n' && str[x])
    {
        vars.allocate_map[y][x] = str[x];
        x++;
    }
    return (x);
}

char **map_to_2d(char *name, t_game vars)
{
    int x;
    int y;
    char *str;

    y = 0;
    vars.n_l = get_numline_map(vars, name);
    vars.fd = open(name, O_RDONLY);
    vars.allocate_map = malloc(sizeof(char *) * (vars.n_l + 1));
    while (vars.n_l > y)
    {
        str = get_next_line(vars.fd);
        if (!str)
        {
            free(str);
            break;
        }
        vars.allocate_map[y] = malloc(ft_strlen(str) + 1);
        x = fill_line(vars, str, y);
        vars.allocate_map[y][x] = '\0';
        free(str);
        y++;
    }
    vars.allocate_map[vars.n_l] = NULL;
    close(vars.fd);
    return (vars.allocate_map);
}

int	key_hook(int keycode, t_game *vars)
{
    if (keycode == 124 || keycode == 2)
        to_x_plus_1(vars);
    else if (keycode == 123 || keycode == 0)
        to_x_minus_1(vars);
    else if (keycode == 125 || keycode == 1)
        to_y_plus_1(vars);
    else if (keycode == 126 || keycode == 13)
        to_y_minus_1(vars);
    else if (keycode == 53)
        exit(0);
	return (0);
}
void to_initialized(t_game *var, char *name)
{
    (*var).map = map_to_2d(name, *var);
    (*var).rows = get_numline_map(*var, name);
    (*var).cols = ft_strlen((*var).map[0]);
    checker(*var, name);
    (*var).map_copy = get_game_copy(*var);
    (*var).map_copy_1 = get_game_copy(*var);
    check_for_fill((*var).map, *var);
    check_for_fill_copy((*var).map_copy, *var);
}
int scor(void *param)
{
    t_game *var = (t_game*) param;
     
    return(0);
}



void    lk()
{
    system("leaks parse");
}

int main(int ac, char **av)
{
    t_game var;
    if (ac != 2)
    {
        ft_putstr_fd("Error", 2);
        exit(0);
    }
    atexit(lk);
    check_file_name(av[1]);
    to_initialized(&var, av[1]);
    var.t = get_player_position(var.map_copy_1);
    var.player_x = var.t[0];
    var.player_y = var.t[1];
    freed_int(var.t);
    freed(var.map);
    freed(var.map_copy);
    var.mlx_ptr = mlx_init();
    if(!var.mlx_ptr)
        return(0);
    var.win_ptr = mlx_new_window(var.mlx_ptr, SIZE_l * var.cols,\
    SIZE_w * var.rows, "My Window");
    wall_map(var);
    var.map_copy_1[var.player_x][var.player_y] = '0';
    var.player_moves = 0;
    mlx_hook(var.win_ptr, 17, 0, kill_redcross, &var);
    mlx_hook(var.win_ptr, 2, 0, key_hook, &var);
    mlx_loop(var.mlx_ptr);
}
