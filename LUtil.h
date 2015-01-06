/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 012

#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <stdio.h>

//Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

bool initGL();
/*
Pre Condition:
 -A valid OpenGL context
Post Condition:
 -Initializes viewport, matrices, and clear color
 -Enables blending
 -Disables depth testing
 -Initializes GLEW
 -Initializes DevIL and DevIL utilities
 -Reports to console if there was an OpenGL error
 -Reports to console if there was a GLEW error
 -Reports to console if there was a DevIL error
 -Returns false if there was an error in initialization
Side Effects:
 -Sets viewport to the fill rendering area
 -Projection matrix is set to an orthographic matrix
 -Modelview matrix is set to identity matrix
 -Matrix mode is set to modelview
 -Clear color is set to black
 -Texturing is enabled
 -Sets DevIL clear color to transparent white
*/

bool loadVertices();
/*
Pre Condition:
 -A valid OpenGL context
Post Condition:
 -Loads vertices to draw the ellipse
Side Effects:
 -None
*/

void createVBO();
/*
Pre Condition:
 -Vertices of ellipse loaded in the vertices array
Post Condition:
 -VBO initialized and bound with vertices data
Side Effects:
 -None
*/

void createIBO();
/*
Pre Condition:
 -Index of vertices loaded in the index array
Post Condition:
 -IBO initialized and bound with index data
Side Effects:
 -None
*/

void update();
/*
Pre Condition:
 -None
Post Condition:
 -Does per frame logic
Side Effects:
 -None
*/

void render();
/*
Pre Condition:
 -A valid OpenGL context
 -Active modelview matrix
Post Condition:
 -Renders the scene
Side Effects:
 -Clears the color buffer
 -Swaps the front/back buffer
*/

#endif
