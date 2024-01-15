/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:15:32 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/20 16:52:36 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_cols(int *grid);
int	check_height_up(int *grid, int *input);
int	check_height_down(int *grid, int *input);
int	check_height_left(int *grid, int *input);
int	check_height_right(int *grid, int *input);

int	generate_rows_check(int *n)
{
	if (n[0] == n[1] || n[0] == n[2] || n[0] == n[3])
		return (0);
	if (n[1] == n[2] || n[1] == n[3])
		return (0);
	if (n[2] == n[3])
		return (0);
	return (1);
}

void	generate_rows(int arr[24][4])
{
	int	i;
	int	n;
	int	m[4];

	i = 0;
	n = 0;
	while (n < 256)
	{
		m[0] = n % 4;
		m[1] = (n / 4) % 4;
		m[2] = (n / 16) % 4;
		m[3] = (n / 64) % 4;
		if (generate_rows_check(m))
		{
			arr[i][0] = m[0] + 1;
			arr[i][1] = m[1] + 1;
			arr[i][2] = m[2] + 1;
			arr[i][3] = m[3] + 1;
			i++;
		}
		n++;
	}
}

void	generate_grid(int comb[24][4], int *grid, int seed)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		grid[i] = comb[seed % 24][i % 4];
		if (i % 4 == 3)
			seed /= 24;
		i++;
	}
}

int	verify_grid(int *grid, int *input)
{
	if (!check_cols(grid))
		return (0);
	if (!check_height_up(grid, input))
		return (0);
	if (!check_height_down(grid, input))
		return (0);
	if (!check_height_left(grid, input))
		return (0);
	if (!check_height_right(grid, input))
		return (0);
	return (1);
}

void	print_grid(int *grid)
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		c = grid[i] + '0';
		write(1, &c, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}
