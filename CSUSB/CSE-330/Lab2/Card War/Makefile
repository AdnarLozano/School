#Makefile for suit
EXEC=game
SRCS=card.cpp deck.cpp player.cpp game.cpp
OBJS=$(SRCS:.cpp=.o) 
$(EXEC): $(OBJS)
	g++ -o $@ $(OBJS) 	
#$< evaluates to the target's dependencies, 
#$@ evaluates to the target

$(OBJS): 
	g++ -c  $*.cpp  

clean:
	rm $(OBJS) $(EXEC)