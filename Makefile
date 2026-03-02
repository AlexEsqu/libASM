# Project Name
NAME	= libasm.a

# Library in C for comparison
LIBFT	= libft.a


# Directories
SRC_DIR_C = libft

SRC_DIR_ASM = libASM

OBJ_DIR = obj

INC_DIR = inc


# Files

SRCS_C	= ft_strlen.c ft_strcpy.c ft_strcmp.c

# 			ft_strdup.c \
			ft_atoi_base.c ft_list_push_front.c ft_list_size.c ft_list_sort.c ft_list_remove_if.c

SRCS_ASM	=

# 			ft_strlen.s ft_strspy.s ft_strsmp.s ft_write.s ft_read.s ft_strdup.s \
			ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJS_C		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS_C))
OBJS_ASM	= $(patsubst %.s,$(OBJ_DIR)/%.o,$(SRCS_ASM))


# Compilation options
CC		= cc
ASM		= nasm

CFLAGS		= -Wall -Wextra -Werror
DEBUGFLAG	= -g
ASMFLAGS	= -f elf64


# General rules
all:		$(LIBFT) $(NAME)

test:		$(LIBFT) $(NAME)
			$(CC) $(CFLAGS) main.c $(LIBFT) -o libftMain
			$(CC) $(CFLAGS) main.c $(NAME) -o libasmMain

$(LIBFT):	$(OBJ_DIR) $(OBJS_C)
			ar rcs $(LIBFT) $(OBJS_C)

$(NAME):	$(OBJ_DIR) $(OBJS_ASM)
			ar rcs $(NAME) $(OBJS_ASM)

$(OBJ_DIR)/%.o: $(SRC_DIR_C)/%.c
				$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR_ASM)/%.s
				$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR):
				mkdir -p $@

clean:
			rm -f $(OBJS_C) $(OBJS_ASM)
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(LIBFT) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
