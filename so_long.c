/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/06 23:18:42 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

// w = 13
// a = 0
// s = 1
// d = 2
// esc = 53
void	so_long(char *file)
{
	struct s_game	g;

	read_map(&g.mp, file);
	g.x = ft_strlen(g.mp[0]);
	g.y = 0;
	while (g.mp[g.y])
		g.y++;
	if (g.x > 32 || g.y > 16)
	{
		write(1, "x and y not rghit 👀", 22);
		free_malloc(g.mp, 0, NULL);
		exit(1);
	}
	put_xpm_to_pointer(&g);
	put_img(&g);
	mlx_key_hook(g.mlx_wind, test, &g);
	mlx_hook(g.mlx_wind, 17, 0, ft_close, &g);
	mlx_loop(g.mlx);
}

void	put_xpm_to_pointer(struct s_game *g)
{
	g->mlx = mlx_init();
	g->imgstone = mlx_xpm_file_to_image(g->mlx,
			"./extures/stone.xpm", &g->img_width, &g->img_height);
	g->imgplr = mlx_xpm_file_to_image(g->mlx,
			"./extures/player.xpm", &g->img_width, &g->img_height);
	g->imgtri9 = mlx_xpm_file_to_image(g->mlx,
			"./extures/tri9.xpm", &g->img_width, &g->img_height);
	g->imgcoin = mlx_xpm_file_to_image(g->mlx,
			"./extures/coin.xpm", &g->img_width, &g->img_height);
	g->imghol = mlx_xpm_file_to_image(g->mlx,
			"./extures/hol.xpm", &g->img_width, &g->img_height);
	g->mlx_wind = mlx_new_window(g->mlx, g->x * 79,
			g->y * 79, "so_long");
}

void	move_gg(struct s_game *g)
{
	mlx_put_image_to_window(g->mlx, g->mlx_wind,
		g->imgtri9, g->xpostion * 79, g->ypostion * 79);
	mlx_put_image_to_window(g->mlx, g->mlx_wind,
		g->imghol, g->xepostion * 79, g->yepostion * 79);
	mlx_put_image_to_window(g->mlx, g->mlx_wind,
		g->imgplr, g->xpostion * 79, g->ypostion * 79);
	if (g->move != g->move_new_line)
	{
		write(1, "\n", 1);
		g->move_new_line = g->move;
	}
	if (g->mp[g->ypostion][g->xpostion] == 'C')
	{
		g->c++;
		g->mp[g->ypostion][g->xpostion] = '0';
	}
	if (g->c == g->coin && g->mp[g->ypostion][g->xpostion] == 'E')
	{
		mlx_destroy_window(g->mlx, g->mlx_wind);
		free_malloc(NULL, 1, g);
		exit(0);
	}
}

int	ft_close(struct s_game *g)
{
	write(1, "7ytiha 🤬", 11);
	mlx_destroy_window(g->mlx, g->mlx_wind);
	free_malloc(NULL, 1, g);
	exit(1);
	return (0);
}

int	test(int key, struct s_game *g)
{
	if (key == 13 && g->mp[g->ypostion - 1][g->xpostion] != '1')
		ft_putnbr(++g->move);
	else if (key == 1 && g->mp[g->ypostion + 1][g->xpostion] != '1')
		ft_putnbr(++g->move);
	else if (key == 0 && g->mp[g->ypostion][g->xpostion - 1] != '1')
		ft_putnbr(++g->move);
	else if (key == 2 && g->mp[g->ypostion][g->xpostion + 1] != '1')
		ft_putnbr(++g->move);
	if (key == 13 && g->mp[g->ypostion - 1][g->xpostion] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind,
			g->imgtri9, g->xpostion * 79, (g->ypostion--) * 79);
	else if (key == 1 && g->mp[g->ypostion + 1][g->xpostion] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind,
			g->imgtri9, g->xpostion * 79, (g->ypostion++) * 79);
	else if (key == 0 && g->mp[g->ypostion][g->xpostion - 1] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind,
			g->imgtri9, (g->xpostion--) * 79, g->ypostion * 79);
	else if (key == 2 && g->mp[g->ypostion][g->xpostion + 1] != '1')
		mlx_put_image_to_window(g->mlx, g->mlx_wind,
			g->imgtri9, (g->xpostion++) * 79, g->ypostion * 79);
	else if (key == 53)
		ft_close(g);
	if (key == 53 || key == 13 || key == 1 || key == 0 || key == 2)
		move_gg(g);
	return (0);
}
