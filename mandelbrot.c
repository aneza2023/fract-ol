/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:50:04 by anezka            #+#    #+#             */
/*   Updated: 2025/03/12 19:08:50 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int putting_mandelbrot(t_fractal *mandel)
{
/* 	int		i;
	int		k;

	i = 0;
	while (i < WIDTH)
	{
		k = 0;
		while (k < HEIGHT)
		{
			mlx_put_pixel(mandel->img, k, i, 0xFF2600FF);
			k++;
		}
		i++;
	} */

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
	{
		printf("Error\n");
		return (1);
	}
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
	{
		printf("Error\n");
		return (1);
	}
	mandelbrot = mlx_init(WIDTH, HEIGHT, "mandelbrot", true);
	if (mandelbrot == NULL)
	{
		printf("Error\n");
		return (1);
	}
	mandel->mlx = mandelbrot;
	create_window(mandel);
	mlx_loop_hook(mandel->mlx, hoopmain, mandel);
	mlx_loop(mandel->mlx);
//	mlx_terminate(mandelbrot);
	return (0);
}
