# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/13 00:33:39 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
DATE = $(shell date +"%y_%m_%d_%H-%M-%S")

# Actual Folder
SRCS_MAIN = ft_printchar.c\
			ft_printf.c\
			ft_printpercent.c\
			ft_putpointer.c\
			../libft/ft_putstr_fd.c\
			../libft/ft_putnbr_fd.c\
			../libft/ft_putchar_fd.c\
			../libft/ft_strlen.c\

# All SRC
SRCS = $(SRCS_MAIN) 

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a


# Commands
all: $(NAME)
	@echo ""
	@echo "All compiled"

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# règle générique .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo ""
	@echo ".o are cleaned.. 🧹"

fclean: clean
	rm -f $(NAME)
	@echo ".a are cleaned.. 🧹"

re: fclean all



#ARCHIVES
zip:
	zip DATE_HOUR.zip *
	mv DATE_HOUR.zip ${DATE}.zip
	mv ${DATE}.zip 00_ARCHIVES

unzip:
	unzip *.zip -d ${DATE}

setup :
	mkdir 00_ARCHIVES


.PHONY: all clean fclean re
