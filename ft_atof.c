/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:39 by anezka            #+#    #+#             */
/*   Updated: 2025/03/11 08:43:06 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_atof(char *argv)
{
    int      i;
    double   result;
    int      sign;
    double   decimal;
    double   decim_places;

    i = 0;
    result = 0.0;
    sign = 1;
    decimal = 0.0;
    decim_places = 10;
    while ((argv[i] == 32) || (argv[i] <= 13 && argv[i] >= 9))
        i++;
    if (argv[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (argv[i] == '+')
		i++;
    while (argv[i] <= '9' && argv[i] >= '0')
	{
		result = result * 10 + argv[i] - '0';
		i++;
	}
    if (argv[i] == '.' || argv[i] == ',')
    {
        i++;
        while (argv[i] <= '9' && argv[i] >= '0')
        {
            decimal = (argv[i] - '0') / decim_places;
            result += decimal; 
            i++;
            decim_places = decim_places * 10;
        }
    }
	return (result * sign);
}

/* int	main(void)
{
	char str[50] = " 31.8";
	printf("%f", ft_atof(str));
	return (0);
} */
