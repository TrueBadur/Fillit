/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:52:39 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/13 13:59:53 by ehugh-be         ###   ########.fr       */
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

//int				put_er(int);
//void			pr_usage(void);
t_list			*read_figs(int fd);
void			workitbaby(t_list *figs, t_board *board, unsigned short posf);
void			free_board(t_board **b);
void			print_board(t_board *b);
#endif
