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

float Rechteck::pruefeDimension(float dimension) {
    if (dimension <= 0) {
        throw OutOfRangeException("Die Groeße des Rechteckes ist 0 oder kleiner, dies ist nicht erlaubt.");
    }
    return dimension;
}
