#include "Color.h"

Color::Color(){
	name = "Black";
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(string nameIn, int redIn, int greenIn, int blueIn){
	name = nameIn;
	red = redIn;
	green = greenIn;
	blue = blueIn;
}

bool Color::operator==(Color one, Color two){
	if(one.red == two.red && one.green == two.green && one.blue == two.blue){
		return true;
	}else{
		return false;
	}
}

bool Color::operator>(Color one, Color two){
	if(one.distance() > two.distance(){
		return true;
	}else{
		return false;
	}
}

bool Color::operator<(Color one, Color two){
	if(one.distance0() < two.distance(){
		return false;
	}else{
		return true;
	}
}

int Color::sum(){
	return color.red + color.green + color.blue;
}

float Color::distance(Color one){
	float tempDist = 0.0;
	tempDist = sqrt(sqr(one.red) + sqr(one.green) + sqr(one.blue));
}