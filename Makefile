cc = gcc
EXEC = lib89_malloc.so
SRC		=	$(shell find src/ -name "*.c")
OBJ		=	$(SRC:.c=.o)
DEP = -I./include/

all : $(EXEC) 
	@echo "[MAKE]" $<

$(EXEC) : $(OBJ)
	@$(cc) -shared -fPIC $(OBJ) -o $(EXEC) -ldl $(DEP)


.c.o:
	@$(cc) -fPIC -c $< -o $@ -ldl $(DEP)
	@echo "[GCC]" $<

clean :
	@rm -f ${OBJ} 
	@rm -rf *.o 

fclean : clean
	@rm -rf $(EXEC)


re:		fclean all


.SUFFIXES: .c .o
