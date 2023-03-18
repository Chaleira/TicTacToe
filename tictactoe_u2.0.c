/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe_u2.0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:06:33 by plopes-c          #+#    #+#             */
/*   Updated: 2023/03/18 08:31:17 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

void print_sheet(ttt2_s game[9])
{
	ft_printf("\n                     |                 |                 \n");	
	ft_printf("       %s   |   %s   |   %s   \n", game[0].matrix[0], game[1].matrix[0], game[2].matrix[0]);	                            
	ft_printf("       %s   |   %s   |   %s   \n", game[0].matrix[1], game[1].matrix[1], game[2].matrix[1]);	                            
	ft_printf("       %s   |   %s   |   %s   \n", game[0].matrix[2], game[1].matrix[2], game[2].matrix[2]);	                            
	ft_printf("       %s   |   %s   |   %s   \n", game[0].matrix[3], game[1].matrix[3], game[2].matrix[3]);	                            
	ft_printf("       %s   |   %s   |   %s   \n", game[0].matrix[4], game[1].matrix[4], game[2].matrix[4]);	                            
	ft_printf("    -----------------|-----------------|-----------------\n");	
	ft_printf("       %s   |   %s   |   %s   \n", game[3].matrix[0], game[4].matrix[0], game[5].matrix[0]);                            	
	ft_printf("       %s   |   %s   |   %s   \n", game[3].matrix[1], game[4].matrix[1], game[5].matrix[1]);                            	
	ft_printf("       %s   |   %s   |   %s   \n", game[3].matrix[2], game[4].matrix[2], game[5].matrix[2]);                            	
	ft_printf("       %s   |   %s   |   %s   \n", game[3].matrix[3], game[4].matrix[3], game[5].matrix[3]);	                           
	ft_printf("       %s   |   %s   |   %s   \n", game[3].matrix[4], game[4].matrix[4], game[5].matrix[4]);	                           
	ft_printf("    -----------------|-----------------|-----------------\n");
	ft_printf("       %s   |   %s   |   %s   \n", game[6].matrix[0], game[7].matrix[0], game[8].matrix[0]);                       
	ft_printf("       %s   |   %s   |   %s   \n", game[6].matrix[1], game[7].matrix[1], game[8].matrix[1]);	                           
	ft_printf("       %s   |   %s   |   %s   \n", game[6].matrix[2], game[7].matrix[2], game[8].matrix[2]);	                           
	ft_printf("       %s   |   %s   |   %s   \n", game[6].matrix[3], game[7].matrix[3], game[8].matrix[3]);	                           
	ft_printf("       %s   |   %s   |   %s   \n", game[6].matrix[4], game[7].matrix[4], game[8].matrix[4]);	                           
	ft_printf("                     |                 |                 \n\n");
}			   

void build_sections(ttt2_s game[9])
{
	int		i;
	int		x;
	int		y;
	
	i = 0;
	x = 0;
	y = 0;
	while (i < 9)
	{
		while (y < 5)
		{
			while(x < 11)
			{
				if (x == 3 || x == 7)
					game[i].matrix[y][x] = '|';
				else if (y == 1 || y == 3)
					game[i].matrix[y][x] = '-';
				else
					game[i].matrix[y][x] = ' ';
				x++;
			}
			x = 0;
			y++;
		}
		y = 0;
		i++;
	}
}

void win(ttt2_s game[9], int w, char c)
{
	int x;
	int	y;

	y = 0;
	x = 0;
	while (y < 5)
	{
		while (x < 11)
		{
			game[w].matrix[y][x] = c;
			x++;
		}
		x = 0;
		y++;
	}
}

char		check_win(ttt2_s game[9], int w)
{
	if (game[w].matrix[0][1] == game[w].matrix[0][5] && game[w].matrix[0][1] == game[w].matrix[0][9])
		return (game[w].matrix[0][1]);
	if (game[w].matrix[2][1] == game[w].matrix[2][5] && game[w].matrix[2][1] == game[w].matrix[2][9])
		return (game[w].matrix[2][1]);
	if (game[w].matrix[4][1] == game[w].matrix[4][5] && game[w].matrix[4][1] == game[w].matrix[4][9])
		return (game[w].matrix[4][1]);
	if (game[w].matrix[0][1] == game[w].matrix[2][1] && game[w].matrix[0][1] == game[w].matrix[4][1])
		return (game[w].matrix[0][1]);
	if (game[w].matrix[0][5] == game[w].matrix[2][5] && game[w].matrix[0][5] == game[w].matrix[4][5])
		return (game[w].matrix[0][5]);
	if (game[w].matrix[0][9] == game[w].matrix[2][9] && game[w].matrix[0][9] == game[w].matrix[4][9])
		return (game[w].matrix[0][9]);
	if (game[w].matrix[0][1] == game[w].matrix[2][5] && game[w].matrix[0][1] == game[w].matrix[4][9])
		return (game[w].matrix[0][1]);
	if (game[w].matrix[0][9] == game[w].matrix[2][5] && game[w].matrix[0][9] == game[w].matrix[4][1])
		return (game[w].matrix[0][9]);
	return (0);
}

int	check_value(ttt2_s game[9], int place, int last_place, int *i)
{
	if (place < 1 || place > 9)
	{
		ft_printf("Don't try to break my code!\n");
		return (0);
	}
	if ((*i) > 0)
	{
		if (game[last_place - 1].visited[place - 1])
		{		
			ft_printf("Nah, can't play there!\n");
			return (0);
		}
	}	
	return (1);
}

void turn(ttt2_s game[9], char turn, int place, int last_place)
{
	last_place -= 1;
	if (place == 1)
		game[last_place].matrix[0][1] = turn;
	if (place == 2)
		game[last_place].matrix[0][5] = turn;
	if (place == 3)
		game[last_place].matrix[0][9] = turn;
	if (place == 4)
		game[last_place].matrix[2][1] = turn;
	if (place == 5)
		game[last_place].matrix[2][5] = turn;
	if (place == 6)
		game[last_place].matrix[2][9] = turn;
	if (place == 7)
		game[last_place].matrix[4][1] = turn;
	if (place == 8)
		game[last_place].matrix[4][5] = turn;
	if (place == 9)
		game[last_place].matrix[4][9] = turn;
	game[last_place].visited[place - 1] = 1;
}

void turn_num(ttt2_s game[9], int *i, char c)
{
	char *str;
	static int	last_place;
	int			place;
	char		winner;

	ft_printf("Playing on : %i\n", last_place);
	ft_printf("Player %c : ", c);
	str = get_next_line(0);
	place = ft_atoi(str);
	if (!check_value(game, place, last_place, i))
	{
		(*i)--;
		return ;
	}
	if (!last_place)
	{
		last_place = place;
		free(str);
		system("clear");
		print_sheet(game);
		ft_printf("Playing on : %i\n", last_place);
		ft_printf("Player %c : ", c);
		str = get_next_line(0);
		place = ft_atoi(str);
	}
	if (check_value(game, place, last_place, i))
	{
		system("clear");
		turn(game, c, place, last_place);
		winner = check_win(game, last_place - 1);
		if (winner == 'X')
			win(game, last_place - 1, 'X');
		if (winner == 'O')
			win(game, last_place - 1, 'O');
		print_sheet(game);
		last_place = place;
		free(str);
	}
}

int main()
{
	static ttt2_s	game[9];
	int				i;

	i = 0;
	build_sections(game);
	system("clear");
	print_sheet(game);
	while (i < 90)
	{
		if (i % 2)
			turn_num(game, &i, 'O');
		else
			turn_num(game, &i, 'X');
		i++;
	}	
	return (0);
}
