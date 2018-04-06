/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:57:32 by svigouro          #+#    #+#             */
/*   Updated: 2018/04/06 12:57:33 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *e, void (*fractal)(t_fractal *f))
{
	mlx_clear_window(e->mlx, e->win);
	init_point(&e->f.p);
	while (++e->f.p.x < WIDTH)
	{
		while (++e->f.p.y < HEIGHT)
		{
			fractal(&e->f);
			color_point(&e->f);
			put_pixel(e->f.p.x, e->f.p.y, e->f.p.color, e);
		}
		e->f.p.y = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->f.text)
		text(e);
}

void	redraw(t_env *e)
{
	if (e->f.type == JULIA)
		draw(e, ft_julia);
	else if (e->f.type == MANDEL)
		draw(e, ft_mandelbrot);
	else if (e->f.type == NEWTON)
		draw(e, ft_newton);
	else if (e->f.type == BURN)
		draw(e, ft_burn);
	else if (e->f.type == MULTI)
		draw(e, ft_multibrot);
}
