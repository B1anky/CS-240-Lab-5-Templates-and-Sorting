#include <string>
#include <cmath>
#include <stdbool.h>
#include <iostream>

class Color{
	private:
		std::string name;

	public:
		int red;
		int green;
		int blue;
		Color();
		Color(std::string nameIn, int redIn, int greenIn, int blueIn);
		bool operator==(Color other);
		bool operator>(Color other);
		bool operator<(Color other);
		friend std::ostream& operator <<(std::ostream &out, Color const& color);
		float distance();

};