/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:46:12 by jihong            #+#    #+#             */
/*   Updated: 2022/01/12 18:48:33 by jihong           ###   ########.fr       */
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

char	*ft_strndup(char *str, size_t n)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		*(ret + i) = *(str + i);
		i ++;
	}
	*(ret + i) = '\0';
	return (ret);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	char	*result;
	int		j;

	result = (char *)malloc(sizeof(char)
			* st(ft_strlen(str1)) + (ft_strlen(str2)) + 1);
	i = 0;
	while (i < ft_strlen(str1))
	{
		result[i] = str1[i];
		i ++;
	}
	j = 0;
	while (i < ft_strlen(str1) + ft_strlen(str2))
	{
		result[i] = str2[j];
		i ++;
		j ++;
	}
	result[i] = '\0';
	return (result);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}
