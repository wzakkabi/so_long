/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/17 16:18:06 by wzakkabi         ###   ########.fr       */
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
	int y;
};

int ft_checkp(char **p)
{
	struct cnt date;
	
	date.i = 0;
	date.x = 0;
	while(p[date.i])
	{
		while(p[date.i][date.x])
		{
			if(p[date.i][date.x] == 'E' || p[date.i][date.x] == 'C')
				return 1;
			date.x++;
		}
		date.x = 0;
		date.i++;
	}
	return 0;
}

void	check_path(char **mp, int y, int x)
{
	struct cnt date;
	while (mp[++y])
	{
		while (mp[y][++x])
		{
			date.x = 0;
			date.y = 0;
			if ((mp[y][x] == 'P' && mp[y][x + 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x + 1] == 'C') || (mp[y][x] == 'P' && mp[y][x + 1] == 'E'))
				mp[y][x + ++date.x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y][x - 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x - 1] == 'C') || (mp[y][x] == 'P' && mp[y][x - 1] == 'E'))
				mp[y][x - ++date.x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y + 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y + 1][x] == 'C') || (mp[y][x] == 'P' && mp[y + 1][x] == 'E'))
				mp[y + ++date.y][x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y - 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y - 1][x] == 'C') || (mp[y][x] == 'P' && mp[y - 1][x] == 'E'))
				mp[y - ++date.y][x] = 'P';
			if(date.x != 0)
				x = 0;
			if(date.y != 0)
				y = 0;
		}
		x = 0;
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
	if(date.E != 1 || date.plr != 1 || date.C < 1)
		return 2;
	if(check_line_first_and_last(date.p[0]) == 0 || check_line_first_and_last(date.p[date.i - 1]) == 0)
		return 3;
	return 1;
}

char **read_maps(fd)
{
	struct cnt date;

	date.x = 0;
	while(1)
	{
		date.p[date.x] = get_next_line(fd);
		if(date.p[date.x] == 0)
			break;
		date.x++;
	}
	return date.p;
}

int	main()
{
	struct cnt date;
	date.i = 0;
	date.p = read_maps(open("map.ber", O_RDONLY));
	int a = check_P_C_E(open("map.ber", O_RDONLY));
	if(a == 1)
		{
			check_path(date.p, 0, 0);
			date.x = ft_checkp(date.p);
		}
	else if (a == 0)
		printf("check the '1' in the frest or last in every line");
	else if (a == 2)
		printf("check C or P of E");
	else if ( a == 3)
		printf("check the 1 in the last and first line");
	printf("%d\n", date.x);
	date.i = 0;
	while(date.p[date.i])
		printf("%s\n", date.p[date.i++]);
	return 0;
}
