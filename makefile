# Make variables
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv` -lm
PREPROCSRC = ./src/preprocessing/
IDENTSRC = ./src/identification/

all: fractal

fractal: fractal.cpp
	@echo Building Project...
	g++ $(PREPROCSRC)*.cpp $(IDENTSRC)*.cpp fractal.cpp $(CFLAGS) $(LIBS) -o ./build/fractal

debug: fractal.cpp
	@echo Building Project...
	g++ $(PREPROCSRC)*.cpp $(IDENTSRC)*.cpp fractal.cpp $(CFLAGS) $(LIBS) -g -o ./build/fractal.debug

test: test.cpp
	@echo Building Project...
	g++ $(PREPROCSRC)*.cpp $(IDENTSRC)*.cpp test.cpp $(CFLAGS) $(LIBS) -g -o fractal

clean:
	rm fractal
