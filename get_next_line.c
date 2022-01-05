/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/01/05 18:51:15 by jihong           ###   ########.fr       */
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
	static char	buff[BUFFER_SIZE + 1];
	int	read_cnt;

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_cnt = read(fd,prev_buff,BUFFER_SIZE); // 버퍼 사이즈만큼 반환
	if (read_cnt < 0)
		return (0);
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
