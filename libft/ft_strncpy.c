/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:35:47 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/14 15:35:49 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (length < len)
	{
		dst[length] = '\0';
		length++;
	}
	return ((char *)dst);
}
