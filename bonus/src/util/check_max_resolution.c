/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_resolution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:41:05 by samin             #+#    #+#             */
/*   Updated: 2021/05/19 21:01:26 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_max_resolution(void *mlx, t_option *op)
{
	int x;
	int y;

	if (op->r[0] == 0 || op->r[1] == 0)
		custom_error("zero resolution error");
	mlx_get_screen_size(mlx, &x, &y);
	if (op->r[0] > x || op->r[1] > y)
	{
		op->r[0] = x;
		op->r[1] = y;
	}
}
