# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:36:27 by mbouthai          #+#    #+#              #
#    Updated: 2022/09/16 05:03:36 by mbouthai         ###   ########.fr        #
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

LFLAGS	:= -L./libft -lft -lreadline

INC_FS	:= minishell.h

SRC_FS	:= minishell_terminal.c minishell_signals.c minishell_env.c minishell.c

INCS	= $(addprefix $(INC_DIR), $(INC_FS))

SRCS	= $(addprefix $(SRC_DIR), $(SRC_FS))

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%=%.o)))

DEPS	= $(addprefix $(DEP_DIR), $(notdir $(SRCS:%=%.d)))

LIBFT	:= libft.a

PRINTF	:= libftprintf.a

all: $(LIBFT) $(NAME)

bonus: $(NAME)

$(LIBFT):
	@echo "\n$(CYAN)BUILDING LIBFT$(RESET)\n"
	@make bonus -C libft

$(NAME): $(OBJS)
	@echo "\n$(GREEN)BUILDING PROJECT$(RESET)\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR):
	@echo "\n$(BOLD)CREATING OBJ DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(DEP_DIR):
	@echo "\n$(BOLD)CREATING DEP DIRECTORY$(RESET)\n"
	@mkdir -p $@

$(OBJS): | $(OBJ_DIR)

$(OBJS): | $(DEP_DIR)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%
	$(CC) $(CFLAGS) -MMD -MF $(addprefix $(DEP_DIR), $(notdir $(<:%=%.d))) -c $< -o $@

cleanobj:
	@echo "\n$(RED)CLEANING OBJECT FILES$(RESET)\n"
	-$(RM) $(wildcard $(OBJS))

cleanobjdir: cleanobj
	-$(RMDIR) $(OBJ_DIR)

cleandep:
	@echo "\n$(RED)CLEANING DEPENDENCIES$(RESET)\n"
	-$(RM) $(wildcard $(DEPS))

cleandepdir: cleandep
	-$(RMDIR) $(DEP_DIR)

clean: cleanobjdir cleandepdir
	@echo "\n$(RED)CLEANING LIBFT$(RESET)\n"
	@make clean -C libft

fclean: clean
	@echo "\n$(RED)FCLEANING LIBFT$(RESET)\n"
	@make fclean -C libft
	-$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all bonus cleanobj cleanobjdir cleandep cleandepdir clean fclean
