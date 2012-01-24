/*
** my_strcat.c for minishell3 in /u/all/duplan_k/cu/rendu/c/minishell1
** 
** Made by kevin duplant
** Login   <duplan_k@epitech.net>
** 
** Started on  Tue Mar  3 20:46:01 2009 kevin duplant
** Last update Thu Mar 19 15:31:22 2009 kevin duplant
*/

#include <stdlib.h>

char	*my_strcat(char *s1, char *s2, char *tab)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (s1[i] != '\0')
    {
      tab[i] = s1[i];
      ++i;
    }
  while (s2[a] != '\0')
    tab[i++] = s2[a++];
  tab[i] = '\0';
  return (tab);
}
