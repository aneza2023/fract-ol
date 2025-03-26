/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:59 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 19:07:07 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mapp_julia(int x, int y, t_fractal *julia)
{
	int	i;
	int	color;
	int	iter;

	i = 0;
	julia->z->real = mapp(2, -2, WIDTH, x) / julia->zoom
		+ julia->shift_x;
	julia->z->im = mapp(-2, 2, HEIGHT, y) / julia->zoom
		+ julia->shift_y;
	iter = julia->ite + (int)(julia->zoom * 0.1);
	while (i < iter)
	{
		julia->z = add(square_of_nb(julia->z), julia->c);
		if (((julia->z->real * julia->z->real) + (julia->z->im
					* julia->z->im)) > 4)
		{
			color = mapp(BLUE, GREEN, 50, i + julia->ite);
			mlx_put_pixel(julia->img, x, y, color);
			return ;
		}
		i++;
	}
	if (((julia->z->real * julia->z->real) + (julia->z->im * julia->z->im)) < 4)
		mlx_put_pixel(julia->img, x, y, ORANGE);
}

int	kickoff_julia(double real, double im)
{
	mlx_t		*julia_con;
	t_fractal	*julia;

	julia = (t_fractal *)malloc(sizeof(t_fractal));
	if (julia == NULL)
		allocation_failed(julia);
	ft_memset(julia, 0, sizeof(t_fractal));
	julia_con = mlx_init(WIDTH, HEIGHT, "Julia", true);
	if (julia_con == NULL)
		allocation_failed(julia);
	julia->mlx = julia_con;
	julia->c = malloc(sizeof(t_complex_nb));
	if (julia->c == NULL)
		allocation_failed(julia);
	julia->c->real = real;
	julia->c->im = im;
	julia->mandelbrot = 0;
	putting_val(julia);
	create_window(julia);
	hooks_for_stuff(julia);
	mlx_loop(julia->mlx);
	return (0);
}
