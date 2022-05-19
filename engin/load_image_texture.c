/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:51:25 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:46:30 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	img->img =
	mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data =
	(int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->no, &img);
	load_image(info, info->texture[1], info->so, &img);
	load_image(info, info->texture[2], info->we, &img);
	load_image(info, info->texture[3], info->ea, &img);
	load_image(info, info->texture[4], info->s, &img);
}
