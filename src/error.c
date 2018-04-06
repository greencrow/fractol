/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:42:27 by svigouro          #+#    #+#             */
/*   Updated: 2018/04/06 12:42:29 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		error(int id)
{
	if (id == 0)
	{
		ft_putstr_fd("Usage: ./fractol [julia | mandelbrot | newton ", 2);
		ft_putstr_fd("| burningship | multibrot]", 2);
	}
	else if (id == 1)
		ft_putendl_fd("Mlx error, verify environement...", 2);
	return (1);
}
