/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamroun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:49:02 by skamroun          #+#    #+#             */
/*   Updated: 2025/02/15 17:49:04 by skamroun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define FIRST 1
# define MIDDLE 2
# define LAST 3

# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft2/libft.h"

char    *gnl(int fd);

#endif
