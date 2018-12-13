/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:05:45 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 20:13:01 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	*ft_makeboard(int fc)
{
	int		i;
	int		j;
	t_board *b;

	if (!(b = malloc(sizeof(t_board))))
		return (NULL);
	if (!(b->data = (char **)malloc(sizeof(char *) * fc)))
	{
		free(b);
		return (NULL);
	}
	i = -1;
	while (++i < fc)
	{
		if (!(b->data[i] = ft_strnew(fc)))
		{
			while (--i)
				free(b->data[i]);
			free(b->data);
			free(b);
			return (NULL);
		}
		j = -1;
		while (++j < fc)
			b->data[i][j] = '.';
	}
	b->w = fc;
	return (b);
}
