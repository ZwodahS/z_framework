vpath %.cpp zf_common
vpath %.cpp zf_sfml
vpath %.cpp zf_platformer

CXX=g++

SDL=`sdl-config --libs --cflags`
LINKLIB=-l SDL_image -l SDL_ttf -l SDL_mixer
OBJDIR=obj


# search frameworks files for all the cpp files
framework = $(shell for F in `ls -d zf_*/` ; do cd $$F ;  ls *.cpp ; cd ..; done)
frameworkobjs = $(patsubst %,$(OBJDIR)/%,$(framework:.cpp=.o))

all: $(frameworkobjs)

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o

remake:
	make clean
	make all

debug:
	@echo $(world)
.PHONY: clean remake debug
