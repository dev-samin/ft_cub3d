/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:41:05 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:28:02 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../mlx/mlx.h"
# include "key_macos.h"
# include "struct.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

int		main_loop(t_info *info);

int		x_close();
void	parse_cub3d(char **argv, t_option *op);
void	parser(int fd, t_option *op);
void	check_argc(t_info *info, int argc, char **argv);
void	check_format(char *str1, char *str2);
void	parse_option(t_option *op, char *line);
void	check_max_resolution(void *mlx, t_option *op);

void	parse_resolution(t_option *op, char *line);
void	parse_helper_resolution(t_option *op, char *line);

void	parse_texture(t_option *op, char *line);
void	parse_helper_texture(char **texture, char *line, char *op_spec);

void	parse_rgb(t_option *op, char *line);
void	parse_helper_rgb0(char *line);
void	parse_helper_rgb1(int *rgb, char *line);
void	parse_helper_rgb2(char **tmp);

void	parse_map(t_option *op, char *line, char **buff);
void	join_map(t_option *op, char *line, char **buff);
void	create_empty_map(t_option *op, char **tmp_map);
void	is_option_full(t_option *op);
int		is_map(char *line);

void	check_player_sprite(t_option *op);
void	sprit_helper(t_option *op);
void	find_sprite(t_option *op);
void	dfs_map(t_option *op, char **map, int y, int x);

void	init_info(t_info *info, t_option *op);
void	init_info_helper(t_info *info, t_option *op);
void	init_buf(t_info *info);
void	init_player_dir_ws(t_info *info, char plyer_dir);
void	init_player_dir_ne(t_info *info, char plyer_dir);

void	init_mlx_img(t_info *info);
void	init_mlx_texture(t_info *info);

void	load_texture(t_info *info);
void	load_image(t_info *info, int *texture, char *path, t_img *img);

void	draw(t_info *info);

void	cal_floor_ceiling(t_info *info);

void	cal_wall(t_info *info);
void	cal_wall_helper_1(t_info *info, t_wall_info *wall_info, int x);
void	cal_wall_helper_2(t_info *info, t_wall_info *wall_info);
void	cal_wall_helper_3(t_info *info, t_wall_info *wall_info);
void	cal_wall_helper_4(t_info *info, t_wall_info *wall_info);
void	cal_wall_helper_5(t_wall_info *wall_info);
void	cal_wall_helper_6(t_info *info, t_wall_info *wall_info);
void	cal_wall_helper_7(t_info *info, t_wall_info *wall_info, int x);

void	cal_sprite(t_info *info);
void	cal_sprite_helper_1(t_info *info, t_sprite_info *sprite_info, int i);
void	cal_sprite_helper_2(t_info *info, t_sprite_info *sprite_info);
void	cal_sprite_helper_3(t_info *info, t_sprite_info *sprite_info, int i);
void	cal_sprite_helper_4(t_info *info, t_sprite_info *sprite_info, int i);
void	cal_sprite_helper_4(t_info *info, t_sprite_info *sprite_info, int i);
void	sort_sprites(t_info *info);
void	sort_order(t_pair *orders, int amount);

void	key_update(t_info *info);
void	key_update_helper_rotate(t_info *info);
void	key_update_helper_moving1(t_info *info);
void	key_update_helper_moving2(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

void	custom_error(char *msg);

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

void	save_screenshot(t_info *info);
int		save_bmp(t_info *info);
void	bmp_data(t_info *info, int fd);
void	bmp_file_header(t_info *info, int fd);
void	bmp_info_header(t_info *info, int fd);

#endif
