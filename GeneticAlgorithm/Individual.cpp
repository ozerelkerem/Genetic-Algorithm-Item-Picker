#include "Individual.h"



Individual::Individual()
{
	this->brain = new Brain();
	SetToDefaults();
}



Individual::Individual(Brain * from)
{
	this->brain = from->clone();
	SetToDefaults();
}

void Individual::calcScore(Maze *m)
{
	bool isAlive = true;
	int x = mapsize / 2, y = mapsize / 2;
	int step = 0;
	int mealEaten = 0;
	int laststep = 0; // son yemeði ne zaman yedi
	int minbetween = 1;
	std::vector<std::pair<int, int>> found; //ayný elmayý yemesin diye gezilen yerleri 2 yapýyoruz onu eski haline getirmek için nereleri yediðini tutuyoruz.
	while (step < chromosomelength && isAlive && mealEaten < numofmeal)
	{
		switch (brain->chromosome[step])
		{
		case 1:
			x--;
			break;
		case 2:
			y--;
			break;
		case 3:
			x++;
			break;
		case 4:
			y++;
			break;
		default:
			assert(false);
		}

		if (x < 0 || y < 0 || x >= mapsize || y >= mapsize)
			isAlive = false;
		if (isAlive && m->at(x,y) == 1)
		{
			minbetween += (step - laststep);
			laststep = step;
			
			mealEaten++;

			m->at(x, y) = 2;
			found.push_back(std::make_pair(x, y));
		}

		step++;

	}
	for (auto pair : found)
		m->at(pair.first, pair.second) = 1;
	if(mealEaten != 0)
		minbetween /= mealEaten;
	
	
	score = mealEaten* mealEaten*mealEaten; 
	score += (mealEaten * 20 * (0.5-((float)laststep / chromosomelength / 2.f))); // son yemeði erken yiyen daha yüksek puan alýr.
	if(isAlive)
		score += (mealEaten*5);
	score += numofmeal / minbetween *3;
	eatcount = mealEaten;
}

/*
Yediði yerlerin kordinatlarýný döndürür
*/
std::vector<std::pair<int, int>> Individual::getvisiteds(Maze * m)
{
	bool isAlive = true;
	int x = mapsize / 2, y = mapsize / 2;
	int step = 0;
	int mealEaten = 0;
	std::vector<std::pair<int, int>> found;
	while (step < chromosomelength && isAlive && mealEaten < numofmeal)
	{
		switch (brain->chromosome[step])
		{
		case 1:
			x--;
			break;
		case 2:
			y--;
			break;
		case 3:
			x++;
			break;
		case 4:
			y++;
			break;
		default:
			break;
		}

		if (x < 0 || y < 0 || x >= mapsize || y >= mapsize)
			isAlive = false;
		if (isAlive && m->at(x, y) == 1)
		{
			mealEaten++;
			m->at(x, y) = 2;
			found.push_back(std::make_pair(x, y));
		}

		step++;

	}
	for (auto pair : found)
		m->at(pair.first, pair.second) = 1;

	return found;
}
