# Make variables
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv` -lm
PREPROCSRC = ./src/preprocessing/
IDENTSRC = ./src/identification/

all: fractal

fractal: fractal.c
	@echo Building Project...
	gcc $(PREPROCSRC)*.c $(IDENTSRC)*.c fractal.c $(CFLAGS) $(LIBS) -o fractal

clean:
	rm fractal
