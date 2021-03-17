#include "field.h"

Field::Field() :
	field(30, std::vector<Object*>(30)),
	day(0),
	generation(0),
	robot_n(0),
	food_n(0),
	g(),
	okno(false)
{}

void Field::create_field() 
{
	day++;
	generation++;
	for (int i = 1; i < 29; i++)
		for (int j = 1; j < 29; j++)
			field[i][j] = new Null();
	for (int i = 0; i < 30; i++)
		field[0][i] = new Wall();
	for (int i = 0; i < 30; i++)
		field[29][i] = new Wall();
	for (int i = 0; i < 30; i++)
		field[i][0] = new Wall();
	for (int i = 0; i < 30; i++)
		field[i][29] = new Wall();
	
	int food = 300;
	int robo = 20;
	robot_n = 20;
	food_n = 500;
	while (food >= 0) {
		int x = rand() % 28 + 1;
		int y = rand() % 28 + 1;
		std::string s = field[x][y]->who();
		if (s == "Null") {
			field[x][y] = new Food;
			food--;
		}
	}

	while (robo >= 0) {
		int x = rand() % 28 + 1;
		int y = rand() % 28 + 1;
		std::string s = field[x][y]->who();
		if (s == "Null") {
			field[x][y] = new Robot;
			if (day == 1)
				field[x][y]->create_programm();
			else if (robo > 15)
				field[x][y]->set_mutate_programm(best_programm[19]);
			else if (robo > 10)
				field[x][y]->set_mutate_programm(best_programm[18]);
			else if (robo > 5)
				field[x][y]->set_mutate_programm(best_programm[17]);
			else 
				field[x][y]->set_mutate_programm(best_programm[16]);
			robo--;
		}
	}
	best_programm.resize(0);
}

void Field::clear() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			delete(field[i][j]);
		}
	}
}

void Field::add_food(int n)
{
	food_n += n;
	while (n > 0) {
		int x = rand() % 28 + 1;
		int y = rand() % 28 + 1;
		std::string s = field[x][y]->who();
		if (s == "Null") {
			field[x][y] = new Food;
			n--;
		}
	}
}

void Field::next_day() {
	day++; 
	if(okno)
		g.clear();
	for (int i = 1; i < 29; i++) {
		for (int j = 1; j < 29; j++) {
			if(okno)
				g.add(field[i][j]->who(), i, j);
			int result = field[i][j]->update();
			if (result == act::skip)
				continue;
			if (result == act::death) {
				robot_n--;
				best_programm.emplace_back(field[i][j]->get_prorgamm());
				delete(field[i][j]);
				field[i][j] = new Null();
			}
			if (result == act::go_up) {
				if (field[i + 1][j]->who() == "Null" || field[i + 1][j]->who() == "Food") {
					if (field[i + 1][j]->who() == "Food") {
						field[i][j]->plus_hp(5);
						food_n--;
					}
					delete(field[i + 1][j]);
					field[i + 1][j] = field[i][j];
					field[i][j] = new Null();
				}
			}
			if (result == act::go_right) {
				if (field[i][j + 1]->who() == "Null" || field[i][j + 1]->who() == "Food") {
					if (field[i][j + 1]->who() == "Food") {
						field[i][j]->plus_hp(5);
						food_n--;
					}
					delete(field[i][j + 1]);
					field[i][j + 1] = field[i][j];
					field[i][j] = new Null();
				}
			}
			if (result == act::go_down) {
				if (field[i - 1][j]->who() == "Null" || field[i - 1][j]->who() == "Food") {
					if (field[i - 1][j]->who() == "Food") {
						field[i][j]->plus_hp(5);
						food_n--;
					}
					delete(field[i - 1][j]);
					field[i - 1][j] = field[i][j];
					field[i][j] = new Null();
				}
			}
			if (result == act::go_left) {
				if (field[i][j - 1]->who() == "Null" || field[i][j - 1]->who() == "Food") {
					if (field[i][j - 1]->who() == "Food") {
						field[i][j]->plus_hp(5);
						food_n--;
					}
					delete(field[i][j - 1]);
					field[i][j - 1] = field[i][j];
					field[i][j] = new Null();
				}
			}
			if (result == act::eat_up && field[i+1][j]->who() == "Food") {
				delete(field[i + 1][j]);
				field[i + 1][j] = new Null();
				field[i][j]->plus_hp(10);
				food_n--;
			}
			if (result == act::eat_right && field[i][j+1]->who() == "Food") {
				delete(field[i][j + 1]);
				field[i][j + 1] = new Null();
				field[i][j]->plus_hp(10);
				food_n--;
			}
			if (result == act::eat_down && field[i-1][j]->who() == "Food") {
				delete(field[i - 1][j]);
				field[i - 1][j] = new Null();
				field[i][j]->plus_hp(10);
				food_n--;
			}
			if (result == act::eat_left && field[i][j-1]->who() == "Food") {
				delete(field[i][j - 1]);
				field[i][j - 1] = new Null();
				field[i][j]->plus_hp(10);
				food_n--;
			}
			if (result == act::see_up) {
				field[i][j]->see(field[i + 1][j]->who());
			}
			if (result == act::see_right) {
				field[i][j]->see(field[i][j + 1]->who());
			}
			if (result == act::see_down) {
				field[i][j]->see(field[i - 1][j]->who());
			}
			if (result == act::see_left) {
				field[i][j]->see(field[i][j - 1]->who());
			}
		}
	}
	if(okno)
		g.disp();
	add_food(500 - food_n);
	if (best_programm.size() >= 20) {
		generation++;
		std::cout << generation << " " << day << "\n";
		day = 0;
		clear();
		create_field();
	}
}