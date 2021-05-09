#ifndef KNOWLEDGE_H_INCLUDED
#define KNOWLEDGE_H_INCLUDED

#include <string>
#include "memtrace.h"
#define INDENTATION 4

using namespace std;

class Node
{
    public:
        Node(string text);
        ~Node();

        string text;
        Node* yes;
        Node* no;
        void setAnswers(string yes, string no);
        bool isLeaf();
        void writeNode(std::ostream& os, int depth);
        void readNode(std::istream& is);

    protected:

    private:
        void addIndent(std::ostream& os, int depth);
};

#endif // KNOWLEDGE_H_INCLUDED
