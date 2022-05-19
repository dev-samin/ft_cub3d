/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 02:48:31 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 03:42:19 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_player_sprite(t_option *op)
{
	int i;
	int j;

	op->player = 0;
	i = -1;
	while (++i < op->map_y)
	{
		j = -1;
		while (++j < op->map_x)
		{
			if (op->player > 1)
				custom_error("no player error");
			if (op->map[i][j] == 'N' || op->map[i][j] == 'W'
			|| op->map[i][j] == 'E' || op->map[i][j] == 'S')
			{
				op->player++;
				op->posx = i;
				op->posy = j;
				op->player_dir = op->map[i][j];
				op->map[i][j] = '0';
			}
			if (op->map[i][j] == '2' || op->map[i][j] == '3')
				op->num_sprites++;
		}
	}
}

void	sprit_helper(t_option *op)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < op->map_y)
	{
		j = -1;
		while (++j < op->map_x)
		{
			if (op->map[i][j] == '2' || op->map[i][j] == '3')
			{
				if (op->map[i][j] == '2')
					op->sprite[count].texture = 4;
				if (op->map[i][j] == '3')
					op->sprite[count].texture = 5;
				op->sprite[count].x = i + 0.5;
				op->sprite[count].y = j + 0.5;
				op->map[i][j] = '0';
				count++;
			}
		}
	}
}

void	find_sprite(t_option *op)
{
	if (op->num_sprites == 0)
		return ;
	op->sprite = malloc(sizeof(t_sprite) * op->num_sprites);
	op->sprite_order = malloc(sizeof(int) * op->num_sprites);
	op->sprite_distance = malloc(sizeof(double) * op->num_sprites);
	sprit_helper(op);
}
