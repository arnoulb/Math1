##
## Makefile for Makefile in /home/willai_n/rendu/101pong
## 
## Made by noah willaime
## Login   <willai_n@epitech.net>
## 
## Started on  Tue Nov 24 10:35:49 2015 noah willaime
## Last update Wed Nov 25 18:51:58 2015 noah willaime
##

SRC =	101pong.c

NAME =	101pong

OBJ =	$(SRC:.c=.o)

all :	$(NAME)

$(NAME) : $(OBJ)
	cc -lm -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
