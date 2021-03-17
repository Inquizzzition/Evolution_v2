#ifndef MUSOR_H
#define MUSOR_H

#include "object.h"

class Null : public Object
{
private:
	std::string nobj;
public:
	Null();
	std::string who(); 
	int update();
};

class Food : public Object
{
private:
	std::string nobj;
public:
	Food();
	std::string who();
	int update();
};

class Wall : public Object
{
private:
	std::string nobj;
public:
	Wall();
	std::string who();
	int update();
};

#endif //MUSOR_H