#include <algorithm>
#include <unordered_map>
#include <sstream>

#include "classes.h"

using namespace std;

unordered_map<UINT, Street> Map::streetMap;
unordered_map<UINT, Intersection> Map::iMap;
unordered_map<UINT, Car> Map::cMap;
unordered_map<string, UINT> Map::streetLookup;
vector<UINT> Map::streets;
vector<UINT> Map::intersections;