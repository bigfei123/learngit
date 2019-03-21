
INC_DIR:=./
SRC_DIR:=./
SRCS:= $(wildcard $(SRC_DIR)*.cc) #SRCS就是一个字符串
CC:= g++
CXXFLAGS:= -g -Wall $(addprefix -I, $(INC_DIR))
LIBS:= -lpthread
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
OBJS1:= Thread.o MutexLock.o Condition.o TestThread.o
OBJS2:= Thread.o MutexLock.o Condition.o TestCondition.o

BIN_EXE1:= TestThread.exe
BIN_EXE2:= TestCondition.exe

all:$(BIN_EXE1) $(BIN_EXE2)

$(BIN_EXE1): $(OBJS1)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)  

$(BIN_EXE2): $(OBJS2)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)  

%.o:%.cc
	$(CC) -o $@ -c $< $(CXXFLAGS) $(LIBS)
print:
	@echo $(OBJS)

clean:
	rm -rf $(OBJS) $(BIN_EXE1) $(BIN_EXE2)
	
