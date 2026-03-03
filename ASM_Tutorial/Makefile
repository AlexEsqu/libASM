NAME = div

all: $(NAME)

re:
	rm -rf $(NAME)
	rm -rf $(NAME).o
	make all

$(NAME):

			nasm -f elf -o $(NAME).o $(NAME).s
			ld -m elf_i386 -o $(NAME) $(NAME).o

# layout asm
# run
# stepi
# info registers <registername>
# echo "set disassembly-flavor intel" > ~/.gdbinit
