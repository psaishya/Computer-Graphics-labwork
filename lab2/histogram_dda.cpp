#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
using namespace std;
void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void drawHistogram(float frequencies[]);
void calculatePointsWithDDA(float x1,float y1,float x2, float y2);
void plotPoints(float x,float y);

int main(int argc, char** argv){
    cout<<"Enter frequencies of ten data:(0-70) ";
    float frequencies[10];
    for (int i=0;i<10;i++){
        cin>>frequencies[i];
    }
    glutInit(&argc, argv);
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }
    glfwSetErrorCallback(errorCallback);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Histogram using DDA", NULL, NULL);
    if (!window)
    {
        cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        drawHistogram(frequencies);
        glfwSwapBuffers(window);
        glfwPollEvents();    }
    glfwTerminate();
    return 0;
}


void drawHistogram(float frequencies[]){
    float x=14.0;
    glPointSize(60.0f);
    float r,g,b;
    r=0.865f;
    g=0.073f;
    b=0.725f;
    for (int i=0;i<10;i++){
        glColor3f (r,g,b); 
        r-=0.08;
        g+=0.085;
        b-=0.184;
        calculatePointsWithDDA(x,15,x,15+frequencies[i]) ;
        string Text = to_string(int(frequencies[i])) ;
        glRasterPos2f(x,5);
        for (char c : Text)
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        x=x+7.5;
    }
    glPointSize(10.0f);
    glColor3f (0.0f,0.0f,0.0f); 
    calculatePointsWithDDA(10,10,10,90) ;
    calculatePointsWithDDA(10,10,90,10) ;
}

void calculatePointsWithDDA(float x1,float y1,float x2, float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float stepSize=0.0;
    float x,y;
    x=x1;
    y=y1;
    plotPoints(x,y);
    if (abs(dx)>abs(dy)){
        stepSize=abs(dx);
    }
    else{
        stepSize=abs(dy);
    }
    float xinc=dx/stepSize;
    float yinc=dy/stepSize;
    for(int i=1;i<=stepSize;i++)
        {   x=x+xinc;
            y=y+yinc;
            plotPoints(x,y);}
}
void plotPoints(float x,float y){  
    glPushMatrix();
    glBegin(GL_POINTS);
    glVertex2f(x,y); 
    glEnd();
    glPopMatrix();
}
void errorCallback(int error, const char *description)
{
    cout << "Error: " << description << endl;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}