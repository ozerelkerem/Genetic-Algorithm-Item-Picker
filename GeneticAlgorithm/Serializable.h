#pragma once

#include <iostream>
#include <fstream>
#include <direct.h>





using namespace std;

class Serializable
{
public:
	template<typename T>
	 static void writefile(ofstream& file, T val, size_t size = 1)
	{
		file.write(reinterpret_cast<char *>(&val), sizeof(T) * size);
	}
	template<typename T>
	 static void writefile(ofstream& file, T *val, size_t size = 1)
	{
		file.write(reinterpret_cast<char *>(val), sizeof(T) * size);
	}

	 static void writefile(ofstream& file, std::string val)
	{
		Serializable::writefile(file, val.size());
		file.write(val.c_str(), val.size());
	}

	template<typename T>
	 static void readfile(ifstream& file, T *val, size_t size = 1)
	{
		file.read((char *)(val), sizeof(T) * size);
	}

	 static void readfile(ifstream& file, std::string *val)
	{
		size_t stringsize;
		Serializable::readfile(file, &stringsize);;
		val->resize(stringsize);
		Serializable::readfile(file, val->data(), stringsize);
	}

};