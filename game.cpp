#include "game.h"
#include "knowledge.h"
#include <string>
#include <fstream>


Game::Game(string knowledgeFile, bool autoSave): gameStage(MENU), currentNode(nullptr),
                                                 learningStage(0), autoSave(autoSave){
    tree = new Node("");
    ifstream ifs;
    ifs.open(knowledgeFile);
    tree->readNode(ifs);
}

Game::~Game(){
    delete tree;
}

string Game::nodeMessage(Node* node){
    if(node->isLeaf()){
        return "Let me guess, it's: " + node->text + ". Is that right?";
    } else {
        return node->text;
    }
}


string Game::step(string userInput){
    bool binaryInput;
    if(gameStage == MENU || gameStage == PLAYING){
        if(userInput.length() == 0 || (tolower(userInput[0]) != 'y' && tolower(userInput[0] != 'n'))){
            return "Please answer with yes or no";
        } else if(tolower(userInput[0]) == 'n'){
            binaryInput = false;
        } else {
            binaryInput = true;
        }
    }
    if(gameStage == MENU){
        return menuStep(binaryInput);
    } else if(gameStage == PLAYING){
        return playingStep(binaryInput);
    } else {
        return learningStep(userInput);
    }
    return "Ooops something went wrong";
}

string Game::playingStep(bool binaryInput){
    if(!currentNode->isLeaf()){
        if(binaryInput){
            currentNode = currentNode->yes;
        } else {
            currentNode = currentNode->no;
        }
        return nodeMessage(currentNode);
    } else {
        if(binaryInput){
            gameStage = MENU;
            return "That's great, want to play another one?";
        } else {
            gameStage = LEARNING;
            learningStage = 0;
            return "Too bad... What should I have asked at this point? Please enter a question";
        }
    }
}

string Game::learningStep(string userInput){
    if(learningStage == 0){
        currentNode->text = userInput;
        learningStage++;
        return "Please enter the solution in case the answer to this question is yes";
    } else if(learningStage == 1){
        currentNode->yes = new Node(userInput);
        learningStage++;
        return "Please enter the solution in case the answer to this question is no";
    } else if(learningStage == 2){
        currentNode->no = new Node(userInput);
        if(autoSave){
            ofstream ofs;
            ofs.open("knowledge.txt");
            tree->writeNode(ofs, 0);
        }
        gameStage = MENU;
        return "Thanks I will remember it next time. Want to play another one?";
    }
    return "Ooops something went wrong";
}

string Game::menuStep(bool binaryInput){
    if(binaryInput){
        currentNode = tree;
        gameStage = PLAYING;
        return "Think of something or someone and answer my questions. " + nodeMessage(currentNode);
    } else {
        return "Thanks, good bye";
    }
}





