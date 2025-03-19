/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:59 by anezka            #+#    #+#             */
/*   Updated: 2025/03/19 11:29:28 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	julia->zx = real;
	julia->zy = im;
	
	return (0);
}