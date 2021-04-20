/**
 * @file fileToVector.cpp
 * Not sure if we need this ?
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> file_to_vector(string filename) {
    ifstream text(filename);
    vector<string> out;

    if (text.is_open()) {
        istream_iterator<string> iter(text);
        while (!text.eof()) {
            out.push_back(*iter);
            ++iter;
        }
    }
}