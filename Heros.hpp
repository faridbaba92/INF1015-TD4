#pragma once
#include "Personnage.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Heros : virtual public Personnage {
public:
	string getEnnemi()const;
	vector<string> getListeAlies()const;
	Heros(string nom, string parution, string ennemi, vector<string> listeAlies) : Personnage(nom, parution), ennemi_(ennemi), listeAlies_(listeAlies) {
	
	}
	ostream& afficher(ostream& out);

private:
	string ennemi_;
	vector<string> listeAlies_;
};


