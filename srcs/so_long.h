/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:56:57 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/12/17 17:56:57 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef so_long
# define so_long

# define WALL "assets/wall.xpm"
# define EMPTY "assets/empty.xpm"
# define PLAYER "assets/player.xpm"
# define EXIT "assets/exit.xpm"
# define COLLECT "assets/collect.xpm"
# define WIN "assets/winner.xpm"

# define ESC 65307
# define W 65362
# define A 65361
# define S 65364
# define D 65363

# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_graph
{
	void	*wall;
	void	*empty;
	void	*collect;
	void	*exit;
	void	*player;
	void	*winner;
}	t_graph;

typedef struct s_init_map
{
	int		height;
	int		length;
	int		x;
	int		y;
	int		player;
	int		escape;
	int		count;
	int		step;
	char	**map;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*maps;
	t_graph	*graph;

}	t_init_map;

void exit_with_error(const char *message, t_init_map *data);
void parsing_maps(t_init_map *data);
void ft_initialise_struct (t_init_map *data, char *fd);
int main(int argc, char **argv);
void free_map(t_init_map *data);
void ft_check_char_count(t_init_map *data);
int ft_check_wall(t_init_map *data);
int ft_check_char( t_init_map *data);
void ft_check_file(t_init_map *data);
void ft_check(t_init_map *data);
int validateMap(t_init_map *init);
void ft_return_initial(t_init_map *data);
void	ft_create_map(t_init_map *data);
void	ft_game_result(t_init_map *data);
int	ft_exit(t_init_map *data);
int	press_key(int keycode, t_init_map *data);
void	ft_graphics(t_init_map *data);
char	*ft_strdup(const char *src);
void free_graphics(t_init_map *data);

# endif