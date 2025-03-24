/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:26:36 by anezka            #+#    #+#             */
/*   Updated: 2025/03/24 10:33:57 by anezka           ###   ########.fr       */
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
 	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_UP)){
		mandel->shift_y -= 0.5;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_DOWN)){
		mandel->shift_y += 0.5;
		putting_mandelbrot(mandel);
	}
	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_LEFT)){
		mandel->shift_x += 0.5;
		putting_mandelbrot(mandel);
	}

	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_RIGHT)){
		mandel->shift_x -= 0.5;
		putting_mandelbrot(mandel);
	}

	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_MINUS)){
		mandel->iteration -= 5;
		putting_mandelbrot(mandel);
	}

	else if (mlx_is_key_down(mandel->mlx, MLX_KEY_KP_ADD)){
		mandel->iteration += 5;
		putting_mandelbrot(mandel);
	}
}

void	scrooling(double xdelta, double ydelta, void *param)
{	
	t_fractal *mandel;

	(void)xdelta;
	
	mandel = param;
	if (ydelta > 0){
		mandel->zoom += ydelta;
		putting_mandelbrot(mandel);
	}
	else if (ydelta < 0){
		mandel->zoom += ydelta;
		putting_mandelbrot(mandel);
	}
}

void hooks_for_stuff(t_fractal *mandel)
{
	mlx_loop_hook(mandel->mlx, hoopmain, mandel);
	mlx_scroll_hook(mandel->mlx, scrooling, mandel);
//	mlx_resize_hook(mandel->mlx, resising, mandel);
	
}