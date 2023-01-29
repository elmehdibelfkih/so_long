/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:05:16 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/29 03:52:35 by ebelfkih         ###   ########.fr       */
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

int	nbr_counter(int j)
{
	int	i;

	i = 0;
	if (j < 0)
		i++;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = nbr_counter(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_calloc(i + 1, 1);
	if (!s)
		return (NULL);
	i--;
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[i--] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}
