/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:24 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/18 16:10:13 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_nb *square_of_nb(t_complex_nb *z)
{
    t_complex_nb    *result;

    result = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (result == NULL)
    {
        printf("Error\n");
        return (NULL);
    }
    result->real = (z->real * z->real) - (z->im * z->im);
    result->im = (2 * z->real * z->im);
    return (result);
}

t_complex_nb *addition_of_nb(t_complex_nb *z, t_complex_nb *c)
{
    t_complex_nb    *result;

    result = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (result == NULL)
    {
        printf("Error\n");
        return (NULL);
    }
    result->real = z->real + c->real;
    result->im = z->im + c->im;
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
    int				color;
    t_complex_nb    *z;
    t_complex_nb    *c;

    i = 0;
    z = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    c = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (c == NULL || z == NULL)
    {
        printf("Error\n");
        return ;
    }
    z->im = 0.0;
    z->real = 0.0;
/* 	mandel->shift_x = 0.0;
	mandel->shift_y = 0.0;
	mandel->iteration = 0; */
    c->real = mapping_pixels(2, -2, WIDTH, 0, x) + mandel->shift_x;
    c->im = mapping_pixels(-2, 2, HEIGHT, 0, y) + mandel->shift_y;
    while (i < 300)
    {
        z = addition_of_nb(square_of_nb(z), c);        
        if (((z->real * z->real) + (z->im * z->im)) > 4) {
            color = mapping_pixels(0xFFFFFF, 0x000000, 50, 0, i + mandel->iteration);
            mlx_put_pixel(mandel->img, x, y, color);
			return ;
        }
        i++;
    }
    if (((z->real * z->real) + (z->im * z->im)) < 4) 
        mlx_put_pixel(mandel->img, x, y, 0x39FF14);
}
