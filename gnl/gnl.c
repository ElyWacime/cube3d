#include "gnl.h"

char    *gnl(int fd)
{
    static char buffer[42];
    char        line[100000];
    static int  counter;
	static int	readed;
	int			i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (counter >= readed)
		{
			readed = read(fd, buffer, 42);
			counter = 0;
			if (readed <= 0)
				break;
		}
		line[i++] = buffer[counter++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
