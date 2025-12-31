
#include "raylib.h"

#ifndef ROAD_H
#define ROAD_H

#include "raylib.h"

class Road {

private:
    float tile;         
    int rows;           
    int cols;           
    float roadWidth;    

    float X;            
    float Y;            
    int screenHeight;
    int screenWidth;

public:
   
    Road(int r, int c, int H, int W, float rw = 60.0f)
        : rows(r), cols(c), roadWidth(rw), screenHeight(H), screenWidth(W)
    {
        
        tile = 50.0f; 

        float totalGridWidth = (cols * tile) + (cols * roadWidth);
        float totalGridHeight = (rows * tile) + (rows * roadWidth);

        X = (screenWidth - totalGridWidth) / 2.0f;
        Y = (screenHeight - totalGridHeight) / 2.0f;

        if (X < 0) X = 0;
        if (Y < 0) Y = 0;
    }

    void createRoads() {

        
        float cellSpacing = tile + roadWidth;

        
        for (int r = 0; r < rows; r++)
        {
            float yStart = Y + (r * cellSpacing);
                     
            if (yStart > screenHeight) break;

            DrawRectangle(

                0,                                 
                (int)yStart,                            
                screenWidth,              
                roadWidth,
                DARKGRAY
            );
        }

        for (int c = 0; c < cols; c++)
        {
            float xStart = X + (c * cellSpacing);

            if (xStart > screenWidth) break;

            DrawRectangle(
                (int)xStart,                           
                0,                                 
                roadWidth,
               screenHeight,              
                DARKGRAY
            );
        }
    }
    
};

#endif