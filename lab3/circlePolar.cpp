#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>
#define PI 3.1415f 


using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void calculateCirclePolarPoints(float radius, float xc,float yc);
void plotPoints(float x, float y, float xc, float yc);

int main(){
    float radius,xc,yc;
    cout<<"Enter the radius of circle: ";
    cin>>radius;
    cout<<"Enter the center xc and yc of circle: ";
    cin>>xc>>yc;
        calculateCirclePolarPoints(radius,xc,yc);

    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }
    glfwSetErrorCallback(errorCallback);
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);
    if (!window)
    {
        cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

/////////////////////for mapping to 100x100
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        calculateCirclePolarPoints(radius,xc,yc);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void calculateCirclePolarPoints(float radius, float xc,float yc){
    float x=radius;
    float y=0;
    float theta=0;
    float thetaFinal=PI/4.0;
    float inc=(1/radius);
    plotPoints(x,y,xc,yc);
    while(theta<thetaFinal){
        x=radius* cosf(theta);
        y=radius* sinf(theta);
        theta=(theta+inc);
        plotPoints(x,y,xc,yc);
    }
    

}

void plotPoints(float x, float y, float xc, float yc){
    // cout<<"x:"<<x<<" y:"<<y<<endl; 
    glPushMatrix();
    glPointSize(7.0f);
    glColor3f (0.4f, 0.5f, 0.55f); 
    glBegin(GL_POINTS);
    glVertex2f(x+xc,y+yc);
    glVertex2f(-x+xc,y+yc);
    glVertex2f(-x+xc,-y+yc);
    glVertex2f(x+xc,-y+yc);
    glVertex2f(y+xc,x+yc);
    glVertex2f(-y+xc,x+yc);
    glVertex2f(-y+xc,-x+yc);
    glVertex2f(y+xc,-x+yc);
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