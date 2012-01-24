/*
** my_put_nbr.c for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Tue Mar 17 14:30:23 2009 remi prsien-
** Last update Fri Mar 20 13:26:30 2009 kevin duplant
*/

#include "corewar.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
    }
  else
    nb = -nb;
  if (nb < -9)
    {
      my_put_nbr(-(nb / 10));
    }
  my_putchar('0' + - (nb % 10));
  return (0);
}
