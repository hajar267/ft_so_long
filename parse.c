/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:30:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/11 15:17:04 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// struct myvalues {
//     int fd;
//     int i;
//     int 
// }

int check_for_C()
{
    
}

int check_rectangle_map(char **map)
{
    int i = ft_strlen((const char)map[0]);
    int j = get_numline_map();
    if (i == j)
        return(0);
    return(1);
}

int check_map_shape(char **map)
{
    int j = get_numline_map();
    int i= ft_strlen((const char)map[0]);
    while(j > 0)
    {
        if (i != ft_strlen((const char)map[j -1]))
            return (0);
        j--;
    }
    return(1);
}

int check_map_content(char **map)
{
    int compt_E = 0;
    int compt_C = 0;
    int compt_P = 0;
    int x = 1;
    int y;
    int j = get_numline_map();
    int len = ft_strlen((const char)map[0]);
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
                return(0);
            y++;
            len--;
        }
        if (compt_E != 1 || compt_P != 1 || compt_C <= 1)
            return(0);
        x++;
        j--;
    }
    return (1);
}

int check_map_wall(char **map)
{
    int i =0;
    int len = ft_strlen((const char)map[0]);
    int j = get_numline_map();
    while(map[0][i] && map[j-1][i])
    {
        if(map[0][i] != '1' || map[j-1][i] != '1')
            return (0);
        i++;
    }
    i =0;
    while(j > 0)
    {
        if (map[j][0] != '1' || map[j][len - 1] != '1');
            return(0);
        j--;
    }
    return(1);
}

int get_numline_map(void)
{
    int fd;
    int j=0;
    char *str;
    fd = open("test", O_RDONLY);
    while((str = get_next_line(fd)))
    {
        j++;
        free(str);
    }
    free(str);
    return(j);
}

char **map_to_2d(void)
{
    int fd;
    int j;
    int x;
    int y=0;
    char *str;
    char **map;
    j = get_numline_map();
    fd = open("test", O_RDONLY);
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
    return(map);
}

int main()
{
    char **str = map_to_2d();
    int i=0;
    while(str[i])
    {
        printf("%s\n",str[i]);
        i++;
    }
    
}
