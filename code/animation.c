/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:35:15 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/05 07:39:58 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_movment(t_vars *vars)
{
	time_t	t;
	int		i;
	int		j;

	srand((unsigned) time(&t));
	t = time(NULL);
	i = (rand() % 3) - 1;
	j = (rand() % 3) - 1;
	if (t % 1 == 0)
	{
		mv_n(vars, i, j);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_map_to_window(vars);
	}
	return (0);
}

void	mv_n(t_vars *vars, int i, int j)
{
	t_int	m;

	m.i = 0;
	while (vars->t[++m.i])
	{
		m.j = 0;
		while (vars->t[m.i][++m.j])
		{
			if ((vars->t[m.i][m.j] == 'N' && vars->t[m.i + i][m.j + j] == '0'))
			{
					vars->t[m.i][m.j] = '0';
					vars->t[m.i + i][m.j + j] = 'N';
			}
		}
	}
}

// void	size_map(t_vars	*vars)
// {
// 	int	x;
// 	int	y;

// 	mlx_get_screen_size(vars->mlx, &x, &y);
// 	if (vars->map_height * vars->img_height > x || (int)(vars->map_width * vars->img_width) > y)
// 		exit_message(8, vars);
// }
