/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:57 by jihong            #+#    #+#             */
/*   Updated: 2022/01/11 22:17:01 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strndup(char *str, int n);
int	check_newline(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strrchr(const char *str, int c);
