#include "game.h"
#include <string>
#include <fstream>


Game::Game(string knowledgeFile, istream& is, ostream& os): playing(true), is(is), os(os){
    tree = new Node("");
    ifstream ifs;
    ifs.open(knowledgeFile);
    tree->readNode(ifs);
    currentNode = tree;
    os << "Think of something or someone" << endl;
    os << "Can we start? " << endl;
    while (!getBinaryAnswer()){
        os << "And now can we start?" << endl;
    }
    play();
}

Game::~Game(){
    delete tree;
}

void Game::play(){
    while(!currentNode->isLeaf()){
        os << currentNode->text << endl;
        if(getBinaryAnswer()){
            currentNode = currentNode->yes;
        }else {
            currentNode = currentNode->no;
        }
    }
    os << "Let me guess, it's: " << currentNode->text << endl;
}

bool Game::getBinaryAnswer(){
    string answer;
    getline(is, answer);
    if(tolower(answer[0]) == 'y'){
        return true;
    } else if(tolower(answer[0]) == 'n'){
        return false;
    } else {
        os << "Please answer with yes or no" << endl;
        return getBinaryAnswer();
    }
}
