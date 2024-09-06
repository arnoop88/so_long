/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:24:43 by apodader          #+#    #+#             */
/*   Updated: 2023/09/13 11:24:43 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = tmp_map;
		tmp_map = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	return (map);
}

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = ft_strlen(argv);
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e'
		&& argv[i - 3] == 'b' && argv[i - 4] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments\n");
		exit(1);
	}
	else
	{
		game.map = read_map(argv[1]);
		if (argv_checker(argv[1]) && map_checker(&game, argv[1]))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map)
				free_map(game.map);
			ft_printf("Error\nInvalid map\n");
			exit(1);
		}
	}
}
