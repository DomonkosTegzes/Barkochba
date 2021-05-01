#include <iostream>
#include "knowledge.h"


//#include "memtrace.h"



Node::Node(string text): text(text), yes(NULL), no(NULL){
    cout << "CREATE NODE " << this->text << endl;
    }

Node::~Node(){
    delete this->yes;
    delete this->no;
}

void Node::setAnswers(string yes, string no){
    this->yes = new Node(yes);
    this->no = new Node(no);
}

bool Node::isLeaf(){
    return this->yes == nullptr && this->no == nullptr;
}

void Node::addIndent(std::ostream& os, int depth){
    for(int i = 0; i < INDENTATION * depth; i++){
        os << " ";
    }
}

void Node::writeNode(std::ostream& os, int depth){
    if(this->isLeaf()){
        addIndent(os, depth);
        os << "-" << this->text << endl;
    } else {
        addIndent(os, depth);
        os << "?" << this->text << endl;
        this->yes->writeNode(os, depth + 1);
        this->no->writeNode(os, depth + 1);
    }
}



void Node::readNode(std::istream& is){
    char c = ' ';
    while(c == ' ' || c == '\n' || c == '\r'){
        is >> c;
    }
    if(c == '-'){
        getline(is, this->text);
    } else if(c == '?'){
        getline(is, this->text);
        this->yes = new Node("");
        this->no = new Node("");
        this->yes->readNode(is);
        this->no->readNode(is);
    }
}






