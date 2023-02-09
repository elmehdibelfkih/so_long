/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/09 23:29:16 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_map_to_window(t_vars *vars)
{
	t_int	m;

	m.i = -1;
	if (check_c(vars) == 0)
		vars->door = vars->o_d_img;
	mlx_clear_window(vars->mlx, vars->win);
	while (vars->t[++m.i])
	{
		m.j = -1;
		while (vars->t[m.i][++m.j])
		{
			if (vars->t[m.i][m.j] == 'P')
				image_window(vars, m.i, m.j, vars->player);
			if (vars->t[m.i][m.j] == 'E')
				image_window(vars, m.i, m.j, vars->door);
			if (vars->t[m.i][m.j] == 'C')
				image_window(vars, m.i, m.j, vars->b_img);
			if (vars->t[m.i][m.j] == '1')
				image_window(vars, m.i, m.j, vars->w_img);
			if (vars->t[m.i][m.j] == '0')
				image_window(vars, m.i, m.j, vars->p_img);
			if (vars->t[m.i][m.j] == 'N')
				image_window(vars, m.i, m.j, vars->t_img);
		}
	}
}

void	image_window(t_vars *vars, int i, int j, void	*img)
{
	char	*msg;
	int		brain;

	brain = check_c(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		vars->img_width * j, vars->img_height * i);
	msg = ft_strjoin(ft_strdup("mouvment : "), ft_itoa(vars->m_c));
	mlx_string_put(vars->mlx, vars->win, 10, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
	msg = ft_strjoin(ft_strdup("token : "), ft_itoa(brain));
	mlx_string_put(vars->mlx, vars->win, 165, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
	msg = ft_strjoin(ft_strdup("score : "),
			ft_itoa(((vars->p - brain) * 100) - vars->m_c * 4));
	mlx_string_put(vars->mlx, vars->win, 300, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 13)
		player_mv(vars, -1, 0);
	else if (keycode == 125 || keycode == 1)
		player_mv(vars, 1, 0);
	else if (keycode == 123 || keycode == 0)
		player_mv(vars, 0, -1);
	else if (keycode == 124 || keycode == 2)
		player_mv(vars, 0, 1);
	else if (keycode == 53)
		exit_message(7, vars);
	else if (keycode == 49)
		enemy_kill(vars);
	return (0);
}

void	player_mv(t_vars *vars, int i, int j)
{
	if (j == -1)
		vars->player = vars->p_2_img;
	if (j == 1)
		vars->player = vars->p_1_img;
	if (vars->t[vars->i][vars->j] == 'P'
		&& vars->t[vars->i + i][vars->j + j] != '1')
	{
		if (vars->t[vars->i + i][vars->j + j] == 'N')
			exit_message(2, vars);
		if (vars->t[vars->i + i][vars->j + j] == 'E' && check_c(vars) != 0)
			return ;
		if (vars->t[vars->i + i][vars->j + j] == 'E')
			exit_message(3, vars);
		vars->t[vars->i][vars->j] = '0';
		vars->j += j;
		vars->i += i;
		vars->t[vars->i][vars->j] = 'P';
		vars->m_c++;
		mlx_put_map_to_window(vars);
		return ;
	}
}
