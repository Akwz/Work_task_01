#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#include "line.h"
#include "area.h"
#include "filter_manager.h"


std::list<Point> parsePoints(const std::string &_buf) {
	char delim = ',';
	std::stringstream s_buffer;
	std::list<Point> result;

	s_buffer << _buf;
	while(!s_buffer.eof()) {
		std::string coords;
		s_buffer >> coords;
		if(coords.size() > 0) {
			int delim_pos = coords.find(delim);
			float x_coord = std::atof(coords.substr(0, delim_pos).c_str());
			float y_coord = std::atof(coords.substr(delim_pos+1).c_str());
			result.push_back(Point(x_coord, y_coord));
		}
	}
	return result;
}

int main(int argc, char **argv) {

	std::string f_path = "input.txt";

	if(argc > 1) {
		std::string f_path = std::string(argv[1]);
	}

	std::list<Line> cur_lines;
	FilterManager cur_filter;

	std::string buffer;
	std::stringstream s_buffer;
	std::ifstream input;
	input.open(f_path);

	// parse area pos
	std::getline(input, buffer, '\n');
	if(buffer.find("area") == std::string::npos) {
		std::cout << "Wrong input format" << std::endl;
		return 1;
	}
	std::getline(input, buffer, '\n');
	Area cur_area(parsePoints(buffer));

	// parse lines
	while(!input.eof()) {
		std::getline(input, buffer, '\n');
		if(buffer.find("line") == 0) {
			std::getline(input, buffer, '\n');
			cur_lines.push_back(Line(parsePoints(buffer)));
		}
	}
	
	input.close();

	// filtering
	cur_filter.setArea(cur_area);
	cur_filter.setLines(cur_lines);
	std::list<Line> filtered_lines = cur_filter.filter();

	int l_count = 0;
	std::cout << "~~~ Filtered list ~~~\n";
	for(Line _line : filtered_lines) {
		++l_count;
		std::cout << "~ line ~\n";
		std::cout << "Point1: ("
				  << _line.getStartPoint().getX()
				  << " ; "
				  << _line.getStartPoint().getY()
				  << ") ";
		std::cout << "Point2: ("
				  << _line.getEndPoint().getX()
				  << " ; "
				  << _line.getEndPoint().getY()
				  << ")\n";
	}
	std::cout << " === Lines count: " << l_count << " ===\n";


	return 0;
}