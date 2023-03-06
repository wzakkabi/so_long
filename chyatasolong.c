/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyatasolong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:16:53 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/06 23:21:06 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void	count_c_e(struct s_game *g)
{
	int	x;
	int	y;
	int	c;

	g->move_new_line = ((y = -1), (c = 0), (g->c = 0), (g->move = 0), 0);
	while (g->mp[++y])
	{
		x = -1;
		while (g->mp[y][++x])
		{
			if (g->mp[y][x] == 'C')
				c++;
			else if (g->mp[y][x] == 'E')
			{
				g->xepostion = x;
				g->yepostion = y;
			}
			else if (g->mp[y][x] == 'P')
			{
				g->xpostion = x;
				g->ypostion = y;
			}
		}
	}
	g->coin = c;
}

void	put_img(struct s_game *g)
{
	g->y = -1;
	while (g->mp[++g->y])
	{
		g->x = -1;
		put_img_chyata(g);
	}
	count_c_e(g);
}

void	put_img_chyata(struct s_game *g)
{
	while (g->mp[g->y][++g->x])
	{
		if (g->mp[g->y][g->x] == '1')
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imgstone, g->x * 79, g->y * 79);
		else if (g->mp[g->y][g->x] == '0')
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imgtri9, g->x * 79, g->y * 79);
		else if (g->mp[g->y][g->x] == 'P')
		{
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imgtri9, g->x * 79, g->y * 79);
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imgplr, g->x * 79, g->y * 79);
		}
		else if (g->mp[g->y][g->x] == 'C')
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imgcoin, g->x * 79, g->y * 79);
		else if (g->mp[g->y][g->x] == 'E')
			mlx_put_image_to_window(g->mlx, g->mlx_wind,
				g->imghol, g->x * 79, g->y * 79);
	}
}
