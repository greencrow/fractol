/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:38:24 by svigouro          #+#    #+#             */
/*   Updated: 2018/04/06 12:50:17 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, int color, t_env *e)
{
	if (y < HEIGHT && x < WIDTH &&
			y >= 0 && x >= 0)
		e->data[y * WIDTH + x] = color;
}

void	init_point(t_point *p)
{
	p->x = -1;
	p->y = -1;
	p->z = -1;
	p->color = 0xFFFFFF;
}

int		init(t_env *e, char *arg)
{
	char	*title;

	arg[0] = ft_toupper(arg[0]);
	title = ft_strjoin("Fractol\t-\t", arg);
	arg[0] = ft_tolower(arg[0]);
	if (!(e->mlx = mlx_init()))
		return (-1);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, title);
	free(title);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
	return (0);
}

void	reset(t_env *e)
{
	if (e->f.type == NEWTON)
		newton_init(&e->f);
	else if (e->f.type == MANDEL)
		mandel_init(&e->f);
	else if (e->f.type == JULIA)
		julia_init(&e->f);
	else if (e->f.type == BURN)
		burn_init(&e->f);
	else if (e->f.type == MULTI)
		multi_init(&e->f);
	redraw(e);
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc != 2)
		return (error(0));
	if (ft_strcmp(argv[1], "newton") && ft_strcmp(argv[1], "julia") &&
		ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "burningship") &&
		ft_strcmp(argv[1], "multibrot"))
		return (error(0));
	if (init(&e, argv[1]) < 0)
		return (error(1));
	choice(argv[1], &e);
	hooks(&e);
}
