#include <iostream>
#include <string>
#include "field.h"

int main()
{
	Field field;
	field.create_field();
	while (true) {
		field.next_day();
	}
}