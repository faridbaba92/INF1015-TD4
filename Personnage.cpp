#include "Personnage.hpp"
#include <string>
using namespace std;

string Personnage::getNom() const{
	return nom_;
}

string Personnage::getParution() const {
	return parution_;
}

ostream& Personnage::afficher(ostream& out) {
	out << "Nom : "
		<< nom_
		<< "\n"
		<< "Parution : "
		<< parution_
		<< "\n";

	return out;
}



ostream& Personnage::changerCouleur(ostream& out, int code){
	string couleur = "\033[" + std::to_string(code) + "m";
	
	out << couleur;
	return out;

};