/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:44:28 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/03 06:29:56 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
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
	return (0);
}

void	player_up(t_vars *vars)
{
	if (vars->t[vars->i][vars->j] == 'P'
		&& vars->t[vars->i - 1][vars->j] != '1')
	{
		if (vars->t[vars->i - 1][vars->j] == 'N')
			exit_message(2, vars);
		if (vars->t[vars->i - 1][vars->j] == 'E' && check_c(vars->t) != 0)
			return ;
		if (vars->t[vars->i - 1][vars->j] == 'E')
			exit_message(3, vars);
		vars->t[vars->i][vars->j] = '0';
		vars->t[--vars->i][vars->j] = 'P';
		vars->m_c++;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_map_to_window(vars);
		return ;
	}
}

void	player_down(t_vars *vars)
{
	if (vars->t[vars->i][vars->j] == 'P'
		&& vars->t[vars->i + 1][vars->j] != '1')
	{
		if (vars->t[vars->i + 1][vars->j] == 'N')
			exit_message(2, vars);
		if (vars->t[vars->i + 1][vars->j] == 'E' && check_c(vars->t) != 0)
			return ;
		if (vars->t[vars->i + 1][vars->j] == 'E')
			exit_message(3, vars);
		vars->t[vars->i][vars->j] = '0';
		vars->t[++vars->i][vars->j] = 'P';
		vars->m_c++;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_map_to_window(vars);
		return ;
	}
}

void	player_right(t_vars *vars)
{
	vars->player = vars->p_2_img;
	if (vars->t[vars->i][vars->j] == 'P'
		&& vars->t[vars->i][vars->j - 1] != '1')
	{
		if (vars->t[vars->i][vars->j - 1] == 'N')
			exit_message(2, vars);
		if (vars->t[vars->i][vars->j - 1] == 'E' && check_c(vars->t) != 0)
			return ;
		if (vars->t[vars->i][vars->j - 1] == 'E')
			exit_message(3, vars);
		vars->t[vars->i][vars->j] = '0';
		vars->t[vars->i][--vars->j] = 'P';
		vars->m_c++;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_map_to_window(vars);
		return ;
	}
}

void	player_left(t_vars *vars)
{
	vars->player = vars->p_1_img;
	if (vars->t[vars->i][vars->j] == 'P'
		&& vars->t[vars->i][vars->j + 1] != '1')
	{
		if (vars->t[vars->i][vars->j + 1] == 'N')
			exit_message(2, vars);
		if (vars->t[vars->i][vars->j + 1] == 'E' && check_c(vars->t) != 0)
			return ;
		if (vars->t[vars->i][vars->j + 1] == 'E')
			exit_message(3, vars);
		vars->t[vars->i][vars->j] = '0';
		vars->t[vars->i][++vars->j] = 'P';
		vars->m_c++;
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_map_to_window(vars);
		return ;
	}
}
