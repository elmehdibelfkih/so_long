/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:58:40 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/29 02:16:06 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	exit_message(int i, t_vars *vars)
{
	char	**message;

	message = malloc(8 * sizeof(char *));
	message[0] = ft_strdup("your map is not *.ber !");
	message[1] = ft_strdup("invalide map !");
	message[2] = ft_strdup("Sorry, you lost !!");
	message[3] = ft_strdup("Congratulations, you win !!");
	message[4] = ft_strdup("invalide file descreptor !!");
	message[5] = ft_strdup("invalide input !!");
	message[6] = ft_strdup("invalide path !!");
	message[7] = NULL;
	write(1, message[i], strlen(message[i]));
	ft_clear(message, 7);
	if (i == 0 || i == 1 || i == 4 || i == 5 || i == 6)
		exit(1);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.img_height = 60;
	vars.img_width = 60;
	vars.player = PLAYER1;
	vars.m_c = 0;
	vars.door = CLOSE_DOOR;
	if (ac != 2)
		exit_message(5, &vars);
	if (!ft_strnstr(av[1] + (ft_strlen(av[1]) - 4), ".ber", 4))
		exit_message(0, &vars);
	read_map(av[1], &vars);
	vars.map_width = ft_strlen(vars.t[0]);
	check_map(&vars);
	check_path(&vars);
	ft_clear(vars.t, vars.map_height);
	read_map(av[1], &vars);
	vars.p = check_c(vars.t);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.img_width * vars.map_width,
			vars.img_height * vars.map_height + 60, "so long");
	mlx_put_map_to_window(&vars);
	mlx_hook(vars.win, 8, 1L << 5, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
