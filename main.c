/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/30 16:23:26 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_numline_map(char *name)
{
    int j=0;
    int fd;
    char *str;
    fd = open(name, O_RDONLY);
    while((str = get_next_line(fd)))
    {
        j++;
        free(str);
    }
    close(fd);
    free(str);
    return(j);
}

void checker(char **map, char *name)
{
    check_start_map(name);
    check_map_shape(map, name);
    check_map_content(map, name);
    check_map_wall(map, name);
    
}

char **map_to_2d(char *name)
{
    int j;
    int x;
    int fd;
    int y=0;
    char *str;
    char **map;
    j = get_numline_map(name);
    fd = open(name, O_RDONLY);
    map = malloc(sizeof(char *) * (j + 1));
    while(j > y)
    {
        str = get_next_line(fd);
        if (!str)
        {
            break;
        }
        map[y] = malloc(ft_strlen(str) + 1);
        x = 0;
        while(str[x] != '\n' && str[x])
        {
            map[y][x] = str[x];
            x++;
        }
        map[y][x] = '\0';
        free(str);
        y++;
    }
    map[j] = NULL;
    close(fd);
    return(map);
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

void check_for_fill(char **map, int rows, int cols)
{
    int *t;
    t = get_player_position(map);
    flood_fill(map,t[0],t[1], rows, cols);
    check_for_c(map);
}

void check_for_fill_copy(char **map_copy, int rows, int cols)
{
    int *t_copy;
    
    t_copy = get_Exit_position(map_copy);
    flood_fill_copy(map_copy, t_copy[0], t_copy[1], rows, cols);
    check_for_E_copy(map_copy);
}

int main(int ac, char **av)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char **map;
    char **map_copy;
    int rows;
    int cols;
    if (ac == 1)
    {
        perror("at least one map !!!");
        exit(0);
    }
    if (ac > 2)
    {
        perror("one map please !!!");
        exit(0);
    }
    check_file_name(av[1]);
    map = map_to_2d(av[1]);
    checker(map, av[1]);
    rows = get_numline_map(av[1]);
    cols = ft_strlen(map[0]);
    map_copy = get_map_copy(map, rows, cols);
    check_for_fill(map, rows, cols);
    check_for_fill(map_copy, rows, cols);
    mlx_ptr = mlx_init();
    // if (mlx_ptr)
    //     return(0);
    win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "My Window");
    // img_ptr = mlx_new_image(mlx_ptr, 1920, 1080);
    mlx_loop(mlx_ptr);
}
