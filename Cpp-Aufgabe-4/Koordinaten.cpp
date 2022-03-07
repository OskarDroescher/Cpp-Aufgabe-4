#include "Koordinaten.h"
#include <string>
#include <sstream>

std::string Koordinaten::toString() const {
    std::stringstream s;
    s << "(" << m_x << "," << m_y << ")" << std::endl;
    return s.str();
}
