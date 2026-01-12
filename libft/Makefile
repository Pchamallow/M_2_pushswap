# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/13 00:30:25 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
DATE = $(shell date +"%y_%m_%d_%H-%M-%S")
NAME = libft.a
FILES = ft_atoi.c \
	ft_bzero.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_strlen.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c\
	ft_strnstr.c \
	ft_itoa.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c\

BONUS_FILES = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

OBJET = ${FILES:.c=.o}
OBJET_BONUS = ${BONUS_FILES:.c=.o}

%.o : %.c
	@${CC} ${FLAGS} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJET}
	@ar rcs $@ ${OBJET}
	@echo "Libft.a is created"

clean :
	@rm -rf ${OBJET} ${OBJET_BONUS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

bonus : ${OBJET_BONUS}
	@ar rcs ${NAME} ${OBJET_BONUS}

zip:
	zip DATE_HOUR.zip *
	mv DATE_HOUR.zip ${DATE}.zip
	mv ${DATE}.zip 00_ARCHIVES

unzip:
	unzip *.zip -d ${DATE}

setup :
	mkdir 00_ARCHIVES

.PHONY : all clean fclean re
