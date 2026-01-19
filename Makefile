# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/19 17:55:17 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g 
DATE = $(shell date +"%y_%m_%d_%H-%M-%S")
BUILD_DIR = .push_swap
# INCLUDES = -Iincludes -Ilibft/includes -Iprintf/includes
NAME = push_swap


#Colors
GREEN='\033[0;32m'
NC='\033[0m'

# Libft Folder
DIR_LIBFT= ./libft
LIB = libft/libft.a
LDFLAGS = -L$(DIR_LIBFT)
LDLIBS = -lft

# Printf Folder
DIR_PRINTF = ./ft_printf
PRI = ft_printf/libftprintf.a
LDFLAGSPRI = -L$(DIR_PRINTF)
LDLIBSPRI = -lft


# All SRC
SRCS = pushswap.c\
	   tester.c\
	   parsing.c\
	   swap.c\
	   rotate.c\
	   number_to_stack.c\
# 	   ft_fillstka.c\

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)



# Commands
all: $(LIB) $(PRI) $(NAME)
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(LIB):
	@$(MAKE) -C $(DIR_LIBFT) -s

$(PRI):
	@$(MAKE) -C $(DIR_PRINTF) -s

$(NAME): $(BUILD_DIR) $(OBJS) $(LIB) $(PRI)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(PRI) -o $(NAME)
	@echo $(GREEN)"✨ Push_swap build created, link with Printf and Libft ✨"$(NC)

$(BUILD_DIR):
	@mkdir -p $@

# règle générique .c -> .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# 	@echo ${GREEN}"✨ Pushswap build created ✨"${NC}

clean:
	make -C $(DIR_LIBFT) clean -s
	make -C $(DIR_PRINTF) clean -s
	@rm -rf $(BUILD_DIR)
	@echo ${GREEN}"Pushswap build is clean.. 🧹"${NC}

fclean: clean
	make -C $(DIR_LIBFT) fclean -s
	make -C $(DIR_PRINTF) fclean -s
	@rm -f $(NAME) 
	@echo ${GREEN}"Pushswap library is clean.. 🧹"${NC}

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

.SILENT:
.PHONY: all clean fclean re
