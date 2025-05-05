#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>

namespace io {
    class Logger
    {
    public:
        Logger(const std::string& path);
        ~Logger();
        void log(const std::string& entry);
    private:
        std::ofstream file;
    };
}
#endif // LOGGER_H
