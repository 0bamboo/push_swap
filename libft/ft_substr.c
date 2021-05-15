/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:51:00 by abdait-m          #+#    #+#             */
/*   Updated: 2019/11/21 15:50:38 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*sub;

	if (!s || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	j = 0;
	while (j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
