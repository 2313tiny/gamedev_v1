SOURCES := source.cpp main.cpp tech.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


all: comp run
comp:$(OBJECTS)
	@clear 
	@g++ $(OBJECTS) -o smd -L/usr/X11R6/lib -lX11  

tech.o:
	@g++ -c tech.cpp -o tech.o -std=c++11

source.o:
	@g++ -c source.cpp -o source.o -std=c++11

main.o:
	@g++ -c main.cpp -o main.o -std=c++11

tech.dep:
	@g++ -c -MM tech.cpp -MT "tech.dep tech.o" -o tech.dep  -std=c++11

source.dep:
	@g++ -c -MM source.cpp -MT "source.dep source.o" -o source.dep  -std=c++11

main.dep:
	@g++ -c -MM main.cpp -MT "main.dep main.o" -o main.dep -std=c++11
-include source.dep main.dep tech.dep  -std=c++11
 
run:
	@./smd
	@ctags -R .
clean:
	rm smd *.o *.dep tags
