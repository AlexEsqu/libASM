# Project Name
NAME	= libft.a


# Directories
SRC_DIR_C = libft_C

SRC_DIR_ASM = libft_ASM

OBJ_DIR = obj

INC_DIR = inc


# Files
SRCS_C	= ft_strlen.c ft_strcpy.c ft_strcmp.c ft_strdup.c \
			ft_atoi_base.c ft_list_push_front.c ft_list_size.c ft_list_sort.c ft_list_remove_if.c

SRS_ASM	= ft_strlen.s ft_strspy.s ft_strsmp.s ft_write.s ft_read.s ft_strdup.s \
			ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(addprefix $(SRC_DIR)/, $(SRCS)))


# Compilation options
CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g


# General rules
all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -g $(INC) -c $< -o $@

$(OBJ_DIR):
				mkdir -p $@

clean:
			rm -f $(OBJS)
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
