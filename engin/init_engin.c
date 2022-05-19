/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:34:08 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 03:47:28 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_buf(t_info *info)
{
	int i;

	i = -1;
	info->zbuffer = malloc(sizeof(double) * info->width);
	info->buf = malloc(sizeof(int*) * info->height);
	while (++i < info->height)
		info->buf[i] = malloc(sizeof(int) * info->width);
}

void	init_player_dir_ws(t_info *info, char plyer_dir)
{
	if (plyer_dir == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
	else if (plyer_dir == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}

void	init_player_dir_ne(t_info *info, char plyer_dir)
{
	if (plyer_dir == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (plyer_dir == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
}

void	init_info_helper(t_info *info, t_option *op)
{
	info->worldmap = op->map;
	info->num_sprites = op->num_sprites;
	info->sprite = op->sprite;
	info->sprite_order = op->sprite_order;
	info->sprite_distance = op->sprite_distance;
	info->width = op->r[0];
	info->height = op->r[1];
	info->no = op->no;
	info->so = op->so;
	info->we = op->we;
	info->ea = op->ea;
	info->s = op->s;
	info->f_rgb = (op->f[0] * 256 * 256) + (op->f[1] * 256) + op->f[2];
	info->c_rgb = (op->c[0] * 256 * 256) + (op->c[1] * 256) + op->c[2];
	info->pos_x = op->posx + 0.5;
	info->pos_y = op->posy + 0.5;
	info->movespeed = 0.08;
	info->rotspeed = 0.07;
}

void	init_info(t_info *info, t_option *op)
{
	init_info_helper(info, op);
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_up = 0;
	info->key_down = 0;
	info->key_left = 0;
	info->key_right = 0;
	info->key_esc = 0;
	init_buf(info);
	init_player_dir_ne(info, op->player_dir);
	init_player_dir_ws(info, op->player_dir);
}
