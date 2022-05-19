/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:34:08 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 22:05:54 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main_loop(t_info *info)
{
	cal_floor_ceiling(info);
	cal_wall(info);
	cal_sprite(info);
	draw(info);
	key_update(info);
	return (0);
}

int		x_close(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info		info;
	t_option	op;

	info.mlx = mlx_init();
	check_argc(&info, argc, argv);
	check_format(argv[1], ".cub");
	ft_memset(&op, 0, sizeof(t_option));
	parse_cub3d(argv, &op);
	check_max_resolution(&info.mlx, &op);
	check_player_sprite(&op);
	find_sprite(&op);
	dfs_map(&op, op.map, op.posx, op.posy);
	init_info(&info, &op);
	init_mlx_img(&info);
	init_mlx_texture(&info);
	load_texture(&info);
	save_screenshot(&info);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &x_close, &info);
	mlx_loop(info.mlx);
}
