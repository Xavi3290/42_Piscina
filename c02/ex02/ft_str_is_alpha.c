/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:21:05 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/22 11:36:47 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	alpha;
	int	i;

	i = 0;
	alpha = 1;
	while (str[i] != '\0')
	{
		if ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91))
			alpha = 1;
		else
			return (0);
		i++;
	}
	return (alpha);
}
