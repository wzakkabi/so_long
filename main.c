/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:13 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/06 23:44:38 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	putstr(char *a)
{
	int	x;

	x = -1;
	while (a[++x])
		write(1, &a[x], 1);
	return (0);
}

void	free_malloc(char **p, int not_struct, struct s_game *g)
{
	int	x;

	if (not_struct == 1)
	{
		mlx_destroy_image(g->mlx, g->imgstone);
		mlx_destroy_image(g->mlx, g->imghol);
		mlx_destroy_image(g->mlx, g->imgcoin);
		mlx_destroy_image(g->mlx, g->imgtri9);
		mlx_destroy_image(g->mlx, g->imgplr);
		free(g->mlx);
		g->x = -1;
		while (g->mp[++g->x])
			free(g->mp[g->x]);
		free(g->mp);
	}
	else
	{
		x = -1;
		while (p[++x])
			free(p[x]);
		free(p);
	}
}

int	test_map(char *file)
{
	char			**map;
	int				vld;
	struct s_strct	s;

	read_map(&map, file);
	vld = check_ecp(map, &s);
	if (vld == 1)
	{
		vld = -1;
		while (map[++vld])
			check_path(map, &vld, 0);
		vld = check_p_path_valid_or_not(map);
		free_malloc(map, 0, NULL);
		if (vld == 0)
		{
			putstr("path_invalid :(");
			exit(1);
		}
	}
	else
	{
		free_malloc(map, 0, NULL);
		exit(1);
	}
	return (1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		n = (n % 10 + '0');
		write(1, &n, 1);
	}
}

int	main(int ac, char **av)
{
	int		x;

	x = 0;
	if (ac == 2)
	{
		while (av[1] && av[1][x] != '.')
				x++;
		if (av[1][x] == '.' && av[1][x + 1] == 'b' && av[1][x + 2] == 'e' &&
		av[1][x + 3] == 'r')
		{
			x = test_map(av[1]);
			if (x == 1)
			{
				so_long(av[1]);
			}
			else
				return (0);
		}
	}
	return (0);
}
