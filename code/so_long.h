/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:00:06 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/02/08 18:45:37 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 20

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <time.h>
# include <string.h>

typedef struct s_vars {
	unsigned int	map_width;
	int				map_height;
	int				img_width;
	int				img_height;
	int				i;
	int				j;
	int				p;
	int				m_c;
	char			**t;
	void			*mlx;
	void			*win;
	void			*door;
	void			*player;
	void			*c_d_img;
	void			*o_d_img;
	void			*b_img;
	void			*p_1_img;
	void			*p_2_img;
	void			*p_img;
	void			*w_img;
	void			*t_img;
}				t_vars;

typedef struct s_int {
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;
}				t_int;

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		n_of_world(char const *s, char c);
int		ft_clear(char **spl, int p);
int		plen(char **spl, const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		check_e_p_c(char **t);
void	check_map(t_vars *vars);
void	read_map(char *map, t_vars *vars);
void	check_path(t_vars *vars);
void	player_mv(t_vars *vars, int i, int j);
int		check_c(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	mlx_put_map_to_window(t_vars *vars);
void	image_window(t_vars *vars, int i, int j, void	*img);
void	exit_message(int i, t_vars *vars);
int		nbr_counter(int j);
char	*ft_itoa(int n);
void	vars_plen(t_vars *vars);
int		esc(t_vars *vars);
int		enemy_movment(t_vars *vars);
void	mv_enemy(t_vars *vars, int i, int j);
void	enemy_kill(t_vars *vars);

#endif