/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:46:12 by jihong            #+#    #+#             */
/*   Updated: 2021/12/28 19:19:40 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (*(c + i) != '\0')
		i ++;
	return (i);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	char 	*ret;
	size_t	i;

	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len+ 1));
	i = 0;
	while(i < len)
	{
		*(ret + i) = *(str + i);
		i ++;
	}
	*(ret + i) = '\0';
	return (ret);
}
