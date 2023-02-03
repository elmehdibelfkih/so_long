/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:58:14 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/03 08:11:19 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_c(t_vars *vars)
{
	t_int	m;

	m.i = -1;
	m.j = -1;
	m.c = 0;
	while (vars->t[++m.i])
	{
		while (vars->t[m.i][++m.j])
		{
			if (vars->t[m.i][m.j] == 'C')
				m.c++;
			if (vars->t[m.i][m.j] == 'P')
			{
				vars->i = m.i;
				vars->j = m.j;
			}
		}
		m.j = 0;
	}
	return (m.c);
}

void	read_map(char *map, t_vars *vars)
{
	int		fd;
	int		i;
	char	*s;
	char	*s1;

	vars->t = NULL;
	i = BUFFER_SIZE;
	s1 = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_message(4, vars);
	while (i == BUFFER_SIZE)
	{
		s = ft_calloc(BUFFER_SIZE + 1, 1);
		i = read(fd, s, BUFFER_SIZE);
		s1 = ft_strjoin(s1, s);
	}
	close(fd);
	if (ft_strnstr(s1, "\n\n", 10000000) != NULL)
	{
		free(s1);
		exit_message(1, vars);
	}
	vars->t = ft_split(s1, '\n');
	free(s1);
}

void	check_map(t_vars *vars)
{
	int	j;

	if (!vars->t)
		exit_message(1, vars);
	vars->map_height = -1;
	while (vars->t[++vars->map_height])
	{
		j = -1;
		if (ft_strlen(vars->t[vars->map_height]) != vars->map_width)
			exit_message(1, vars);
		while (vars->t[vars->map_height][++j])
		{
			if (vars->map_height == 0 && vars->t[vars->map_height][j] != '1')
				exit_message(1, vars);
			if (!vars->t[vars->map_height + 1]
				&& vars->t[vars->map_height][j] != '1')
				exit_message(1, vars);
			if (vars->t[vars->map_height][0] != '1' ||
				vars->t[vars->map_height][vars->map_width - 1] != '1')
				exit_message(1, vars);
		}
	}
	if (!check_e_p_c(vars->t))
		exit_message(1, vars);
}

void	check_path(t_vars *vars)
{
	t_int	m;

	m.i = 0;
	if (!vars->t)
		exit_message(1, vars);
	while (vars->t[++m.i])
	{
		m.j = 0;
		while (vars->t[m.i][++m.j])
		{
			if ((vars->t[m.i][m.j] == '0' || vars->t[m.i][m.j] == 'C') && (vars
				->t[m.i][m.j - 1] == 'P' || vars->t[m.i][m.j + 1] == 'P' || vars
				->t[m.i - 1][m.j] == 'P' || vars->t[m.i + 1][m.j] == 'P'))
			{
					vars->t[m.i][m.j--] = 'P';
					m.i--;
			}
			if (vars->t[m.i][m.j] == 'E' && (vars->t[m.i][m.j - 1] == 'P'
			|| vars->t[m.i][m.j + 1] == 'P' || vars->t[m.i - 1][m.j] == 'P'
			|| vars->t[m.i + 1][m.j] == 'P'))
				m.e = 1;
		}
	}
	if (m.e != 1 || check_c(vars) != 0)
		exit_message(6, vars);
}

int	check_e_p_c(char **t)
{
	t_int	m;

	m.i = 0;
	m.e = 0;
	m.p = 0;
	m.c = 0;
	while (t[++m.i])
	{
		m.j = 0;
		while (t[m.i][++m.j])
		{
			if (t[m.i][m.j] == 'P')
				m.p++;
			if (t[m.i][m.j] == 'E')
				m.e++;
			if (t[m.i][m.j] == 'C')
				m.c++;
			if (t[m.i][m.j] != 'C' && t[m.i][m.j] != 'P' && t[m.i][m.j] != 'E'
			&& t[m.i][m.j] != '0' && t[m.i][m.j] != '1' && t[m.i][m.j] != 'N')
				return (0);
		}
	}
	if (m.p == 1 && m.e == 1 && m.c >= 1)
		return (m.c);
	return (0);
}
