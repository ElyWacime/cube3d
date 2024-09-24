#include "cube.h"

void ft_error(void)
{
    char *err_str;

    err_str = (char *)mlx_strerror(mlx_errno);
	write(2, err_str, ft_strlen(err_str));
	exit(EXIT_FAILURE);
}

void    free_double(void **ptr)
{
    if (!ptr)
        return ;
    while (ptr)
    {
        if (*ptr)
            free(*ptr);
        ptr++;
    }
}