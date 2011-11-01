#ifndef __OUTPUT_FILE_WRITER_H__
#define __OUTPUT_FILE_WRITER_H__

#include <fstream>
#include <string>

using namespace std;

/*! \brief An output file writer
 *  It will facilitate easy writing of result to the output file */
class OutputFileWriter{
        /*! The output file object */
        ofstream outputFile;
        /*! An error string that will be set if an error occurs */
        string error;

        public:
        /*! \brief The destructor
         * To make sure opened file is closed */
        ~OutputFileWriter();

        /*! \brief The constructor
         * To open a file given the filename
         * \param oFileName The name of output file
         * */
        OutputFileWriter(char * oFileName);

        /*! \brief Result writer
         * This method extracts all parenthesized infix expressions from the input vector one by one and writes them to the file openedi
         * \param data A string to be written to the file
         * \return void */
        void writeData(string data);

        /*! \brief Error displayer
         * This method returns an error message corresponding to the error occured
         * \return A string containing the error message */
        string getError();
};

#endif
