/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:05:48 by carys             #+#    #+#             */
/*   Updated: 2022/02/26 17:49:30 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_go_front(t_game_map *v)
{
	if (v->map_data[v->pos_y - 1][v->pos_x] == 'C'
	|| v->map_data[v->pos_y - 1][v->pos_x] == '0')
	{
		if (v->map_data[v->pos_y - 1][v->pos_x] == 'C')
			(v->game_score)++;
		v->map_data[v->pos_y - 1][v->pos_x] = 'P';
		v->map_data[v->pos_y--][v->pos_x] = '0';
		return (1);
	}
	if ((v->map_data[v->pos_y - 1][v->pos_x] == 'E')
	&& (v->game_score == v->max_score))
	{
		printf("You are winner!\n");
		exit(0);
	}
	return (0);
}

static int	ft_go_back(t_game_map *v)
{
	if (v->map_data[v->pos_y + 1][v->pos_x] == 'C'
	|| v->map_data[v->pos_y + 1][v->pos_x] == '0')
	{
		if (v->map_data[v->pos_y + 1][v->pos_x] == 'C')
			(v->game_score)++;
		v->map_data[v->pos_y + 1][v->pos_x] = 'P';
		v->map_data[v->pos_y++][v->pos_x] = '0';
		return (1);
	}
	if ((v->map_data[v->pos_y + 1][v->pos_x] == 'E')
	&& (v->game_score == v->max_score))
	{
		printf("You are winner!\n");
		exit(0);
	}
	return (0);
}

static int	ft_go_left(t_game_map *v)
{
	if (v->map_data[v->pos_y][v->pos_x - 1] == 'C'
	|| v->map_data[v->pos_y][v->pos_x - 1] == '0')
	{
		if (v->map_data[v->pos_y][v->pos_x - 1] == 'C')
			(v->game_score)++;
		v->map_data[v->pos_y][v->pos_x - 1] = 'P';
		v->map_data[v->pos_y][v->pos_x--] = '0';
		return (1);
	}
	if ((v->map_data[v->pos_y][v->pos_x - 1] == 'E')
	&& (v->game_score == v->max_score))
	{
		printf("You are winner!\n");
		exit(0);
	}
	return (0);
}

static int	ft_go_right(t_game_map *v)
{
	if (v->map_data[v->pos_y][v->pos_x + 1] == 'C'
	|| v->map_data[v->pos_y][v->pos_x + 1] == '0')
	{
		if (v->map_data[v->pos_y][v->pos_x + 1] == 'C')
			(v->game_score)++;
		v->map_data[v->pos_y][v->pos_x + 1] = 'P';
		v->map_data[v->pos_y][v->pos_x++] = '0';
		return (1);
	}
	if ((v->map_data[v->pos_y][v->pos_x + 1] == 'E')
	&& (v->game_score == v->max_score))
	{
		printf("You are winner!\n");
		exit(0);
	}
	return (0);
}

int	ft_key_hook(int keycode, t_game_map *v)
{
	int			step;
	static int	steps;

	step = 0;
	if (keycode == 13)
		step += ft_go_front(v);
	else if (keycode == 1)
		step += ft_go_back(v);
	else if (keycode == 0)
		step += ft_go_left(v);
	else if (keycode == 2)
		step += ft_go_right(v);
	else if (keycode == 53)
	{
		printf("Don't worry, try again\n");
		exit(0);
	}
	if (step != 0)
	{
		printf("Moves: %d\n", ++steps);
		ft_render(v);
	}
	return (0);
}
