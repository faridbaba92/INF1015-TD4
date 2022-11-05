#include "VilainHeros.hpp"
using namespace std;




ostream&  VilainHeros::afficher(ostream& out)
{
	changerCouleur(out, 32);

	Personnage::afficher(out);
	
	out << "objectif : "
		<< getObjectif() << "\n" << "Ennemi : " << getEnnemi() << "\n";

	out << "liste d'ali�s :  \n";

	for (int i = 0; i < getListeAlies().size(); i++)
	{
		out << "\t" << getListeAlies()[i] << "\n";
	}

	out << "mission sp�ciale : " << missionSpeciale_;

	changerCouleur(out, 0);


	return out;

}