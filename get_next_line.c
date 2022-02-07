/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/02/07 17:12:58 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_line(char *str)
{
	int	i;
	char *line;
	if(ft_strlen(str) == 0)
		return (0);
	if (str == NULL)
		return (NULL);
	i = 0;
	while(str[i] && str[i] != '\n' && str)
		i ++;
	line = ft_strndup(str, i + 1);
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
	line = ft_strndup(&str[i + 1], str_len - i);
	line[str_len - i] = '\0';
	free(str);
	if(ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
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
		if (!read_cnt)
			break;
		st_save = ft_strjoin(st_save,buff);
	}
	line = get_line(st_save);
	st_save = split_line(st_save);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;
// 	fd = open("./test.txt",O_RDONLY);
// 	i = 0;
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		i ++;
// 		printf("%d번째 줄 : %s",i,line);
// 	}
// 	//if(get_next_line(fd) == 1)
// 	//	printf("%s",line);
// }

// int main(void)
// {
// 	int fd;
// 	fd = open("./test.txt",O_RDONLY);
// 	if(get_next_line(fd) == NULL)
// 		printf("ok");
// 	printf("줄 : %s\n",get_next_line(fd));
// 	printf("줄 : %s\n",get_next_line(fd));
// 	printf("줄 : %s\n",get_next_line(fd));
// 	printf("줄 : %s\n",get_next_line(fd));
// 	printf("줄 : %s\n",get_next_line(fd));
// 	printf("줄 : %s\n",get_next_line(fd));
// 	if (get_next_line(fd) == 0)
// 		printf("끝@");
// 	//if(get_next_line(fd) == 1)
// 	//	printf("%s",line);
// }
