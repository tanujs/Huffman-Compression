/*
 * Huffman.cpp
 *
 *  Created on: 31-Oct-2011
 *      Author: prabhakar
 */

#include "Huffman.h"

Huffman::Huffman(MinPriorityQueue<Node> &q) {
	// TODO Auto-generated constructor stub
	this->q=q;
}

Huffman::~Huffman() {
	// TODO Auto-generated destructor stub
}

Node *Huffman::getHuffmanTree()
{
	int size=q.getSize();
	for(int i=1; i<size; i++){
		Node *z=new Node;
		Node *a= new Node;
		Node *b=new Node;
		*a=q.extractMinimum();
		*b=q.extractMinimum();
		a->setParent(z);
		b->setParent(z);
		z->setLeft(a);
		z->setRight(b);
		z->setFrequency(z->getLeft()->getFrequency()+z->getRight()->getFrequency());
		q.insert(*z);
	}
	Node *ret=new Node;
	*ret=q.extractMinimum();
	return ret;
}





