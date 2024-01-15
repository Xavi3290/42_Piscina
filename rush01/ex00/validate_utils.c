/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:38:51 by pfontenl          #+#    #+#             */
/*   Updated: 2023/08/20 16:37:37 by pfontenl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_cols(int *grid)
{
	int	col;
	int	row;
	int	val_count[4];

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			val_count[row] = 0;
			row++;
		}
		row = 0;
		while (row < 4)
		{
			val_count[grid[row * 4 + col] - 1]++;
			row++;
		}
		if (val_count[0] * val_count[1] * val_count[2] * val_count[3] != 1)
			return (0);
		col++;
	}
	return (1);
}

int	check_height_up(int *grid, int *input)
{
	int	col;
	int	row;
	int	max_height;
	int	seen_boxes;

	col = 0;
	while (col < 4)
	{
		row = 0;
		max_height = 0;
		seen_boxes = 0;
		while (row < 4)
		{
			if (grid[row * 4 + col] > max_height)
			{
				seen_boxes++;
				max_height = grid[row * 4 + col];
			}
			row++;
		}
		if (seen_boxes != input[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_height_down(int *grid, int *input)
{
	int	col;
	int	row;
	int	max_height;
	int	seen_boxes;

	col = 0;
	while (col < 4)
	{
		row = 3;
		max_height = 0;
		seen_boxes = 0;
		while (row >= 0)
		{
			if (grid[row * 4 + col] > max_height)
			{
				seen_boxes++;
				max_height = grid[row * 4 + col];
			}
			row--;
		}
		if (seen_boxes != input[col + 4])
			return (0);
		col++;
	}
	return (1);
}

int	check_height_left(int *grid, int *input)
{
	int	col;
	int	row;
	int	max_height;
	int	seen_boxes;

	row = 0;
	while (row < 4)
	{
		col = 0;
		max_height = 0;
		seen_boxes = 0;
		while (col < 4)
		{
			if (grid[row * 4 + col] > max_height)
			{
				seen_boxes++;
				max_height = grid[row * 4 + col];
			}
			col++;
		}
		if (seen_boxes != input[row + 8])
			return (0);
		row++;
	}
	return (1);
}

int	check_height_right(int *grid, int *input)
{
	int	col;
	int	row;
	int	max_height;
	int	seen_boxes;

	row = 0;
	while (row < 4)
	{
		col = 3;
		max_height = 0;
		seen_boxes = 0;
		while (col >= 0)
		{
			if (grid[row * 4 + col] > max_height)
			{
				seen_boxes++;
				max_height = grid[row * 4 + col];
			}
			col--;
		}
		if (seen_boxes != input[row + 12])
			return (0);
		row++;
	}
	return (1);
}
