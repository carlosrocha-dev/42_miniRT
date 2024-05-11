/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:50:24 by bluiz-al          #+#    #+#             */
/*   Updated: 2024/01/21 16:32:42 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size)
	{
		if (size > dst_len)
		{
			size -= dst_len;
			dst += dst_len;
			src_len += dst_len;
			while (*src && --size)
				*dst++ = *(char *)src++;
			*dst = '\0';
		}
		else
			src_len += size;
	}
	return (src_len);
}
