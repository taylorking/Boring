CC=clang++
CXXFLAGS=-I/opt/local/include -g
OBJS=Renderer.o EntityRenderer.o Display.o Level.o Control.o State.o Player.o Entity.o Game.o main.o
test: $(OBJS) 
		$(CC) $(CXXFLAGS) -L/opt/local/lib $(OBJS) -o test -lsdl2 -lsdl2_ttf -lsdl2_image

.C.o:
		$(CC) $(CXXFLAGS) -c $< -o $@ 

clean: 
		rm *.o test
