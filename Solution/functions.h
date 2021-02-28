#pragma once

#include <vector>
#include <string>

#include "classes.h"

using namespace std;

int calculateScore(vector<Schedule> ss);
vector<Schedule> generateSchedule(string &inputPath);
void generateOutput(string outputPath, vector<Schedule> ss);
UINT processStreet(string line, UINT i);
UINT processCar(string line, UINT id);
vector<Schedule> generateSchedules(UINT inters, UINT cars);