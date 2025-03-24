/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:59 by anezka            #+#    #+#             */
/*   Updated: 2025/03/24 15:44:53 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mapp_julia(int x, int y, t_fractal *julia)
{
	int i;
	int color;

	i = 0;
	julia->z->real = mapping_pixels(2, -2, WIDTH, 0, x) / julia->zoom + julia->shift_x;
    julia->z->im = mapping_pixels(-2, 2, HEIGHT, 0, y)/ julia->zoom + julia->shift_y;
	while (i < julia->iteration)
    {
    	julia->z = addition_of_nb(square_of_nb(julia->z), julia->c);        
        if (((julia->z->real * julia->z->real) + (julia->z->im * julia->z->im)) > 4) {
            color = mapping_pixels(BLUE, GREEN, 50, 0, i + julia->iteration);
            mlx_put_pixel(julia->img, x, y, color);
			return ;
        }
        i++;
    }
    if (((julia->z->real * julia->z->real) + (julia->z->im * julia->z->im)) < 4){
    	mlx_put_pixel(julia->img, x, y, ORANGE);
	}
}

int	kickoff_julia(double real, double im)
{
	mlx_t		*julia_con;
	t_fractal	*julia;

	julia = (t_fractal *)malloc(sizeof(t_fractal *));
	if (julia == NULL)
		allocation_failed(julia);
	julia_con = mlx_init(WIDTH, HEIGHT, "Julia", true);
	if (julia_con == NULL)
		allocation_failed(julia_con);
	julia->mlx = julia_con;
	julia->c = malloc(sizeof(t_complex_nb));
	if (julia->c == NULL)
		allocation_failed(julia->c);
	julia->c->real = real;
	julia->c->im = im;
	julia->mandelbrot = 0;
	julia = putting_val(julia);
	create_window(julia);
	hooks_for_stuff(julia);
	mlx_loop(julia->mlx);
	mlx_terminate(julia_con);
//	correct_ending(julia);
	return (0);
}
