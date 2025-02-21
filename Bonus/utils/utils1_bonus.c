/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <skamroun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:55:01 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/21 16:36:58 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube_bonus.h"

void	quit_program(t_var *var)
{
	free_double((void **)var->map);
	free(var->map);
	mlx_terminate(var->mlx);
	exit(0);
}

void	ft_error(void)
{
	char	*err_str;

	err_str = (char *)mlx_strerror(mlx_errno);
	write(2, "Error\n", 6);
	write(2, err_str, ft_strlen(err_str));
	exit(EXIT_FAILURE);
}

void	free_double(void **ptr)
{
	if (!ptr)
		return ;
	while (ptr && *ptr)
	{
		free(*ptr);
		ptr++;
	}
}

int	strlen_double(void **ptr)
{
	int		i;
	void	**holder;

	holder = ptr;
	if (!holder)
		return (0);
	i = 0;
	while (holder && *holder)
	{
		holder++;
		i++;
	}
	return (i);
}

char	**strdup_double(char **str)
{
	char	**ret;
	int		retlen;
	int		i;

	retlen = strlen_double((void **)str);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (retlen + 1));
	while (i < retlen)
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
