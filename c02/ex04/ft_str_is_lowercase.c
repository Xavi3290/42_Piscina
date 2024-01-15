/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:34:19 by xroca-pe          #+#    #+#             */
/*   Updated: 2023/08/22 12:30:17 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	low;
	int	i;

	i = 0;
	low = 1;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
			low = 1;
		else
			return (0);
		i++;
	}
	return (low);
}
