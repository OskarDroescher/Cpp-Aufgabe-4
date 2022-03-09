#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <limits>
#include "Graph.h"
#include "Kreis.h"
#include "Rechteck.h"
#include "OutOfRangeException.h"

std::vector<Graph*> elements{};

void flush() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(std::string prompt) {
	std::cout << prompt << ": ";
	int num;
	std::cin >> num;
	flush();
	return num;
}

float readFloat(std::string prompt) {
	std::cout << prompt << ": ";
	float num;
	std::cin >> num;
	flush();
	return num;
}

int getSelection(std::vector<std::string> options, std::string title = "Aktionen", std::string prompt = "Was moechten Sie machen") {

	if (options.size() == 0) {
		return 0;
	}

	std::cout << "--- " << title << " ---" << std::endl;
	for (int i = 0; i < options.size(); ++i) {
		std::cout << "  " << i + 1 << ": " << options[i] << std::endl;
	}
	std::cout << std::endl;

	int auswahl = readInt(prompt);

	if (auswahl < 1 || auswahl > options.size()) {
		std::cout << std::endl << std::endl << "Ungueltige Eingabe..." << std::endl << std::endl << std::endl;
		return getSelection(options);
	}

	std::cout << std::endl << std::endl << std::endl;

	return auswahl - 1;
}

Koordinaten getPosition() {
	float x = readFloat("Position (X)");
	float y = readFloat("Position (Y)");
	return Koordinaten(x, y);
}

void createKreis() {
	std::cout << "--- Kreis ---" << std::endl;
	Koordinaten ursprung = getPosition();
	float radius = readFloat("Radius");

	try {
		elements.push_back(new Kreis(ursprung, radius));
	}
	catch (OutOfRangeException e) {
		std::cout << std::endl << "Ungueltige Eingabe: " << e.getError() << std::endl;
		createKreis();
	}
	std::cout << std::endl << std::endl << std::endl;
}

void createRechteck() {
	std::cout << "--- Rechteck ---" << std::endl;
	Koordinaten ursprung = getPosition();
	float breite = readFloat("Breite");
	float hoehe = readFloat("Hoehe");

	try {
		elements.push_back(new Rechteck(ursprung, breite, hoehe));
	}
	catch (OutOfRangeException e) {
		std::cout << std::endl << "Ungueltige Eingabe: " << e.getError() << std::endl;
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

void listElements(bool kreise = false) {
	std::cout << "---  Gespeicherte Elemente (" << (kreise ? "erst Kreise dann Rechtecke" : "Gemischt") << ") ---" << std::endl;

	float bereich = 0;

	if (kreise) {
		for (int i = 0; i < elements.size(); ++i) {
			Kreis* kKreis = dynamic_cast<Kreis*>(elements[i]);
			if (kKreis != 0) {
				bereich += printElementAndReturnArea(elements[i]);
			}
		}
		for (int i = 0; i < elements.size(); ++i) {
			Kreis* kKreis = dynamic_cast<Kreis*>(elements[i]);
			if (kKreis == 0) {
				bereich += printElementAndReturnArea(elements[i]);
			}
		}
	}
	else {
		for (int i = 0; i < elements.size(); ++i) {
			bereich += printElementAndReturnArea(elements[i]);
		}
	}
	std::cout << std::endl << "  Gesamtanzahl: " << elements.size() << " Elemente" << std::endl;
	std::cout << "  Gesamtflaeche: " << bereich << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

int main() {
	//---------------Aufgabe_2--------------------------------
	/*
	Kreis kreis = Kreis(10, 15, 3);
	std::cout << "--- Kreis ---" << std::endl;
	std::cout << kreis.toString() << std::endl << std::endl;
	std::cout << "kreis.setRadius(50);" << std::endl;
	kreis.setRadius(50);
	std::cout << "--- Kreis ---" << std::endl;
	std::cout << kreis.toString() << std::endl << std::endl;
	std::cout << "kreis.getUrsprung().setX(20);" << std::endl;
	kreis.getUrsprung().setX(20);
	std::cout << "--- Kreis ---" << std::endl;
	std::cout << kreis.toString() << std::endl << std::endl;
	Rechteck rechteck = Rechteck(10, 10, 5, 20);
	std::cout << "--- Rechteck ---" << std::endl;
	std::cout << rechteck.toString() << std::endl << std::endl;
	std::cout << "rechteck.setWidth(50);" << std::endl;
	rechteck.setWidth(50);
	std::cout << "--- Rechteck ---" << std::endl;
	std::cout << rechteck.toString() << std::endl << std::endl;
	std::cout << "rechteck.getUrsprung().setX(20);" << std::endl;
	rechteck.getUrsprung().setX(20);
	std::cout << "--- Rechteck ---" << std::endl;
	std::cout << rechteck.toString() << std::endl << std::endl;
	*/

	//-----------------Aufgabe_4--------------------------
	/*
	// Kreis kann weiter erstellt werden
	Kreis kreis = Kreis(5);
	// Graph kann einzeln nicht erstellt werden
	// Graph graph = Graph(5, 20);
	*/

	//------------------Aufgabe_6-------------------------

	std::vector<std::string> modus{ "Ein Element erstellen", "Alle Elemente anzeigen", "Programm beenden" };
	std::vector<std::string> elementmodus{ "Kreis", "Rechteck" };
	std::vector<std::string> auswahlmodus{ "Gemischt", "erst Kreise dann Rechtecke" };

	while (true) {
		switch (getSelection(modus)) {
		case 0:
			switch (getSelection(elementmodus, "Elementtypen", "Was fuer ein Element wollen Sie erstellen")) {
			case 0:
				createKreis();
				break;
			case 1:
				createRechteck();
				break;
			}
			break;
		case 1:
			switch (getSelection(auswahlmodus, "Sortierungen", "Wie wollen sie die Elemente sortieren")) {
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
