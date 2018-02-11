//game.cpp
#include "card.h"
#include "deck.h"
#include "player.h"

int main()
{
  //create and shuffle deck
  Deck theDeck;
  
  theDeck.shuffle();

  //create 2 players
  Player p1( theDeck );
  Player p2( theDeck );
  
  //play until deck empty
  while ( !theDeck.isEmpty() ) {
    Card c1 = p1.draw();
    cout << "Player 1 plays " << c1 << endl;
    Card c2 = p2.draw();
    cout << "Player 2 plays " << c2 << endl;
 
    if ( c1.rank == c2.rank ) {	//tie
	p1.addPoints( 1 );
	p2.addPoints( 1 );
	cout << "Players tie" << endl;
    } else if ( c1.rank > c2.rank ) {
	p1.addPoints( 2 );
	cout << "Player 1 wins round " << endl;
    } else {		//player 2 wins
	p2.addPoints( 2 );
	cout << "Player 2 wins round " << endl;
    }
    //replace cards drawn
    p1.replaceCard( theDeck );
    p2.replaceCard( theDeck );
  }  //while
  cout << "Total score for Player 1 : " << p1.score() << endl;
  cout << "Total score for Player 2 : " << p2.score() << endl;

  return 0;
}

