/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:52:39 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/12 18:51:00 by mbartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char			data[8];
	char			w;
	char			h;
	unsigned char	l;
}				t_tet;

# define COLS(x) x->data[1], x->data[3], x->data[5], x->data[7]
# define ROWS(x) x->data[0], x->data[2], x->data[4], x->data[6]
# define FUCKING_TET(x) x->data[0] == 0 && x->data[1] == 1 && x->data[2] == 1 && x->data[3] == 0 && x->data[4] == 1 && x->data[5] == 1 && x->data[6] == 2 && x->data[7] == 1

//void			pr_usage(void);
t_tet		*improve_tet(t_tet *one);
int			put_er(int ret);
t_list		*read_figs(int fd);
void			workitbaby(t_vector *figs, char **board);
#endif
