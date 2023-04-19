#include "scalar_2d_grid.h"

#include <iostream>
#include <ofGraphics.h>
#include <string>

void Scalar2DGrid::setup(int width, int height, float pointOffset){
    //adding +2 so we have points off screen
    int columnAmount = (width/pointOffset) + 2;
    int rowAmount = (height/pointOffset) + 2;

    points.resize(rowAmount);
    pointMesh.setMode(OF_PRIMITIVE_POINTS);
    wireframe.setMode(OF_PRIMITIVE_LINES);

    float x = 0, y = 0;
    for(int i = 0; i < rowAmount; i++){

        points[i].resize(columnAmount);

        x = 0;
        for(int j = 0; j < columnAmount; j++){
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
            ofVec3f rightPosition(x + pointOffset, y, 0);
            ofVec3f bottomPosition(x, y + pointOffset, 0);
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

            x += pointOffset;
        }
        y += pointOffset;
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
