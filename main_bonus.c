/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:08:13 by carys             #+#    #+#             */
/*   Updated: 2022/02/24 16:57:54 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map(t_game_map *v)
{
	int	a;

	v->mlx = mlx_init();
	if (v->mlx == NULL)
		ft_error("so_long: mlx_init returns NULL\n");
	v->wn = mlx_new_window(v->mlx, 40 * v->map_lenght,
			40 * v->map_height, "so_long");
	if (v->wn == NULL)
		ft_error("so_long: mlx_new_window returns NULL\n");
	v->go = mlx_xpm_file_to_image(v->mlx, "images/0.xpm", &a, &a);
	v->wall = mlx_xpm_file_to_image(v->mlx, "images/1.xpm", &a, &a);
	v->exit = mlx_xpm_file_to_image(v->mlx, "images/E.xpm", &a, &a);
	v->player = mlx_xpm_file_to_image(v->mlx, "images/P.xpm", &a, &a);
	v->coin = mlx_xpm_file_to_image(v->mlx, "animation/anim0.xpm", &a, &a);
	v->enemy1 = mlx_xpm_file_to_image(v->mlx, "images/Z.xpm", &a, &a);
	v->enemy2 = mlx_xpm_file_to_image(v->mlx, "images/Z.xpm", &a, &a);
	v->steps = 0;
	v->game_score = 0;
	add_enemy(v, 0, 0, 0);
}

void	ft_render_bonus(t_game_map *v, int i, int j)
{
	while (v->map_data[++i])
	{
		j = -1;
		while (v->map_data[i][++j])
		{
			mlx_put_image_to_window(v->mlx, v->wn, v->go, j * 40, i * 40);
			if (v->map_data[i][j] == '1')
				mlx_put_image_to_window(v->mlx, v->wn, v->wall, j * 40, i * 40);
			else if (v->map_data[i][j] == 'E')
				mlx_put_image_to_window(v->mlx, v->wn, v->exit, j * 40, i * 40);
			else if (v->map_data[i][j] == 'P')
				mlx_put_image_to_window(v->mlx, v->wn, v->player,
					j * 40, i * 40);
			else if (v->map_data[i][j] == 'C')
				mlx_put_image_to_window(v->mlx, v->wn, v->coin, j * 40, i * 40);
			else if (v->map_data[i][j] == 'Z')
				mlx_put_image_to_window(v->mlx, v->wn, v->enemy1,
					j * 40, i * 40);
			else if (v->map_data[i][j] == 'W')
				mlx_put_image_to_window(v->mlx, v->wn, v->enemy2,
					j * 40, i * 40);
		}
	}
	print_moves(v);
}

static int	ft_exit(void *param)
{
	if (param)
		ft_putstr_fd(param, 2);
	exit(0);
}

int	ft_get_map(int argc, char **argv, t_game_map *v)
{
	int	read_result;
	int	count_str;
	int	coin;

	if (argc != 2)
		ft_error("so_long: wrong count of arguments\n");
	coin = 0;
	count_str = 1;
	read_result = -1;
	if (ft_check_filename(argv[1]))
	{
		read_result = ft_read_map(argv[1], v, &count_str);
		if (read_result == 0)
		{
			if (ft_check_map(v, &count_str, &coin) == 0)
				return (0);
		}
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game_map	v;

	if (argc < 2)
		ft_error("so_long: wrong count of arguments\n");
	if (ft_get_map(argc, argv, &v) == -1)
		ft_error("so_long: invalid file\n");
	init_map(&v);
	init_animation(&v);
	ft_render_bonus(&v, -1, -1);
	mlx_key_hook(v.wn, ft_key_hook, &v);
	mlx_hook(v.wn, 17, 0, ft_exit, 0);
	mlx_loop_hook(v.mlx, ft_animation, &v);
	mlx_loop(v.mlx);
}
