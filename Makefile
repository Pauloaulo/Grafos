INCLUDE = ./include
SCR = ./scr
PROGRAM = ./program

all: lisrun
	
lisrun:
	g++ $(SCR)/Grafo.cpp $(SCR)/main.cpp -I $(INCLUDE) -o $(PROGRAM)/teste

run:
	start $(PROGRAM)/teste

clean:
	rm $(PROGRAM)/teste