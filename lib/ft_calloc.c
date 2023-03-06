/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:14:28 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/21 15:44:04 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (SIZE_MAX <= size || SIZE_MAX <= count)
		return (NULL);
	if (SIZE_MAX <= size * count)
		return (NULL);
	str = (void *) malloc(size * count);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
