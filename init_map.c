#include "cube.h"

void	get_node_positions(t_list *map)
{
	int		lst_size;
	int		count;

	count = 0;
	lst_size = ft_lstsize(map);
	while (map)
	{
		if (count == 0)
			map->position = FIRST;
		else if (count == lst_size)
			map->position = LAST;
		else
			map->position = MIDDLE;
        count++;
        printf("fuck %d\n", count);
		map = map->next;
	}
}

int create_map(void)
{
	char        *line = NULL;
	int         fd = open("gnl/file", O_RDONLY);
	t_list	    *map;
	map = NULL;
	line = gnl(fd);
    while (line)
	{
        printf("%s", line);
		ft_lstadd_back(&map, ft_lstnew(line));
        printf(">>>>>>%s", (char *)ft_lstlast(map)->content);
		line = gnl(fd);
	}
    map = map->next;
    // printf("%p\n", map->next);
    // get_node_positions(map);
	// while (map)
	// {
    //     printf("%d\t%s",map->position, (char *)map->content);
    //     map = map->next;
	// }
    return 0;	
}
