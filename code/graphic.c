/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/29 01:39:59 by ebelfkih         ###   ########.fr       */
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
		exit (0);
	mlx_put_map_to_window(vars);
	return (0);
}

void	mlx_put_map_to_window(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->t[++i])
	{
		j = -1;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P')
				image_window(vars, i, j, vars->player);
			if (vars->t[i][j] == 'E')
				image_window(vars, i, j, vars->door);
			if (vars->t[i][j] == 'C')
				image_window(vars, i, j, BRAIN);
			if (vars->t[i][j] == '1')
				image_window(vars, i, j, WALL);
			if (vars->t[i][j] == '0')
				image_window(vars, i, j, PATH);
			if (vars->t[i][j] == '0')
				image_window(vars, i, j, PATH);
			if (vars->t[i][j] == 'N')
				image_window(vars, i, j, TRAP);
		}
	}
}

void	image_window(t_vars *vars, int i, int j, char *s)
{
	char	*msg;
	int		brain;

	brain = check_c(vars->t);
	if (brain == 0)
		vars->door = OPEN_DOOR;
	vars->img = mlx_xpm_file_to_image(vars->mlx, s,
			&vars->img_height, &vars->img_width);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->img_width * j, vars->img_height * i);
	mlx_destroy_image(vars->mlx, vars->img);
	msg = ft_strjoin(ft_strdup("mouvment : "), ft_itoa(vars->m_c));
	mlx_string_put(vars->mlx, vars->win, 10, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
	msg = ft_strjoin(ft_strdup("brain : "), ft_itoa(brain));
	mlx_string_put(vars->mlx, vars->win, 165, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
	msg = ft_strjoin(ft_strdup("score : "),
			ft_itoa(((vars->p - brain) * 100) - vars->m_c * 4));
	mlx_string_put(vars->mlx, vars->win, 300, (vars->map_height
			* vars->img_height) + 10, 0xFF0000, msg);
	free (msg);
}
