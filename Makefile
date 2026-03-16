# Project Name
NAME	= libasm.a

# Library in C for comparison
LIBFT	= libft.a


# Directories
SRC_DIR_C = libft

SRC_DIR_ASM = libASM

OBJ_DIR_C = obj_C

OBJ_DIR_ASM = obj_ASM

LIBFT_ASM_DIR = libft_decompiled

INC_DIR = inc


# Files

SRCS_C		= 	ft_strlen.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strlen_in_C.c \
				ft_strcmp_in_C.c \
				ft_strcpy_in_C.c \
				ft_strdup_in_C.c

SRCS_ASM	= 	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s

# 			ft_strlen.s ft_strspy.s ft_strsmp.s ft_write.s ft_read.s ft_strdup.s \
			ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJS_C		= $(patsubst %.c,$(OBJ_DIR_C)/%.o,$(SRCS_C))
OBJS_ASM	= $(patsubst %.s,$(OBJ_DIR_ASM)/%.o,$(SRCS_ASM))


# Compilation options
CC		= clang
ASM		= nasm

CFLAGS		= -Wall -Wextra -Werror
DEBUGFLAG	= -g
ASMGENFLAG	= -S -mllvm --x86-asm-syntax=intel
ASMFLAGS	= -f elf64

#####################################
#									#
#			MANDATORY RULES			#
#									#
#####################################

all:		$(NAME)

$(NAME):	$(OBJ_DIR_ASM) $(OBJS_ASM) $(OBJ_DIR_C) obj_C/ft_strlen_in_C.o obj_C/ft_strcmp_in_C.o obj_C/ft_strcpy_in_C.o obj_C/ft_strdup_in_C.o
			ar rcs $(NAME) $(OBJS_ASM) obj_C/ft_strlen_in_C.o obj_C/ft_strcmp_in_C.o obj_C/ft_strcpy_in_C.o obj_C/ft_strdup_in_C.o

clean:
			rm -f $(OBJS_C) $(OBJS_ASM)
			rm -rf $(OBJ_DIR)
			rm -rf $(LIBFT_ASM_DIR)

fclean:		clean
			rm -f $(LIBFT) $(NAME)

re:			fclean all


#####################################
#									#
#			ADDON RULES				#
#									#
#####################################

# Compile two executable from main, one with ASM library, one with C library
test:		$(LIBFT) $(NAME) $(OBJ_DIR_C)
			$(CC) $(CFLAGS) main.c $(NAME) -o libasmMain

# Compile code to ASM with intel syntax
generate:	$(patsubst %.c,$(LIBFT_ASM_DIR)/%.s,$(SRCS_C))


#####################################
#									#
#			ACTUAL RULES			#
#									#
#####################################


$(LIBFT):	$(OBJ_DIR_C) $(OBJS_C)
			ar rcs $(LIBFT) $(OBJS_C)

$(OBJ_DIR_C)/%.o: $(SRC_DIR_C)/%.c
				$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR_ASM)/%.o: $(SRC_DIR_ASM)/%.s
				$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR_ASM):
				mkdir -p $@

$(OBJ_DIR_C):
				mkdir -p $@

$(LIBFT_ASM_DIR)/%.s:	$(SRC_DIR_C)/%.c
						mkdir -p $(LIBFT_ASM_DIR)
						$(CC) $(CFLAGS) $(ASMGENFLAG) $< -o $@



.PHONY:		all clean fclean re test generate
