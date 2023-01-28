/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:00:06 by ebelfkih          #+#    #+#             */
/*   Updated: 2023/01/28 03:17:36 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define CLOSE_DOOR "./images/close_door.xpm"
# define  OPEN_DOOR "./images/open_door.xpm"
# define  BRAIN "./images/brain.xpm"
# define  PLAYER1 "./images/player1.xpm"
# define  PLAYER2 "./images/player2.xpm"
# define  PATH "./images/path.xpm"
# define  WALL "./images/wall.xpm"
# define  TRAP "./images/trap.xpm"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>

typedef struct s_vars {
	char	**t;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		bits_per_pixel;
	int		map_height;
	int		map_width;
	int		img_width;
	int		img_height;
	char	*player;
	char	*door;
	int		m_c;
	int		p;
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
int		check_map(char **t, int *i);
char	**read_map(char *map);
int		check_path(char **t);
void	player_up(t_vars *vars);
void	player_down(t_vars *vars);
void	player_left(t_vars *vars);
void	player_right(t_vars *vars);
int		check_c(char **t);
int		key_hook(int keycode, t_vars *vars);
void	mlx_put_map_to_window(t_vars *vars);
void	image_window(t_vars *vars, int i, int j, char *s);
void	exit_message(int i);
int		nbr_counter(int j);
char	*ft_itoa(int n);

#endif