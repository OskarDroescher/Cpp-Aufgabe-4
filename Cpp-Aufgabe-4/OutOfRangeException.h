#ifndef OUTOFRANGEEXCEPTION_H
#define OUTOFRANGEEXCEPTION_H

#include <exception>
#include <string>

class OutOfRangeException
{
    public:
        OutOfRangeException (const std::string& message): m_message(message) {}

        std::string getError() const {
            return "OutOfRangeException: " + m_message;
        }

    private:
        std::string m_message;
};
#endif /* OUTOFRANGEEXCEPTION_H */
