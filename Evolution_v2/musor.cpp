#include "musor.h"

Null::Null() :
	nobj("Null")
{}
Food::Food() :
	Object(),
	nobj("Food")
{}
Wall::Wall() :
	Object(),
	nobj("Wall")
{}
std::string Null::who() {
	return nobj;
}
std::string Wall::who() {
	return nobj;
}
std::string Food::who() {
	return nobj;
}
int Food::update() {
	return act::skip;
}

int Null::update() {
	return act::skip;
}

int Wall::update() {
	return act::skip;
}