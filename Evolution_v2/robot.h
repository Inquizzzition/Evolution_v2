#ifndef ROBOT_H
#define ROBOT_H

#include "object.h"

enum action{Go, Eat, Turn_l, Turn_r, See};

class Robot : public Object
{
private:
	std::string nobj;
	std::vector<int> programm;
	int ind;
	int div;
	int hp;
public:
	Robot();
	void create_programm();
	void set_mutate_programm(std::vector<int> p);
	std::string who();
	std::vector<int> get_prorgamm();
	int update();
	void plus_hp(int p);
	void see(std::string s);
};

#endif // !ROBOT_H
/*

*/