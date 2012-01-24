/*
** assembleur.c for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Fri Mar  6 15:56:44 2009 remi prsien-
** Last update Fri Mar 20 17:05:54 2009 kevin duplant
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"

void	my_list_label(t_list **begin, char *data);
void	aff_list(t_list *begin);

char	*COR_TO_S(char *S_FILE)
{
  int	i;
  char	*tab;
  char	*str;
  char	*COR;

  i = 0;
  str = ".cor";
  COR = xmalloc((my_strlen(S_FILE) + my_strlen(str) + 1) * sizeof(*COR));
  tab = xmalloc((my_strlen(S_FILE) + 1) * sizeof(*tab));
  while (S_FILE[i] != '.')
    {
      tab[i] = S_FILE[i];
      ++i;
    }
  tab[i] = '\0';
  my_strcat(tab, str, COR);
  return (COR);
}

int	check_chars(char c)
{
  int	i;

  i = 0;
  while (LABEL_CHARS[i] != '\0')
    {
      if (c == LABEL_CHARS[i])
	return (0);
      ++i;
    }
  return (1);
}

void	error_label(char *tab, int i)
{
  int	a;
  int	n;

  a = 0;
  n = 1;
  while (a <= i)
    {
      if (tab[a] == '\n')
	++n;
      ++a;
    }
  while (tab[i - 1] != '\n')
    --i;
  my_putstr("label ");
  while (tab[i] != LABEL_CHAR)
    {
      my_putchar(tab[i]);
      ++i;
    }
  my_putstr(" undefine line ");
  my_put_nbr(n);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}

int	check_chars_bis(char *tab, int i)
{
  int	a;

  a = 0;
  while (tab[i - 1] != '\n')
    --i;
  while (tab[i] != LABEL_CHAR)
    {
      while (LABEL_CHARS[a] != '\0')
	{
	  if (tab[i] == LABEL_CHARS[a])
	    break;
	  ++a;
	}
      if (LABEL_CHARS[a] == '\0')
	error_label(tab, i);
      a = 0;
      ++i;
    }
  return (0);
}

int	count_char(char *tab, int i)
{
  int	a;

  a = 0;
  while (tab[i] != LABEL_CHAR)
    {
      ++i;
      ++a;
    }
  return (a);
}

void	count_line_bis(char *tab, int i, t_list *begin, int n)
{
  int	a;
  char	*str;

  a = 0;
  --i;
  str = xmalloc(count_char(tab, i) + 1 * sizeof(*str));
  while (tab[i - 1] != '\n')
    --i;
  while (tab[i] != LABEL_CHAR)
    {
      str[a] = tab[i];
      ++i;
      ++a;
    }
  str[a] = '\0';
  if (my_strcmp(str, begin->data) == 0)
    {
      my_put_nbr(n);
      my_putchar('\n');
      exit(EXIT_FAILURE);
    }
  free(str);
}

void	count_line(char *tab, t_list *begin)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (tab[i] != '\0')
    {
      if (tab[i] == '\n')
	++n;
      if (tab[i] == LABEL_CHAR)
	count_line_bis(tab, i, begin, n);
      ++i;
    }
}

void	check_list(t_list *begin, char *tab)
{
  char	*str;

  str = begin->data;
  begin = begin->next;
  while (begin)
    {
      if (my_strcmp(str, begin->data) == 0)
	{
	  my_putstr("label ");
	  my_putstr(begin->data);
	  my_putstr(" multiple definition line ");
	  count_line(tab, begin);
	  exit(EXIT_FAILURE);
	}
      begin = begin->next;
    }
}

void	check_label(char *tab, int i, t_list **begin)
{
  char	*str;
  int	a;

  a = 0;
  --i;
  if (check_chars(tab[i]) == 0  && check_chars_bis(tab, i) == 0)
    {
      str = xmalloc(count_char(tab, i) + 1 * sizeof(*str));
      while (tab[i - 1] != '\n')
	--i;
      while (tab[i] != LABEL_CHAR)
	{
	  str[a] = tab[i];
	  ++i;
	  ++a;
	}
      str[a] = '\0';
      my_list_label(begin, str);
      free(str);
    }
}

void		LABEL_PARS(char *tab)
{
  int		i;
  t_list	*begin;

  i = 0;
  begin = NULL;
  while (tab[i] != '\0')
    {
      if (tab[i] == LABEL_CHAR)
	check_label(tab, i, &begin);
      ++i;
    }
  while (begin)
    {
      check_list(begin, tab);
      begin = begin->next;
    }
}

void	pars(char *tab)
{
  LABEL_PARS(tab);
}

int	convert(char *S_FILE)
{
  int	FD_O;
  int	i;
  char	*tab;
  char	buff[1000];

  i = 0;
  if ((FD_O = open(S_FILE, O_RDONLY)) == -1)
    {
      my_putstr("Can't read the file\n");
      return (EXIT_FAILURE);
    }
  while (i != 1)
    {
      tab = xread(FD_O, buff);
      if (tab == NULL)
	break;
      pars(tab);
      ++i;
    }
  close(FD_O);
  return (0);
}

int	COR_OPEN(char *str, char *S_FILE)
{
  int	COR_FILE;

  if ((COR_FILE = open(str, O_CREAT | O_RDWR, 0777)) == -1)
    {
      my_putstr("Can't create the file\n");
      return (EXIT_FAILURE);
    }
  convert(S_FILE);
  close(COR_FILE);
  return (0);
}

int	main(int ac, char **av)
{
  char	*str;

  if (ac != 2)
    {
      my_putstr("Enter the filename\n");
      return (EXIT_FAILURE);
    }
  str = COR_TO_S(av[1]);
  COR_OPEN(str, av[1]);
  return (EXIT_SUCCESS);
}
