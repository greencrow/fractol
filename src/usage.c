/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:25:14 by svigouro          #+#    #+#             */
/*   Updated: 2018/04/06 12:05:23 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(int error)
{
	if (error == 0)
	{
		ft_putstr_fd("Usage: ./fractol [julia | mandelbrot | newton", 2);
		ft_putstr_fd("| burningship | multibrot]", 2);
	}
	else if (error == 1)
		ft_putendl_fd("Mlx error, verify environement...", 2);
	exit(0);
}
