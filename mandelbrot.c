/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:50:04 by anezka            #+#    #+#             */
/*   Updated: 2025/03/19 11:08:37 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*putting_val(t_fractal *mandel)
{
	mandel->zx = 0.0;
	mandel->zy = 0.0;
	mandel->iteration = 0;
	mandel->shift_x = 0.0;
	mandel->shift_y = 0.0;
	return (mandel);
}

int putting_mandelbrot(t_fractal *mandel)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mapping(x, y, mandel);
			y++;
		}
		x++;
	}	
	return (0);
}	

int	create_window(t_fractal *mandel)
{
    mlx_image_t *mandel_set;

	mandel_set = mlx_new_image(mandel->mlx, WIDTH, HEIGHT);
	if (mandel_set == NULL)
		allocation_failed(mandel_set);
	mandel->img = mandel_set;
	mlx_image_to_window(mandel->mlx, mandel->img, 0, 0);
	putting_mandelbrot(mandel);
	return (0);
}

int kickoff_mandelbrot()
{
    mlx_t       *mandelbrot;
	t_fractal	*mandel;

	mandel = (t_fractal *)malloc(sizeof(t_fractal *));
	if (mandel == NULL)
		allocation_failed(mandel);
	mandelbrot = mlx_init(WIDTH, HEIGHT, "mandelbrot", true);
	if (mandelbrot == NULL)
		allocation_failed(mandelbrot);
	mandel->mlx = mandelbrot;
	mandel = putting_val(mandel);
	create_window(mandel);
	hooks_for_stuff(mandel);
//	mlx_loop_hook(mandel->mlx, hoopmain, mandel);
	mlx_loop(mandel->mlx);
	mlx_terminate(mandelbrot);
	return (0);
}
