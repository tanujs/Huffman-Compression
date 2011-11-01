#include "InputFileReader.h"

InputFileReader::InputFileReader(string iFileName){
       inputFile.open(iFileName.c_str());
       if(!(inputFile.is_open()))
			error="Error in opening input file!";
}

InputFileReader::~InputFileReader(){
        inputFile.close();
}

MinPriorityQueue<Node> InputFileReader::getQueue(){
	int *charset=new int[256];
	while(!inputFile.eof()){
		char *c=new char;
		inputFile.read(c, 1);
		charset[(int)(*c)]++;
		delete c;
	}
	MinPriorityQueue<Node> ret;
	for(int i=0; i<256; i++){
		Node n;
		if(!charset[i])
			continue;
		n.setCharacter((char)i);
		n.setFrequency(charset[i]);
		ret.insert(n);
	}
	return ret;
}
string InputFileReader::getString(){
	string res;
	while(!inputFile.eof()){
		char c;
		inputFile.read(&c, 1);
		res=res+c;
	}
	return res;
}
string InputFileReader::getError(){
        return error;
}
