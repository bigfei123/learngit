
INC_DIR:=./
SRC_DIR:=./
SRCS:= $(wildcard $(SRC_DIR)/*.cc) #SRCS就是一个字符串
CC:= g++
CXXFLAGS:= -g -Wall $(addprefix -I, $(INC_DIR))
LIBS:= -lpthread
OBJS:= $(patsubst %.cc, %.o, $(SRCS))

BIN_EXE:=TestThreadpool.exe

$(BIN_EXE):$(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)  

%.o:%.cc
	$(CC) -o $@ -c $< $(CXXFLAGS) $(LIBS)
print:
	@echo $(OBJS)

clean:
	rm -rf $(OBJS) $(BIN_EXE)
	
