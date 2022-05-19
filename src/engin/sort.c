/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 02:07:29 by samin             #+#    #+#             */
/*   Updated: 2021/05/13 19:46:27 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_info *info)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair*)malloc(sizeof(t_pair) * info->num_sprites);
	i = 0;
	while (i < info->num_sprites)
	{
		sprites[i].first = info->sprite_distance[i];
		sprites[i].second = info->sprite_order[i];
		i++;
	}
	sort_order(sprites, info->num_sprites);
	i = 0;
	while (i < info->num_sprites)
	{
		info->sprite_distance[i] = sprites[info->num_sprites - i - 1].first;
		info->sprite_order[i] = sprites[info->num_sprites - i - 1].second;
		i++;
	}
	free(sprites);
}
