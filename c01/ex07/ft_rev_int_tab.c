/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:17:22 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/15 13:41:28 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux1;
	int	aux2;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		aux1 = tab[i];
		aux2 = tab[j];
		tab[i] = aux2;
		tab[j] = aux1;
		i++;
		j--;
	}
}
