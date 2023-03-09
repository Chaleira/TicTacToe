/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:30 by chales            #+#    #+#             */
/*   Updated: 2023/03/09 20:12:52 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

int	**alloc_matrix()
{
	int **matrix;
	int	*array;
	int i;

	i = 0;
	matrix = ft_calloc(sizeof(int *), 3);
	while (i < 3)
	{ 
		array = ft_calloc(sizeof(int), 3);
		matrix[i] = array; 
		i++;
	}
	return(matrix);
}

void print_ttt(int **matrix)
{
	ft_printf("\n\n  %c   |  %c   |  %c  \n", matrix[0][0], matrix[0][1], matrix[0][2]);
	ft_printf("------|------|------\n");
	ft_printf("  %c   |  %c   |  %c   \n", matrix[1][0], matrix[1][1], matrix[1][2]);
	ft_printf("------|------|------\n");
	ft_printf("  %c   |  %c   |  %c   \n\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}
void set_matrix_to_space(int **matrix)
{
	int	i;
	int	j;
	int num;

	i = 0;
	j = 0;
	num = 49;
	while (i < 3)
	{
		while (j < 3)
		{
			matrix[i][j] = num;
			num++;
			j++;
		}
		j = 0;
		i++;
	}
}

void print_play(ttt_s *ttt, int turn)
{
	int i;

	i = 1;
	while (i <= 3)
	{	
		if (ttt->num == i)
		{
			ttt->sheet[0][i - 1] = turn;
			print_ttt(ttt->sheet);
		}	
		i++;
	}
	i = 4;
	while (i <= 6 && i > 3)
	{
		if (ttt->num == i)
		{
			ttt->sheet[1][i - 4] = turn;
			print_ttt(ttt->sheet);
		}
		i++;
	}
	i = 7;
	while (i <= 9 && i > 6)
	{
		if (ttt->num == i)
		{
			ttt->sheet[2][i - 7] = turn;
			print_ttt(ttt->sheet);
		}
		i++;
	}
}

int check_repeat(int num)
{
	static int 	array[9];
	int			i;
	static int nb;
	
	if (num > 9 || num < 1)
		return (0);
	i = 0;
	while (i < 9)
	{
		if (array[i] == num)
			return (0);
		i++;
	}
	array[nb] = num;
	nb++;
	return (1);
}

void free_space(int **matrix)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int check_win(int **matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2])
				return (matrix[0][0]);
			if (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2])
				return (matrix[1][0]);
			if (matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2])
				return (matrix[2][0]);
			if (matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0])
				return (matrix[0][0]);
			if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1])
				return (matrix[0][1]);
			if (matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2])
				return (matrix[0][2]);
			if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2])
				return (matrix[0][0]);
			if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])
				return (matrix[0][2]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int main()
{
	ttt_s	ttt;
	int		i;
	int		winner;

	i = 0;
	system("clear");
	ttt.sheet = alloc_matrix();
	set_matrix_to_space(ttt.sheet);
	print_ttt(ttt.sheet);
	while (i < 9)
	{
		if (i % 2)
		{
			ft_printf("Player O Turn : \n");
			ttt.num = ft_atoi(get_next_line(0));
			if (!check_repeat(ttt.num))
			{
				ft_printf("Can't Place There!\n");
				i--;
			}
			else
			{
				system("clear");
				print_play(&ttt, 79);
			}
		}
		else
		{
			ft_printf("Player X Turn : \n	");
			ttt.num = ft_atoi(get_next_line(0));
			if (!check_repeat(ttt.num))
			{
				ft_printf("Can't Place There!\n");
				i--;
			}
			else
			{
				system("clear");
				print_play(&ttt, 88);
			}
		}
		i++;
		if(check_win(ttt.sheet))
		{
			winner = check_win(ttt.sheet);
			if (winner == 88)
				ft_printf("Player X Wins! Congrats!\n");
			else if (winner == 79)
				ft_printf("Player O Wins! Congrats!\n");
			free_space(ttt.sheet);
			return (0);
		}
	}
	ft_printf("Seems Like We Have a Tie! Rematch?\n");
	free_space(ttt.sheet);
}
