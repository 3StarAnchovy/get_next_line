/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:11 by jihong            #+#    #+#             */
/*   Updated: 2022/01/05 13:19:05 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 5

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int	flag;

	if(fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (0);
	flag = read(fd,buff,BUFFER_SIZE);
	if (flag < 0)
		return (0);
	line = buff;
	return (1);
}

int main(void)
{
	int fd;
	char *line = 0;
	fd = open("./test.txt",O_RDONLY);
	if(get_next_line(fd,&line) == 1)
		printf("%s",line);
}
