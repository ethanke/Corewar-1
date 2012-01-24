/*
** xmalloc.c for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Fri Mar  6 16:59:24 2009 remi prsien-
** Last update Fri Mar  6 17:01:21 2009 remi prsien-
*/

#include <unistd.h>
#include <stdlib.h>

void	*xmalloc(int nb_word)
{
  int	i;
  void	*str;

  str = malloc(nb_word);
  if (str == NULL)
    {
      i = write(2, "Could not allocate memory", 26);
      if (i == -1)
	{
	  exit(EXIT_FAILURE);
	}
      exit(EXIT_FAILURE);
    }
  return (str);
}
