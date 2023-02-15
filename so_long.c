/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/15 18:28:50 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "./gg/get_next_line.h"
#include <unistd.h>


struct cnt
{
	char **p;
	int plr;
	int E;
	int C;
	int x;
	int line;
	int i;
};

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

int check_line_first_and_last(char *p)
{
	int x = 0;
	if(!p)
		return 0;
	while(p[x])
	{
		if(p[x] != '1')
			return 0;
		x++;
	}
	return 1;
}

int check_P_C_E(int fd)
{
	struct cnt date;
	
	date.x = 0;
	date.E = 0;
	date.C = 0;
	date.plr = 0;
	date.i = 0;
	while(date.p[date.i])
	{
		date.p[date.i] = get_next_line(fd);
		if(!date.p[date.i])
			break;
		date.line = ft_strlen(date.p[0]);
		if(date.line != ft_strlen(date.p[date.i]) || date.p[date.i][0] != '1' || date.p[date.i][date.line - 1] != '1')
			return 0;
		date.x = 0;
		while(date.p[date.i][date.x])
		{
			if(date.p[date.i][date.x] == 'P')
				date.plr++;
			else if(date.p[date.i][date.x] == 'C')
				date.C++;
			else if(date.p[date.i][date.x] == 'E')
				date.E++;
			date.x++;
		}
		date.i++;
	}
	if(date.E != 1 || date.plr != 1 || date.C <= 1)
	{
		printf("check P or E or C");
		return 2;
	}
	if(check_line_first_and_last(date.p[0]) == 0 || check_line_first_and_last(date.p[date.i - 1]) == 0)
		return 3;
	return 1;
}

char **read_maps(fd);
{
	struct cnt date;

	date.x = 0;
	while(date.p[date.x])
	{
		date.p[date.x] = get_next_line(fd);
		date.x++;
	}
	return date.p;
}

int checkp(int fd)
{
	struct cnt date;
	
	
}


int	main()
{
	struct cnt date;
	
	int a = check_P_C_E(open("map.ber", O_RDONLY));
	if(a == 1)
		checkp(open("map.ber", O_RDONLY))
	return 0;
}
