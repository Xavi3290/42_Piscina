/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:10:53 by gprada-t          #+#    #+#             */
/*   Updated: 2023/08/13 19:22:23 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	r;
	int	c;

	if (x > 0 && y > 0)
	{
		r = 0;
		while (r++ < y)
		{
			c = 0;
			while (c++ < x)
			{
				if ((r == y && c == 1) || (r == 1 && c == x))
					ft_putchar('o');
				else if ((r == 1 && c == 1) || (r == y && c == x))
					ft_putchar('o');
				else if (c > 1 && r > 1 && c < x && r < y)
					ft_putchar(' ');
				else if (c == 1 || c == x)
					ft_putchar('|');
				else
					ft_putchar('-');
			}
			ft_putchar('\n');
		}
	}
}
