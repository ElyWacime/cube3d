#include "../cube.h"

void    check_textures(char *NO, char *SO, char *WE, char *EA)
{
    if (ft_strncmp(NO, "NO ", 3)
        || ft_strncmp(SO, "SO ", 3)
        || ft_strncmp(WE, "WE ", 3)
        || ft_strncmp(EA, "EA ", 3))
    {
        write(2, "Error 1\nInvalid path!", 21);
        exit(72);
    }
}

void   check_path(char *NO, char *SO, char *WE, char *EA)
{
    int fd1;
    int fd2;
    int fd3;
    int fd4;

    fd1 = open(NO, O_RDONLY);
    fd2 = open(SO, O_RDONLY);
    fd3 = open(WE, O_RDONLY);
    fd4 = open(EA, O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
    {
        write(2, "Error 2\nInvalid path!\n", 20);
        close(fd1);
        close(fd2);
        close(fd3);
        close(fd4);
        exit(73);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
}

void    parse_textures(t_var *var)
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;

    if (strlen_double((void**)var->textures) < 4)
    {
        write(2, "Error 3\nInvalid path!", 20);
        exit(71);
    }
    check_textures(var->textures[0], var->textures[1],
                    var->textures[2], var->textures[3]);
    NO = var->textures[0] + 3;
    SO = var->textures[1] + 3;
    WE = var->textures[2] + 3;
    EA = var->textures[3] + 3;
    check_path(NO, SO, WE, EA);
}

void    get_texures(t_var *var, int fd)
{
    char *line;
    char *tmp;
    int i;

    i = -1;
    tmp = NULL;
    while (++i < 4)
    {
        line = gnl(fd);
        if (!line)
        {
            write(2, "Error\nInvalid map!", 18);
            exit(5);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
    }
    var->textures = ft_split(tmp, '\n');
    parse_textures(var);
    free(tmp);
}

void    check_len(char **color)
{
    if (strlen_double((void**)color) != 3)
    {
        write(2, "Error\nInvalid color!", 19);
        exit(90);
    }
}
