#include"Vilain.hpp"
using namespace std;


string Vilain::getObjectif() const{
	return objectif_;
}

ostream& Vilain::afficher(ostream& out) {
	changerCouleur(out, 91);

	Personnage::afficher(out);

	out << "objectif : "
		<< objectif_ << "\n";

	changerCouleur(out, 0);


	return out;
}