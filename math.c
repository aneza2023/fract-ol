/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:58:24 by ahavrank          #+#    #+#             */
/*   Updated: 2025/03/12 19:33:25 by ahavrank         ###   ########.fr       */
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
    t_complex_nb    *z;
    t_complex_nb    *c;

    i = 0;
    z = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (z == NULL)
    {
        printf("Error\n");
        return ;
    }
    c = (t_complex_nb *)malloc(sizeof(t_complex_nb *));
    if (c == NULL)
    {
        printf("Error\n");
        return ;
    }
    z->im = 0.0;
    z->real = 0.0;
    c->im = mapping_pixels(2, -2, WIDTH, y, i);
    c->real = mapping_pixels(-2, 2, HEIGHT, x, i);
    while (i < 50)
    {
        z = addition_of_nb(square_of_nb(z), c);
        printf("%f ", c->real);
        printf("%f\n", c->im);
        // if (c->real < 0 || c->im < 0) {
        //     i++;
        //     continue;
        // }
        if (((z->real * z->real) + (z->im * z->im)) > 4) {
            printf("It's outside\n");
            mlx_put_pixel(mandel->img, c->real, c->im, 0xAAAFFF);
            // mlx_put_pixel(mandel->img, c->real, c->im, 0xFF0000FF);
        }
        else {
            printf("It's inside\n");
            mlx_put_pixel(mandel->img, x, y, 0x0000FF);
            // mlx_put_pixel(mandel->img, c->real, c->im, 0x0000FF);
        }
        i++;
    }
    if (((z->real * z->real) + (z->im * z->im)) < 4) 
        mlx_put_pixel(mandel->img, c->real, c->im, 0xAAAFFF);
 //   mlx_image_to_window(mandel->mlx, mandel->img, 0, 0);

 //   mlx_put_pixel(mandel->img, 1, 1, 0x0000FF);

}