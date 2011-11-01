#include "OutputFileWriter.h"

/*******************************************************************************************
 * ~OutputFileWriter - Destructor for this class
 * Argument(s) - None
 * Method - Closes the file stream
 ******************************************************************************************/
OutputFileWriter::~OutputFileWriter(){
        outputFile.close();
}


/********************************************************************************************
 * OutputFileWriter - Constructor for this class
 * Argument(s) - Pointer to the file name
 * Method - Takes the name of a file, links it to the output filestream. If there is
 *              an error while opening the file, sets an error string
 *******************************************************************************************/
OutputFileWriter::OutputFileWriter(char * oFileName){
       outputFile.open(oFileName);
       if(!(outputFile.is_open()))
               error="There was an issue opening the output file.";
}

/*******************************************************************************************
 * getError - Displays the error associated
 * Return - An error string
 ******************************************************************************************/
string OutputFileWriter::getError(){
        return error;
}

/*******************************************************************************************
 * writeString - Writes an string to a file
 * Return - None
 ******************************************************************************************/
void OutputFileWriter::writeData(string data){

}
