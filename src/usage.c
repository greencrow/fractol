/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:25:14 by svigouro          #+#    #+#             */
/*   Updated: 2018/04/05 13:25:23 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(int error)
{
	if (error == 0)
	{
		ft_putstr_fd("Usage: ./fractol [julia | mandelbrot ", 2);
		ft_putstr_fd("| newton | burningship | multibrot | juliux ", 2);
		ft_putendl_fd("| celtic | bird]", 2);
	}
	else if (error == 1)
		ft_putendl_fd("Mlx error, verify environement...", 2);
	exit(0);
}
