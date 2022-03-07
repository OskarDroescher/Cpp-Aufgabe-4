#include "Graph.h"
#include <string>
#include <sstream>
#include <iomanip>

std::string Graph::toString() const
{
    std::stringstream s;
    s << "Einfuegepunkt: " << m_ursprung.toString();
    return s.str();
}


