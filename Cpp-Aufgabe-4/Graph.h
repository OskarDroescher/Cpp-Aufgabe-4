#ifndef GRAPH_H
#define GRAPH_H

#include "Koordinaten.h"

class Graph
{
    protected:
        Koordinaten m_origin;
        Graph(float x, float y) : m_origin(Koordinaten(x,y)) {}
        Graph(Koordinaten origin) : m_origin(origin) {}

    public:

        Koordinaten& getOrigin() {return m_origin;}
        void setOrigin(Koordinaten origin) {m_origin = origin;}

        virtual float getArea() const = 0;
        virtual std::string toString() const;
        virtual ~Graph () {};

};

#endif /* GRAPH_H */
