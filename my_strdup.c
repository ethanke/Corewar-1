/*
** my_strdup.c for corewar in /u/all/duplan_k/cu/rendu/c/proj/corewar
** 
** Made by kevin duplant
** Login   <duplan_k@epitech.net>
** 
** Started on  Thu Mar 19 16:30:28 2009 kevin duplant
** Last update Thu Mar 19 16:34:50 2009 kevin duplant
*/

#include "corewar.h"

char	*my_strdup(char *tab)
{
  int	i;
  char	*str;

  i = 0;
  str = xmalloc((my_strlen(tab) + 1) * sizeof(*str));
  while (tab[i] != '\0')
    {
      str[i] = tab[i];
      ++i;
    }
  str[i] = '\0';
  return (str);
}
