#include "Population.h"



Population::Population()
{
	individuals.resize(populationsize);
	std::generate(individuals.begin(), individuals.end(), []() {return new Individual(); });
}

Population::Population(Population *population, Maze *m)
{
	population->calcFitness(m);

	individuals.resize(populationsize);
	
	individuals[0] = new Individual(population->best->brain); //en iyi bireyi her zaman hayatta tut
/*	individuals[1] = crossOver(population->best, population->randomSelect());
	individuals[2] = crossOver(population->randomSelect(), population->best);
	individuals[3] = new Individual(population->best->brain);
	individuals[4] = new Individual(population->best->brain);
	individuals[5] = new Individual(population->best->brain);
	individuals[6] = new Individual(population->best->brain);
	individuals[3]->brain->mutate(0.2);
	individuals[4]->brain->mutate(0.07);
	individuals[5]->brain->mutate(0.3);
	individuals[6]->brain->mutate(0.5);*/

	std::sort(population->individuals.begin(), population->individuals.end(), []( Individual *a, Individual *b) { return a->score > b->score; });

	for(int i = 1; i < populationsize *crossoverrate; i++)
	{
		/*
		Individual *child = population->randomSelect();
		Individual *baby = new Individual(child->brain);
		baby->brain->mutate(mutaterate);
		individuals[i] = baby;
		*/
		Individual *baby = crossOver(population->randomSelect(), population->randomSelect());
		baby->brain->mutate(mutaterate);
		individuals[i] = baby;
	}
	for(int i = populationsize *crossoverrate; i < populationsize ; i++)
	{
		Individual *baby = new Individual( population->randomSelect()->brain);
		baby->brain->mutate(mutaterate);
		individuals[i] = baby;
	}
}

void Population::calcFitness(Maze *m)
{
	double sum = 0;
	for (auto &indi : individuals)
	{
		indi->calcScore(m);
		sum += indi->score;
	}
	assert(sum > 0);
	for (auto &indi : individuals)
	{
		indi->fitness = indi->score / sum * 100;
	}

	calcBest();
}

void Population::calcBest()
{
	best = *std::max_element(individuals.begin(), individuals.end(), []( const Individual *a, const Individual *b) { return a->fitness < b->fitness; });
}

Individual * Population::randomSelect()
{
	double random = dist(mersenne_engine) * selectrate;
	double runningSum = 0;
	for (auto indi : individuals)
	{
		runningSum += indi->fitness;
		if (runningSum > random)
			return indi;
	}
	return individuals.back();
	assert(false);

}

Individual * Population::crossOver(Individual *father, Individual *mother)
{
	Individual *child = new Individual();
	int point = dist(mersenne_engine) * chromosomelength;
	for (int i = 0; i < point; i++)
		child->brain->chromosome[i] = father->brain->chromosome[i];
	for (int i = point; i < chromosomelength; i++)
		child->brain->chromosome[i] = mother->brain->chromosome[i];
	return child;

}


