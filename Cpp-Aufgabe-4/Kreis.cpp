#include "Kreis.h"
#include "OutOfRangeException.h"
#include <string>
#include <sstream>
#include <iomanip>

std::string Kreis::toString() const
{
    std::stringstream s;
    s << Graph::toString();
    s << "Radius: " << m_radius;
    return s.str();
}

float Kreis::getArea() const {
    return 3.1415926535 * m_radius * m_radius;
}

float Kreis::checkRadius(float radius) {
    if (radius <= 0) {
        throw OutOfRangeException("Radius des Kreises ist 0 oder kleiner, dies ist nicht erlaubt.");
    } 
    return radius;
}
