#pragma once
#include "shared.h"
#include "Individual.h"

class Population
{
public:
	/**
	 *   Random Bireylerden olu�an bir populasyon yarat�r
	 **/
	Population();
	/**
	 *   Bir Populasyondan Populasyon Yatar�r. ve gerekli hesaplamalar� yapar
	 **/
	Population(Population*, Maze *);
	~Population() { std::for_each(individuals.begin(), individuals.end(), [](Individual *x) { delete x; }); };

	/*
		Bireylerin uygunluk de�erini hesapla
	*/
	void calcFitness(Maze *m);

	/*
		En uygun bireyi bul
	*/
	void calcBest();
	/*
		en uygun birey
	*/
	Individual *best;
	/*
		Uygunluk oran�na g�re bir birey se� | Rulet
	*/
	Individual *randomSelect();

	/*
		Kromozom uzunlu�undan bir orta nokta belirle yar�n� anneden yar�s�n� babadan al�p crossover yap
	*/
	Individual *crossOver(Individual *, Individual *);

	/*
		Bireylerin dizisi
	*/
	std::vector<Individual*> individuals;
};

