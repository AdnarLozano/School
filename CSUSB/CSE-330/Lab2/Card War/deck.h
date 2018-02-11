//deck.h
#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck {
public:
  //constructor
  Deck();

  //operations on a deck
  void shuffle();
  bool isEmpty();
  Card draw();		//return the next card

protected:
  Card cards[52];	//hold collection of cards
  int  topCard;		//points to top card in deck
};

class randomInteger {
  public:
    unsigned int operator () ( unsigned int );
};


#endif
