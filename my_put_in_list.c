/*
** clist.c for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Tue Mar 17 15:13:02 2009 remi prsien-
** Last update Fri Mar 20 11:34:13 2009 kevin duplant
*/

#include "corewar.h"

void		my_list_label(t_list **begin, char *data)
{
  t_list	*new_elem;

  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->data = my_strdup(data);
  new_elem->next = *begin;
  *begin = new_elem;
}

void	aff_list(t_list *begin)
{
  while (begin)
    {
      my_putstr(begin->data);
      my_putchar('\n');
      begin = begin->next;
    }
}
