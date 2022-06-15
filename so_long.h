/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:57 by carys             #+#    #+#             */
/*   Updated: 2022/02/24 15:06:33 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_animation
{
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
}	t_anim;

typedef struct s_game_map
{
	char	**map_data;
	int		map_height;
	int		map_lenght;
	int		game_score;
	int		max_score;
	int		pos_x;
	int		pos_y;
	int		steps;
	void	*mlx;
	void	*wn;
	void	*go;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*player;
	void	*enemy1;
	void	*enemy2;
	t_anim	anim;
}	t_game_map;

int		main(int argc, char **argv);
void	ft_render(t_game_map *v);
int		ft_get_map(int argc, char **argv, t_game_map *v);
int		ft_check_map(t_game_map *v, int *count_str, int *coin);
int		ft_read_map(char *str, t_game_map *v, int *count_str);
int		ft_check_filename(char *str);
int		check_rectangle(t_game_map *v, int i, int count_str);
int		check_char_and_coin(t_game_map *v, int *coin, int i, int j);
int		check_exit_person(t_game_map *v, int i, int j);
int		check_wall(t_game_map *v, int i, int j, int count_str);
int		ft_key_hook(int keycode, t_game_map *v);
int		gnl(char **line, int fd);
void	ft_perror(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *str);
int		main_bonus(int argc, char **argv);
void	ft_render_bonus(t_game_map *v, int i, int j);
void	init_animation(t_game_map *v);
int		ft_animation(t_game_map *v);
void	print_moves(t_game_map *v);
void	add_enemy(t_game_map *v, int i, int j, int count);
void	enemy_two(t_game_map *v, int i, int j);
void	enemy_one(t_game_map *v, int i, int j);
char	*ft_itoa(int n);

#endif