CC=clang++
CXXFLAGS=-I/opt/local/include -g
OBJS=Display.o Level.o State.o Player.o Entity.o Game.o main.o
test: $(OBJS) 
		$(CC) $(CXXFLAGS) -L/opt/local/lib $(OBJS) -o test -lsdl2 -lsdl2_ttf

.C.o:
		$(CC) $(CXXFLAGS) -c $< -o $@ 

clean: 
		rm *.o test
