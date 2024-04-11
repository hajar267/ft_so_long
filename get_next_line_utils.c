/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:17:37 by hfiqar            #+#    #+#             */
/*   Updated: 2024/01/17 18:12:02 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// here bring ur ustlis functions from libft
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen((char *)s) +1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ifstate(size_t len_s, size_t start, size_t len)
{
	size_t	size;

	if (len_s < start)
		size = 0;
	else if (len_s < start + len)
		size = len_s - start;
	else
		size = len;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if(s2 == NULL)
		return ((char *)s1);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (free(str) ,NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free((char *)s1), str);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	size;
	size_t	len_s;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	size = ifstate(len_s, start, len);
	str = (char *)malloc(size + 1);
	if (!str)
		return (free(str), NULL);
	while (s[i] && j < len)
	{
		if (i < start)
			i++;
		else
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
