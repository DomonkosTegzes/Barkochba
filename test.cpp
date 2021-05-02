#include <iostream>
#include <fstream>

#include "game.h"
#include "knowledge.h"


using namespace std;

int main()
{
    cout << "START TESTING" << endl;
    ifstream ifs;
    ifs.open("test.txt");
    Game game("knowledge.txt");
    string response = "";
    string userInput;
    string expectedResponse;
    while(response.find("good bye") == string::npos){
        getline(ifs, userInput);
        getline(ifs, expectedResponse);
        response = game.step(userInput);
        cout << userInput << endl;
        cout << response << endl;
        if(response != expectedResponse){
            throw std::logic_error("Response not as expected!");
        }
    }
    cin >> userInput;
    return 0;
}
