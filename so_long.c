/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/12 01:22:33 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "./gg/get_next_line.h"

void check_path(char **mp , int line,int *C, int *E)
{
	int x = 0;
	int p = 0;
	while(mp[x]&& x <= line)
	{
		if(mp[x][p] == 'P');
			{
				if(mp[x][p + 1] == '0')
					{
						
						break;
					}
			}
		printf("g");
		x++;
	}
	printf("q");
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
	int cc = 0;
	int ee = 0;

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
				plr++;
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
	check_path(p , x, &cc, &ee);
	if(cc == C && ee == 1)
	{
		printf("good job azin ;)");
	}
	return 0;
}
