/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:52:39 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/17 17:17:58 by mbartole         ###   ########.fr       */
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
typedef struct	s_board
{
	char	**data;
	char	w;
	char	row;
	char	col;
}				t_board;

# define IT_IS_COLS(x) x->data[1], x->data[3], x->data[5], x->data[7]
# define IT_IS_ROWS(x) x->data[0], x->data[2], x->data[4], x->data[6]
# define TET_1PART(x) x[0] == 0 && x[1] == 1 && x[2] == 1 && x[3] == 0
# define TET_2PART(x) x[4] == 1 && x[5] == 1 && x[6] == 2 && x[7] == 1

int				pr_usage(void);
t_list			*read_figs(int fd, int *b_size);
int				workitbaby(t_list *figs, t_board *board, unsigned short posf);
void			free_board(t_board **b);
int				print_board(t_board *b);
t_board			*ft_makeboard(int w);
t_tet			*improve_tet(t_tet *one, t_list **l);
void			check_valid(t_tet *t, t_list **l);
int				put_er(int ret, t_list **l, t_tet *tet);
#endif
