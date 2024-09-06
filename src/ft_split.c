/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:44:42 by apodader          #+#    #+#             */
/*   Updated: 2023/01/25 15:11:40 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	w_count(const char *s, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*s)
	{
		if (*s == c)
		{
			x = 0;
		}
		else if (x == 0)
		{
			x = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int	w_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_memdel(char **str)
{
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	str = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)ft_calloc((w_count(s, c) + 1), sizeof(*tab));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tab[i] = ft_substr(s, 0, w_len(s, c));
			if (!tab[i])
			{
				ft_memdel(tab);
				free(tab);
				return (NULL);
			}
			i++;
			s += w_len(s, c);
		}
	}
	return (tab);
}
