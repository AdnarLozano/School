//player.cpp
#include "deck.h"
#include "player.h"

Player::Player( Deck &aDeck )
{
  myScore = 0;
  for ( int i = 0; i < 3; i++ )
	myCards[i] = aDeck.draw();
  removedCard = 0;
}

extern randomInteger randomizer;  

Card Player::draw()
{
  removedCard = randomizer( 3 );
  return myCards[removedCard];
}

void Player::addPoints( int npoints )
{
  myScore += npoints;
}

int Player::score()
{
  return myScore;
}

void Player::replaceCard( Deck &aDeck )
{
  myCards[removedCard] = aDeck.draw();
}

