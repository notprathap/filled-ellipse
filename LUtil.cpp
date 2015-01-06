/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 017

#include "LUtil.h"
#include "Ellipse.h"
#include <vector>
#include "LVertexPos2D.h"

//Vertex buffer
GLuint gVertexBuffer = 0;

//Index buffer
GLuint gIndexBuffer = 0;

//index for vertices
std::vector<LVertexPos2D> points;
std::vector<GLuint> indices;

bool initGL()
{
    //Initialize GLEW
    GLenum glewError = glewInit();
    if( glewError != GLEW_OK )
    {
        printf( "Error initializing GLEW! %s\n", glewGetErrorString( glewError ) );
        return false;
    }

    //Make sure OpenGL 2.1 is supported
    if( !GLEW_VERSION_2_1 )
    {
        printf( "OpenGL 2.1 not supported!\n" );
        return false;
    }

    //Set the viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

bool loadVertices()
{
    long cx = SCREEN_WIDTH * 1.f / 2.f;
    long cy = SCREEN_HEIGHT * 1.f / 2.f;

    // initialize ellipse
    Ellipse::Ellipse ellipse(100,50, cx, cy );
    
    // load first set of points
    std::vector<LVertexPos2D> firstSetOfpoints;
    firstSetOfpoints = ellipse.getFirstSetOfPoints();

    for (int i = 0; i < firstSetOfpoints.size(); i++){
        // origin of the ellipse
        LVertexPos2D point1;
        point1.x = cx;
        point1.y = cy;
        points.push_back(point1);

        // second vertex of the triangle
        LVertexPos2D point2;
        point2.x = firstSetOfpoints[i].x;
        point2.y = firstSetOfpoints[i].y + 3;
        points.push_back(point2);

        // third vertex of the triangle
        LVertexPos2D point3;
        point3.x = firstSetOfpoints[i].x;
        point3.y = firstSetOfpoints[i].y - 3;
        points.push_back(point3);
    }

    // load second set of points
    std::vector<LVertexPos2D> secondSetOfpoints;
    secondSetOfpoints = ellipse.getSecondSetOfPoints();

    for (int i = 0; i < secondSetOfpoints.size(); i++){
        // origin of the ellipse
        LVertexPos2D point1;
        point1.x = cx;
        point1.y = cy;
        points.push_back(point1);

        // second vertex of the triangle
        LVertexPos2D point2;
        point2.x = secondSetOfpoints[i].x + 3;
        point2.y = secondSetOfpoints[i].y;
        points.push_back(point2);

        // third vertex of the triangle
        LVertexPos2D point3;
        point3.x = secondSetOfpoints[i].x - 3;
        point3.y = secondSetOfpoints[i].y;
        points.push_back(point3);
    }

    // set indices
    for (int i = 0; i < points.size(); i++){
        indices.push_back(i);
    }

    // create vbo and ibo
    createVBO();
    createIBO();
    return true;
}

void createVBO()
{
    //Create VBO
    glGenBuffers( 1, &gVertexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, gVertexBuffer );
    glBufferData( GL_ARRAY_BUFFER, points.size() * sizeof(LVertexPos2D), &points[0], GL_STATIC_DRAW );
}

void createIBO()
{
    //Create IBO
    glGenBuffers( 1, &gIndexBuffer );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIndexBuffer );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW );
}

void update()
{

}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Enable vertex arrays
    glEnableClientState( GL_VERTEX_ARRAY );

        //Set vertex data
		glBindBuffer( GL_ARRAY_BUFFER, gVertexBuffer );
        glVertexPointer( 2, GL_FLOAT, 0, NULL );

        //Draw points using vertex data and index data
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIndexBuffer );

        // Draw the triangles
        glDrawElements( GL_TRIANGLES, points.size(), GL_UNSIGNED_INT, NULL );

    //Disable vertex arrays
    glDisableClientState( GL_VERTEX_ARRAY );

    //Update screen
    glutSwapBuffers();
}
