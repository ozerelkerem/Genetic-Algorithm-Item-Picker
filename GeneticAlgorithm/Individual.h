#pragma once
#include "shared.h"
#include "Brain.h"
#include "Maze.h"
class Individual
{
public:
	/*
	Random Beyine Sahip Birey Olu�turur.
	*/
	Individual();

	/*
	Verilen Beyni kopyalarak ayn� bireyi olu�turur.
	*/
	Individual(Brain *from);
	~Individual() { delete brain;  }

	Brain *brain;
	/*
		Ka� adet elma yedi
	*/
	int eatcount;

	/*
		Ka� puan yapt�
	*/
	float score;

	/*
		uygunluk de�eri
	*/
	float fitness;

	/*
		Haritada yapt��� puan� hesapla
	*/
	void calcScore(Maze *);



	//�izimler ile alakal� fonksiyonlar
	std::vector<std::pair<int, int>> getvisiteds(Maze *m);
	Point2D position;
	bool isAlive;
	void update(unsigned int step) {
		int eatcounter = 0;
		if (isAlive)
		{
			switch (brain->chromosome[step])
			{
			case 1:
				position.x--;
				break;
			case 2:
				position.y--;
				break;
			case 3:
				position.x++;
				break;
			case 4:
				position.y++;
				break;
			}

			if (position.x < 0 || position.y < 0 || position.x >= mapsize || position.y >= mapsize)
				isAlive = false;

		}
	};
	void SetToDefaults() {
		position = Point2D(mapsize / 2, mapsize / 2);
		isAlive = true;
	};

};

