##
## Makefile for Makefile in /u/all/prsien_r/cu/rendu/c/proj/corewar
## 
## Made by remi prsien-
## Login   <prsien_r@epitech.net>
## 
## Started on  Fri Feb 13 14:16:02 2009 remi prsien-
## Last update Fri Mar 20 13:26:06 2009 kevin duplant
##

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_linux	=	gcc

CC		=	$(CC_$(OSTYPE))

NAME		=	asm
SRC		=	assembly.c		\
			my_tool.c		\
			my_put_in_list.c	\
			my_put_nbr.c		\
			my_getnbr.c		\
			my_strcat.c		\
			my_strdup.c		\
			xmalloc.c		\
			xread.c

OBJ		=	$(SRC:.c=.o)
CFLAGS		+=	-W -Wall -ansi -pedantic
RM		=	rm -f

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)
			$(RM) *~

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean re fclean