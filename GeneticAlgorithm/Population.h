#pragma once
#include "shared.h"
#include "Individual.h"

class Population
{
public:
	/**
	 *   Random Bireylerden oluþan bir populasyon yaratýr
	 **/
	Population();
	/**
	 *   Bir Populasyondan Populasyon Yatarýr. ve gerekli hesaplamalarý yapar
	 **/
	Population(Population*, Maze *);
	~Population() { std::for_each(individuals.begin(), individuals.end(), [](Individual *x) { delete x; }); };

	/*
		Bireylerin uygunluk deðerini hesapla
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
		Uygunluk oranýna göre bir birey seç | Rulet
	*/
	Individual *randomSelect();

	/*
		Kromozom uzunluðundan bir orta nokta belirle yarýný anneden yarýsýný babadan alýp crossover yap
	*/
	Individual *crossOver(Individual *, Individual *);

	/*
		Bireylerin dizisi
	*/
	std::vector<Individual*> individuals;
};

