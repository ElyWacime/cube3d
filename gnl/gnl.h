#ifndef GNL_H
# define GNL_H

# define FIRST 1
# define MIDDLE 2
# define LAST 3

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

char    *gnl(int fd);

#endif