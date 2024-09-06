/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:36:28 by apodader          #+#    #+#             */
/*   Updated: 2023/09/16 10:36:28 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "textures/player_w.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "textures/player_a.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "textures/player_s.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "textures/player_d.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update('w', game);
	if (game->map[game->y][game->x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y + 1][game->x] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y][game->x] == '1'
		|| game->map[game->y][game->x] == 'E')
		game->y++;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y][game->x] == 'C')
			game->n_collect--;
		game->map[game->y][game->x] = 'P';
		game->map[game->y + 1][game->x] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update('a', game);
	if (game->map[game->y][game->x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y][game->x + 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y][game->x] == '1'
		|| game->map[game->y][game->x] == 'E')
		game->x++;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y][game->x] == 'C')
			game->n_collect--;
		game->map[game->y][game->x] = 'P';
		game->map[game->y][game->x + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_update('s', game);
	if (game->map[game->y][game->x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y - 1][game->x] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y][game->x] == '1'
		|| game->map[game->y][game->x] == 'E')
		game->y--;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y][game->x] == 'C')
			game->n_collect--;
		game->map[game->y][game->x] = 'P';
		game->map[game->y - 1][game->x] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update('d', game);
	if (game->map[game->y][game->x] == 'E' && game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y][game->x - 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y][game->x] == '1'
		|| game->map[game->y][game->x] == 'E')
		game->x--;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y][game->x] == 'C')
			game->n_collect--;
		game->map[game->y][game->x] = 'P';
		game->map[game->y][game->x - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
