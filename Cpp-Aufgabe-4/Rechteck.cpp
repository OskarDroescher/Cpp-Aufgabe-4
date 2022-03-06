#include "Rechteck.h"
#include "OutOfRangeException.h"

#include <string>
#include <sstream>
#include <iomanip>

std::string Rechteck::toString() const
{
    std::stringstream s;
    s << Graph::toString();
    s << "Breite: " << m_width << std::endl;
    s << "Hoehe: " << m_height;
    return s.str();
}

float Rechteck::getArea() const {
    return m_width * m_height;
}

float Rechteck::checkDimension(float dimension) {
    if (dimension <= 0) {
        throw OutOfRangeException("dimension of a rectangle may not be 0 or less");
    }
    return dimension;
}
