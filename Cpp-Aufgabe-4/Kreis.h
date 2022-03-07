#ifndef KREIS_H
#define KREIS_H
#include "Graph.h"

class Kreis: public Graph
{
    private:
        float m_radius;

    public:
        ~Kreis() {};
        Kreis(float x, float y, float radius) : Graph(x, y), m_radius(checkRadius(radius)) {};
        Kreis(float radius) : Graph(0, 0), m_radius(checkRadius(radius)) {};
        Kreis(Koordinaten ursprung, float radius) : Graph(ursprung), m_radius(checkRadius(radius)) {};
        std::string toString() const;
        void setRadius(float radius) {m_radius = checkRadius(radius);}
        float getRadius() {return m_radius;}
        float getArea() const;
        static float checkRadius(float radius);
};

#endif
