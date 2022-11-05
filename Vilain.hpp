#pragma once
using namespace std;
#include "Personnage.hpp"

class Vilain : virtual public Personnage {
public:
	string getObjectif()const;
	Vilain(string nom, string parution, string objectif): Personnage(nom, parution), objectif_(objectif){
	}

	ostream& afficher(ostream& out);
private:
	string objectif_;
};