#ifndef GUI_H
#define GUI_H

#include<SFML/Graphics.hpp>

class Gui 
{
private:
	sf::RenderWindow window;
	sf::RectangleShape ob;
public:
	Gui();
	void add(std::string s, int i, int j);
	void disp();
	void clear();
};


#endif //GUI_H
