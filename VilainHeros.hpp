#pragma once
#include"Vilain.hpp"
#include"Heros.hpp"
using namespace std;

class VilainHeros : public Heros, public Vilain {
public:
	VilainHeros(Heros h, Vilain v) : Personnage(v.getNom() + "-" + h.getNom(), v.getParution() + "-" + h.getParution()), Heros(h), Vilain(v), missionSpeciale_(v.getObjectif() + " dans le monde de " + h.getParution()) {};

	ostream& afficher(ostream& out);
private:
	string missionSpeciale_;
};