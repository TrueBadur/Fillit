/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:52:30 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 02:16:33 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecpush(t_vector *vec)
{
	void	*data_c;

	if (!vec)
		return (NULL);
	data_c = vec->data;
	if (!(vec->data = malloc(vec->cap * 2)))
	{
		free(data_c);
		free(vec);
		return (NULL);
	}
	vec->cap *= 2;
	ft_memcpy(vec->data, data_c, vec->len);
	free(data_c);
	return (vec);
}
