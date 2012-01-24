/*
** xread.c for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Sat Mar 14 17:27:27 2009 remi prsien-
** Last update Sat Mar 14 17:30:38 2009 remi prsien-
*/

#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

char	*xread(int fd, char *buffer)
{
  int	a;
  int	i;

  a = read(fd, buffer, BUF_SIZE);
  if (a == -1)
    {
      i = write(1, "Could not read\n", 16);
      if (i == -1)
	{
	  exit(EXIT_FAILURE);
	}
      exit(EXIT_FAILURE);
    }
  return (buffer);
}
