#include <iostream>
#include <fstream>

#include "game.h"
#include "knowledge.h"


using namespace std;

int main()
{
    ifstream test;
    test.open("test1.txt");
    Game game("test1.txt", cin, cout);
    //Node* node = new Node("");
    //node->readNode(test);
    //Node *node = new Node("Ferfi?");
    //node->setAnswers(">30?", ">20?");
    //node->yes->setAnswers("Apa", "Domi");
    //node->no->setAnswers("Anya", "Emma");
    //node->writeNode(cout, 0);
    //delete node;
    return 0;
}
