#include "Maze.h"



Maze::Maze()
{
	map.resize(mapsize*mapsize, 0);
	int placedMeal = 0;
	while (placedMeal < numofmeal)
	{
		int x = dist(mersenne_engine) * mapsize;
		int y = dist(mersenne_engine) * mapsize;

		if (at(x,y) == 0)
		{
			at(x,y) = 1;
			placedMeal++;
		}
	}


}

Maze::Maze(std::string path)
{
	ifstream file;
	file.open(path, ios::binary | ios::in);
	if (!file)
		throw std::exception("File error when saving a model.");

	map.resize(mapsize *mapsize);
	Serializable::readfile(file, this->map.data(), mapsize * mapsize);
}


Maze::~Maze()
{
}

void Maze::save(std::string path)
{
	ofstream file;
	file.open(path, ios::binary | ios::out);
	if (!file)
		throw std::exception("File error when saving a model.");


	
	Serializable::writefile(file, map.data(), mapsize*mapsize);

	file.close();
}
