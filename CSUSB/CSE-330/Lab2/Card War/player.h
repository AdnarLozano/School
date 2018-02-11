//player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
  Player ( Deck & );

  Card draw();
  void addPoints ( int );
  int  score();
  void replaceCard( Deck & );

protected:
  Card myCards[3];	//player holds three cards and randomly draw one
  int  myScore;
  int  removedCard;
};

#endif
