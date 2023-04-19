#pragma once

#include <vector>
#include "ofMesh.h"

typedef struct Scalar2DPoint_t {
    int x, y;
    float value;
} Scalar2DPoint;


class Scalar2DGrid {
private:
    int width, height;
    std::vector<std::vector<Scalar2DPoint>> points;
    ofMesh pointMesh;
    ofMesh wireframe;
public:
    //Scalar2DGrid();
    //~Scalar2DGrid();

    void setup(int width, int height, float pointOffset);
    void draw();
};
