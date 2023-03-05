/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/05 20:18:39 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

// w = 13
// a = 0
// s = 1
// d = 2
// esc = 53

void move_gg(struct game *g)
{
	mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->xEpostion * 79, g->yEpostion * 79);
	mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->xpostion * 79, g->ypostion * 79);
	if(g->mp[g->ypostion][g->xpostion] == 'C')
	{
		g->C++;
		g->mp[g->ypostion][g->xpostion] = '0';
	}
	if(g->C == g->coin && g->mp[g->ypostion][g->xpostion] == 'E')
	{
		mlx_clear_window(g->mlx, g->mlx_wind);
		mlx_destroy_window(g->mlx, g->mlx_wind);
		free_malloc(g->mp);
		exit(1);
	}
}

int test(int key, struct game *g)
{
	if(key == 13 && g->mp[g->ypostion - 1][g->xpostion] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion * 79, g->ypostion-- * 79);
	else if(key == 1 && g->mp[g->ypostion + 1][g->xpostion] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion * 79, g->ypostion++ * 79);
	else if(key == 0 && g->mp[g->ypostion][g->xpostion - 1] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion-- * 79, g->ypostion * 79);
	else if(key == 2 && g->mp[g->ypostion][g->xpostion + 1] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion++ * 79, g->ypostion * 79);

	else if(key == 53 && g->mp[g->ypostion + 1][g->xpostion] != '1')
	{
		mlx_clear_window(g->mlx, g->mlx_wind);
		mlx_destroy_window(g->mlx, g->mlx_wind);
		free_malloc(g->mp);
		exit(1);
	}
	if(key == 53 || key == 13 || key == 1 || key == 0 || key == 2)
		move_gg(g);
	return 0;
}

void count_C_E(struct game *g)
{
	int x;
	int y;
	int c;
	
	g->move = 0;
	x = ((y = -1), (c = 0), -1);
	g->C = 0;

	while(g->mp[++y])
	{
		while(g->mp[y][++x])
		{
			if(g->mp[y][x] == 'C')
				c++;
			else if (g->mp[y][x] == 'E')
			{
				g->xEpostion = x;
				g->yEpostion = y;
			}
			else if (g->mp[y][x] == 'P')
			{
				g->xpostion = x;
				g->ypostion = y;
			}
		}
		x = -1;
	}
	g->coin = c;
}

void put_img(struct game *g)
{
	g->y = -1;
	while(g->mp[++g->y])
	{
		g->x = -1;
		while(g->mp[g->y][++g->x])
		{
			if(g->mp[g->y][g->x] == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgstone, g->x * 79, g->y * 79);
			else if(g->mp[g->y][g->x] == '0')
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->x * 79, g->y * 79);
			else if(g->mp[g->y][g->x] == 'P')
			{
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->x * 79, g->y * 79);
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->x * 79, g->y * 79);
			}
			else if(g->mp[g->y][g->x] == 'C')
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgcoin, g->x * 79, g->y * 79);
			else if(g->mp[g->y][g->x] == 'E')
				mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->x * 79, g->y * 79);
		}
	}
	count_C_E(g);
}

void so_long(char *file)
{
	struct game g;
	
	read_map(&g.mp, file);
	g.x = ft_strlen(g.mp[0]);
	g.y = 0;
	while(g.mp[g.y])
		g.y++;
	if(g.x > 32 || g.y > 16)
	{
		write(1,"x and y not rghit ;(", 20);
		return ;
	}
	g.mlx = mlx_init();
	g.imgstone = mlx_xpm_file_to_image(g.mlx, "./xpm/stone.xpm", &g.img_width, &g.img_height);
	g.imgplr = mlx_xpm_file_to_image(g.mlx, "./xpm/player.xpm", &g.img_width, &g.img_height);
	g.imgtri9 = mlx_xpm_file_to_image(g.mlx, "./xpm/tri9.xpm", &g.img_width, &g.img_height);
	g.imgcoin = mlx_xpm_file_to_image(g.mlx, "./xpm/coin.xpm", &g.img_width, &g.img_height);
	g.imghol = mlx_xpm_file_to_image(g.mlx, "./xpm/hol.xpm", &g.img_width, &g.img_height);
	g.mlx_wind = mlx_new_window(g.mlx, g.x * 79, g.y * 79, "so_long");
	put_img(&g);
	mlx_key_hook(g.mlx_wind, test, &g);
	mlx_loop(g.mlx);
}










// void so_long(char **mp)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx,1920, 1080, "so_long");
// 	// t_img.img = 
	
// 	img = mlx_xpm_file_to_image(mlx, "MiConv.com__New Project.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx,  mlx_win, img, 0, 0);
// 	mlx_loop(mlx);
// }

// int test(int key, struct game *g)
// {
// 	if(key == 13 && g->mp[g->ypostion - 1][g->xpostion] != '1')
// 	{
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion * 79, g->ypostion-- * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->xEpostion * 79, g->yEpostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->xpostion * 79, g->ypostion * 79);
// 	}
// 	else if(key == 1 && g->mp[g->ypostion + 1][g->xpostion] != '1')
// 	{
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion * 79, g->ypostion++ * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->xEpostion * 79, g->yEpostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->xpostion * 79, g->ypostion * 79);
// 	}
// 	else if(key == 0 && g->mp[g->ypostion][g->xpostion - 1] != '1')
// 	{
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion-- * 79, g->ypostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->xEpostion * 79, g->yEpostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->xpostion * 79, g->ypostion * 79);
// 	}
// 	else if(key == 2 && g->mp[g->ypostion][g->xpostion + 1] != '1')
// 	{
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgtri9, g->xpostion++ * 79, g->ypostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imghol, g->xEpostion * 79, g->yEpostion * 79);
// 		mlx_put_image_to_window(g->mlx, g->mlx_wind, g->imgplr, g->xpostion * 79, g->ypostion * 79);
// 	}
// 	else if(key == 53 && g->mp[g->ypostion + 1][g->xpostion] != '1')
// 	{
		
// 	}
// 	return 0;
// }
