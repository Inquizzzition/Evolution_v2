#include "robot.h"

Robot::Robot() :
	nobj("Robot"),
	programm(16),
	ind(0),
	div(rand() % 4),
	hp(40)
{}

int Robot::update()
{
	int t = programm[ind];
	ind++;
	if (ind >= programm.size())
		ind = 0;
	hp--;
	if (hp <= 0) 
		return (act::death);
	if (t == action::Go)
		return(div + 1);
	if (t == action::Turn_r) {
		div++;
		if (div >= 4)
			div = 0;
	}
	if (t == action::Turn_r) {
		div--;
		if (div < 0)
			div = 3;
	}
	if (t == action::Eat) {
		return(div + 5);
	}
	if (t == action::See) {
		return(div+9);
	}
	return act::skip;
}

void Robot::plus_hp(int p) {
	hp += p;
}

void Robot::see(std::string s) {
	if (s == "Null")
		ind += 1;
	if (s == "Food")
		ind += 2;
	if (s == "Wall")
		ind += 3;
	if (s == "Robot")
		ind += 4;
	if (ind >= programm.size())
		ind = 0;
}

std::string Robot::who() 
{
	return nobj;
}
void Robot::create_programm()
{
	for (int i = 0; i < programm.size(); i++) {
		programm[i] = rand() % 5;
	}
}
void Robot::set_mutate_programm(std::vector<int> p)
{
	int i = rand() % p.size();
	p[i] = rand() % 5;
	programm = p;
}
std::vector<int> Robot::get_prorgamm()
{
	return(programm);
}

