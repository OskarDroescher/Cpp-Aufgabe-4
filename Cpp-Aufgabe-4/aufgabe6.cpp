#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <limits>

#include "Graph.h"
#include "Kreis.h"
#include "Rechteck.h"
#include "OutOfRangeException.h"

std::vector<Graph*> elements {};

void flush () {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt (std::string prompt) {
    std::cout << prompt << ": ";
    int num;
    std::cin >> num;
    flush();
    return num;
}

float readFloat (std::string prompt) {
    std::cout << prompt << ": ";
    float num;
    std::cin >> num;
    flush();
    return num;
}

int getSelection(std::vector<std::string> options, std::string title = "Optionen", std::string prompt = "Was moechten Sie tun") {
    
    if (options.size() == 0) {
        return 0;
    }

    std::cout << "--- " << title << " ---" << std::endl;
    for (int i = 0; i < options.size(); ++i) {
        std::cout << "  " << i+1 << ": " << options[i] << std::endl;
    }
    std::cout << std::endl;

    int selection = readInt(prompt);

    if (selection < 1 || selection > options.size()) {
        std::cout << std::endl << std::endl << "Invalide Eingabe..." << std::endl << std::endl << std::endl;
        return getSelection(options);
    }

    std::cout << std::endl << std::endl << std::endl;

    return selection - 1;
}

Koordinaten getPosition () {
    float x = readFloat("Position (X)");
    float y = readFloat("Position (Y)");
    return Koordinaten(x,y);
}

void createKreis() {
    std::cout << "--- Kreis ---" << std::endl;
    Koordinaten origin = getPosition();
    float radius = readFloat("Radius");

    try {
        elements.push_back(new Kreis(origin, radius));
    } catch (OutOfRangeException e) {
        std::cout << std::endl << "Invalide Eingabe: " << e.getError() << std::endl;
        createKreis();
    }
    std::cout << std::endl << std::endl << std::endl;
}

void createRechteck() {
    std::cout << "--- Rechteck ---" << std::endl;
    Koordinaten origin = getPosition();
    float width = readFloat("Breite");
    float height = readFloat("Hoehe");

    try {
        elements.push_back(new Rechteck(origin, width, height));
    } catch (OutOfRangeException e) {
        std::cout << std::endl << "Invalide Eingabe: " << e.getError() << std::endl;
        createRechteck();
    }
    std::cout << std::endl << std::endl << std::endl;
}

float printElementAndReturnArea(Graph* element) {
    std::cout << "-----------------------" << std::endl;
    std::cout << element->toString() << std::endl;
    float area = element->getArea();
    std::cout << "Flaeche: " << area << std::endl;
    std::cout << "-----------------------" << std::endl << std::endl;
    return area;
}

void listElements(bool circlesFirst = false) {
    std::cout << "---  Gespeicherte Elemente (" << (circlesFirst ? "Kreise zuerst" : "Gemischt") << ") ---" << std::endl;
    
    float totalArea = 0;

    if (circlesFirst) {
        for (int i = 0; i < elements.size(); ++i) {
            Kreis* pKreis = dynamic_cast<Kreis*>(elements[i]);
            if(pKreis != 0) {
                totalArea += printElementAndReturnArea(elements[i]);
            }
        }
        for (int i = 0; i < elements.size(); ++i) {
            Kreis* pKreis = dynamic_cast<Kreis*>(elements[i]);
            if(pKreis == 0) {
                totalArea += printElementAndReturnArea(elements[i]);
            }
        }

    } else {
        for (int i = 0; i < elements.size(); ++i) {
            totalArea += printElementAndReturnArea(elements[i]);
        }
    }

    
    std::cout << std::endl << "  Gesamtanzahl: " << elements.size() << " Elemente" << std::endl;
    std::cout << "  Gesamtflaeche: " << totalArea << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}

int main() {
    std::vector<std::string> modes{"Ein Element erstellen", "Alle Elemente auflisten", "Das Programm beenden"};
    std::vector<std::string> elementTypes{"Kreis", "Rechteck"};
    std::vector<std::string> sortModes{"Gemischt", "Kreise zuerst"};

    while (true) {
        switch (getSelection(modes)) {
            case 0:
                switch (getSelection(elementTypes, "Elementtypen", "Was fuer ein Element wollen Sie erstellen")) {
                    case 0:
                        createKreis();
                        break;
                    case 1:
                        createRechteck();
                        break;
                }
                break;
            case 1:
                switch (getSelection(sortModes, "Sortierungen", "Wie wollen sie die Elemente sortieren")) {
                    case 0:
                        listElements();
                        break;
                    case 1:
                        listElements(true);
                        break;
                }
                break;
            case 2:
                for (int i = 0; i < elements.size(); ++i) {
                     delete elements[i];
                }
                return 0;
                break;
        }
    } 
}
