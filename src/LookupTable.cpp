#include "LookupTable.h"
#include <iostream>
#include "ofGraphics.h"

#define MAX_CONFIGURATIONS 16

void LookupTable::setup(float point_offset){
    offset = point_offset;

    configurations.resize(MAX_CONFIGURATIONS);
    
    //here we will have some predefined configurations
    //config 0 has no lines
    //config 1-4 has one line
    configurations[1].push_back(std::make_pair(ofVec2f(0.0f, offset/2), ofVec2f(offset/2, offset)));
    configurations[2].push_back(std::make_pair(ofVec2f(offset, offset/2), ofVec2f(offset/2, offset)));
    configurations[3].push_back(std::make_pair(ofVec2f(0.0f, offset/2), ofVec2f(offset, offset/2)));
    configurations[4].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(offset, offset/2)));
    //config 5 has two lines
    configurations[5].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(0.0f, offset/2)));
    configurations[5].push_back(std::make_pair(ofVec2f(offset, offset/2), ofVec2f(offset/2, offset)));
    //config 6-9 has one line
    configurations[6].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(offset/2, offset)));
    configurations[7].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(0.0f, offset/2)));
    configurations[8].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(0.0f, offset/2)));
    configurations[9].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(offset/2, offset)));
    //config 10 has two lines
    configurations[10].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(offset, offset/2)));
    configurations[10].push_back(std::make_pair(ofVec2f(0.0f, offset/2), ofVec2f(offset/2, offset)));
    //config 11-14 has one line
    configurations[11].push_back(std::make_pair(ofVec2f(offset/2, 0.0f), ofVec2f(offset, offset/2)));
    configurations[12].push_back(std::make_pair(ofVec2f(0.0f, offset/2), ofVec2f(offset, offset/2)));
    configurations[13].push_back(std::make_pair(ofVec2f(offset, offset/2), ofVec2f(offset/2, offset)));
    configurations[14].push_back(std::make_pair(ofVec2f(0.0f, offset/2), ofVec2f(offset/2, offset)));
    //config 15 has no lines

}

void LookupTable::draw(){
    float off = 0.0f;
    for(int i = 0; i < MAX_CONFIGURATIONS; i++){
        auto val = configurations[i];
        for(auto line : val){
            ofSetColor(ofColor::green);
            ofDrawLine(ofVec2f(off + line.first.x, line.first.y), ofVec2f(off + line.second.x, line.second.y));
        }
        off += offset;

    }
}
