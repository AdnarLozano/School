//suit_test.cpp
#include "card.h"
int main(){
	Card cards[52];
	int  topCard;
	for ( int i = 1; i <= 13; i++ )
 	{
		Card c1(diamond, i ), c2( spade, i), c3( heart, i ), c4( club, i );
		cards[++topCard] = c1; 
		cards[++topCard] = c2; 
		cards[++topCard] = c3; 
		cards[++topCard] = c4; 
	}
	//prints out all 52 cards
	for (int i = 0; i < 52; i++ )
	{
		cout<<cards[i]<<"\n";
	}
	Card c1;
  	Card c2( diamond, 8 );

	cout << "Card one\n";
	cout << c1.rank << endl;
	cout << "Card two\n";
	cout << c2.rank << endl;
	return 0;
}

