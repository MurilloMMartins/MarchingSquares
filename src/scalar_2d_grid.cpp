#include "scalar_2d_grid.h"

#include <iostream>
#include <ofGraphics.h>
#include <string>

void Scalar2DGrid::setup(int width, int height, float point_offset){
    //adding +2 so we have points off screen
    this->columns = (width/point_offset) + 2;
    this->rows = (height/point_offset) + 2;

    points.resize(rows);
    pointMesh.setMode(OF_PRIMITIVE_POINTS);
    wireframe.setMode(OF_PRIMITIVE_LINES);

    float x = 0, y = 0;
    for(int i = 0; i < rows; i++){

        points[i].resize(columns);

        x = 0;
        for(int j = 0; j < columns; j++){
            //initializing point matrix
            points[i][j].x = x;
            points[i][j].y = y;
            points[i][j].value = 0.0f;

            //initializing point mesh
            ofColor color = ofColor::white;
            ofVec3f position(x, y, 0.0f);
            pointMesh.addColor(color);
            pointMesh.addVertex(position);

            //initializing wireframe mesh
            ofVec3f rightPosition(x + point_offset, y, 0);
            ofVec3f bottomPosition(x, y + point_offset, 0);
            //horizontal line
            wireframe.addColor(color);
            wireframe.addVertex(position);
            wireframe.addColor(color);
            wireframe.addVertex(rightPosition);
            //vertical line
            wireframe.addColor(color);
            wireframe.addVertex(position);
            wireframe.addColor(color);
            wireframe.addVertex(bottomPosition);

            x += point_offset;
        }
        y += point_offset;
    }

    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.5f);
}

void Scalar2DGrid::draw(){
    pointMesh.draw();
    wireframe.draw();

    for(auto row : points){
        for(auto point : row){
            int offset = 10.0f;
            std::string value = ofToString(point.value, 2);
            ofDrawBitmapString(value, point.x, point.y + offset);
        }
    }
}

float Scalar2DGrid::getPointValue(int column, int row){
    return points[row][column].value;
}

void Scalar2DGrid::setPointValue(int column, int row, float new_value){
    points[row][column].value = new_value;
}