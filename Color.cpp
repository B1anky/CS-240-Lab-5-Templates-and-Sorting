#include "Color.h"

Color::Color(){
	name = "Black";
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(std::string nameIn, int redIn, int greenIn, int blueIn){
	name = nameIn;
	red = redIn;
	green = greenIn;
	blue = blueIn;
}

bool Color::operator==(Color other){
	if(this->red == other.red && this->green == other.green && this->blue == other.blue){
		return true;
	}else{
		return false;
	}
}

bool Color::operator>(Color other){
	if(this->distance() < other.distance()){
		return true;
	}else{
		return false;
	}
}

bool Color::operator<(Color other){
	if(this->distance() > other.distance()){
		return true;
	}else{
		return false;
	}
}

float Color::distance(){
	return sqrt(pow(this->red, 2) + pow(this->green, 2) + pow(this->blue, 2));
}

std::ostream& operator <<(std::ostream &out, Color const& color){
	out << color.name;
	//<< " R: " << color.red << " G:" << color.green << " B: " << color.blue;
	return out;
}