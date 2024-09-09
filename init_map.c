#include "cube.h"

void	get_node_positions(t_list *map)
{
	t_list	*head;
	int		lst_size;
	int		count;

	count = 0;
	lst_size = ft_lstsize(map);
	head = map;
	while (head)
	{
		if (count == 0)
			head->position = FIRST;
		else if (count = lst_size)
			head->position = LAST;
		else
			head->position = MIDDLE;
		head = head->next;
	}
}

int create_map(void)
{
	char        *line = NULL;
	int         fd = open("file", O_RDONLY);
	t_list	    *map;
	t_list	    *head;

	map = NULL;
	line = gnl(fd);
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(line));
		line = gnl(fd);
	}
	while (map)
	{
		printf("%s", (char *)map->content);
		map = map->next;
	}	
}