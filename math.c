/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:24 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:07 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_nb *square_of_nb(t_complex_nb *z)
{
    double  temp;

    temp = (z->real * z->real) - (z->im * z->im);
    z->im = (2 * z->real * z->im);
    z->real = temp;
    return (z);
}

t_complex_nb *addition_of_nb(t_complex_nb *z, t_complex_nb *c)
{
    z->real = z->real + c->real;
    z->im = z->im + c->im;
    return (z);
}

double mapping_pixels(double new_max, double new_min, double old_max, double old_min, int i)
{
    double  resized_val;

    resized_val = (new_max - new_min) * (i - old_min) / (old_max - old_min) + new_min;
    return (resized_val);
}

void mapping(int x, int y, t_fractal *mandel)
{
    int             i;
    int				color;

    i = 0;
    mandel->z->real = 0.0;
    mandel->z->im = 0.0;
	mandel->c->real = mapping_pixels(2, -2, WIDTH, 0, x) / mandel->zoom + mandel->shift_x;
    mandel->c->im = mapping_pixels(-2, 2, HEIGHT, 0, y)/ mandel->zoom + mandel->shift_y;
    while (i < mandel->iteration)
    {
    	mandel->z = addition_of_nb(square_of_nb(mandel->z), mandel->c);        
        if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) > 4) {
            color = mapping_pixels(BLUE, BABY_BLUE, 50, 0, i + mandel->iteration);
            mlx_put_pixel(mandel->img, x, y, color);
			return ;
        }
        i++;
    }
    if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) < 4){
    	mlx_put_pixel(mandel->img, x, y, ORANGE);
	}
}
