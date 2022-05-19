/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:52:22 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:47:02 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	cal_sprite_helper_1(t_info *info, t_sprite_info *sprite_info, int i)
{
	sprite_info->sprite_x =
	info->sprite[info->sprite_order[i]].x - info->pos_x;
	sprite_info->sprite_y =
	info->sprite[info->sprite_order[i]].y - info->pos_y;
	sprite_info->invdet =
	1.0 / (info->plane_x * info->dir_y - info->dir_x * info->plane_y);
	sprite_info->transform_x =
	sprite_info->invdet * (info->dir_y * sprite_info->sprite_x -
	info->dir_x * sprite_info->sprite_y);
	sprite_info->transform_y =
	sprite_info->invdet *
	(-info->plane_y * sprite_info->sprite_x +
	info->plane_x * sprite_info->sprite_y);
	sprite_info->spritescreen_x =
	(int)((info->width / 2) *
	(1 + sprite_info->transform_x / sprite_info->transform_y));
}

void	cal_sprite_helper_2(t_info *info, t_sprite_info *sprite_info)
{
	sprite_info->v_movescreen =
	(int)(sprite_info->v_move / sprite_info->transform_y);
	sprite_info->sprite_height =
	(int)fabs((info->height / sprite_info->transform_y) / sprite_info->v_div);
	sprite_info->drawstart_y =
	-(sprite_info->sprite_height) / 2 + info->height / 2 +
	sprite_info->v_movescreen;
	if (sprite_info->drawstart_y < 0)
		sprite_info->drawstart_y = 0;
	sprite_info->drawend_y = sprite_info->sprite_height / 2 +
	info->height / 2 + sprite_info->v_movescreen;
	if (sprite_info->drawend_y >= info->height)
		sprite_info->drawend_y = info->height - 1;
	sprite_info->sprite_width =
	(int)fabs((info->height / sprite_info->transform_y) / sprite_info->u_div);
	sprite_info->drawstart_x =
	-(sprite_info->sprite_width) / 2 + sprite_info->spritescreen_x;
	if (sprite_info->drawstart_x < 0)
		sprite_info->drawstart_x = 0;
	sprite_info->drawend_x =
	sprite_info->sprite_width / 2 + sprite_info->spritescreen_x;
	if (sprite_info->drawend_x >= info->width)
		sprite_info->drawend_x = info->width - 1;
	sprite_info->stripe = sprite_info->drawstart_x;
	sprite_info->y = sprite_info->drawstart_y;
}

void	cal_sprite_helper_3(t_info *info, t_sprite_info *sprite_info, int i)
{
	while (sprite_info->stripe < sprite_info->drawend_x)
	{
		sprite_info->tex_x = (int)((256 * (sprite_info->stripe -
		(-(sprite_info->sprite_width) / 2 + sprite_info->spritescreen_x))
		* TEX_WIDTH / sprite_info->sprite_width) / 256);
		if (sprite_info->transform_y > 0 && sprite_info->stripe > 0
		&& sprite_info->stripe < info->width
		&& sprite_info->transform_y < info->zbuffer[sprite_info->stripe])
			sprite_info->y = sprite_info->drawstart_y;
		cal_sprite_helper_4(info, sprite_info, i);
		sprite_info->stripe++;
	}
}

void	cal_sprite_helper_4(t_info *info, t_sprite_info *sprite_info, int i)
{
	while (sprite_info->y < sprite_info->drawend_y)
	{
		sprite_info->d = (sprite_info->y - (sprite_info->v_movescreen)) *
		256 - info->height * 128 + sprite_info->sprite_height * 128;
		sprite_info->tex_y =
		((sprite_info->d * TEX_HEIGHT) / sprite_info->sprite_height) / 256;
		sprite_info->color = info->texture
		[info->sprite[info->sprite_order[i]].texture]
		[TEX_WIDTH * sprite_info->tex_y + sprite_info->tex_x];
		if ((sprite_info->color & 0x00FFFFFF) != 0)
			info->buf[sprite_info->y][sprite_info->stripe] = sprite_info->color;
		sprite_info->y++;
	}
}

void	cal_sprite(t_info *info)
{
	int				i;
	t_sprite_info	sprite_info;

	i = -1;
	sprite_info.u_div = 1;
	sprite_info.v_div = 1;
	sprite_info.v_move = 0.0;
	while (++i < info->num_sprites)
	{
		info->sprite_order[i] = i;
		info->sprite_distance[i] =
		((info->pos_x - info->sprite[i].x) *
		(info->pos_x - info->sprite[i].x) +
		(info->pos_y - info->sprite[i].y) *
		(info->pos_y - info->sprite[i].y));
	}
	sort_sprites(info);
	i = -1;
	while (++i < info->num_sprites)
	{
		cal_sprite_helper_1(info, &sprite_info, i);
		cal_sprite_helper_2(info, &sprite_info);
		cal_sprite_helper_3(info, &sprite_info, i);
	}
}
