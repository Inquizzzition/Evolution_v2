#include "object.h"

Object::Object():
	obj("Object")
{}

void Object::create_programm() {}
void Object::set_mutate_programm(std::vector<int> p) {}
std::vector<int> Object::get_prorgamm() {
	std::vector<int> a(16, rand()%5);
	return a;
}
int Object::update() { 
	return 0; 
}
void Object::plus_hp(int p) {}
void Object::see(std::string s){}
std::string Object::who() {
	return obj;
}
