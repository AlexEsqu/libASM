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

LIBFT_ASM_DIR = libft_disassembled

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

SRCS_BENCH	=	tests/benchmarks/run_benchmarks.sh

OBJS_C		= $(patsubst %.c,$(OBJ_DIR_C)/%.o,$(SRCS_C))
OBJS_ASM	= $(patsubst %.s,$(OBJ_DIR_ASM)/%.o,$(SRCS_ASM))


# Compilation options
CC		= clang
GCC 	= gcc
ASM		= nasm

CFLAGS		= -Wall -Wextra -Werror -fno-builtin
DEBUGFLAG	= -g
DISASMFLAG	= -S -mllvm --x86-asm-syntax=intel
ASMFLAGS	= -f elf64
TESTFLAGS	= -L.. -lasm -lft

CRIT_INC_FLAG	= -I$$HOME/Criterion/include
CRIT_LIB_FLAG	= -L$$HOME/Criterion/build/src -Wl,-rpath=$$HOME/Criterion/build/src -lcriterion

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
			rm -rf $(OBJ_DIR_TEST)
			rm -rf $(MAIN)
			rm -rf $(LIBFT_ASM_DIR)
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
			chmod 777 ./tests/install_tester.sh
			./tests/install_tester.sh
			$(GCC) $(DEBUGFLAG) $(CFLAGS) $(CRIT_INC_FLAG) -I$(INC_DIR) $(SRCS_TEST) -o $@ -L. -lasm -lft $(CRIT_LIB_FLAG)
			./unit_test --verbose

# Compile library with benchmarks
benchmark:	$(NAME) $(LIBFT) $(SRCS_BENCH)
			./tests/benchmarks/run_benchmarks.sh

# Decompile C code into assembler
deassemble:	$(addprefix $(SRC_DIR_C)/, $(SRCS_C)) $(patsubst %.c,$(LIBFT_ASM_DIR)/%.s,$(SRCS_C))


#####################################
#									#
#			ACTUAL RULES			#
#									#
#####################################


$(LIBFT):	$(OBJ_DIR_C) $(OBJS_C)
			ar rcs $(LIBFT) $(OBJS_C)

$(OBJ_DIR_C)/%.o: $(SRC_DIR_C)/%.c
			$(CC) $(CFLAGS) -o3 -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR_ASM)/%.o: $(SRC_DIR_ASM)/%.s
			$(ASM) $(ASMFLAGS) $< -o $@

$(OBJ_DIR_ASM):
			mkdir -p $@

$(OBJ_DIR_C):
			mkdir -p $@

$(LIBFT_ASM_DIR)/%.s:	$(SRC_DIR_C)/%.c
			mkdir -p $(LIBFT_ASM_DIR)
			$(CC) $(CFLAGS) $(DISASMFLAG) $< -o $@

.PHONY:		all clean fclean re unit_test deassemble
