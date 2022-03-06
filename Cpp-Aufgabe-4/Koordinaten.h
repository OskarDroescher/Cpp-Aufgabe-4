#ifndef KOORDINATEN_H
#define KOORDINATEN_H

#include <string>

class Koordinaten
{
    private:
        float m_x; 
        float m_y;

    public:
        Koordinaten(float x, float y) : m_x(x), m_y(y) {}

        void setY(float y) {m_y = y;}
        float getY() const {return m_y;}

        void setX(float x) {m_x = x;}
        float getX() const {return m_x;}    

        std::string toString() const;

};

#endif /* KOORDINATEN_H */
