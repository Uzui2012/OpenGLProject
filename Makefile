#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = OpenGLmain

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) MyTriangle.cpp -IC:\Development\freeglut\include -IC:\Development\glm -IC:\Development\glew\include -LC:\Development\freeglut\lib -lfreeglut -lglu32 -lopengl32 -o $(OBJ_NAME) 