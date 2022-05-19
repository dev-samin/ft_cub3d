/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:39:39 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:47:07 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_mlx_img(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data =
	(int *)mlx_get_data_addr(info->img.img,
	&info->img.bpp, &info->img.size_l, &info->img.endian);
}

void	init_mlx_texture(t_info *info)
{
	int i;

	i = 0;
	if (!(info->texture = (int **)malloc(sizeof(int *) * 6)))
		exit(0);
	i = 0;
	while (i < 6)
	{
		if (!(info->texture[i] =
		malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
			exit(0);
		i++;
	}
}
