#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void calculateCirclePoints(float radius, float xc,float yc);
void plotPoints(float x, float y, float xc, float yc);

int main(){
    float radius,xc,yc;
    cout<<"Enter the radius of circle: ";
    cin>>radius;
    cout<<"Enter the center xc and yc of circle: ";
    cin>>xc>>yc;
        calculateCirclePoints(radius,xc,yc);

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
        calculateCirclePoints(radius,xc,yc);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void calculateCirclePoints(float radius, float xc,float yc){
    float x=0;
    float y=radius;
    plotPoints(x,y,xc,yc);
    float p0=1-radius;
    float pk=p0;
    while(x<y){
        if (pk<0){
            x=x+1;
            y=y;
            pk=pk+2*x+1;
        }
        else{
            x=x+1;
            y=y-1;
            pk=pk+2*x+1-2*y;
        }
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