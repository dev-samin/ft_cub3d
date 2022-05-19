/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:22:05 by samin             #+#    #+#             */
/*   Updated: 2021/04/26 01:28:00 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((src[i] != '\0') && ((dstsize - 1) > i))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen > dstsize)
		return (srclen + dstsize);
	if (dstlen < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - dstlen - 1)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((newstr = malloc((s1_len + s2_len + 1) * sizeof(char))) == 0)
		return (0);
	ft_strlcpy(newstr, s1, s1_len + 1);
	ft_strlcat(newstr, s2, s1_len + s2_len + 1);
	return (newstr);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1) + 1;
	if ((tmp = malloc(len * sizeof(char))) == NULL)
		return (0);
	ft_strlcpy(tmp, s1, len);
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (s == NULL)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((substring = malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	i = start;
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
