/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:07:49 by carys             #+#    #+#             */
/*   Updated: 2022/02/25 14:15:07 by carys            ###   ########.fr       */
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
	v->coin = mlx_xpm_file_to_image(v->mlx, "images/C.xpm", &a, &a);
	v->game_score = 0;
}

void	ft_render(t_game_map *v)
{
	int	x;
	int	y;

	x = -1;
	while (v->map_data[++x])
	{
		y = -1;
		while (v->map_data[x][++y])
		{
			mlx_put_image_to_window(v->mlx, v->wn, v->go, y * 40, x * 40);
			if (v->map_data[x][y] == '1')
				mlx_put_image_to_window(v->mlx, v->wn, v->wall, y * 40, x * 40);
			if (v->map_data[x][y] == 'E')
				mlx_put_image_to_window(v->mlx, v->wn, v->exit, y * 40, x * 40);
			if (v->map_data[x][y] == 'P')
				mlx_put_image_to_window(v->mlx, v->wn, v->player,
					y * 40, x * 40);
			if (v->map_data[x][y] == 'C')
				mlx_put_image_to_window(v->mlx, v->wn, v->coin, y * 40, x * 40);
		}
	}
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

	if (argc != 2)
		ft_error("so_long: wrong count of arguments\n");
	if (ft_get_map(argc, argv, &v) == -1)
		ft_error("so_long: invalid file\n");
	init_map(&v);
	ft_render(&v);
	mlx_key_hook(v.wn, ft_key_hook, &v);
	mlx_hook(v.wn, 17, 0, ft_exit, 0);
	mlx_loop(v.mlx);
}
