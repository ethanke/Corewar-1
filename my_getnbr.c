/*
** my_getnbr.c for my_getnbr in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Tue Mar 17 17:39:01 2009 remi prsien-
** Last update Thu Mar 19 15:12:52 2009 kevin duplant
*/

#include "corewar.h"

int	my_getnbr(char *str)
{
  int	res;
  int	a;
  int	i;

  a = 1;
  res = 0;
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      res = res + (a * (str[i] - '0'));
      a = a * 10;
      i = i - 1;
    }
  return (res);
}
