/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:13 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/18 15:20:05 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"


void free_chyata(char **p)
{
	int x = 0;

	while(p[x])
	{
		free(p[x]);
		x++;
	}
}

int checkmaps(char *av)
{
	struct cnt date;

	date.p = read_maps(open("map.ber", O_RDONLY));
	date.a = check_P_C_E(date.p);
	if(date.a == 1)
	{
		while(date.p[++date.i])
			check_path(date.p, &date.i, 0);
		date.x = ft_checkp(date.p);
		if(date.x == 0)
		{
			free_chyata(date.p);
			return 1;
		}
		else if(date.x == 1)
			printf("error player cant collect all the collectible");
		else if(date.x == 2)
			printf("error there is some other carracter in the map :(");
	}
	else if (date.a == 0)
		printf("check the '1' in the frest or last in every line");
	else if (date.a == 2)
		printf("check C or P of E");
	else if (date.a == 3)
		printf("check the 1 in the last and first line");
	free_chyata(date.p);
	return 0;
}

int	main(int ac, char **av)
{
	struct cnt date;
	if(ac == 2)
	{
		date.x = 0;
		while(av[1][date.x])
			date.x++;
		if(av[1][date.x - 1] == 'r' && av[1][date.x - 2] == 'e' && av[1][date.x - 3] == 'b' && av[1][date.x - 4] == '.')
			printf("succes");
	}
	return 0;
}