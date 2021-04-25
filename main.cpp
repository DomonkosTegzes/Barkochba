#include <iostream>
#include "game.h"


using namespace std;

int main()
{
    Game game;
    while(true){
        string userInput;
        cout << "Hogy hivnak?";
        cin >> userInput;
        cout << game.step(userInput) << endl;
    }
    return 0;
}
