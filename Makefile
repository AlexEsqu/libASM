# Project Name
NAME	= libasm.a

# Library in C for comparison
LIBFT	= libft.a

# Main for tests
MAIN	= main


# Directories
SRC_DIR_C = libft

SRC_DIR_ASM = libASM

OBJ_DIR_C = obj_C

OBJ_DIR_ASM = obj_ASM

OBJ_DIR_TEST = obj_tests

LIBFT_ASM_DIR = libft_compiled_to_asm

INC_DIR = inc


# Files

SRCS_C		= 	ft_strlen.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_read.c \
				ft_write.c \
				ft_atoi_base.c

SRCS_ASM	= 	ft_strlen.s \
				ft_strcmp.s \
				ft_strcpy.s \
				ft_read.s \
				ft_write.s \
				ft_strdup.s \
				ft_atoi_base.s

SRCS_TEST	=	tests/unit_test.c

SRCS_MAIN	=	tests/main.c

SRCS_BENCH	=	tests/libasm_benchmark.c

# 			ft_strlen.s ft_strspy.s ft_strsmp.s ft_write.s ft_read.s ft_strdup.s \
			ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJS_C		= $(patsubst %.c,$(OBJ_DIR_C)/%.o,$(SRCS_C))
OBJS_ASM	= $(patsubst %.s,$(OBJ_DIR_ASM)/%.o,$(SRCS_ASM))


# Compilation options
CC		= clang -g
ASM		= nasm

CFLAGS		= -Wall -Wextra -Werror
DEBUGFLAG	= -g
ASMGENFLAG	= -S -mllvm --x86-asm-syntax=intel
ASMFLAGS	= -f elf64
TESTFLAGS	= -L.. -lasm -lft -lcriterion

PKG_CONFIG	= pkg-config
CRIT_CFLAGS	= $(shell $(PKG_CONFIG) --cflags criterion 2>/dev/null || echo "-I/usr/include")
CRIT_LDFLAGS	= $(shell $(PKG_CONFIG) --libs criterion 2>/dev/null || echo "-lcriterion")

#####################################
#									#
#			MANDATORY RULES			#
#									#
#####################################

all:		$(NAME)

$(NAME):	$(OBJ_DIR_ASM) $(OBJS_ASM)
			ar rcs $(NAME) $(OBJS_ASM)

clean:
			rm -f $(OBJS_C) $(OBJS_ASM)
			rm -rf $(OBJ_DIR_ASM)
			rm -rf $(OBJ_DIR_C)
			rm -rf $(MAIN)
			rm -rf libft_deassembled
			rm -rf benchmark
			rm -rf unit_test

fclean:		clean
			rm -f $(LIBFT) $(NAME)

re:			fclean all


#####################################
#									#
#			ADDON RULES				#
#									#
#####################################

# Compile library with main
main:		$(NAME) $(LIBFT) $(SRCS_MAIN)
			$(CC) $(CFLAGS) $(SRCS_MAIN) $(LIBFT) $(NAME) -o $(MAIN)

# Compile library with unit tests
unit_test:	$(NAME) $(LIBFT) $(SRCS_TEST)
			gcc $(CFLAGS) $(CRIT_CFLAGS) -I$(INC_DIR) $(SRCS_TEST) -o $@ -L. -lasm -lft $(CRIT_LDFLAGS)
			./unit_test --verbose

# Compile library with unit tests
benchmark:	$(NAME) $(LIBFT) $(SRCS_BENCH)
			gcc $(CRIT_CFLAGS) -I$(INC_DIR) tests/libasm_benchmark.c -o benchmark -L. -lasm -lft $(CRIT_LDFLAGS)
			./benchmark

# Decompile C code into assembler
decompile:	$(patsubst %.c,$(LIBFT_ASM_DIR)/%.s,$(SRCS_C))


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

.PHONY:		all clean fclean re test decompile
