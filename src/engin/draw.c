/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:23:13 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:58:15 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw(t_info *info)
{
	int x;
	int y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[y * info->width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	if (info->save_sw == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
