#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <string>
#include <iostream>

namespace io {
    class Notifier
    {
    public:
        virtual ~Notifier() = default;
        virtual void send(const std::string& msg) = 0;
    };

    class EmailNotifier : public io::Notifier {
        void send(const std::string& msg) override;
    };

}



#endif // NOTIFIER_H
