#pragma once
#define _HAS_STD_BYTE 0



#include<iostream>
#include<stdint.h>
#include<vector>
#include <random>
#include <algorithm>

struct Point2D {
	int x, y;

	Point2D() : x(0), y(0) {}
	Point2D(int a, int b) : x(a), y(b) {}
};
#define GUI
#ifdef GUI
#include <assert.h>
#include <Windows.h>
#include "ogl/GL/glew.h"
#include "ogl/GLFW/glfw3.h"


struct ColorRGB {
	GLfloat r, g, b;

	ColorRGB(GLfloat x, GLfloat y, GLfloat z) : r(x), g(y), b(z) {}
};




#endif

#define numofmeal 10 //Haritadaki yemek say�s�
#define mapsize 9 // Haritan�n b�y�kl��� nXn
#define populationsize 450 // Bir jenerasyonda ka� adet birey olacak
#define chromosomelength 81  // bir kromozomdaki gen say�s�
#define mutaterate 0.07 // her bir genin i�in mutasyon oran� [0,1]
#define selectrate 100 // [0,100] yeni nesil, eski nesilin %  ka��ndan se�ilsin
#define crossoverrate 0.3 // [0,1] yeni nesili olu�tururken ka��nda crossover olsun
#define maxstep 1000 // Maksimum ad�m say�s�


using Gene = uint8_t;
using Chromosome = std::vector<Gene>;


static std::random_device rnd_device;
static std::mt19937 mersenne_engine{ rnd_device() };
static std::uniform_real_distribution<double> dist{ 0, 1 };