/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carys <carys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:05:31 by carys             #+#    #+#             */
/*   Updated: 2022/02/25 14:14:24 by carys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_game_map *m, int i, int j, int count)
{
	i = m->map_height - 1;
	while (--i > 0)
	{
		j = m->map_lenght - 1;
		while (--j > 0)
		{
			if (m->map_data[i][j] == '0')
			{
				if (count == 0 && m->map_data[i][j - 1] == '0')
				{
					m->map_data[i][j - 1] = 'Z';
					count = 1;
					i -= 1;
				}
				else if (count == 1 && m->map_data[i][j - 1] == '0')
				{
					m->map_data[i][j - 1] = 'W';
					count = 2;
					break ;
				}
			}
		}
	}
}

static void	ft_go_enemy1(t_game_map *m, int i, int j)
{
	static int	left;

	if (left == 1 && (m->map_data[i][j - 1] == '0'
		|| m->map_data[i][j - 1] == 'P'))
	{
		if (m->map_data[i][j - 1] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i][j - 2] != '0'
			&& m->map_data[i][j - 2] != 'P')
			left = 0;
		m->map_data[i][j - 1] = 'Z';
		m->map_data[i][j--] = '0';
	}
	else if (left == 0 && (m->map_data[i][j + 1] == '0'
		|| m->map_data[i][j + 1] == 'P'))
	{
		if (m->map_data[i][j + 1] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i][j + 2] != '0'
			&& m->map_data[i][j + 2] != 'P')
			left = 1;
		m->map_data[i][j + 1] = 'Z';
		m->map_data[i][j++] = '0';
	}
}

static void	ft_go_enemy2(t_game_map *v, int i, int j)
{
	static int	front;

	if (front == 1 && (v->map_data[i - 1][j] == '0'
		|| v->map_data[i - 1][j] == 'P'))
	{
		if (v->map_data[i - 1][j] == 'P')
			ft_error("Game over!\n");
		if (v->map_data[i - 2][j] != '0'
			&& v->map_data[i - 2][j] != 'P')
			front = 0;
		v->map_data[i - 1][j] = 'W';
		v->map_data[i--][j] = '0';
	}
	else if (front == 0 && (v->map_data[i + 1][j] == '0'
		|| v->map_data[i + 1][j] == 'P'))
	{
		if (v->map_data[i + 1][j] == 'P')
			ft_error("Game over!\n");
		if (v->map_data[i + 2][j] != '0'
			&& v->map_data[i + 2][j] != 'P')
			front = 1;
		v->map_data[i + 1][j] = 'W';
		v->map_data[i++][j] = '0';
	}
}

void	enemy_one(t_game_map *v, int i, int j)
{
	static int	time;

	time++;
	if ((time % 10) == 0)
	{
		while (v->map_data[++i])
		{
			j = -1;
			while (v->map_data[i][++j])
			{
				if (v->map_data[i][j] == 'Z')
				{
					ft_go_enemy1(v, i, j);
					ft_render_bonus(v, -1, -1);
					return ;
				}
			}
		}
	}
}

void	enemy_two(t_game_map *v, int i, int j)
{
	static int	time;

	time++;
	if ((time % 10) == 0)
	{
		while (v->map_data[++i])
		{
			j = -1;
			while (v->map_data[i][++j])
			{
				if (v->map_data[i][j] == 'W')
				{
					ft_go_enemy2(v, i, j);
					ft_render_bonus(v, -1, -1);
					return ;
				}
			}
		}
	}
}
