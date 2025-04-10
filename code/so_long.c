/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:58:40 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/06 19:39:24 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.img_height = 65;
	vars.img_width = 65;
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
	vars_plen(&vars);
	vars.p = check_c(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.img_width * vars.map_width,
			vars.img_height * vars.map_height + 60, "so long");
	mlx_put_map_to_window(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, esc, &vars);
	mlx_loop_hook(vars.mlx, enemy_movment, &vars);
	mlx_loop(vars.mlx);
}
