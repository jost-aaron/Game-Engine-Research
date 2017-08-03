
#include "fileUtils.hpp"

std::string read_file(const char* inFile) {

        // All of tis is C code not C++

        // Get the file object
        FILE* file = fopen(inFile,"rt");

        // Seek for the end of the file
        fseek(file,0,SEEK_END);

        // record the length of the file
        unsigned long length = ftell(file);

        // Create a storage variable for all of the data and add 1 to length for termination character
        char* data = new char[length + 1];

        // Clear all of the data in the buffer
        memset(data,0,length+1);

        // reset the seek position
        fseek(file,0,SEEK_SET);

        // Read all of the data into the buffer
        fread(data,1,length,file);

        // Close the file reader
        fclose(file);

        // Load the results char[] into a string object
        std::string resultData(data);

        // Delete the char[] buffer so its not in memory anymore
        delete[] data;

        return resultData;

}
