#ifndef GRAPH_H
#define GRAPH_H
#include "Koordinaten.h"

class Graph
{
    protected:
        Koordinaten m_ursprung;
        Graph(float x, float y) : m_ursprung(Koordinaten(x,y)) {}
        Graph(Koordinaten ursprung) : m_ursprung(ursprung) {}

    public:
        Koordinaten& getUrsprung() {return m_ursprung;}
        void setUrsprung(Koordinaten ursprung) {m_ursprung = ursprung;}
        virtual float getArea() const = 0;
        virtual std::string toString() const;
        virtual ~Graph () {};
};

#endif
