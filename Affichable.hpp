#pragma once
#include <iostream>
using namespace std;

class Affichable {
public:
	virtual ostream& afficher(ostream& out) = 0;
	virtual ostream& changerCouleur(ostream& out, int code) = 0;
};
