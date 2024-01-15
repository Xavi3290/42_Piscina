/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:45:43 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/31 15:58:40 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int mult;

	if (nb == 0 && power == 0)
		return (1);
	else if ( nb <= 0 || power < 0) 
		return (0);
	else
	{
		mult = 1;
		i = 0;
		while (i < power)
		{
			mult *= nb;
			i++;	
		}
	}
	return (mult);

}
