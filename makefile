# Make variables
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv` -lm
PREPROCSRC = ./src/preprocessing/
IDENTSRC = ./src/identification/

all: fractal

fractal: fractal.cpp
	@echo Building Project...
	g++ $(PREPROCSRC)*.cpp $(IDENTSRC)*.cpp fractal.cpp $(CFLAGS) $(LIBS) -o fractal

clean:
	rm fractal
