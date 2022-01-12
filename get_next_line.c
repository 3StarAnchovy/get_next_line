/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/01/12 16:51:33 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

static char*get_line(char *str)
{
	int	i;
	char *line;

	if (str == NULL)
		return (NULL);
	i = 0;
	while(str[i] && str[i] != '\n' && str)
		i ++;
	line = ft_strndup(str, i);
	line[i + 1] = '\0';
	return (line);
}

static char	*split_line(char *str)
{
	int		i;
	char	*line;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n' && str)
		i ++;
	if(str[i] == '\0')
	{
		free(str);
		return (0);
	}
	line = ft_strndup(&str[i - 1], str_len - i);
	line[str_len - i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	char	*line; // 최종리턴값
	char	buff[BUFFER_SIZE + 1];
	static char	*st_save;
	int	read_cnt;

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (st_save == NULL)
		st_save = ft_strndup("",1);
	read_cnt = 1;
	while(read_cnt != 0 && !(check_newline(st_save)))
	{
		read_cnt = read(fd,buff,BUFFER_SIZE);
		if (read_cnt == -1)
			return (NULL);
		buff[read_cnt] = '\0';
		if (read_cnt == 0)
			break;
		st_save = ft_strjoin(st_save,buff);
	}
	line = get_line(st_save);
	st_save = split_line(st_save);
	printf("백업 : %s\n",st_save);
	return (line);
	printf("백업");
}

int main(void)
{
	int fd;
	fd = open("./test.txt",O_RDONLY);
	printf("줄 : %s",get_next_line(fd));
	//if(get_next_line(fd) == 1)
	//	printf("%s",line);
}
