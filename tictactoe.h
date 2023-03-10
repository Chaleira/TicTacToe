/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:01 by chales            #+#    #+#             */
/*   Updated: 2023/03/10 13:40:13 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TICTACTOE_H
# define TICTACTOE_H

# include "libft/libft.h"

typedef struct tictactoe_matrix
{
	int **sheet;
	int	**print_matrix;
	int num;
}				ttt_s;

typedef struct tictactoe_matrix_3d
{
	ttt_s 	matrix_2d;
	int		***matrix_3d;
}				ttt_3d_s;


#endif