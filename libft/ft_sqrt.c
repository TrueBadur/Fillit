/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:37:54 by mbartole          #+#    #+#             */
/*   Updated: 2018/10/20 17:33:08 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		s;
	int		mem;
	int		deepmem;

	s = nb;
	mem = 0;
	deepmem = 0;
	if (nb <= 0)
		return (0);
	while (mem != nb && deepmem != nb)
	{
		deepmem = mem;
		mem = nb;
		nb = (nb + s / nb) / 2;
	}
	if (nb * nb == s)
		return (nb);
	else
		return (0);
}