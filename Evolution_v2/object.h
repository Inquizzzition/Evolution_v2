#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>

enum act {
	skip, 
	go_up, go_left, go_down, go_right,
	eat_up, eat_left, eat_down, eat_right, 
	see_up, see_left, see_down, see_right,
	death
};

class Object
{
private:
	std::string obj;
public:
	Object();
	virtual void create_programm();
	virtual void set_mutate_programm(std::vector<int> p);
	virtual std::vector<int> get_prorgamm();
	virtual int update();
	virtual std::string who();
	virtual void plus_hp(int p);
	virtual void see(std::string s);
};



#endif //OBJECT_H