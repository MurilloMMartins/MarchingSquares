#pragma once

#include <vector>
#include "ofMesh.h"

typedef struct Scalar2DPoint_t {
    int x, y;
    float value;
} Scalar2DPoint;


class Scalar2DGrid {
private:
    int columns, rows;
    std::vector<std::vector<Scalar2DPoint>> points;
    ofMesh pointMesh;
    ofMesh wireframe;
public:
    //Scalar2DGrid();
    //~Scalar2DGrid();

    void setup(int width, int height, float point_offset);
    void draw();
    float getPointValue(int column, int row);
    void setPointValue(int column, int row, float new_value);
};
