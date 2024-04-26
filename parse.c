/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/26 19:55:03 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// struct myvalues {
//     int fd;
//     int i;
//     int 
// }

void flood_fill(char **map, int y, int x)
{
    if (map[y][x] == 1)
        return;
    map[y][x] = 'F';
    flood_fill(map, y - 1, x);
    flood_fill(map, y + 1, x);
    flood_fill(map, y, x + 1);
    flood_fill(map, y, x - 1);
}

void checker(char **map, int fd)
{
    check_map_shape(map, fd);
    check_map_content(map, fd);
    check_map_wall(map, fd);
}

void check_map_shape(char **map, int fd)
{
    int j = get_numline_map(fd);
    int i= ft_strlen((const char)map[0]);
    if (j == i)
    {
        perror("error invalid map");
        exit(0);
    }
    while(j > 0)
    {
        if (i != ft_strlen((const char)map[j -1]))
        {
            perror("error invalid map");
            exit(0);
        }
        j--;
    }
}

void check_map_content(char **map, int fd)
{
    int compt_E = 0;
    int compt_C = 0;
    int compt_P = 0;
    int x = 1;
    int y;
    int j = get_numline_map(fd) - 1;
    int len = ft_strlen((const char)map[0]) - 1;
    while(j - 1 > 0)
    {
        y = 1;
        while(len - 1 > 0)
        {
            if (map[x][y] == 'E')
                compt_E++;
            else if (map[x][y] == 'C')
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
        if (compt_E != 1 || compt_P != 1 || compt_C < 1)
        {
            perror("error more than E || P or less than one C !!!");
            exit(0);
        }
        x++;
        j--;
    }
}

void check_map_wall(int fd, char **map)  //struct as a parametre
{
    int i =0;
    int len = ft_strlen((const char)map[0]);
    int j = get_numline_map(fd);
    while(map[0][i] && map[j-1][i])
    {
        if(map[0][i] != '1' || map[j-1][i] != '1')
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

int get_numline_map(int fd)
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

void map_to_2d(int fd)
{
    int j;
    int x;
    int y=0;
    char *str;
    char **map;
    j = get_numline_map(fd);
    map = malloc(sizeof(char *) * (j + 1));
    while(j > y)
    {
        str = get_next_line(fd);
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
}

void check_file_name(char *name)
{
    int i = 0;
    while(name[i])
    {
        if (name[i] == '.' && name[i + 1] == 'b' 
        && name[i + 2] == 'e' && name[i + 3] == 'r');
            return ;
    }
    perror("correct file's name haaa!!!");
    exit(0);
}

int main(int ac, char **av)
{
    char **map; // struct
    int fd;
    void *mlx_ptr;
    void *win_ptr;
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
    map_to_2d(fd);
    checker(map, fd);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "My Window");
    mlx_loop(mlx_ptr);
}
