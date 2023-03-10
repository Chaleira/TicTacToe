/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe_ultimate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:16:35 by chales            #+#    #+#             */
/*   Updated: 2023/03/10 16:31:49 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

int	**alloc_matrix(int size_y, int size_x)
{
	int **matrix;
	int	*array;
	int i;

	i = 0;
	matrix = ft_calloc(sizeof(int *), size_y);
	while (i < size_y)
	{ 
		array = ft_calloc(sizeof(int), size_x);
		matrix[i] = array; 
		i++;
	}
	return(matrix);
}

int	***alloc_3d_matrix()
{
	int ***matrix_3d;
	int	i;

	i = 0;
	matrix_3d = ft_calloc(sizeof(int **), 9);
	while (i < 9)
	{
		matrix_3d[i] = alloc_matrix(3, 3);
		i++;
	}
	return (matrix_3d);
}

void set_matrix_sheet(int **matrix, ttt_3d_s *ttt_3d)
{
	int i;
	int j;
	int x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	i = 0;
	j = 0;
	while (i < 19)
	{
		while (j < 54)
		{
			if (j == 17 || j == 35)
				matrix[i][j] = '|';
			else if ((j == 6 || j == 10  || j == 24 || j == 28
				|| j == 42 || j == 46) && (i != 0 && i != 6 && i != 12 && i != 18))
				matrix[i][j] = '|';
			else if ((i == 6 || i == 12))
				matrix[i][j] = '-';
			else if ((i == 2 || i == 4 || i == 8 || i == 10 || i == 14
				|| i == 16) && ((j > 2) && (j < 14 || j > 20) && (j < 32 || j > 38) && j < 50))
				matrix[i][j] = '-';
			else if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17)
				&& (j == 4 || j == 8 || j == 12 || j == 22 || j == 26 || j == 30 || j == 40 || j == 44 || j == 48))
				{
					matrix[i][j] = ttt_3d->matrix_3d[count][y][x];
					x++;
				}
			else
				matrix[i][j] = ' ';
			if (j == 53)
				matrix[i][j] = '\n';
			if (x == 3)
			{
				x = 0;
				count++;
			}
			if (count == 3 || count == 6 || count == 9)
			{
				y++;
				if (y == 3 && (count == 3 || count == 6 || count == 9))
				{
					if (count == 3)
						count = 4;
					if (count == 6)
						count = 7;
					y = 0;
				}
				else
					count = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void set_3d_matrix(ttt_3d_s *ttt_3d)
{
	int i;
	int	j;
	int count;
	int num;

	i = 0;
	j = 0;
	num = 48;
	count = 0;
	while (count < 9)
	{
		while (i < 3)
		{
			while (j < 3)
			{
				ttt_3d->matrix_3d[count][i][j] = num;
				num++;
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		count++;
	}
}

// void print_sheet(ttt_s *ttt)
// {
// 	(void)ttt;
// 	ft_printf("                 |                 |                 \n");	0
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	1
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	2
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	3
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	4
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	5
// 	ft_printf("-----------------|-----------------|-----------------\n");	6
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	7
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	8
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	9
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	10
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	11
// 	ft_printf("-----------------|-----------------|-----------------\n");	12
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	13
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	14
// 	ft_printf("      |   |      |      |   |      |      |   |      \n");	15
// 	ft_printf("   ---|---|---   |   ---|---|---   |   ---|---|---   \n");	16
// 	ft_printf("      |   | s    |      |   |      |      |   |      \n");	17
// 	ft_printf("                 |                 |                 \n\n");	18
//}			   012345678911111111112222222222333333333344444444445555
//						 01234567890123456789012345678901234567890123

int main ()
{
	ttt_3d_s 	ttt_3d;
	int		**sheet;
	int			i;
	int			j;

	i = 0;
	j = 0;
	// print_sheet(&ttt_3d.matrix_2d);
	sheet = alloc_matrix(19, 54);
	ttt_3d.matrix_3d = alloc_3d_matrix();
	set_3d_matrix(&ttt_3d);
	set_matrix_sheet(sheet, &ttt_3d);
	ft_printf("\n");
	while (i < 19)
	{
		while (j < 54)
		{
			ft_printf("%c", sheet[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("\n");
	j = 0;
	i = 0;
	return (0);
}