/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:35:08 by gfragoso          #+#    #+#             */
/*   Updated: 2024/09/24 22:41:11 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_point	test;

	(void)argv;
	(void)argc;
	test = ft_point_new(10.39423914, -20.309459);
	test = ft_point_mult(test, test);
	printf("%f %f\n", test.x, test.y);
	return (SUCCESS);
}
