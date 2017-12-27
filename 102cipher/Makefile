##
## Makefile for Makefile in /home/willai_n/rendu/101pong
## 
## Made by noah willaime
## Login   <willai_n@epitech.net>
## 
## Started on  Tue Nov 24 10:35:49 2015 noah willaime
## Last update Wed Dec  9 14:41:00 2015 Arnould Jean-Michel
##

SRC =	102cipher.c

NAME =	102cipher

OBJ =	$(SRC:.c=.o)

CFLAGS= -g
all :	$(NAME)

$(NAME) : $(OBJ)
	cc -lm -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
