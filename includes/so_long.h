/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apodader <apodader@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:46:55 by apodader          #+#    #+#             */
/*   Updated: 2023/09/13 11:46:55 by apodader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include "get_next_line.h"

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x;
	int		y;
	int		moves;
	int		endgame;
}	t_game;

typedef struct s_mapcheck
{
	char	**map;
	int		n_collect;
	int		x;
	int		y;
	int		exit;
}	t_mapcheck;

char	*ft_strdup(char const *src);
char	**ft_split(char const *s, char c);
int		ft_ptrlen(char **ptr);
int		valid_route(t_mapcheck *mapcheck, int x, int y);
int		map_checker(t_game *game, char *path);
void	pec_count(t_game *game, int i, int j);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);
void	free_map(char **map);
int		exit_game(t_game *game);
void	success_event(void);
int		map_draw(t_game *game);
void	player_w(t_game *game);
void	player_a(t_game *game);
void	player_s(t_game *game);
void	player_d(t_game *game);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	game_init(t_game *game);
void	gameplay(t_game *game);
char	**read_map(char *path);

#endif