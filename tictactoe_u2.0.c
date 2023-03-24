/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe_u2.0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chales <chales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:06:33 by plopes-c          #+#    #+#             */
/*   Updated: 2023/03/24 18:55:11 by chales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

void clear(ttt2_s game[9], int w);

void welcoming(void)
{
	ft_printf("\n\nThis is a TicTacToe Ultimate game!\n\n");
	ft_printf("The Rules are simple:\n\n	1 - The first player chooses where to start\n\n	2 - You can only play in the (big game) house where your opponent played last in the small game\n\n	3 - If that small game is already finished you can choose in which game you want to play next!\n\n");
	ft_printf("Press ENTER to start...");
	get_next_line(0);
}

int check_tie(ttt2_s game[9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (game[i].won == 0 || game[i].tied < 9)
			return (1);
		i++;
	}
	return (0);
}

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

void build_win(ttt2_s game[9], int w, char c)
{
	int i;
	if (c != 'X' && c != 'O')
		return;
	else
	{
		clear(game, w);
		if (c == 'X')
		{
			// game[w].matrix[0][4] = '\\';
			game[w].matrix[0][4] = '\\';
			game[w].matrix[1][5] = '\\';
			game[w].matrix[2][6] = '\\';
			game[w].matrix[3][7] = '\\';
			game[w].matrix[3][4] = '/';
			game[w].matrix[2][5] = '/';
			game[w].matrix[1][6] = '/';
			game[w].matrix[0][7] = '/';
			// game[w].matrix[0][9] = '/';
		}
		if (c == 'O')
		{
			i = 3;
			while (i < 9)
			{
				game[w].matrix[0][i] = '_';
				game[w].matrix[3][i] = '_';
				i++;
			}
			i = 1;
			while (i < 4)
			{
				game[w].matrix[i][2] = '|';
				game[w].matrix[i][9] = '|';
				i++;
			}
		}
		game[w].won = 1;
		game[w].c_won = c;
	}
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

int	check_game_won(ttt2_s game[9])
{
	if (game[game[0].game_on - 1].won)
	{
		ft_printf("Game Already Won!\n");
		game[0].game_on = 0;
		return (0);
	}
	return (1);
}

int		get_input(ttt2_s game[9], char c)
{
	char *str;
	int			small_play;

	if (!game[0].game_on)
	{
		ft_printf("Player %c Choose the game to play in: ", c);
		str = get_next_line(0);
		game[0].game_on = ft_atoi(str);
		free(str);
		if (game[0].game_on < 1 || game[0].game_on > 9)
		{
			ft_printf("Play Between 1 and 9!\n");
			game[0].game_on = 0;
			return (0);
		}
		if (!check_game_won(game))
			return (0);
		if (game[game[0].game_on - 1].tied == 9)
		{
			game[0].game_on = 0;
			ft_printf("That Game is tied!\n");
			return (0);
		}
	}
	ft_printf("Playing on: %i\n", game[0].game_on);
	ft_printf("Player %c : ", c);
	str = get_next_line(0);
	small_play = ft_atoi(str);
	free(str);
	return(small_play);
}

void clear(ttt2_s game[9], int w)
{
	int x;
	int	y;

	y = 0;
	x = 0;
	while (y < 5)
	{
		while (x < 11)
		{
			game[w].matrix[y][x] = ' ';
			x++;
		}
		x = 0;
		y++;
	}
}

char		check_win(ttt2_s game[9], int w)
{
	if (game[w].matrix[0][1] == game[w].matrix[0][5] && game[w].matrix[0][1] == game[w].matrix[0][9] && game[w].matrix[0][1] != ' ')
		return (game[w].matrix[0][1]);
	if (game[w].matrix[2][1] == game[w].matrix[2][5] && game[w].matrix[2][1] == game[w].matrix[2][9] && game[w].matrix[2][1] != ' ')
		return (game[w].matrix[2][1]);
	if (game[w].matrix[4][1] == game[w].matrix[4][5] && game[w].matrix[4][1] == game[w].matrix[4][9] && game[w].matrix[4][1] != ' ')
		return (game[w].matrix[4][1]);
	if (game[w].matrix[0][1] == game[w].matrix[2][1] && game[w].matrix[0][1] == game[w].matrix[4][1] && game[w].matrix[0][1] != ' ')
		return (game[w].matrix[0][1]);
	if (game[w].matrix[0][5] == game[w].matrix[2][5] && game[w].matrix[0][5] == game[w].matrix[4][5] && game[w].matrix[0][5] != ' ')
		return (game[w].matrix[0][5]);
	if (game[w].matrix[0][9] == game[w].matrix[2][9] && game[w].matrix[0][9] == game[w].matrix[4][9] && game[w].matrix[0][9] != ' ')
		return (game[w].matrix[0][9]);
	if (game[w].matrix[0][1] == game[w].matrix[2][5] && game[w].matrix[0][1] == game[w].matrix[4][9] && game[w].matrix[0][1] != ' ')
		return (game[w].matrix[0][1]);
	if (game[w].matrix[0][9] == game[w].matrix[2][5] && game[w].matrix[0][9] == game[w].matrix[4][1] && game[w].matrix[0][9] != ' ')
		return (game[w].matrix[0][9]);
	return (0);
}

int	check_value(ttt2_s game[9], int small_play, int big_play, int *i)
{
	if ((small_play < 1 || small_play > 9))
	{
		ft_printf("Don't try to break my code!\n");
		return (0);
	}
	if ((*i) > 0)
	{
		if (game[big_play - 1].visited[small_play - 1])
		{		
			ft_printf("Nah, can't play there!\n");
			return (0);
		}
	}
	return (1);
}

void turn(ttt2_s game[9], char turn, int small_play, int big_play)
{
	big_play -= 1;
	if (small_play == 1)
		game[big_play].matrix[0][1] = turn;
	if (small_play == 2)
		game[big_play].matrix[0][5] = turn;
	if (small_play == 3)
		game[big_play].matrix[0][9] = turn;
	if (small_play == 4)
		game[big_play].matrix[2][1] = turn;
	if (small_play == 5)
		game[big_play].matrix[2][5] = turn;
	if (small_play == 6)
		game[big_play].matrix[2][9] = turn;
	if (small_play == 7)
		game[big_play].matrix[4][1] = turn;
	if (small_play == 8)
		game[big_play].matrix[4][5] = turn;
	if (small_play == 9)
		game[big_play].matrix[4][9] = turn;
	game[big_play].visited[small_play - 1] = 1;
	game[big_play].tied += 1;
}

void turn_num(ttt2_s game[9], int *i, char c)
{
	int			small_play;
	int			check_game;

	small_play = get_input(game, c);
	check_game = check_value(game, small_play, game[0].game_on, i);
	if (!check_game || !small_play)
	{
		(*i)--;
		return ;
	}
	else
	{
		system("clear");
		turn(game, c, small_play, game[0].game_on);
		if (game[game[0].game_on - 1].tied >= 9 && !check_win(game, game[0].game_on - 1))
			clear(game, game[0].game_on - 1);
		build_win(game, game[0].game_on - 1, check_win(game, game[0].game_on - 1));
		if (game[small_play - 1].won || game[small_play - 1].tied == 9)
			game[0].game_on = 0;
		else
			game[0].game_on = small_play;
		print_sheet(game);
	}
}

char check_big_win(ttt2_s game[9])
{
	if (game[0].c_won == game[1].c_won && game[0].c_won == game[2].c_won && game[0].c_won != 0)
		return (game[0].c_won);
	if (game[3].c_won == game[4].c_won && game[3].c_won == game[5].c_won && game[3].c_won != 0)
		return (game[3].c_won);
	if (game[6].c_won == game[7].c_won && game[6].c_won == game[8].c_won && game[6].c_won != 0)
		return (game[6].c_won);
	if (game[0].c_won == game[3].c_won && game[0].c_won == game[6].c_won && game[0].c_won != 0)
		return (game[0].c_won);
	if (game[1].c_won == game[4].c_won && game[1].c_won == game[7].c_won && game[1].c_won != 0)
		return (game[1].c_won);
	if (game[2].c_won == game[5].c_won && game[2].c_won == game[8].c_won && game[2].c_won != 0)
		return (game[2].c_won);
	if (game[0].c_won == game[4].c_won && game[0].c_won == game[8].c_won && game[0].c_won != 0)
		return (game[0].c_won);
	if (game[2].c_won == game[4].c_won && game[2].c_won == game[6].c_won && game[2].c_won != 0)
		return (game[2].c_won);
	return (0);
}

int main()
{
	static ttt2_s	game[9];
	int				i;
	char			big_winner;
	i = 0;
	system("clear");
	welcoming();
	build_sections(game);
	system("clear");
	print_sheet(game);
	while (i <= 81)
	{
		if (i % 2)
			turn_num(game, &i, 'O');
		else
			turn_num(game, &i, 'X');
		big_winner = check_big_win(game);
		if (big_winner == 'X')
		{
			ft_printf("Congrats X Won!\n");
			return (0);
		}
		else if (big_winner == 'O')
		{
			ft_printf("Congrats O Won!\n");
			return (0);
		}
		else if (!check_tie(game))
		{
			ft_printf("Seems Like We Have a Draw!\n");
			return (0);
		}
		i++;
	}
	return (0);
}
