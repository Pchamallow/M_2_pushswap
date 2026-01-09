# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/05 18:42:27 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** 

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
DATE = $(shell date +"%y_%m_%d_%H-%M-%S")

#Colors
GREEN='\033[0;32m'
NC='\033[0m'

# Actual Folder
SRCS_MAIN = fichier.c\
	fichier.c\

# Libft Folder
SRCS_LIBFT = fichier.c\
	fichier.c\

# All SRC
SRCS = $(SRCS_MAIN) $(SRCS_LIBFT)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a


# Commands
all: $(NAME)
	@echo ""
	@echo "${GREEN}💫 All compiled 💫${NC}"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# règle générique .c -> .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo ""
	@echo "${GREEN}.o are cleaned.. 🧹${NC}"

fclean: clean
	@rm -f $(NAME)
	@echo "${GREEN}.a are cleaned.. 🧹${NC}"

re: fclean all



#ARCHIVES
zip:
	@zip DATE_HOUR.zip *
	@mv DATE_HOUR.zip ${DATE}.zip
	@mv ${DATE}.zip 00_ARCHIVES
	@echo "${GREEN}All is zipped.${NC}"

unzip:
	@unzip *.zip -d ${DATE}
	@echo "${GREEN}All is unzipp.${NC}"

setup :
	@mkdir 00_ARCHIVES
	@echo "${GREEN}Setup is good !${NC}"
	


.PHONY: all clean fclean re


#Ameliorations a ajouter 
# sans @ = calcul de la commande + print de la commande
#avec @ = juste print de la commande
#COULEURS : 
# notamment dans le c pour les segment fault etc avoir du rouge pour une meilleure visibilité
