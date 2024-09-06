/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:57:16 by apodader          #+#    #+#             */
/*   Updated: 2023/09/26 16:18:10 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keyword, t_game *game)
{
	if (keyword == KEY_W)
	{
		game->y -= 1;
		player_w(game);
	}
	if (keyword == KEY_A)
	{
		game->x -= 1;
		player_a(game);
	}
	if (keyword == KEY_S)
	{
		game->y += 1;
		player_s(game);
	}
	if (keyword == KEY_D)
	{
		game->x += 1;
		player_d(game);
	}
}

static void	str_put(t_game *game)
{
	char	*moves;
	char	*collect;
	char	*str1;
	char	*str2;

	moves = ft_itoa(game->moves);
	collect = ft_itoa(game->n_collect);
	str1 = ft_strjoin("Steps: ", moves);
	str2 = ft_strjoin("Collectibles left: ", collect);
	mlx_string_put(game->mlx, game->win, 5, 5, 0x00FFFFFF, str1);
	mlx_string_put(game->mlx, game->win, 5, 20, 0x00FFFFFF, str2);
	free(moves);
	free(collect);
	free(str1);
	free(str2);
}

static int	press_key(int keyword, t_game *game)
{
	if (keyword == KEY_ESC || keyword == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keyword, game);
		ft_printf("Moves: %d\n", game->moves);
		ft_printf("Collectibles left: %d\n", game->n_collect);
		str_put(game);
		if (game->endgame == 1)
		{
			success_event();
			exit_game(game);
		}
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 0, press_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}
