/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/22 18:27:38 by ahavrank         ###   ########.fr       */
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

#define BLUE 0x00FFFF
#define GREEN 0xFF00FF

//#define BLUE 0x0000FF
//#define GREEN 0x00FF00
#define YELLOW 0xFFFF00
#define RED 0xFF0000

#define BROWN 0x964B00
#define BEIGE 0xF5F5DC
#define SIENNA 0xA0522D
#define UMBER 0x8B4513
#define CLAY 0xB86B4A

#define LIGHT_PINK 0xFFB6C1
#define BABY_BLUE 0x89CFF0
#define MINT 0xB2FFFC
#define LAVENDER 0xE6E6FA
#define PEACH 0xFFDAB9

#define ORANGE 0xFFA500
#define PURPLE 0x800080
#define TEAL 0x008080
#define CORAL 0xFF7F50
#define SALMON 0xFA8072

#define NAVY 0x000080
#define FOREST 0x228B22
#define MAROON 0x800000
#define VIOLET 0x9400D3
#define TURQUOISE 0x40E0D0

#define GOLD 0xFFD700
#define SILVER 0xC0C0C0
#define COPPER 0xB87333
#define BRONZE 0xCD7F32
#define ROSE_GOLD 0xFF0078




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

void	scrooling(double xdelta, double ydelta, void *param);

#endif
