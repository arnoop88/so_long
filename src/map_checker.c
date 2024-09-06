/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:41:57 by apodader          #+#    #+#             */
/*   Updated: 2023/09/14 01:41:57 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_ptrlen(map);
	while (map[0][i] != '\0' && map[len - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[len - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	correct_format(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	pec_ok(t_game *game, t_mapcheck *mapcheck)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i] != NULL)
	{
		j = 1;
		while (game->map[i][j] != '\0')
		{
			pec_count(game, i, j);
			mapcheck->n_collect = game->n_collect;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_collect == 0)
		return (0);
	return (1);
}

int	map_checker(t_game *game, char *path)
{
	t_mapcheck	mapcheck;

	mapcheck.map = read_map(path);
	mapcheck.exit = 0;
	if (is_rectangular(game->map) && is_wall(game->map)
		&& correct_format(game->map) && pec_ok(game, &mapcheck)
		&& valid_route(&mapcheck, game->x, game->y))
	{
		free_map(mapcheck.map);
		return (1);
	}
	free_map(mapcheck.map);
	return (0);
}
