#include "filter_manager.h"

FilterManager::FilterManager(CalculationMethod *method)
	: isCrosses(method)
{

}

FilterManager::~FilterManager() {
	delete isCrosses;
}
/*..........................................*/

void FilterManager::setArea(const Area &a) {
	m_area = a;
}

void FilterManager::setLines(const std::list<Line> &lines) {
	m_lines = lines;
}

std::list<Line> FilterManager::filter() const {
	std::list<Line> result;
	for(Line cur_line : m_lines) {
		if((*isCrosses)(cur_line, m_area)) {
			result.push_back(cur_line);
		}
	}
	return result;
}