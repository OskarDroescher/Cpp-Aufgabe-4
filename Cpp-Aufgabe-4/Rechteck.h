#ifndef RECHTECK_H
#define RECHTECK_H

#include <string>

#include "Graph.h"

class Rechteck: public Graph
{
    private:
        float m_width;
        float m_height;

    public:
        ~Rechteck () { {}};

        Rechteck(float x, float y, float width, float height) : Graph(x,y), m_width(checkDimension(width)), m_height(checkDimension(height)) {}
        Rechteck(float width, float height) : Graph(0,0), m_width(checkDimension(width)), m_height(checkDimension(height)) {}

        Rechteck(Koordinaten origin, float width, float height) : Graph(origin), m_width(checkDimension(width)), m_height(checkDimension(height)) {}

        std::string toString() const;

        void setWidth(float width) {m_width = checkDimension(width);}
        float getWidth() const {return m_width;}

        void setHeight(float height) {m_height = checkDimension(height);}
        float getHeight() const {return m_height;}

        float getArea() const;

        static float checkDimension(float dimension);
};

#endif /* RECHTECK_H */
