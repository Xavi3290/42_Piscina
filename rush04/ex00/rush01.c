/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:49:20 by aprenafe          #+#    #+#             */
/*   Updated: 2023/08/13 19:26:00 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x > 0 && y > 0)
	{
		row = 0;
		while (row++ < y)
		{
			col = 0;
			while (col++ < x)
			{
				if (col == 1 && row == 1)
					ft_putchar('/');
				else if (row == y && col == x && y != 1 && x != 1)
					ft_putchar('/');
				else if ((col == x && row == 1) || (row == y && col == 1))
					ft_putchar('\\');
				else if (col > 1 && row > 1 && row < y && col < x)
					ft_putchar(' ');
				else
					ft_putchar('*');
			}
			ft_putchar('\n');
		}
	}
}
