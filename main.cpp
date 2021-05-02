#include <iostream>
#include <fstream>

#include "game.h"
#include "knowledge.h"


using namespace std;

int main()
{
    Game game("knowledge.txt");
    string response = game.step("yes");
    string userInput;
    cout << response << endl;
    while(response.find("good bye") == string::npos){
        cin >> userInput;
        response = game.step(userInput);
        cout << response << endl;
    }
    return 0;
}
