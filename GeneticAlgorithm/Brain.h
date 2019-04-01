#pragma once
#include"shared.h"

class Brain
{
public:
	/*
	Random genlerden olu�an bir beyin �retir
	*/
	Brain();
	~Brain() { };
	/*
	Genler dizisi
	*/
	Chromosome chromosome;
	/*
		Verilen �ans parametresine g�re her bir geni mutasyana u�rat�r. Her bir gen i�in random at�l�r.
	*/
	inline void mutate(double chance) {
		double random;
		for (int i = 0; i < chromosomelength; i++)
		{
			random = dist(mersenne_engine);
			if (random < chance)
			{
				chromosome[i] = dist(mersenne_engine) * 4 + 1;
			}
		}
			
	};
	/*
		Ayn� beynin yeni bir kopyas�n� olu�turur.
	*/
	inline Brain *clone() {
		Brain *newone = new Brain();
		newone->chromosome = chromosome;
		return  newone;
	};
	
};

