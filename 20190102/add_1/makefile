INC_DIR:=./include/
SRC_DIR:=./src/
SRCS:= $(wildcard $(SRC_DIR)*.c)
CC:= gcc
CXXFLAGS:= -g -Wall $(addprefix -I, $(INC_DIR))
LIBS:= 
OBJS:= $(patsubst %.c, %.o, $(SRCS))

BIN_EXE:=./bin/test.exe

#main.exe: add.o main.o
$(BIN_EXE):$(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)

%.o:%.c
	$(CC) -o $@ -c $< $(CXXFLAGS) $(LIBS)

print:
	@echo $(OBJS)

.PHONY:rebuild clean
rebuild:clean $(BIN_EXE)

clean:
	rm -rf $(OBJS) $(BIN_EXE)
