/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/14 13:22:48 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "./gg/get_next_line.h"
#include <unistd.h>

void	check_path(char **mp, int y, int x)
{
	
	while (mp[y])
	{
		while (mp[y][x])
		{
			if ((mp[y][x] == 'P' && mp[y][x + 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x + 1] == 'C') || (mp[y][x] == 'P' && mp[y][x + 1] == 'E'))
				mp[y][x + 1] = 'P';
			if ((mp[y][x] == 'P' && mp[y][x - 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x - 1] == 'C') || (mp[y][x] == 'P' && mp[y][x - 1] == 'E'))
				mp[y][x - 1] = 'P';
			if ((mp[y][x] == 'P' && mp[y + 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y + 1][x] == 'C') || (mp[y][x] == 'P' && mp[y + 1][x] == 'E'))
				mp[y + 1][x] = 'P';
			if ((mp[y][x] == 'P' && mp[y - 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y - 1][x] == 'C') || (mp[y][x] == 'P' && mp[y - 1][x] == 'E'))
				mp[y - 1][x] = 'P';
			x++;
		}
		x = 0;
		y++;
	}
}


int	main()
{
	int fd = open("map.ber", O_RDONLY);
	char **p;
	int x = 0;
	int line = 0;
	int plr = 0;
	int E = 0;
	int C = 0;
	int y;
	int xy;
	
	while(1)
	{
		p[x] = get_next_line(fd);
		if(p[x] == 0)
			break;
		line = ft_strlen(p[0]);
		if(line != ft_strlen(p[x]) || p[x][line-1] != '1' || p[x][0] != '1')
			return printf("error check the maps");
		line = 0;
		while(p[x][line])
		{
			if(p[x][line] == 'P')
			{
				xy = line;
				y = x;
				plr++;
			}
			else if (p[x][line] == 'E')
				E++;
			else if (p[x][line] == 'C')
				C++;
			line++;
		}
		x++;
	}
	if(plr != 1 || E != 1 || C < 1)
	{
		printf("check P or E or C");
		return 0;
	}
	int i =0;
	while(i < 100)
	{
		check_path(p , 0, 0);
		i++;
	}
	i = 0;
	while(i < x)
		printf("%s\n", p[i++]);
	return 0;
}
