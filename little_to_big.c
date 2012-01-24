/*
** test.c for endian in /u/all/duplan_k/cu/rendu/c/proj/corewar
** 
** Made by kevin duplant
** Login   <duplan_k@epitech.net>
** 
** Started on  Thu Mar 26 13:04:34 2009 kevin duplant
** Last update Sat Mar 28 15:11:58 2009 kevin duplant
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	xopen(char *str)
{
  if (open(str, O_CREAT | O_WRONLY) == -1)
    exit(EXIT_FAILURE);
  return (open(str, O_CREAT | O_WRONLY));
}

void	xwrite(int fd, int i, int a)
{
  if (write(fd, &i, a) == -1)
    exit(EXIT_FAILURE);
}

void		convert_little_to_big(int i, char *str)
{
  unsigned char	oct[4];
  int		fd;
  int		j;
  int		cmp;

  j = 0;
  cmp = 255;
  while (j < 4)
    {
      oct[j++] = 255 & i;
      i /= 256;
    }
  j = 0;
  i = 0;
  cmp = 1;
  while (j < 4)
    {
      i += (oct[3 - j++] * cmp);
      cmp *= 256;
    }
  fd = xopen(str);
  xwrite(fd, i, 4);
}

int	main()
{
  int	i;
  char	*str;

  str = "toto.cor";
  i = 0xea83f3;
  convert_little_to_big(i, str);
  return (0);
}
