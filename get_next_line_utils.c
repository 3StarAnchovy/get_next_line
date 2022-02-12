/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:46:12 by jihong            #+#    #+#             */
/*   Updated: 2022/02/12 18:14:33 by jihong           ###   ########.fr       */
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
	if (ret == NULL)
		return (NULL);
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
	size_t		i;
	char		*result;
	int			j;
	size_t		str1_len;
	size_t		str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	result = (char *)malloc(sizeof(char) * (str1_len + str2_len + 1));
	i = 0;
	while (i < str1_len)
	{
		result[i] = str1[i];
		i ++;
	}
	j = 0;
	while (i < str1_len + str2_len)
	{
		result[i] = str2[j];
		i ++;
		j ++;
	}
	result[i] = '\0';
	free((void *)str1);
	return (result);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}
