/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/22 14:48:21 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H   
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/include/MLX42/MLX42.h"

#define HEIGHT 1000
#define WIDTH 1000

typedef struct fractal
{
    double      zx;
    double      zy;
    double      cx;
    double      cy;
    mlx_t       *mlx;
    mlx_image_t *img;
    double      iteration;
    double      shift_x;
    double      shift_y;
    double      zoom;
}   t_fractal;

typedef struct complex_nb
{
    double  real;
    double  im;
}   t_complex_nb;

int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_atoi(const char *nptr);
double  ft_atof(char *argv);
int     kickoff_julia(double real, double im);
int     getting_val(char *argv1, char *argv2);
int     check_julia(char *argv);
int     check_mandelbrot(char *argv);
int     kickoff_mandelbrot(void);
int     create_window(t_fractal *mandel);
int     putting_mandelbrot(t_fractal *mandel);
void	hoopmain(void *param);
void    mapping(int x, int y, t_fractal *mandel);
double  mapping_pixels(double new_max, double new_min, double old_max, double old_min, int i);
t_complex_nb *addition_of_nb(t_complex_nb *z, t_complex_nb *c);
t_complex_nb *square_of_nb(t_complex_nb *z);
void hooks_for_stuff(t_fractal *mandel);
t_fractal	*putting_val(t_fractal *mandel);
int error_input(void);
int allocation_failed(void *fractol);
int correct_ending(void *fractol);
int	kickoff_julia(double real, double im);

void	scrooling(double xdelta, double ydelta, void *param);

#endif
