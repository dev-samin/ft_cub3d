/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:41:05 by samin             #+#    #+#             */
/*   Updated: 2021/05/14 03:13:18 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		key_press(int key, t_info *info)
{
	if (key == K_ESC)
	{
		system("killall afplay");
		exit(0);
	}
	else if (key == K_W)
		info->key_w = 1;
	else if (key == K_A)
		info->key_a = 1;
	else if (key == K_S)
		info->key_s = 1;
	else if (key == K_D)
		info->key_d = 1;
	else if (key == K_AR_U)
		info->key_up = 1;
	else if (key == K_AR_D)
		info->key_down = 1;
	else if (key == K_AR_L)
		info->key_left = 1;
	else if (key == K_AR_R)
		info->key_right = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 0;
	else if (key == K_A)
		info->key_a = 0;
	else if (key == K_S)
		info->key_s = 0;
	else if (key == K_D)
		info->key_d = 0;
	else if (key == K_AR_U)
		info->key_up = 0;
	else if (key == K_AR_D)
		info->key_down = 0;
	else if (key == K_AR_L)
		info->key_left = 0;
	else if (key == K_AR_R)
		info->key_right = 0;
	return (0);
}
