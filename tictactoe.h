/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:30:01 by chales            #+#    #+#             */
/*   Updated: 2023/03/17 23:33:52 by plopes-c         ###   ########.fr       */
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
	char				matrix[5][12];
	char				won;
	int					visited[9];
	int					house_on[9];
}				ttt2_s;


#endif