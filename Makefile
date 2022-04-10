GCC = gcc
EXEC = Bitmap
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDE = -I ./include/
FLAG = -g -W -Wall -Werror -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -lavcall -lusb -std=c11

all:    $(EXEC)

%.o : %.c
	@$(GCC) -o $@ -c $< $(INCLUDE) $(FLAG)

$(EXEC) : $(OBJ)
	@$(CC) -o $@ $^ $(FLAG)

fclean:
	@rm -rf $(EXEC) src/*o src/*~ include/*~ *~
	@rm -rf $(EXEC)
re: fclean all


