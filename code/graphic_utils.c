/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/03 06:31:18 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_map_to_window(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	if (check_c(vars->t) == 0)
		vars->door = vars->o_d_img;
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
				image_window(vars, i, j, vars->b_img);
			if (vars->t[i][j] == '1')
				image_window(vars, i, j, vars->w_img);
			if (vars->t[i][j] == '0')
				image_window(vars, i, j, vars->p_img);
			if (vars->t[i][j] == 'N')
				image_window(vars, i, j, vars->t_img);
		}
	}
}

void	image_window(t_vars *vars, int i, int j, void	*img)
{
	char	*msg;
	int		brain;

	brain = check_c(vars->t);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		vars->img_width * j, vars->img_height * i);
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

void	xpm_to_img(t_vars *vars)
{
	vars->o_d_img = mlx_xpm_file_to_image(vars->mlx, "./images/open_door.xpm",
			&vars->img_height, &vars->img_width);
	vars->c_d_img = mlx_xpm_file_to_image(vars->mlx, "./images/close_door.xpm",
			&vars->img_height, &vars->img_width);
	vars->b_img = mlx_xpm_file_to_image(vars->mlx, "./images/brain.xpm",
			&vars->img_height, &vars->img_width);
	vars->p_1_img = mlx_xpm_file_to_image(vars->mlx, "./images/player1.xpm",
			&vars->img_height, &vars->img_width);
	vars->p_2_img = mlx_xpm_file_to_image(vars->mlx, "./images/player2.xpm",
			&vars->img_height, &vars->img_width);
	vars->p_img = mlx_xpm_file_to_image(vars->mlx, "./images/path.xpm",
			&vars->img_height, &vars->img_width);
	vars->w_img = mlx_xpm_file_to_image(vars->mlx, "./images/wall.xpm",
			&vars->img_height, &vars->img_width);
	vars->t_img = mlx_xpm_file_to_image(vars->mlx, "./images/trap.xpm",
			&vars->img_height, &vars->img_width);
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
	{
		ft_clear(vars->t, vars->map_height);
		exit(1);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	ft_clear(vars->t, vars->map_height);
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
		return (free(s1), s2);
	if (!s2)
		return (free(s2), s1);
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

void	p_position(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->t[++i])
	{
		j = 0;
		while (vars->t[i][++j])
		{
			if (vars->t[i][j] == 'P')
			{
				vars->i = i;
				vars->j = j;
				return ;
			}
		}
	}
}
