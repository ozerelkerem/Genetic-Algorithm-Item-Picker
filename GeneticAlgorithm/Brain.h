#pragma once
#include"shared.h"

class Brain
{
public:
	/*
	Random genlerden oluþan bir beyin üretir
	*/
	Brain();
	~Brain() { };
	/*
	Genler dizisi
	*/
	Chromosome chromosome;
	/*
		Verilen þans parametresine göre her bir geni mutasyana uðratýr. Her bir gen için random atýlýr.
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
		Ayný beynin yeni bir kopyasýný oluþturur.
	*/
	inline Brain *clone() {
		Brain *newone = new Brain();
		newone->chromosome = chromosome;
		return  newone;
	};
	
};

