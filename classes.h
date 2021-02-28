#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

#define UINT unsigned int
#define ULONG unsigned long
#define V_ULONG vector<ULONG>
#define V_UINT vector<UINT>

using namespace std;

class Intersection{
    public:
        vector<UINT> incoming;
        vector<UINT> outgoing;
};

class Street{
    public:
        UINT start;
        UINT end;
        UINT length;
        UINT id;
        string name;
};

class Car{
    public:
        UINT id;
        UINT num_streets;
        vector<UINT> path;
};

class Map{
    public:
        static vector<UINT> intersections;
        static vector<UINT> streets;
        static unordered_map<UINT, Street> streetMap;
        static unordered_map<UINT, Intersection> iMap;
        static unordered_map<UINT, Car> cMap;
        static unordered_map<string, UINT> streetLookup;
};

class Schedule{
    public:
        UINT intersection;
        vector<string> streets;
        vector<UINT> timing;   
};