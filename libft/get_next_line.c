/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:51:25 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/11 17:47:34 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static int	ft_gnlsub(t_vector *vec, int offset, char **line)
{
	if(!(*line = malloc(offset + 1)))
		return (-1);
	ft_memcpy(*line, vec->data + vec->offset, offset);
	*(*line + offset) = '\0';
	vec->offset += offset + 1;
	return (1);
}

static int	ft_checkbuf(t_vector *vec, char **line, int offset, int rr)
{
	int		i;
	char	*src;

	if (!vec)
		return (0);
	i = 0;
	src = (char *)vec->data + vec->offset + offset;
//		printf("In checkbuf\n	vec->len = %d, vec->cap = %d\n	vec->data = %p, vec->data = %s\n	vec->ptr = %p, vec->ptr = %s\n",
//				vec->len, vec->cap, vec->data,(char *)vec->data, vec->data + vec->offset, (char *)vec->data + vec->offset);
	while (1)
	{
		if (src + i >= ((char *)vec->data) + vec->len)
		{
			if (rr < BUFF_SIZE)
				return (ft_gnlsub(vec, offset + i, line));
			if (vec->len - vec->offset < vec->cap / 3 && vec->cap > BUFF_SIZE)
				vec = ft_vecshrink(vec, vec->offset);
			return (0);
		}
		if (src[i] == '\n')
			return (ft_gnlsub(vec, offset + i, line));
		i++;
	}
}

static int	ft_readtobuf(t_vector *vec, char **line, int fd)
{
	int rr;
	int	tmp;
	int	i;

	i = 0;
	while (1)
	{
//		printf("Before read\n	vec->len = %d, vec->cap = %d\n	vec->data = %p, vec->data = %s\n	vec->ptr = %p, vec->ptr = %s\n",
//				vec->len, vec->cap, vec->data,(char *)vec->data, vec->data + vec->offset, (char *)vec->data + vec->offset);
		if (vec->len && vec->len < vec->cap / 4 && vec->cap > BUFF_SIZE)
			if(!(vec = ft_vecshrink(vec, 0)))
				return (-1);
		if (vec->cap - vec->len < BUFF_SIZE)
			if (!(vec = ft_vecpush(vec)))
				return (-1);
//		printf(" rr = %d, fd = %d\n", rr, fd);
		rr = read(fd, (vec->data + vec->len), BUFF_SIZE);
//		printf(" rr = %d, fd = %d\n", rr, fd);
		if (rr < 0 || rr == 0)
			return (rr);
		vec->len += rr;
		i += rr;
//		printf("After read\n	vec->len = %d, vec->cap = %d\n	vec->data = %p, vec->data = %s\n	vec->ptr = %p, vec->ptr = %s\n",
//				vec->len, vec->cap, vec->data,(char *)vec->data, vec->data + vec->offset, (char *)vec->data + vec->offset);
		if ((tmp = ft_checkbuf(vec, line, i - rr, rr)))
			return (tmp);
	}
}

static t_vector	*ft_checkfd(t_btavl **tr, int key)
{
	t_vector	*tmp = NULL;
	t_btavl		*tmtr = NULL;
	
	if (!tr)
		return (NULL);
	if (!(tmp = ft_avlsearch(*tr, key)))
	{
		if (!(tmp = ft_vecinit(BUFF_SIZE)))
			return (NULL);
//		printf("Allocated %p\n", tmp->data);
		if (!(tmtr = ft_avlnew(tmp, key, sizeof(t_vector))))
		{
			free(tmp);
			return (NULL);
		}
		*tr = ft_avlins(*tr, tmtr);
		free(tmp);
		return (t_vector *)(tmtr->data);
	}
	return (t_vector *)(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_btavl *tree = NULL;
	int				tmp;
	t_vector		*vector;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	vector = ft_checkfd(&tree, fd);
//	printf(" vec = %p\n", vector);
//		printf("After read\n	vec->len = %d, vec->cap = %d\n	vec->data = %p, vec->data = %s\n	vec->ptr = %p, vec->ptr = %s vec->offset = %d\n",
//				vector->len, vector->cap, vector->data,(char *)vector->data, vector->data + vector->offset, (char *)vector->data + vector->offset, vector->offset);
	if ((tmp = ft_checkbuf(vector, line, 0, BUFF_SIZE)))
	{
//		printf("Before possible remove\n");
		if (tmp == -1)
			ft_avlrem(tree, fd, &ft_vecdel);
		return (tmp);
	}
//	printf(" vec = %p\n", vector);
	tmp = ft_readtobuf(vector, line, fd);
//	printf(" vec = %p\n", vector);
//	printf(" vec->data = %p\n", vector->data);
	if (tmp != 1 || vector->offset > vector->len)
	{
		if (vector->offset < vector->len)
			tmp = ft_gnlsub(vector, vector->len - vector->offset, line);
//		printf("Before remove\n");
		tree = ft_avlrem(tree, fd, &ft_vecdel);
//		printf("Before remove2\n");
	}
//	printf("vector = %p\n", vector);
	return (tmp);
}
