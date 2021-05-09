#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include "memtrace.h"
#include "knowledge.h"
#include <iostream>

#define MENU 0
#define PLAYING 1
#define LEARNING 2


using namespace std;

/**
 *Primary class organizing the Barkochba game.
 */
class Game{
private:
    ///Decides whether the program is currently playing or learning.
    int gameStage;
    Node* tree;
    Node* currentNode;
    int learningStage;
    bool autoSave;
    string nodeMessage(Node* node);
    string menuStep(bool binaryInput);
    string playingStep(bool binaryInput);
    string learningStep(string userInput);


public:
    /**
    *Creates a new game.
    */
    Game(string knowledgeFile, bool autoSave);
    ~Game();
    /**
     *Performs one question and answer step.
     *@param userInput The input entered by the user.
     *@return reaction to the user's input.
     */
    string step(string userInput);

};


#endif // GAME_H_INCLUDED
