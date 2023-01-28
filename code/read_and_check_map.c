/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 05:58:14 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/28 01:25:24 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_c(char **t)
{
	t_int	m;

	m.i = -1;
	m.j = -1;
	m.c = 0;
	while (t[++m.i])
	{
		while (t[m.i][++m.j])
			if (t[m.i][m.j] == 'C')
				m.c++;
		m.j = 0;
	}
	return (m.c);
}

char	**read_map(char *map)
{
	int		fd;
	int		i;
	char	*s;
	char	*s1;
	char	**t;

	i = BUFFER_SIZE;
	s1 = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_message(4);
	while (i == BUFFER_SIZE)
	{
		s = ft_calloc(BUFFER_SIZE + 1, 1);
		i = read(fd, s, BUFFER_SIZE);
		s1 = ft_strjoin(s1, s);
	}
	close(fd);
	if (ft_strnstr(s1, "\n\n", 10000000) != NULL)
		return (NULL);
	t = ft_split(s1, '\n');
	free(s1);
	return (t);
}

int	check_map(char **t, int *i)
{
	int	j;

	*i = -1;
	j = -1;
	if (!t)
		return (0);
	while (t[++*i])
	{
		if (ft_strlen(t[*i]) != ft_strlen(t[0]))
			return (0);
		while (t[*i][++j])
		{
			if (i == 0 && t[*i][j] != '1')
				return (0);
			if (t[*i + 1] == NULL && t[*i][j] != '1')
				return (0);
			if (t[*i][0] != '1' || t[*i][ft_strlen(t[0]) - 1] != '1')
				return (0);
		}
		j = 0;
	}
	if (check_e_p_c(t) == 0)
		return (0);
	return (check_path(t));
}

int	check_path(char **t)
{
	t_int	m;

	m.i = 0;
	if (!t)
		return (0);
	while (t[++m.i])
	{
		m.j = 0;
		while (t[m.i][++m.j])
		{
			if ((t[m.i][m.j] == '0' || t[m.i][m.j] == 'C') &&
				(t[m.i][m.j - 1] == 'P' || t[m.i][m.j + 1] == 'P'
				|| t[m.i - 1][m.j] == 'P' || t[m.i + 1][m.j] == 'P'))
			{
					t[m.i][m.j--] = 'P';
					m.i--;
			}
			if (t[m.i][m.j] == 'E' && (t[m.i][m.j - 1] == 'P' || t[m.i][m.j + 1]
				== 'P' || t[m.i - 1][m.j] == 'P' || t[m.i + 1][m.j] == 'P'))
				m.e = 1;
		}
	}
	if (m.e == 1 && check_c(t) == 0)
		return (m.e);
	return (0);
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
