/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:08:57 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/20 17:06:29 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	generate_rows(int comb[24][4]);
void	generate_grid(int comb[24][4], int *grid, int seed);
int		verify_grid(int *grid, int *input);
void	print_grid(int *grid);

int	validate_input(int argn, char **args, int *input)
{
	int		i;
	char	*str;

	if (argn != 2)
		return (0);
	else
	{
		i = 0;
		str = args[1];
		while (i < 32)
		{
			if (i == 31 && str[i] != '\0')
				return (0);
			else if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
				return (0);
			else if (i < 31 && i % 2 != 0 && str[i] != ' ')
				return (0);
			if (i % 2 == 0)
				input[i / 2] = str[i] - 48;
			i++;
		}
	}
	return (1);
}

int	get_result_seed(int comb[24][4], int *grid, int *input)
{
	int	seed;

	seed = 0;
	while (seed < 331776)
	{
		generate_grid(comb, grid, seed);
		if (verify_grid(grid, input))
			return (seed);
		else
			seed++;
	}
	return (-1);
}

int	main(int argn, char **args)
{
	int	comb[24][4];
	int	grid[16];
	int	input[16];
	int	result_seed;

	generate_rows(comb);
	if (validate_input(argn, args, input))
		result_seed = get_result_seed(comb, grid, input);
	else
		result_seed = -1;
	if (result_seed == -1)
		write(1, "Error\n", 6);
	else
		print_grid(grid);
	return (0);
}
