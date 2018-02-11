#include "deck.h"
#include <algorithm>
#include <math.h>

unsigned int randomInteger::operator () ( unsigned int max )
{
  unsigned int r = rand();
  return r % max;
}

Deck::Deck()
{
  topCard = -1;		//deck empty
  for ( int i = 1; i <= 13; i++ )
  {
    Card c1(diamond, i ), c2( spade, i), c3( heart, i ), c4( club, i );
    cards[++topCard] = c1; 
    cards[++topCard] = c2; 
    cards[++topCard] = c3; 
    cards[++topCard] = c4; 
  }
}

randomInteger randomizer;  //global variable

void Deck::shuffle()
//randomly shuffle cards array, using generic algorithm random_shuffle
{
  random_shuffle( cards, cards+52, randomizer );
}

Card Deck::draw()
//return topCard
{
  if ( !isEmpty() )
    return cards[topCard--];
  else{
    Card specialCard( spade, 14 );
    return specialCard;
  }
}

bool Deck::isEmpty()
{
  return topCard < 0;
}


