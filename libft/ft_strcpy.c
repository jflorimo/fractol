/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 17:21:05 by jflorimo          #+#    #+#             */
/*   Updated: 2013/12/07 17:21:39 by jflorimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	char	*s;

	s = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s);
}
