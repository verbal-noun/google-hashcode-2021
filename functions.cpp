#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <math.h>

#include "functions.h"

#define PRINT_PROGRESS(x, y) cout << fixed << setprecision(2) << 100.0f * (x) / (y) << "%\r"
#define CLEAR_LINE cout << "\b\b\b\b\b\b\b\r"
#define LOG(x) cout << (x) << endl

using namespace std;

unordered_map<UINT, UINT> street_pop;

int calculateScore(vector<Schedule> ss)
{
	int score = 0;

	return score;
}

/*
bool sizeComp(UINT p1, UINT p2){
    return Pizza::pizzaMap[p1].numIng > Pizza::pizzaMap[p2].numIng;
}*/

vector<Schedule> generateSchedule(string &inputPath){
    UINT D, I, S, V, F;

    ifstream inputFile(inputPath);

    if (!inputFile.is_open())
	{
		LOG("!!! FILE NOT FOUND !!!");
		throw uncaught_exception;
	}

	string line;
	getline(inputFile, line);

    istringstream str(line);
    str >> D >> I >> S >> V >> F;

    for (UINT i=0; i < I; i++){
        Intersection inter;
        Map::iMap[i] = inter;
    }

    for (UINT i=0; i < S; i++){
        getline(inputFile, line);
        UINT s = processStreet(line, i);
    }

    for (UINT i=0; i < V; i++){
        getline(inputFile, line);
        UINT v = processCar(line, i);
    }

    vector<Schedule> schedules = generateSchedules(I, V);

    return schedules;
}

UINT processStreet(string line, UINT i){
    Street s;
    s.id = i;
    istringstream str(line);
    str >> s.start >> s.end >> s.name >> s.length;

    Map::streetMap[i] = s;
    Map::streetLookup[s.name] = i;
    Map::streets.emplace_back(i);

    Map::iMap[s.start].outgoing.emplace_back(i);
    Map::iMap[s.end].incoming.emplace_back(i);

    return i;
}

UINT processCar(string line, UINT id){
    Car c;
    c.id = id;
    istringstream str(line);

    str >> c.num_streets;

    for (UINT i=0; i < c.num_streets; i++){
        string name;
        str >> name;
        UINT id = Map::streetLookup[name];
        c.path.emplace_back(id);
        street_pop[id]++;
    }

    Map::cMap[id] = c;

    return id;
}

vector<Schedule> generateSchedules(UINT inters, UINT cars){
    vector<Schedule> ss;
    for(UINT i = 0; i < inters; i++){
        Schedule s;
        s.intersection = i;
        double total = 0;
        for (UINT s_id: Map::iMap[i].incoming){
            if (street_pop[s_id] > 0){
                s.streets.emplace_back(Map::streetMap[s_id].name);
                total += street_pop[s_id];
            }
        }

        for (string str: s.streets){
            UINT s_id = Map::streetLookup[str];
            UINT score = ceil(5*street_pop[s_id]/total);
            s.timing.emplace_back(score);
        }

        if (s.timing.size() > 0){
            ss.emplace_back(s);
        }
    }

    return ss;
}

void generateOutput(string outputPath, vector<Schedule> ss){
    ofstream outputFile(outputPath);
    
    outputFile << ss.size();

    for(Schedule s: ss){
        if (s.timing.size() > 0){
            outputFile << endl << s.intersection;
            
            UINT size = s.timing.size();
            outputFile << endl << size;

            for(UINT i = 0; i < size; i++){
                outputFile << endl << s.streets[i] << " " << s.timing[i];
            }
        }
    }
    
	outputFile.close();
}