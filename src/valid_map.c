/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:16:44 by apodader          #+#    #+#             */
/*   Updated: 2023/09/20 14:03:00 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_route(t_mapcheck *mapcheck, int x, int y)
{
	if (mapcheck->map[y][x] == '1')
		return (0);
	else if (mapcheck->map[y][x] == 'C')
		mapcheck->n_collect--;
	else if (mapcheck->map[y][x] == 'E')
		mapcheck->exit = 1;
	mapcheck->map[y][x] = '1';
	valid_route(mapcheck, x - 1, y);
	valid_route(mapcheck, x + 1, y);
	valid_route(mapcheck, x, y - 1);
	valid_route(mapcheck, x, y + 1);
	if (mapcheck->exit == 1 && mapcheck->n_collect == 0)
		return (1);
	else
		return (0);
}

void	pec_count(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->n_player++;
		game->y = i;
		game->x = j;
	}
	else if (game->map[i][j] == 'E')
		game->n_exit++;
	else if (game->map[i][j] == 'C')
		game->n_collect++;
}
