#pragma once

#include <vector>
#include "ofVec2f.h"

class LookupTable {
private:
    std::vector<std::vector<std::pair<ofVec2f, ofVec2f>>> configurations;
    float offset;
public:
    // LookupTable(int point_offset);
    // ~LookupTable();

    void setup(float point_offset);
    
    //temporary function
    void draw();
};