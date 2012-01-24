/*
** convert_to_hex.c for corewar in /u/all/stelle_t/cu/rendu/c/proj/corewar
** 
** Made by thomas stelletta
** Login   <stelle_t@epitech.net>
** 
** Started on  Fri Mar 20 11:17:09 2009 thomas stelletta
** Last update Thu Mar 26 13:12:47 2009 kevin duplant
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_struct
{
  int	y;
  char	str[5];
  char	*str2;
  char	bin[5];
  int	a;
  int	i;
  int	j;
  int	z;
  char	hex[27];
}		t_struct;

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	find_pos(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	len_base;
  int	len_str;
  int	fact;

  if (str[0] == '-')
    {
      return (-my_getnbr_base(&str[1], base));
    }
  fact = 1;
  len_base = strlen(base);
  len_str = strlen(str) - 1;
  result = 0;
  while (len_str >= 0)
    {
      result = result + find_pos(str[len_str], base) * fact;
      fact = len_base * fact;
      len_str = len_str - 1;
    }
  return (result);
}

char	*convert_to_hex3(char *tab, t_struct *s)
{
  s->i = 0;
  s->z = 0;
  while (tab[s->i] != '\0')
    {
      ++s->i;
      if (s->i % 4 == 0)
	{
	  s->a = s->i - 4;
	  s->j = 0;
	  while (s->a != s->i)
	    {
	      s->str[s->j] = tab[s->a];
	      ++s->a;
	      ++s->j;
	    }
	  s->str[s->j] = '\0';
	  s->a = my_getnbr_base(s->str, "01");
	  s->hex[s->z] = s->str2[s->a];
	  ++s->z;
	}
    }
  s->hex[s->z] = '\0';
  printf("%s\n", s->hex);
  return (s->hex);
}

void	copy_tab(char *tab, t_struct *s)
{
  s->y = 0;
  while (tab[s->y] != '\0')
    {
      s->bin[s->a] = tab[s->y];
      ++s->a;
      ++s->y;
    }
  s->bin[s->a] = '\0';
  my_strcpy(tab, s->bin);
}

void	replace_by_zero(char *tab, t_struct *s, int i)
{
  if ((s->y % 4) > 0 && i == 1)
    {
      while ((s->y % 4) != 0)
	{
	  s->bin[s->a] = '0';
	  ++s->a;
	  ++s->y;
	}
      copy_tab(tab, s);
    }
}

char	*convert_bin_hex(char *tab, int i)
{
  t_struct s;
  char	*str;

  s.y = strlen(tab);
  s.a = 0;
  s.str2 = "0123456789ABCDEF";
  if ((s.y % 4) > 0 && i == 0)
    {
      while ((s.y % 4) != 0)
	{
	  tab[s.y] = '0';
	  ++s.y;
	}
      tab[s.y] = '\0';
    }
  replace_by_zero(tab, &s, i);
  str = convert_to_hex3(tab, &s);
  return (str);
}
