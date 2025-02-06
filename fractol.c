

#include "fractol.h"
#include "MLX42.h"

//will it work if for example juliaxx??
int checking_input(char *argv)
{
    printf("argv: %s\n", argv);
    if(ft_strncmp(argv, "julia", 5) == 0)
        return (0);
    else if(ft_strncmp(argv, "mandelbrot", 10) == 0)
        return (0);
    return (1);
}

//checking values for julia + kickoff
int additional_check(char *argv1, char *argv2, char *julia)
{
    printf("additional check %s, %s ", argv1, argv2);
    return (0); 
}


int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 4)
    {
        write(1, "wrong input\n", 13);
        return (1);
    }
    else{
        if (checking_input(argv[1]) != 0)
        {
            write(1, "wrong input\n", 13);
            return (1);
        }
        else if (checking_input(argv[1])== 0 && argc == 4)
            additional_check(argv[2], argv[3], argv[1]);
    }
    return (0);
}   