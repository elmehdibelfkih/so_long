/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:21:13 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/09 21:34:39 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	message[8] = ft_strdup("invalide image !!");
	message[9] = NULL;
	write(1, message[i], strlen(message[i]));
	ft_clear(message, 8);
	if (i == 0)
		exit(1);
	if (i == 0 || i == 1 || i == 4 || i == 5 || i == 6 || i == 8)
	{
		ft_clear(vars->t, vars->map_height);
		exit(1);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	ft_clear(vars->t, vars->map_height);
	exit(1);
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

void	vars_plen(t_vars *vars)
{
	vars->o_d_img = mlx_xpm_file_to_image(vars->mlx,
			"./ textures/open_door.xpm", &vars->img_height, &vars->img_width);
	vars->c_d_img = mlx_xpm_file_to_image(vars->mlx,
			"./ textures/close_door.xpm", &vars->img_height, &vars->img_width);
	vars->b_img = mlx_xpm_file_to_image(vars->mlx,
			"./ textures/collectible.xpm", &vars->img_height, &vars->img_width);
	vars->p_1_img = mlx_xpm_file_to_image(vars->mlx, "./ textures/player1.xpm",
			&vars->img_height, &vars->img_width);
	vars->p_2_img = mlx_xpm_file_to_image(vars->mlx, "./ textures/player2.xpm",
			&vars->img_height, &vars->img_width);
	vars->p_img = mlx_xpm_file_to_image(vars->mlx, "./ textures/path.xpm",
			&vars->img_height, &vars->img_width);
	vars->w_img = mlx_xpm_file_to_image(vars->mlx, "./ textures/wall.xpm",
			&vars->img_height, &vars->img_width);
	vars->t_img = mlx_xpm_file_to_image(vars->mlx, "./ textures/enemy.xpm",
			&vars->img_height, &vars->img_width);
	if (!vars->o_d_img || !vars->c_d_img || !vars->b_img || !vars->p_1_img
		|| !vars->p_2_img || !vars->p_img || !vars->w_img || !vars->t_img)
		exit_message(8, vars);
	vars->player = vars->p_1_img;
	vars->m_c = 0;
	vars->door = vars->c_d_img;
}

int	esc(t_vars *vars)
{
	return (exit_message(7, vars), 0);
}
