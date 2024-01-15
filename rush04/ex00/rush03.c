/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:08:25 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/13 19:53:00 by gprada-t         ###   ########.fr       */
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
				if ((col == 1 && row == 1) || (row == y && col == 1)) 
					ft_putchar('A');
				else if ((col == x && row == y) || (col == x && row == 1))
					ft_putchar('C');
				else if (col > 1 && row > 1 && row < y && col < x)
					ft_putchar(' ');
				else
					ft_putchar('B');
			}
			ft_putchar('\n');
		}
	}
}
