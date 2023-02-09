/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:35:15 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/08 22:09:54 by ebelfkih         ###   ########.fr       */
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
		mv_enemy(vars, i, j);
		mlx_put_map_to_window(vars);
	}
	return (0);
}

void	mv_enemy(t_vars *vars, int i, int j)
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

void	enemy_kill(t_vars *vars)
{
	if (vars->player == vars->p_2_img && vars->t[vars->i][vars->j - 1] == 'N')
	{
		vars->t[vars->i][vars->j - 1] = 'C';
		mlx_put_map_to_window(vars);
	}
	if (vars->player == vars->p_1_img && vars->t[vars->i][vars->j + 1] == 'N')
	{
		vars->t[vars->i][vars->j + 1] = 'C';
		mlx_put_map_to_window(vars);
	}	
}
