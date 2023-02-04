# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2023/01/09 12:49:52 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell

BOLD	:=\033[1m

RESET	:=\033[0m

RED	:=\033[91m

GREEN	:=\033[92m

CYAN	:=\033[96m

INC_DIR	:= inc/ 

EXTERN	:= -Ilibft/

SRC_DIR	:= src/

OBJ_DIR	:= obj/

DEP_DIR	:= dep/

RM	:= rm -f

RMDIR	:= rmdir

CC	:= gcc

CFLAGS	:= -Wall -Werror -Wextra -g -I$(INC_DIR) $(EXTERN)

LFLAGS	:= -L./libft -lft -lreadline -fsanitize=address

INC_FS	:= minishell.h minishell_colors.h minishell_env.h minishell_stack.h minishell_tokenizer.h

SRC_FS	:= minishell_terminal.c minishell_signals.c \
       	minishell_env.c minishell.c \
	minishell_tokens.c tokenizer.c \
	minishell_predicates.c minishell_validator.c \
	minishell_stack.c minishell_syntax_analyser.c

INCS	= $(addprefix $(INC_DIR),$(INC_FS))

SRCS	= $(addprefix $(SRC_DIR),$(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR),$(SRC_FS:%=%.o))

DEPS	= $(addprefix $(DEP_DIR),$(SRC_FS:%=%.d))

LIBFT	:= libft.a

define	colorize = 
	@echo "\n$(1)$(2)$(RESET)\n"
endef

all: $(LIBFT) $(NAME)

bonus: $(NAME)

$(LIBFT):
	$(call colorize,$(CYAN),BUILDING LIBFT)
	@make bonus -C libft

$(NAME): $(OBJS)
	$(call colorize,$(GREEN),BUILDING PROJECT)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR),$(notdir $(<:%=%.d))) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJ_DIR):
	$(call colorize,$(BOLD),CREATING OBJ DIRECTORY)
	@mkdir -p $@

$(DEP_DIR):
	$(call colorize,$(BOLD),CREATING DEP DIRECTORY)
	@mkdir -p $@

cleanobj:
	$(call colorize,$(RED),CLEANING OBJECT FILES)
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	$(call colorize,$(RED),CLEANING MAKEFILE DEPENDENCY FILES)
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir
	$(call colorize,$(RED),CLEANING LIBFT)
	@make clean -C libft

fclean: clean
	$(call colorize,$(RED),FCLEANING LIBFT)
	@make fclean -C libft
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
