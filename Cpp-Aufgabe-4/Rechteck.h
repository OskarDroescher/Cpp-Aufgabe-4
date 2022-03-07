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
        Rechteck(float x, float y, float width, float height) : Graph(x,y), m_width(pruefeDimension(width)), m_height(pruefeDimension(height)) {}
        Rechteck(float width, float height) : Graph(0,0), m_width(pruefeDimension(width)), m_height(pruefeDimension(height)) {}
        Rechteck(Koordinaten ursprung, float width, float height) : Graph(ursprung), m_width(pruefeDimension(width)), m_height(pruefeDimension(height)) {}
        std::string toString() const;
        void setWidth(float width) {m_width = pruefeDimension(width);}
        float getWidth() const {return m_width;}
        void setHeight(float height) {m_height = pruefeDimension(height);}
        float getHeight() const {return m_height;}
        float getArea() const;
        static float pruefeDimension(float dimension);
};

#endif
