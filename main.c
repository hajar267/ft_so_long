/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/28 13:04:22 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_numline_map(t_var   *vars, int fd)
{
    int j=0;
    char *str;
    while((str = get_next_line(fd)))
    {
        j++;
        free(str);
    }
    free(str);
    return(j);
}

void checker(t_var  *vars, int fd)
{
    check_map_shape(vars, fd);
    check_map_content(vars, fd);
    check_map_wall(vars, fd);
}

void map_to_2d(t_var    *vars, int fd)
{
    int j;
    int x;
    int y=0;
    char *str;
    j = get_numline_map(vars, fd);
    vars->map = malloc(sizeof(char *) * (j + 1));
    printf("hhh1\n");
    while(j > y)
    {
        str = get_next_line(fd);
        vars->map[y] = malloc(ft_strlen(str) + 1);
        x = 0;
        while(str[x] != '\n' && str[x])
        {
            vars->map[y][x] = str[x];
            x++;
        }
        vars->map[y][x] = '\0';
        free(str);
        y++;
    }
    vars->map[j] = NULL;
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

int main(int ac, char **av)
{
    t_var   *vars;
    int fd;
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
    fd = open(av[1], O_RDONLY);
    map_to_2d(vars, fd);
    printf("hhh\n");
    checker(vars, fd);
    t_var   *my_vars;
    my_vars = malloc(sizeof(t_var ));
    if (!my_vars)
        return(0);
    // vars->mlx_ptr = mlx_init();
    // if (!vars->mlx_ptr)
    //     return(0);
    // vars->win_ptr = mlx_new_window(vars->mlx_ptr, 1000, 800, "My Window");
    // vars->img_ptr = mlx_new_image(vars->mlx_ptr, 1920, 1080);
    // mlx_loop(vars->mlx_ptr);
}
