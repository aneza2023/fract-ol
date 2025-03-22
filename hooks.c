/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:26:36 by anezka            #+#    #+#             */
/*   Updated: 2025/03/22 14:49:00 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	hoopmain(void *param)
{
	t_fractal *mandel;

	mandel = param;
	if (mlx_is_key_down(mandel->mlx, MLX_KEY_ESCAPE)){
		mlx_close_window(mandel->mlx);
		// free(mandel);		
	}
	
	
	// BONUS IF IT WORKS - works for a bit, later killed
/* 	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_UP))
		mandel->shift_y -= 0.5;
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_DOWN))
		mandel->shift_y += 0.5;
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_LEFT))
		mandel->shift_x += 0.5;
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_RIGHT))
		mandel->shift_x -= 0.5;
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_MINUS))
		mandel->iteration -= 10;
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_KP_ADD))
		mandel->iteration += 10; */
	putting_mandelbrot(mandel);
}

void	scrooling(double xdelta, double ydelta, void *param)
{	
	t_fractal *mandel;

	mandel = param;
	if (ydelta > 0)
		mandel->zoom += ydelta;
	else if (ydelta < 0)
		mandel->zoom += ydelta;
	if (xdelta != 0)
		write (1, "p", 2);
	
}

void hooks_for_stuff(t_fractal *mandel)
{
	mlx_loop_hook(mandel->mlx, hoopmain, mandel);
	mlx_scroll_hook(mandel->mlx, scrooling, mandel);

//	mlx_resize_hook(mandel->mlx, resising, mandel);
	
}