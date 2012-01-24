/*
** corewar.h for corewar in /u/all/prsien_r/cu/rendu/c/proj/corewar
** 
** Made by remi prsien-
** Login   <prsien_r@epitech.net>
** 
** Started on  Fri Mar  6 16:20:51 2009 remi prsien-
** Last update Tue Apr 14 11:09:46 2009 kevin duplant
*/

#ifndef _COREWAR_H_
# define _COREWAR_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
}		t_list;

void	my_putchar(char d);
void	my_putstr(char *str);
void	*xmalloc(int nb_word);

int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_put_nbr(int nb);

char	*xread(int fd, char *buffer);
char	*my_strcat(char *s1, char *s2, char *tab);
char	*my_strdup(char *tab);

#endif /* !_COREWAR_H_ */
