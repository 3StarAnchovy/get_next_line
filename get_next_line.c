/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/01/10 20:07:57 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10

static int get_nlidx(char *line)
{
	int	i;

	i = 0;
	while (*(line + i) != '\0')
	{
		if (*(line + i) == '\n')
			return (i);
		i ++;
	}
	return (-1);
}

char *get_next_line(int fd)
{
	char *line;
	char prev_buff[BUFFER_SIZE + 1];
	static char	*tmp_buff;
	int	read_cnt;

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(tmp_buff == NULL)
		tmp_buff = ft_strdup("");
	read_cnt = read(fd,prev_buff,BUFFER_SIZE); // 버퍼 사이즈만큼 반환
	while(read_cnt > 0)
	{
		prev_buff[read_cnt] = '\0';
		tmp_buff = ft_strjoin(tmp_buff,prev_buff);
	}
	line = prev_buff;
	return (line);
}

int main(void)
{
	int fd;
	fd = open("./test.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	//if(get_next_line(fd) == 1)
	//	printf("%s",line);
}
