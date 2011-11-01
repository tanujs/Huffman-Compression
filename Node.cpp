/*
 * Node.cpp
 *
 *  Created on: 30-Oct-2011
 *      Author: prabhakar
 */

#include "Node.h"

Node *Node::getLeft() const
{
    return left;
}

Node *Node::getRight() const
{
    return right;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}

void Node::setRight(Node *right)
{
    this->right = right;
}

ostream& operator<<(ostream& os, const Node& n)
{
    os << n.character <<"-"<<n.frequency<<" ";
    return os;
}

Node::Node(){
	left=NULL;
	right=NULL;
	parent=NULL;
}

Node::Node(int freq){
	frequency=freq;
	character=255;
	left=NULL;
	right=NULL;
	parent=NULL;
}

unsigned char Node::getCharacter() const
{
    return character;
}

int Node::getFrequency() const
{
    return frequency;
}

void Node::setCharacter(unsigned char character)
{
    this->character = character;
}

void Node::setFrequency(int frequency)
{
    this->frequency = frequency;
}

bool Node::operator<(const Node &in) const{
	return (this->frequency < in.frequency);
}

bool Node::operator <=(const Node & in) const
{
	return (this->frequency <= in.frequency);
}



bool Node::operator >(const Node & in) const
{
	return (this->frequency > in.frequency);
}



bool Node::operator >=(const Node & in) const
{
	return (this->frequency >= in.frequency);
}

bool Node::operator ==(const Node & in) const
{
	return (this->frequency == in.frequency);
}

Node *Node::getParent() const
{
    return parent;
}

void Node::setParent(Node *parent)
{
    this->parent = parent;
}

map<string, unsigned char>* Node::getAllPaths(){
	int *paths=new int[1024];
	int pathlen=0;
	map<string, unsigned char> *res = new map<string, unsigned char>;
	traverseRecur(this, paths, pathlen, res);
	return res;
}

void Node::traverseRecur(Node *ptr, int* paths, int pathlen, map<string, unsigned char> *res){
	if(!ptr)
		return;
	if(ptr->getParent()){
		if(ptr==ptr->getParent()->getLeft())
			paths[pathlen++]=0;
		else
			paths[pathlen++]=1;
	}
	if(!ptr->getLeft() && !ptr->getRight()){
		printArray(paths, pathlen, res, ptr->getCharacter());
		return;
	}
	traverseRecur(ptr->getLeft(), paths, pathlen, res);
	traverseRecur(ptr->getRight(), paths, pathlen, res);
}

void Node::printArray(int *paths, int pathlen, map<string, unsigned char> *res, unsigned char c){
	string s;
	for(int i=0; i<pathlen; i++)
		s=s+(char)(paths[i]+48);
	res->insert(pair<string, unsigned char>(s, c));
}
