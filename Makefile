# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 18:40:53 by pswirgie          #+#    #+#              #
#    Updated: 2026/01/31 19:54:11 by pswirgie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= cc
AR_FLAGS	:= ar
CFLAGS		:= -Wall -Wextra -Werror
DATE		:= $(shell date +"%y_%m_%d_%H-%M-%S")
BUILD_DIR	:= .push_swap

# Includes
INCLUDES	:= \
				-Iincludes \
		   		-Ilib/libft/ \

NAME		:= push_swap

#Colors
GREEN		:='\033[0;32m'
NC			:='\033[0m'

# Libft Folder
DIR_LIBFT	:= lib/libft
LIB			:= lib/libft/libft.a

# All SRC
SRCS		:= 						\
			src/pushswap.c			\
			src/algorithm.c			\
			src/push.c				\
			src/fill_index.c		\
			src/ft_max.c			\
			src/create_stack_a.c	\
			src/is_int_minmax.c		\
			src/parse.c 			\
			src/apply_butterfly.c	\
			src/number_to_stack.c	\
			src/rotate.c			\

OBJS		:= $(SRCS:src/%.c=$(BUILD_DIR)/%.o)

# ================= COMMANDS ================= #

all: $(LIB) $(NAME)
	@echo $(GREEN)"💫 All compiled 💫\n"$(NC)

$(LIB):
	@$(MAKE) -C $(DIR_LIBFT) -s

$(NAME): $(BUILD_DIR) $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB) -o $(NAME)
	@echo $(GREEN)"\n✨ Push_swap build created, linked with Printf and Libft ✨\n"$(NC)


$(BUILD_DIR):
	@mkdir -p $@

# règle générique .c -> .o 🔨
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(DIR_LIBFT) clean -s
	@rm -rf $(BUILD_DIR)
	@echo $(GREEN)"Pushswap build is clean.. 🧹"$(NC)

fclean: clean
	@$(MAKE) -C $(DIR_LIBFT) fclean -s
	@rm -f $(NAME)
	@echo $(GREEN)"Pushswap library is clean.. 🧹"$(NC)

re: fclean 
	$(MAKE) all

# ================= Archives ================= #

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
.PHONY: all clean fclean re setup unzip zip
