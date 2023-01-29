/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:44:28 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/29 03:48:52 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	// write(1, ft_itoa(keycode), 3);
	mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 126 || keycode == 13)
		player_up(vars);
	else if (keycode == 125 || keycode == 1)
		player_down(vars);
	else if (keycode == 123 || keycode == 0)
		player_right(vars);
	else if (keycode == 124 || keycode == 2)
		player_left(vars);
	else if (keycode == 53)
		exit_message(7, vars);
	mlx_put_map_to_window(vars);
	return (0);
}

void	player_up(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->t[++i])
	{
		j = 0;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P' && vars->t[i - 1][j] != '1')
			{
				if (vars->t[i - 1][j] == 'N')
					exit_message(2, vars);
				if (vars->t[i - 1][j] == 'E' && check_c(vars->t) != 0)
					return ;
				if (vars->t[i - 1][j] == 'E')
					exit_message(3, vars);
				vars->t[i][j] = '0';
				vars->t[i - 1][j] = 'P';
				vars->m_c++;
				return ;
			}
		}
	}
}

void	player_down(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->t[++i])
	{
		j = 0;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P' && vars->t[i + 1][j] != '1')
			{
				if (vars->t[i + 1][j] == 'N')
					exit_message(2, vars);
				if (vars->t[i + 1][j] == 'E' && check_c(vars->t) != 0)
					return ;
				if (vars->t[i + 1][j] == 'E')
					exit_message(3, vars);
				vars->t[i][j] = '0';
				vars->t[i + 1][j] = 'P';
				vars->m_c++;
				return ;
			}
		}
	}
}

void	player_right(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->player = PLAYER2;
	while (vars->t[++i])
	{
		j = 0;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P' && vars->t[i][j - 1] != '1')
			{
				if (vars->t[i][j - 1] == 'N')
					exit_message(2, vars);
				if (vars->t[i][j - 1] == 'E' && check_c(vars->t) != 0)
					return ;
				if (vars->t[i][j - 1] == 'E')
					exit_message(3, vars);
				vars->t[i][j] = '0';
				vars->t[i][j - 1] = 'P';
				vars->m_c++;
				return ;
			}
		}
	}
}

void	player_left(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->player = PLAYER1;
	while (vars->t[++i])
	{	
		j = 0;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P' && vars->t[i][j + 1] != '1')
			{
				if (vars->t[i][j + 1] == 'N')
					exit_message(2, vars);
				if (vars->t[i][j + 1] == 'E' && check_c(vars->t) != 0)
					return ;
				if (vars->t[i][j + 1] == 'E')
					exit_message(3, vars);
				vars->t[i][j] = '0';
				vars->t[i][j + 1] = 'P';
				vars->m_c++;
				return ;
			}
		}
	}
}
