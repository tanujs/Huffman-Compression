#ifndef __INPUT_FILE_READER_H__
#define __INPUT_FILE_READER_H__

#include <fstream>
#include <string>
#include <sstream>
#include "Node.h"
#include "MinPriorityQueue.h"
#include <cstring>

using namespace std;
//! Class for taking and processing a user input file.
/*!
 * This class contains appropriate methods that help parse the input file and convert the input into suitable data structures that can be processed comfortably.
 */
class InputFileReader{

		/*! The input file object. */
        ifstream inputFile;

        /*! An error string that will be set if an error occurs. */
        string error;

        public:
        /*! \brief The destructor.
         * To make sure opened file is closed. */
        ~InputFileReader();

        /*! \brief The constructor.
         * To open a file given the filename
         * \param iFileName The input file name
         *
         */

        InputFileReader(string iFileName);

        MinPriorityQueue<Node> getQueue();

        /*! \brief The explode method.
         * To explode an input line into characters and put them all in an array. This method internally uses space as a delimiter.
         * \param str The input string line
         */


        /*! \brief Error displayer
         * This method returns an error message corresponding to the error occured
         * \return A string containing the error message
         */
        string getError();
        string getString();
};

#endif
