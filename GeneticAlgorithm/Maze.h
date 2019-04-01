#pragma once
#include "shared.h"
#include "Serializable.h"
class Maze
{
public:
	Maze();
	Maze(std::string);
	~Maze();


	void save(std::string);

	
	std::vector<uint8_t> map;

	void printMaze() {
		for (int i = 0; i < mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
				std::cout << (at(j,i) ? "+" : "-") << " ";
			std::cout << std::endl;
		}
	};

	inline uint8_t& at(int i, int j) { return map[j + i * mapsize]; }


};

