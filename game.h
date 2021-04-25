#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>

class Game;
/**
 *Primary class organizing the Barkochba game.
 */
class Game{
private:
    ///Decides whether the program is currently playing or learning.
    bool playing;
public:
    /**
    *Creates a new game.
    */
    Game(){}
    /**
     *Performs one question and answer step.
     *@param userInput The input entered by the user.
     *@return reaction to the user's input.
     */
    std::string step(std::string userInput);
};


#endif // GAME_H_INCLUDED
