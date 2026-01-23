# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/23 23:36:30 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
DATE = $(shell date +"%y_%m_%d_%H-%M-%S")
BUILD_DIR = .push_swap

# Includes 🏗️
INCLUDES = -Iincludes \
           -Iincludes/libft/ \
           -Iincludes/ft_printf/

NAME = push_swap

#Colors 🎨
GREEN='\033[0;32m'
NC='\033[0m'

# Libft Folder 📚
DIR_LIBFT = includes/libft
LIB = includes/libft/libft.a

# Printf Folder 🖨️
DIR_PRINTF = includes/ft_printf
PRI = includes/ft_printf/libftprintf.a

# All SRC 📂
SRCS = src/pushswap.c\
       src/tester.c\
       src/parse.c\
       src/swap.c\
       src/butterfly.c\
       src/number_to_stack.c\
       src/rotate.c\
       src/reverse_rotate.c
# 	   ft_fillstka.c\

OBJS = $(SRCS:src/%.c=$(BUILD_DIR)/%.o)



# ================= COMMANDS ================= #

all: $(LIB) $(PRI) $(NAME)
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(LIB):
	@$(MAKE) -C $(DIR_LIBFT) -s

$(PRI):
	@$(MAKE) -C $(DIR_PRINTF) -s

$(NAME): $(BUILD_DIR) $(OBJS) $(LIB) $(PRI)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB) $(PRI) -o $(NAME)
	@echo $(GREEN)"\n✨ Push_swap build created, linked with Printf and Libft ✨\n"$(NC)

$(BUILD_DIR):
	@mkdir -p $@

# règle générique .c -> .o 🔨
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(DIR_LIBFT) clean -s
	@make -C $(DIR_PRINTF) clean -s
	@rm -rf $(BUILD_DIR)
	@echo $(GREEN)"Pushswap build is clean.. 🧹"$(NC)

fclean: clean
	@make -C $(DIR_LIBFT) fclean -s
	@make -C $(DIR_PRINTF) fclean -s
	@rm -f $(NAME)
	@echo $(GREEN)"Pushswap library is clean.. 🧹"$(NC)

re: fclean all


# ================= Archives 📦 ================= #

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
