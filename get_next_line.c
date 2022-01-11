/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/01/11 20:31:30 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 10


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
		st_save = ft_strdup("",1);
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
