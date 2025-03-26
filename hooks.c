/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:26:36 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 19:09:38 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shifting(void *param)
{
	t_fractal	*mandel;

	mandel = param;
	if (mlx_is_key_down(mandel->mlx, MLX_KEY_UP))
	{
		mandel->shift_y += 0.1 / mandel->zoom;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_DOWN))
	{
		mandel->shift_y -= 0.1 / mandel->zoom;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_LEFT))
	{
		mandel->shift_x -= 0.1 / mandel->zoom;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_RIGHT))
	{
		mandel->shift_x += 0.1 / mandel->zoom;
		putting_mandelbrot(mandel);
	}
}

void	escaping(void *param)
{
	t_fractal	*mandel;

	mandel = param;
	if (mlx_is_key_down(mandel->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mandel->mlx);
		correct_ending(mandel);
	}
}

void	iterating(void *param)
{
	t_fractal	*mandel;

	mandel = param;
	if (mlx_is_key_down(mandel->mlx, MLX_KEY_KP_SUBTRACT))
	{
		mandel->ite -= 5;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_KP_ADD))
	{
		mandel->ite += 5;
		putting_mandelbrot(mandel);
	}
}

void	scrooling(double xdelta, double ydelta, void *param)
{
	t_fractal	*mandel;

	(void)xdelta;
	mandel = param;
	if (ydelta > 0)
	{
		mandel->zoom *= 1.1;
		putting_mandelbrot(mandel);
	}
	else if (ydelta < 0)
	{
		mandel->zoom /= 1.1;
		putting_mandelbrot(mandel);
	}
}

void	hooks_for_stuff(t_fractal *mandel)
{
	mlx_loop_hook(mandel->mlx, shifting, mandel);
	mlx_loop_hook(mandel->mlx, escaping, mandel);
	mlx_loop_hook(mandel->mlx, iterating, mandel);
	mlx_scroll_hook(mandel->mlx, scrooling, mandel);
	mlx_close_hook(mandel->mlx, correct_ending, mandel);
}
