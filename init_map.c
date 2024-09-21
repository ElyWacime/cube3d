#include "cube.h"

char **create_map(void)
{
	char        *line = NULL;
	int         fd = open("./gnl/file", O_RDONLY);
    char        **map;
    char        *_map;

    _map = NULL;
    line = gnl(fd);
    while (line)
    {
        _map = ft_strjoin(_map, line);
        free(line);
        line = gnl(fd);
    }
    map = ft_split(_map, '\n');
    return (map);
}
