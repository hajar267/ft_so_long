/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:22:32 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/16 17:27:58 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freed(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	*fill_map(t_game *adr_var)
{
	char	*str;
	t_game	vars;

	vars = *adr_var;
	while (vars.n_l > vars.inc)
	{
		str = get_next_line(vars.fd);
		if (!str)
		{
			free(str);
			break ;
		}
		vars.allocate_map[vars.inc] = malloc(ft_strlen(str) + 1);
		if (!vars.allocate_map)
			return (NULL);
		fill_line(vars, str, vars.inc);
		vars.inc++;
	}
	return ((void *)1);
}