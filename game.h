#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
//#include "memtrace.h"
#include "knowledge.h"
#include <iostream>

using namespace std;

/**
 *Primary class organizing the Barkochba game.
 */
class Game{
private:
    ///Decides whether the program is currently playing or learning.
    bool playing;
    istream& is;
    ostream& os;
    Node* tree;
    Node* currentNode;
    bool getBinaryAnswer();
public:
    /**
    *Creates a new game.
    */
    Game(string knowledgeFile, istream& is, ostream& os);
    ~Game();
    /**
     *Performs one question and answer step.
     *@param userInput The input entered by the user.
     *@return reaction to the user's input.
     */
    void play();
};


#endif // GAME_H_INCLUDED
