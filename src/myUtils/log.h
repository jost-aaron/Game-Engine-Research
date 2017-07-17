#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

// Header guard to make sure this is only included once
#ifndef logging_header_included
#define logging_header_included

// The default log file type
#define LOG_FILE_NAME "log.txt"

// Enable logging to a file
#define LOG_TO_FILE

// For easier use
#define LOG_C(str_in) myUtils::logging::console(str_in)

// Check if logging to file is inabled
#ifdef LOG_TO_FILE
// If it is allow logging to file
#define LOG_F(str_in) myUtils::logging::file(str_in)
#else
// Dont allow logging to file
#define LOG_F(str_in)
#endif

// Macros for logging to both
#define LOG_B(str_in) LOG_C(str_in); LOG_F(str_in)
#define LOG_CLEAR() myUtils::logging::clear()

namespace myUtils { namespace logging {

// Get current date/time, format is YmyUtilsYYY-MM-DD.HH:mm:ss
std::string currentDateTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%m min : %s sec", &tstruct);

        return buf;
}

// For logging to the console
void console(std::string str_to_log) {
        std::cout << "- " << str_to_log << "\n";
}

//For logging to the log file
void file(std::string str_to_log) {
        std::ofstream log_file;

        log_file.open(LOG_FILE_NAME, std::ios_base::app);
        log_file << currentDateTime() << " | "<< str_to_log << "\n";
}

// For clearing the current log file
void clear(){
        std::ofstream log_file;

        log_file.open(LOG_FILE_NAME);
        log_file << "";
}


// For logging to both the file and console at the same time
void both(std::string str_to_log){
        file(str_to_log);
        console(str_to_log);
}

}}

#endif
