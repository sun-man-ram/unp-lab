
CC_Compiler = gcc
C_FLAGS = -Wall -g


SERVER_EXEC = server
CLIENT_EXEC = client


SERVER_OBJECTS = student.o course.o server.o


CLIENT_OBJECTS = parser.o client.o main.o


Header_Files = student.h course.h parser.h

all: $(SERVER_EXEC) $(CLIENT_EXEC)

$(SERVER_EXEC): $(SERVER_OBJECTS)
	$(CC_Compiler) $(C_FLAGS) -o $(SERVER_EXEC) $(SERVER_OBJECTS)

$(CLIENT_EXEC): $(CLIENT_OBJECTS)
	$(CC_Compiler) $(C_FLAGS) -o $(CLIENT_EXEC) $(CLIENT_OBJECTS)

server.o: server.c $(Header_Files)
	$(CC_Compiler) $(C_FLAGS) -c server.c

client.o: client.c $(Header_Files)
	$(CC_Compiler) $(C_FLAGS) -c client.c

student.o: student.c $(Header_Files)
	$(CC_Compiler) $(C_FLAGS) -c student.c

course.o: course.c $(Header_Files)
	$(CC_Compiler) $(C_FLAGS) -c course.c

parser.o: parser.c $(Header_Files)
	$(CC_Compiler) $(C_FLAGS) -c parser.c

clean:
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(SERVER_EXEC) $(CLIENT_EXEC)

.PHONY: all clean
