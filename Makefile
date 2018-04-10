LINK_TARGET = test.exe

OBJS = \
	PossibleVertices.o	\
	PossibleEdges.o	\
	Lists.o	\
	view.o	\
	model.o	\
	geometry.o	\
	debug.o	\
	TwoDModelGenerator.o	\
	ThreeDModelGenerator.o	\
	fileParser.o	\
	rotator.o	\

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all :	$(LINK_TARGET)
	echo	all	done

$(LINK_TARGET) : $(OBJS)
	g++	-o	$@	$^

%.o : %.cpp
	g++	-c	$<

clean : 
	rm	$(REBUILDABLES)
	echo	Clean	done