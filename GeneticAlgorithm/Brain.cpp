#include "Brain.h"



Brain::Brain()
{
	chromosome.resize(chromosomelength);
	std::generate(chromosome.begin(), chromosome.end(), []() {return dist(mersenne_engine) * 4 + 1; });
}


