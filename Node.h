/*
 * Node.h
 *
 *  Created on: 30-Oct-2011
 *      Author: prabhakar
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Node {
	unsigned char character;
	int frequency;
	Node *left;
	Node *right;
	Node *parent;
    void traverseRecur(Node *ptr, int *paths, int pathlen, map<string, unsigned char> *res);
    //stringstream codes;
    void printArray(int *paths, int pathlen, map<string, unsigned char> *res, unsigned char c);
public:
	Node();
	Node(int freq);
    unsigned char getCharacter() const;
    int getFrequency() const;
    void setCharacter(unsigned char character);
    void setFrequency(int frequency);
    bool operator<(const Node &in) const;
    bool operator<=(const Node &in) const;
    bool operator>(const Node &in) const;
    bool operator>=(const Node &in) const;
    bool operator==(const Node &in) const;
    friend ostream& operator<<(ostream& os, const Node& n);
    Node *getLeft() const;
    Node *getRight() const;
    void setLeft(Node *left);
    void setRight(Node *right);
    map<string, unsigned char>* getAllPaths();
    Node *getParent() const;
    void setParent(Node *parent);

};

#endif /* NODE_H_ */
