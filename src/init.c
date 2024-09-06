/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:13:39 by apodader          #+#    #+#             */
/*   Updated: 2023/09/14 14:13:39 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "textures/floor.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "textures/wall.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "textures/player_s.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "textures/taco.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "textures/exit.xpm", &game->img_w, &game->img_h);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->map_w = ft_strlen(game->map[0]) * 32;
	game->map_h = ft_ptrlen(game->map) * 32;
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "So_long");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
	map_draw(game);
}
