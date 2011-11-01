/*
 * main.cpp
 *
 *  Created on: 29-Oct-2011
 *      Author: prabhakar
 */
#include <iostream>
#include "MinPriorityQueue.h"
#include "MinHeap.h"
#include "InputFileReader.h"
#include "Node.h"
#include "Huffman.h"
#include <map>

using namespace std;

int main(){
	InputFileReader ifr((char *)"/home/prabhakar/test.txt");
	MinPriorityQueue<Node> a=ifr.getQueue();
	Huffman h=a;
	Node* root=h.getHuffmanTree();
	map<string, unsigned char> *encoding=root->getAllPaths();
	/*for(map<string, unsigned char>::iterator it=encoding->begin(); it!=encoding->end(); it++){
		if(it->second=='\000')
			cout<<it->first<<" ==> "<<"EOF"<<endl;
		else if(it->second=='\n')
			cout<<it->first<<" ==> "<<"\\n"<<endl;
		else
			cout<<it->first<<" ==> "<<it->second<<endl;
	}*/
	ifr.test();
	return 0;
}




