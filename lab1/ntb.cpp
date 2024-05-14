#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#define PI 3.1415f 
using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void drawMountain();
void drawMountainWithSnow();
void filloutsideMountain();
void drawSquare();
void drawDome();
void ntb_text();
void drawTempleRoof();
void drawtemple();
void drawRoofbar();
void drawDomeHead();
void drawRedpoly();
void smalltriangle();
void drawSnow();
void drawFace();

// void drawAxes() {
//     glColor3f(0.0f, 0.0f, 0.0f); 
//     glLineWidth(2.0f); 
//     glBegin(GL_LINES);
//     glVertex2f(-1.0f, 0.0f); 
//     glVertex2f(1.0f, 0.0f);  
//     glEnd();
//     glBegin(GL_LINES);
//     glVertex2f(0.0f, -1.0f); 
//     glVertex2f(0.0f, 1.0f);  
//     glEnd();
//     glLineWidth(1.0f);
// }

int main(int argc, char** argv)
{   if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }
    glfwSetErrorCallback(errorCallback);
    GLFWwindow *window = glfwCreateWindow(1000, 1000, "Nepal Tourism Board", NULL, NULL);
    if (!window)
    {cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;}
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // drawAxes();
        drawMountainWithSnow();
        glLineWidth(40.0f);
        drawMountain();
        filloutsideMountain();
        drawDomeHead();
        drawRedpoly();
        drawSquare();
        drawDome();
        drawtemple();
        ntb_text();
        drawSnow();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void errorCallback(int error, const char *description)
{
    cout << "Error: " << description << endl;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void drawMountain(){
    glBegin(GL_POLYGON);
    // glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glVertex2f(0.75f, -0.1f);      
    glVertex2f(-0.25f, -1.0f); 
    glVertex2f(1.75f, -1.0f);  
    glVertex2f(0.75f, -0.1f);     
    glEnd();   
}

void drawMountainWithSnow(){
    glPushMatrix();
    glTranslatef(-0.4f, 0.25f, 0.0f);
    glLineWidth(40.0f);
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    drawMountain();

// filling color inside blue mountain
    glBegin(GL_POLYGON);
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
    glVertex2f(0.75f, -0.1f);
    glVertex2f(-0.4f, -1.0f); 
    glVertex2f(1.7f, -1.0f);  
    glEnd();
    glPopMatrix();
}

void drawSnow(){
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); 
    //anticlockwise from top
    glVertex2f(0.35f, 0.14f);    // first
    glVertex2f(0.235f, 0.05f);  // second 
    glVertex2f(0.29f, -0.01f);   // third
    glVertex2f(0.34f, 0.05f);    // fourth
    glVertex2f(0.37f, 0.03f);   // fifth
    glVertex2f(0.40f, 0.05f);//sixth
    glVertex2f(0.485f, -0.01f);   // seventh
    glVertex2f(0.49f, 0.01f); // eighth
    glEnd();
    glPopMatrix();

}
void filloutsideMountain(){
 // filling white inside outside mountain
    glPushMatrix();
    glTranslatef(0.0f, -0.07f, 0.0f);
    glLineWidth(40.0f);
    glColor3f(0.2039f, 0.2353f, 0.5765f); 

    drawMountain();
    glBegin(GL_POLYGON);
    glColor3f (1.0f, 1.0f, 1.0f); 
    glVertex2f(0.75f, -0.1f);
    glVertex2f(-0.4f, -1.0f); 
    glVertex2f(1.7f, -1.0f);  
    glEnd();
    glPopMatrix();
}


void drawSquare(){
    glLineWidth(25.0f);
// top orange
    glBegin(GL_LINE_STRIP);
    glColor3f(0.8863f, 0.0f, 0.1333f);
    glVertex2f(-0.035f, 0.15f);  
    glVertex2f(-0.465f, 0.15f);
    glEnd();

    glLineWidth(20.0f);

    glBegin(GL_LINE_STRIP);
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
    glVertex2f(-0.08f, 0.115f);
    glVertex2f(-0.08f, -0.4f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
    glVertex2f(-0.425f, 0.115f);
    glVertex2f(-0.425f, -0.165f);
    glEnd();

//inside of square
   drawFace();

}
void drawFace(){
    glColor3f(0.8863f, 0.0f, 0.1333f);
    glBegin(GL_TRIANGLE_FAN);
    float centrex=-0.25f;
    float centrey=0.075f;
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * PI * float(i) / float(100);
        float x = centrex+0.015f * cos(angle);
        float y = centrey+0.015f * sin(angle);
        glVertex2f(x, y);
        }
    glEnd();
//left eye
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glLineWidth(5.0f); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.365f, 0.0f); // Bottom-left vertex
    glVertex2f(-0.385f, 0.0175f); 
    glVertex2f(-0.365f, 0.035f); // Top-left vertex
    glVertex2f(-0.3f, 0.035f); // Top-right vertex
    glVertex2f(-0.28f, 0.0175f);
    glVertex2f(-0.3f, 0.0f); // Bottom-right vertex
    glEnd();
//left eyeball
    glBegin(GL_TRIANGLE_FAN);
    float eyeCentrex=-0.3325f;
    float eyeCentrey=0.0175f;
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * PI * float(i) / float(100);
        float x = eyeCentrex+0.015f * cos(angle);
        float y = eyeCentrey+0.015f * sin(angle);
        glVertex2f(x, y);
        }
    glEnd();
 //// eyebrows
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.385f, 0.0475f); 
    glVertex2f(-0.365f, 0.065f);
    glVertex2f(-0.305f, 0.065f);
    glVertex2f(-0.28f, 0.0475f);
    glEnd();
//right eye
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glLineWidth(5.0f); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.20f, 0.0f); // Bottom-left vertex
    glVertex2f(-0.22f, 0.017f);
    glVertex2f(-0.20f, 0.035f); // Top-left vertex
    glVertex2f(-0.14f, 0.035f);// Top-right vertex
    glVertex2f(-0.12f, 0.017f);
    glVertex2f(-0.14f, 0.0f); // Bottom-right vertex
    glEnd();
//right eyeball
    glBegin(GL_TRIANGLE_FAN);
    eyeCentrex=-0.17f;
    eyeCentrey=0.0175f;
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * PI * float(i) / float(100);
        float x = eyeCentrex+0.015f * cos(angle);
        float y = eyeCentrey+0.015f * sin(angle);
        glVertex2f(x, y);
        }
    glEnd();
//eyebrows
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.22f, 0.0475f); 
    glVertex2f(-0.2f, 0.065f);
    glVertex2f(-0.14f, 0.065f);
    glVertex2f(-0.12f, 0.0475f);
    glEnd();

////nose
    glBegin(GL_LINE_STRIP);
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    glLineWidth(1.0f);
    for (int i = 100 * 2.25; i >= 0; --i) {
        float theta = -2.0f * PI * i / float(100);
        float x = -0.25f + (0.001f + i * 0.00015f) * cos(theta);
        float y = -0.035 + (0.001f + i * 0.00015f) * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawtemple(){
    drawTempleRoof();
    glPushMatrix();
    glScalef(1.5f, 1.2f, 1.0f);
    glTranslatef(0.17f, -0.3f, 0.0f);
    drawTempleRoof();
    glPopMatrix();
    drawRoofbar();
// smaller triangle
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    smalltriangle();
}
void  smalltriangle(){
    glPushMatrix();
    glTranslatef(-0.54f, 0.11f, 0.0f);
    glLineWidth(40.0f);
    glScalef(0.03f, 0.07f, 1.0f);
    drawMountain();
    glPopMatrix();
}
void drawTempleRoof(){
    glColor3f (0.2039f, 0.2353f, 0.5765f); 

    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.165f);  // Bottom-left vertex
    glVertex2f(-0.25f, -0.165f);   // Bottom-right vertex
    glVertex2f(-0.451f, 0.015f);    // Top-right vertex
    glVertex2f(-0.6f, 0.015f);   // Top-left vertex
    glEnd();

    glLineWidth(25.0f);
// top orange
    glBegin(GL_LINE_STRIP);
    glColor3f(0.8863f, 0.0f, 0.1333f);
    glVertex2f(-0.24f, -0.20f);  
    glVertex2f(-0.82f, -0.20f);
    glEnd();
}
void drawRoofbar(){
    glLineWidth(25.0f);
// top orange
glColor3f(0.8863f, 0.0f, 0.1333f);
    glBegin(GL_QUADS);
    glVertex2f(-0.63f, -0.32f);  // Bottom-left vertex
    glVertex2f(-0.42f, -0.32f);   // Bottom-right vertex
    glVertex2f(-0.3f, -0.20f);    // Top-right vertex
    glVertex2f(-0.75f, -0.20f);   // Top-left vertex
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); 

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, -0.29f);  // Bottom-left vertex
    glVertex2f(-0.44f, -0.29f);  // Bottom-right vertex
    glVertex2f(-0.36f, -0.22f);  // Top-right vertex
    glVertex2f(-0.69f, -0.22f);  // Top-left vertex
    glEnd();


// titled triangles
    glPushMatrix();
    glTranslatef(-0.4f, 0.14f, 0.0f);
    glLineWidth(40.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); 
    glColor3f(0.8863f, 0.0f, 0.1333f);
    smalltriangle();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.08f, -0.59f, 0.0f);
    glLineWidth(40.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f); 
    glColor3f(0.8863f, 0.0f, 0.1333f);
    smalltriangle();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.55f, -0.26f, 0.0f);
    glLineWidth(40.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); 
    glColor3f(0.8863f, 0.0f, 0.1333f);
    smalltriangle();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.205f,  -0.99f, 0.0f);
    glLineWidth(40.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f); 
    glColor3f(0.8863f, 0.0f, 0.1333f);
    smalltriangle();
    glPopMatrix();

}
void drawDomeHead(){
    glPushMatrix();
    glTranslatef(-0.37f, 0.94f, 0.0f);
    glLineWidth(40.0f);
    glScalef(0.16f, 0.74f, 1.0f);
    glColor3f(0.2039f, 0.2353f, 0.5765f); 

    drawMountain();
    glPopMatrix();
    
    // for white strips
    float x_coord1=-0.035f;
    float x_coord2=-0.465f;
    float y_coord=0.24f;
    float line_width=9.7f;
    for (int i=0;i<13;i++){
        glLineWidth(line_width);
        glBegin(GL_LINE_STRIP);
        glColor3f (1.0f, 1.0f, 1.0f); 
        glVertex2f(x_coord1, y_coord);  
        glVertex2f(x_coord2, y_coord);
        glEnd();
        y_coord=y_coord+0.05f;
        line_width=line_width+0.4f;
    }

    // little triangle
    glPushMatrix();
    glTranslatef(-0.268f, 0.95f, 0.0f);
    glLineWidth(40.0f);
    glScalef(0.025f, 0.13f, 1.0f);
    glColor3f(0.2039f, 0.2353f, 0.5765f); 
    drawMountain();
    glPopMatrix();

    glColor3f (0.2039f, 0.2353f, 0.5765f); 
// little blue line

    glLineWidth(18.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.23f, 0.81);  
    glVertex2f(-0.265f, 0.81);
    glEnd();

    glLineWidth(18.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.207f, 0.82);  
    glVertex2f(-0.290f, 0.82);
    glEnd();
}

void drawRedpoly(){
    //outer white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.155f, 0.15f);  //Botton-right
    glVertex2f(-0.35f, 0.15f);  // Bottom-left 
    glVertex2f(-0.35f, 0.23f);   // Top-left 
    glVertex2f(-0.255f, 0.30f);  // Top-middle 
    glVertex2f(-0.155f, 0.23f);  // Top-right
    glEnd();

//red
    glColor3f(0.8863f, 0.0f, 0.1333f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.17f, 0.15f);  //Botton-right
    glVertex2f(-0.34f, 0.15f);  // Bottom-left 
    glVertex2f(-0.34f, 0.2f);   // Top-left 
    glVertex2f(-0.255f, 0.28f);  // Top-middle 
    glVertex2f(-0.17f, 0.2f);  // Top-right
    glEnd();

//inner white
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.19f, 0.15f);  //Botton-right
    glVertex2f(-0.32f, 0.15f);  // Bottom-left 
    glVertex2f(-0.255f, 0.24f);  // Top-middle 
    glEnd();
}
void drawDome(){
    float cx=-0.2f;
    float cy=-1.0f;
    float r=0.8f;
    int num_segments=180;

// border
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
    glLineWidth(40.0f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <=  num_segments / 2; i++) {
        float theta = PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_POLYGON);
    for (int i = 0; i <= num_segments / 2; i++) {
        float theta =2* PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void ntb_text(){
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
// for N
    glLineWidth(30.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.935f, -0.66f); 
    glVertex2f(-0.935f, -0.88f); 
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.91f, -0.686f); // Top-left
    glVertex2f(-0.73f, -0.853f); // Bottom-right
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7f, -0.66f); 
    glVertex2f(-0.7f, -0.88f); 
    glEnd();

// for T
    glBegin(GL_LINES);
    glVertex2f(-0.2f, -0.69f); // Top
    glVertex2f(-0.5f, -0.69f); // Top
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.35f, -0.66f); 
    glVertex2f(-0.35f, -0.88f); 
    glEnd();

// for B
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.66f); 
    glVertex2f(0.0f, -0.88f); 
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.69f); // Top
    glVertex2f(0.2f, -0.69f); // Top
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.77f); // Top
    glVertex2f(0.2f, -0.77f); // Top
    glEnd();
   
    glBegin(GL_LINES); 
    glVertex2f(0.0f, -0.85f); // Top
    glVertex2f(0.2f, -0.85f); // Top
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.2f, -0.66f); 
    glVertex2f(0.2f, -0.88f); 
    glEnd();
}