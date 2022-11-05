#include "Heros.hpp"
using namespace std;



string Heros:: getEnnemi()const {
	return ennemi_;
}

vector<string> Heros::getListeAlies() const {
	return listeAlies_;
}


ostream& Heros::afficher(ostream& out) {
	changerCouleur(out, 34);
	Personnage::afficher(out);

	out << "liste d'aliés :  \n";

	for (int i = 0; i < listeAlies_.size(); i++)
	{
		out << "\t" << listeAlies_[i] << "\n";
	}

	changerCouleur(out, 0);


	return out;
}