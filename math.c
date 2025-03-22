/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:24 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/22 18:43:31 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_nb *square_of_nb(t_complex_nb *z)
{
    t_complex_nb    *result;

    result = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (result == NULL)
		allocation_failed(result);
    result->real = (z->real * z->real) - (z->im * z->im);
    result->im = (2 * z->real * z->im);
    return (result);
}

t_complex_nb *addition_of_nb(t_complex_nb *z, t_complex_nb *c)
{
    t_complex_nb    *result;

    result = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (result == NULL)
		allocation_failed(result);
    result->real = z->real + c->real;
    result->im = z->im + c->im;
	printf("%f", result->real);
    return (result);
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
//    int				color;

    i = 0;
	(void)x;
	(void)y;
	(void)mandel;
	// mapping pixels / zoom + shift;
	mandel->c->real = mapping_pixels(2, -2, WIDTH, 0, x);
    mandel->c->im = mapping_pixels(-2, 2, HEIGHT, 0, y);
	mandel->z = addition_of_nb(square_of_nb(mandel->z), mandel->c); 
/*     while (i < 2)
    {
    	mandel->z = addition_of_nb(square_of_nb(mandel->z), mandel->c);        
        if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) > 4) {
            color = mapping_pixels(BLUE, GREEN, 50, 0, i + mandel->iteration);
            mlx_put_pixel(mandel->img, x, y, color);
			return ;
        }
        i++;
    }
    if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) < 4){
    	mlx_put_pixel(mandel->img, x, y, MAROON);
	}
	putting_mandelbrot(mandel); */
}
