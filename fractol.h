/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/24 11:14:59 by anezka           ###   ########.fr       */
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

typedef struct complex_nb
{
    double  real;
    double  im;
}   t_complex_nb;

typedef struct fractal
{
    t_complex_nb    *z;
    t_complex_nb    *c;
    int             mandelbrot;
	double			realx;
	double			realy;
	double			imx;
	double			imy;
    mlx_t           *mlx;
    mlx_image_t     *img;
    double          iteration;
    double      	shift_x;
    double      	shift_y;
    double      	zoom;
}   t_fractal;


// colors

#define BLUE 0x0000FFFF
#define GREEN 0x00FF00FF
#define YELLOW 0xFFFF00FF
#define RED 0xFF0000FF

#define BROWN 0x964B00FF
#define BEIGE 0xF5F5DCFF
#define SIENNA 0xA0522DFF
#define UMBER 0x8B4513FF
#define CLAY 0xB86B4AFF

#define LIGHT_PINK 0xFFB6C1FF
#define BABY_BLUE 0x89CFF0FF
#define MINT 0xB2FFFCFF
#define LAVENDER 0xE6E6FAFF
#define PEACH 0xFFDAB9FF

#define ORANGE 0xFFA500FF
#define PURPLE 0x800080FF
#define TEAL 0x008080FF
#define CORAL 0xFF7F50FF
#define SALMON 0xFA8072FF

#define NAVY 0x000080FF
#define FOREST 0x228B22FF
#define MAROON 0x800000FF
#define VIOLET 0x9400D3FF
#define TURQUOISE 0x40E0D0FF

#define GOLD 0xFFD700FF
#define SILVER 0xC0C0C0FF
#define COPPER 0xB87333FF
#define BRONZE 0xCD7F32FF
#define ROSE_GOLD 0xFF0078FF




// fce
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
void mapp_julia(int x, int y, t_fractal *julia);
void	scrooling(double xdelta, double ydelta, void *param);

#endif
