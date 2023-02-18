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

int	main()
{
	struct cnt date;
	date.i = 0;
	date.p = read_maps(open("map.ber", O_RDONLY));
	int a = check_P_C_E(open("map.ber", O_RDONLY));
	if(a == 1)
		{
			while(date.p[++date.i])
				check_path(date.p, &date.i, 0);
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