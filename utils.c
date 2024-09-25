#include "cube.h"

void ft_error(void)
{
    char *err_str;

    err_str = (char *)mlx_strerror(mlx_errno);
    write(2, "Error\n", 6);
	write(2, err_str, ft_strlen(err_str));
	exit(EXIT_FAILURE);
}

void    free_double(void **ptr)
{
    if (!ptr)
        return ;
    while (ptr && *ptr)
    {
        free(*ptr);
        ptr++;
    }
}

int strlen_double(void **ptr)
{
    int i;

    if (!ptr)
        return 0;
    i = -1;
    while (ptr && *ptr)
    {
        ptr++;
        i++;
    }
    return i;
}

char    **strdup_double_str(char **str)
{
    char **ret;
    int retlen;
    int i;

    i = -1;
    retlen = strlen_double((void **)str);
    ret = malloc(sizeof(char *) * (retlen + 1));
    while (++i < retlen)
    {
        ret[i] = ft_strdup(str[i]);
    }
    ret[i] = NULL;
    return (ret);
}
