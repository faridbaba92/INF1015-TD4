#pragma once
#include "Affichable.hpp"
using namespace std;

class Personnage :public  Affichable {
public:
	Personnage(string nom, string parution) : nom_(nom), parution_(parution) {};
	
	string getNom() const;
	string getParution()const;
	virtual ostream& afficher(ostream& out);
	virtual ostream& changerCouleur(ostream& out, int code);
private:
	string nom_;
	string parution_;
};
