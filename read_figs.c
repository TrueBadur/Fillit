/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 17:14:40 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_vector *read_figs(int fd)
{
	char	*line;
	int		i;
	int		len;

	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		len = ft_strlen(line);
		if (len != 4 || (i % 4 == 1 && len != 0))
			return (NULL);
	}
}
