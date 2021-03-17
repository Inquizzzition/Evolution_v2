#include "gui.h"

Gui::Gui() :
	window(sf::VideoMode(300, 300), "Evol"),
	ob(sf::Vector2f(10.f, 10.f))
{}

void Gui::add(std::string s, int i, int j) {
	ob.setPosition(i*10, j*10);
	if (s == "Wall") {
		ob.setFillColor(sf::Color(255, 218, 185));
		window.draw(ob);
	}
	if (s == "Food") {
		ob.setFillColor(sf::Color(154, 205, 50));
		window.draw(ob);
	}
	if (s == "Robot") {
		ob.setFillColor(sf::Color(220, 20, 60));
		window.draw(ob);
	}
}

void Gui::disp() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	window.display();
}

void Gui::clear() {
	window.clear();
}