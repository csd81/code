#include "logger.h"
#include <string>

io::Logger::Logger(const std::string& p) : file(p) {}
io::Logger::~Logger(){ if(file.is_open()) file.close(); }
void io::Logger::log(const std::string& e) {
    file << e << "\n";
}
