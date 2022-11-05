#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "VilainHeros.hpp"
#include <iostream>
using namespace std;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

/*
shared_ptr<Jeu> lireJeu(istream& fichier, Liste<Jeu>& listeJeux)
{
	Jeu jeu = {}; // On initialise une structure vide de type Jeu
	jeu.titre = lireString(fichier);
	jeu.anneeSortie = int(lireUintTailleVariable(fichier));
	jeu.developpeur = lireString(fichier);
	size_t nElements = lireUintTailleVariable(fichier);
	// Rendu ici, les champs précédents de la structure jeu sont remplis avec la
	// bonne information.

	//TODO: Ajouter en mémoire le jeu lu. Il faut revoyer le pointeur créé.
	// Attention, il faut aussi créer un tableau dynamique pour les concepteurs
	// que contient un jeu. Servez-vous de votre fonction d'ajout de jeu car la
	// liste de jeux participé est une ListeJeu. Afficher un message lorsque
	// l'allocation du jeu est réussie.
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(jeu);  // Ou allouer directement au début plutôt qu'en faire une copie ici.
	cout << "\033[96m" << "Allocation en mémoire du jeu " << jeu.titre
			  << "\033[0m" << endl;
	// cout << jeu.titre << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	//ptrJeu->concepteurs.elements = new Concepteur* [ptrJeu->concepteurs.nElements];  // On n'a pas demandé de faire une réallocation dynamique pour les designers.

	for (size_t i = 0; i < nElements; i++) {
		shared_ptr ptrConcepteur = lireConcepteur(fichier, listeJeux);
		ptrJeu->concepteurs.ajouter(ptrConcepteur);
	}
	return ptrJeu; //TODO: Retourner le pointeur vers le nouveau jeu.
}

*/



Heros lireHeros(ifstream& fichier) {
	string nom = lireString(fichier);
	string parution = lireString(fichier);
	string ennemi = lireString(fichier);

	size_t nElements = lireUintTailleVariable(fichier);

	vector<string> listeAlies;

	for (int i = 0; i < nElements; i++) {

		listeAlies.push_back(lireString(fichier));
	}

	Heros heros(nom,  parution,  ennemi,listeAlies);
	return heros;
}



void creerHeros(vector<Heros>& vecteurHeros, ifstream& fichier) {
	size_t nElements = lireUintTailleVariable(fichier);

	for (int i = 0; i < nElements; i++) {
		vecteurHeros.push_back(lireHeros(fichier));
	}
}

Vilain lireVilain(ifstream& fichier) {
	string nom = lireString(fichier);
	string parution = lireString(fichier);
	string objectif = lireString(fichier);



	Vilain vilain(nom, parution, objectif);
	return vilain;
}

void creerVilain(vector<Vilain>& vecteurVilain, ifstream& fichier) {

	size_t nElements = lireUintTailleVariable(fichier);

	for (int i = 0; i < nElements; i++) {
		vecteurVilain.push_back(lireVilain(fichier));
	}
}


int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)
	vector <Heros> vecteurHeros;
	vector <Vilain> vecteurVilain;
	vector <shared_ptr<Personnage>> vecteurPersonnage;

	creerHeros(vecteurHeros, fichierHeros);
	creerVilain(vecteurVilain, fichierVilains);




	for (int i = 0; i < vecteurHeros.size(); i++) {
		vecteurHeros[i].afficher(cout);
		cout << "═════════════════════════════════════════════════════════════════════════"<< "\n";
	}

	for (int i = 0; i < vecteurVilain.size(); i++) {
		vecteurVilain[i].afficher(cout);
		cout << "═════════════════════════════════════════════════════════════════════════" << "\n";
	}


	for (int i = 0; i < vecteurHeros.size(); i++) {
		vecteurPersonnage.push_back(make_shared<Heros>(vecteurHeros[i]));
	}
	for (int i = 0; i < vecteurVilain.size(); i++) {
		vecteurPersonnage.push_back(make_shared<Vilain>(vecteurVilain[i]));
	}

	VilainHeros vilainHeros(vecteurHeros[0], vecteurVilain[1]);

	vecteurPersonnage.push_back(make_shared<VilainHeros>(vilainHeros));

	for (int i = 0; i < vecteurPersonnage.size(); i++) {
		
		vecteurPersonnage[i]->afficher(cout);
	}

}
