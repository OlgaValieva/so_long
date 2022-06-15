/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:04:00 by carys             #+#    #+#             */
/*   Updated: 2022/02/26 18:39:40 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_animation(t_game_map *v)
{
	int	a;

	v->anim.img0 = mlx_xpm_file_to_image(v->mlx, "animation/anim0.xpm", &a, &a);
	v->anim.img1 = mlx_xpm_file_to_image(v->mlx, "animation/anim1.xpm", &a, &a);
	v->anim.img2 = mlx_xpm_file_to_image(v->mlx, "animation/anim2.xpm", &a, &a);
	v->anim.img3 = mlx_xpm_file_to_image(v->mlx, "animation/anim3.xpm", &a, &a);
	v->anim.img4 = mlx_xpm_file_to_image(v->mlx, "animation/anim4.xpm", &a, &a);
	v->anim.img5 = mlx_xpm_file_to_image(v->mlx, "animation/anim5.xpm", &a, &a);
}

static void	ft_put_animation(int i, int j, t_game_map *v, int an)
{
	if (an == 0)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img0, j * 40, i * 40);
	else if (an == 1)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img1, j * 40, i * 40);
	else if (an == 2)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img2, j * 40, i * 40);
	else if (an == 3)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img3, j * 40, i * 40);
	else if (an == 4)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img4, j * 40, i * 40);
	else if (an == 5)
		mlx_put_image_to_window(v->mlx, v->wn,
			v->anim.img5, j * 40, i * 40);
}

int	ft_animation(t_game_map *v)
{
	int			i;
	int			j;
	static int	animation;

	i = -1;
	while (v->map_data[++i])
	{
		j = -1;
		while (v->map_data[i][++j])
		{
			if (v->map_data[i][j] == 'C')
				ft_put_animation(i, j, v, animation);
		}
	}
	animation++;
	if (animation > 5)
		animation = 0;
	usleep(100000);
	enemy_one(v, -1, -1);
	enemy_two(v, -1, -1);
	return (1);
}

void	print_moves(t_game_map *v)
{
	char	*str;

	str = ft_itoa(v->steps);
	mlx_string_put(v->mlx, v->wn, 5, 6, 0xDF911C, "Moves: ");
	mlx_string_put(v->mlx, v->wn, 70, 6, 0xFF0000, str);
	free(str);
}
