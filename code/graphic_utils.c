/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/29 03:57:15 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	exit_message(int i, t_vars *vars)
{
	char	**message;

	message = malloc(9 * sizeof(char *));
	message[0] = ft_strdup("your map is not *.ber !");
	message[1] = ft_strdup("invalide map !");
	message[2] = ft_strdup("Sorry, you lost !!");
	message[3] = ft_strdup("Congratulations, you win !!");
	message[4] = ft_strdup("invalide file descreptor !!");
	message[5] = ft_strdup("invalide input !!");
	message[6] = ft_strdup("invalide path !!");
	message[7] = ft_strdup("exit : 0 error !!");
	message[8] = NULL;
	write(1, message[i], strlen(message[i]));
	ft_clear(message, 8);
	if (i == 0 || i == 1 || i == 4 || i == 5 || i == 6)
		exit(1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	return (free(s1), free(s2), s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = ft_strlen(s1);
	j = -1;
	s2 = malloc(i * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (i >= ++j)
		s2[j] = s1[j];
	return (s2);
}
