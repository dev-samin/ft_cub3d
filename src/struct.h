/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:43:09 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 17:07:05 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define TEX_WIDTH 				64
# define TEX_HEIGHT 			64

typedef struct		s_sprite
{
	double		x;
	double		y;
	int			texture;
}					t_sprite;

typedef struct		s_option
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			r[2];
	int			f[3];
	int			c[3];
	int			map_x;
	int			map_y;
	char		**map;
	int			checker[8];
	int			map_sw;
	int			player;
	char		player_dir;
	int			posx;
	int			posy;
	t_sprite	*sprite;
	int			num_sprites;
	int			*sprite_order;
	double		*sprite_distance;
	int			empty_line;
	int			invalid_map;
}					t_option;

typedef struct		s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}					t_img;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct		s_wall_info
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
}					t_wall_info;

typedef struct		s_sprite_info
{
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		spritescreen_x;
	int		v_movescreen;
	int		sprite_height;
	int		drawstart_y;
	int		drawend_y;
	int		sprite_width;
	int		drawstart_x;
	int		drawend_x;
	int		stripe;
	int		y;
	int		tex_x;
	int		d;
	int		tex_y;
	int		color;
	int		u_div;
	int		v_div;
	double	v_move;
}					t_sprite_info;

typedef struct		s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_esc;
	t_img		img;
	int			**buf;
	double		*zbuffer;
	int			**texture;
	double		movespeed;
	double		rotspeed;
	char		**worldmap;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f_rgb;
	int			c_rgb;
	t_sprite	*sprite;
	int			num_sprites;
	int			*sprite_order;
	double		*sprite_distance;
	double		old_dir_x;
	double		old_plane_x;
	int			width;
	int			height;
	int			save_sw;
}					t_info;
#endif
