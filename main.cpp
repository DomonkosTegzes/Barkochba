#include <iostream>
#include <fstream>

#include "game.h"
#include "knowledge.h"
#include "memtrace.h"


using namespace std;

int main()
{
    Game game("knowledge.txt", true);
    string response = game.step("yes");
    string userInput;
    cout << response << endl;
    while(response.find("good bye") == string::npos){
        getline(cin, userInput);
        response = game.step(userInput);
        cout << response << endl;
    }
    Game* game1 = new Game("knowledge.txt", true);
    return 0;
}
