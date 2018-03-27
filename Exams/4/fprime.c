/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhusak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:09:40 by rhusak            #+#    #+#             */
/*   Updated: 2018/03/25 13:23:06 by rhusak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int num;
	int z;
	
	z = 2;
	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		while (num > 1)
		{
			while (num % z == 0)
			{				
				num = num / z;
				printf("%i", z);
				if (num > 1)
					printf("*");
			}
			z++;
		}
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}
