/*
 * Huffman.h
 *
 *  Created on: 31-Oct-2011
 *      Author: prabhakar
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_
#include "MinPriorityQueue.h"
#include "Node.h"

class Huffman {
	MinPriorityQueue<Node> q;
public:
	Huffman(MinPriorityQueue<Node> &q);
	~Huffman();
	Node * getHuffmanTree();
};

#endif /* HUFFMAN_H_ */
