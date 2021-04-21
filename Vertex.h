/**
 * @file Vertex.h
 * @brief Vertex class to represent an airport
 */

#pragma once
#include <string>
#include "Edge.h"
#include <unordered_map>
using namespace std;

struct Vertex {
    int id;
    string city;
    string country;
    string code;
    double latitude;
    double longitude;
    unordered_map<int, Edge> airports; //source airports
};