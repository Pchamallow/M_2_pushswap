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
BUILD_DIR = .push_swap
INCLUDES = -Iincludes -Ilibft/includes
NAME = push_swap
LIB = libft/libft.a


#Colors
GREEN='\033[0;32m'
NC='\033[0m'


# Libft Folder
DIR_LIBFT= ./libft
LDFLAGS = -L$(DIR_LIBFT)
LDLIBS = -lft


# All SRC
SRCS = pushswap.c\
	   ft_fillstka.c\

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)




# Commands
all: $(LIB) $(NAME)
	@echo $(GREEN)"💫 All compiled 💫"$(NC)

$(LIB):
	@$(MAKE) -C $(DIR_LIBFT)

$(NAME): $(BUILD_DIR) $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo $(GREEN)"✨ $(NAME) created ✨"$(NC)

$(BUILD_DIR):
	@mkdir -p $@

# règle générique .c -> .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo make -C $(DIR_LIBFT) clean
	@echo rm -rf $(BUILD_DIR)
	@echo ${GREEN}"Build is clean.. 🧹"${NC}

fclean: clean
	@$(make) -C $(DIR_LIBFT) fclean
	@rm -f $(NAME)
	@echo ${GREEN}"Pushswap is clean.. 🧹"${NC}

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
