
#ifndef FRACTOL_H   
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>

typedef struct complex_number
{
    double  x;
    double  y;
}   t_comp_nb;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *nptr);

#endif
