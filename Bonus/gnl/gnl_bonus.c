/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:48:57 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 20:47:46 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

char	*gnl(int fd)
{
	static char	buffer[42];
	static int	counter;
	static int	readed;
	char		line[100000];
	int			i;

	i = 0;
	while (fd >= 0 && 1)
	{
		if (counter >= readed)
		{
			readed = read(fd, buffer, 42);
			counter = 0;
			if (readed <= 0)
				break ;
		}
		line[i++] = buffer[counter++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
