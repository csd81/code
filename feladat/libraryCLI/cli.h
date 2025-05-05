#ifndef CLI_H
#define CLI_H
#include "library.h"


namespace io {
    class CLI
    {
    public:
        void run(domain::Library& lib);
    private:
        void handleCommand(const std::string& line, domain::Library& lib);
    };
}

#endif // CLI_H
