/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:24 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/26 17:51:35 by ahavrank         ###   ########.fr       */
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

// double mapping_pixels(double new_max, double new_min, double old_max, double old_min, int i)
// {
//     double  resized_val;

//     resized_val = (new_max - new_min) * (i - old_min) / (old_max - old_min) + new_min;
//     return (resized_val);
// }

double mapping_pixels(double new_max, double new_min, double old_max, int i)
{
    double  resized_val;

    resized_val = (new_max - new_min) * (i - 0) / (old_max - 0) + new_min;
    return (resized_val);
}

// t_fractal *getting_formap(int x, int y, t_fractal *mandel)
// {
//     mandel->formap = malloc(sizeof(t_formap));
//     if (mandel->formap == NULL)
//         allocation_failed(mandel);
//     mandel->formap->x = x;
//     mandel->formap->y = y;
//     mandel->formap->zero = 0;
//     return (mandel);
// }

void mapping(int x, int y, t_fractal *mandel)
{
    int             i;
    int				color;
    int             iter;

    i = 0;
    // mandel = getting_formap(x, y, mandel);
    mandel->z->real = 0.0;
    mandel->z->im = 0.0;
	mandel->c->real = (mapping_pixels(2, -2, WIDTH, x) / mandel->zoom) + mandel->shift_x;
    mandel->c->im = (mapping_pixels(-2, 2, HEIGHT, y)/ mandel->zoom) + mandel->shift_y;
    iter =  mandel->iteration + (int)(mandel->zoom * 0.1);
    while (i < iter)
    {
    	mandel->z = addition_of_nb(square_of_nb(mandel->z), mandel->c);        
        if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) > 4) {
            color = mapping_pixels(BLUE, BABY_BLUE, 50, i + mandel->iteration);
            mlx_put_pixel(mandel->img, x, y, color);
			return ;
        }
        i++;
    }
    if (((mandel->z->real * mandel->z->real) + (mandel->z->im * mandel->z->im)) < 4){
    	mlx_put_pixel(mandel->img, x, y, ORANGE);
	}
}
