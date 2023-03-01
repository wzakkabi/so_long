/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:13 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/28 23:05:05 by wzakkabi         ###   ########.fr       */
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
void free_malloc(char **p)
{
	int x = -1;

	while(p[++x])
		free(p[x]);
	free(p);
}
int test_map(char *file)
{
	char **map;
	int vld;
	struct strct s;
	int x = 0;
	read_map(&map, file);
	vld = check_ecp(map, s);
	if(vld == 1)
	{
		vld = 0;
		while(map[vld])
		{
			check_path(map, &vld, 0);
			vld++;
		}
		vld = check_p_path_valid_or_not(map);
		if(vld == 0)
		{
			free_malloc(map);
			return putstr("path_invalid :(");
		}
	}
	else
		free_malloc(map);
	return 1;
}

int main(int ac, char **av)
{
	int x = 0;
	char **p;
	if(ac == 2)
	{
		while(av[1] && av[1][x] != '.')
				x++;
		if(av[1][x] == '.' && av[1][x + 1] == 'b' && av[1][x + 2] == 'e' && av[1][x + 3] == 'r')
		{
			x = test_map(av[1]);
			if(x == 1)
			{
				read_map(&p, av[1]);
				so_long(p);
			}
			else
				return 0;
		}
	}
	return 0;
}