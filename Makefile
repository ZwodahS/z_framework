vpath %.cpp zf_common
vpath %.cpp zf_inputs
vpath %.cpp zf_hud
vpath %.cpp zf_sfml
vpath %.cpp zf_sfml/animations
vpath %.cpp zf_utility

WARNING= -Wextra -Wno-switch -Wno-sign-compare -Wno-missing-braces -Wno-unused-parameter
OPTIMIZE= -fno-exceptions

CXX=clang++ ${WARNING}

OBJDIR=obj

common = $(shell (cd zf_common ; ls *.cpp ))
commonobjs = $(patsubst %, $(OBJDIR)/% , $(common:.cpp=.o))

sfml = $(shell cd zf_sfml ; ls *.cpp )
sfmlobjs = $(patsubst %, $(OBJDIR)/% , $(sfml:.cpp=.o))

sfmlsubdir = $(shell cd zf_sfml ; for F in `ls -d */` ; do cd $$F ; ls *.cpp ; cd .. ; done )
sfmlsubdirobjs = $(patsubst %, $(OBJDIR)/%, $(sfmlsubdir:.cpp=.o))

inputs = $(shell cd zf_inputs ; ls *.cpp )
inputsobjs = $(patsubst %, $(OBJDIR)/% , $(inputs:.cpp=.o))

hud = $(shell cd zf_hud ; ls *.cpp )
hudobjs = $(patsubst %, $(OBJDIR)/% , $(hud:.cpp=.o))
	
utility = $(shell cd zf_utility ; ls *.cpp )
utilityobjs = $(patsubst %, $(OBJDIR)/% , $(utility:.cpp=.o))

all: $(commonobjs) $(sfmlobjs) $(sfmlsubdirobjs) 

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
