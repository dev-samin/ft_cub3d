/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:49:52 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 22:05:47 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	bmp_data(t_info *info, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = info->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < info->width)
		{
			buffer[0] =
			(unsigned char)(info->img.data[i * info->width + j] % 256);
			buffer[1] =
			(unsigned char)(info->img.data[i * info->width + j] / 256 % 256);
			buffer[2] = (unsigned char)
			(info->img.data[i * info->width + j] / 256 / 256 % 256);
			buffer[3] =
			(unsigned char)(0);
			write(fd, buffer, 4);
			j++;
		}
		i--;
	}
}

void	bmp_file_header(t_info *info, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = info->width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = info->height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	bmp_info_header(t_info *info, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = info->height * info->width * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

void	save_screenshot(t_info *info)
{
	int		fd;

	if (info->save_sw == 0)
		return ;
	cal_floor_ceiling(info);
	cal_wall(info);
	cal_sprite(info);
	draw(info);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bmp_info_header(info, fd);
	bmp_file_header(info, fd);
	bmp_data(info, fd);
	close(fd);
	exit(0);
}
