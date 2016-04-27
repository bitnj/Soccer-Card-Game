# compiler
CC = g++

# compiler flags
# -g add debugging information to the executable
# -Wall show warnings
CFLAGS = -g -Wall

# paths to header files not in /usr/include
INCLUDES = -I/usr/include/mysql

# libraries to link
LIBS = -L/usr/lib64/mysql -lmysqlclient -lm

# first target
TARGET = Main2

all:
	make build;
	make run;

build:
	${CC} ${CFLAGS} ${INCLUDES} ${TARGET}.cpp -o ${TARGET} ${LIBS}

#build:
#	g++ -std=c++0x -c Main2.cpp;
#	g++ Main2.cpp -o Main2;
	
run:
	./Main2;
	
clean:
	-rm Main2;
	-rm Main2.o
