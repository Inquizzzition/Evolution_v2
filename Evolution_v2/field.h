#ifndef FIELD_H
#define FIELD_H

#include "robot.h"
#include "musor.h"
#include "gui.h"

#include <iostream>
#include <string>
#include <vector>

class Field {
private:
	Gui g;
	std::vector<std::vector<Object*>> field;
	std::vector<std::vector<int>> best_programm;
	int day;
	int robot_n;
	int generation;
	int food_n;
	bool okno;
public:
	Field();
	void clear();
	void create_field();
	void next_day();
	void add_food(int n);
};

#endif // !FIELD_H