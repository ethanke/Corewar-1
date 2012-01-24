/*
** my_tool.c for minishell in /u/all/duplan_k/cu/rendu/c/minishell3
** 
** Made by kevin duplant
** Login   <duplan_k@epitech.net>
** 
** Started on  Wed Mar  4 10:37:16 2009 kevin duplant
** Last update Fri Mar 20 14:16:59 2009 kevin duplant
*/

#include <unistd.h>

void     my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] != '\0') && (i < n))
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  return (0);
}
