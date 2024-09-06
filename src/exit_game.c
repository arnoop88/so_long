/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:38:23 by apodader          #+#    #+#             */
/*   Updated: 2023/09/26 16:18:44 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	success_event(void)
{
	printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	printf("░░░░█▀▀▀░█▀▀▀░░█▀▀░▀▀█░░█░░░░\n");
	printf("░░░░█░▀█░█░▀█░░█▀▀░▄▀░░░▀░░░░\n");
	printf("░░░░▀▀▀▀░▀▀▀▀░░▀▀▀░▀▀▀░░▀░░░░\n");
	printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (1);
}
