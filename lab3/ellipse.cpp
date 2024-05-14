#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void calculateEllipsePoints(float rx,float ry, float xc, float yc);
void plotPoints(float x, float y, float xc, float yc);

int main(){
    float xc,yc,rx,ry;
    cout<<"Enter the center x,y of ellipse: ";
    cin>>xc>>yc;
    cout<<"Enter the major axis radius rx and minor axis radius ry of circle: ";
    cin>>rx>>ry;
        calculateEllipsePoints(rx,ry,xc,yc);

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
        calculateEllipsePoints(rx,ry,xc,yc);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void calculateEllipsePoints(float rx,float ry, float xc, float yc){
    float x=0;
    float y=ry;
    plotPoints(x,y,xc,yc);
////for region 1
    float p10=(ry*ry)-(rx*rx*ry)+(rx*rx)/4;
    float p1k=p10;
    while((2*ry*ry*x)<(2*rx*rx*y)){
        if (p1k<0){
            x=x+1;
            y=y;
            p1k=p1k+(2*ry*ry*x)+(ry*ry);
        }
        else{
            x=x+1;
            y=y-1;
            p1k=p1k+(2*ry*ry*x)-(2*rx*rx*y)+(ry*ry);
        }
        plotPoints(x,y,xc,yc);
    }
    ////for region 2
    float p20=((ry*ry)*(x+0.5)*(x+0.5))+((rx*rx)*(y-1)*(y-1))-(rx*rx*ry*ry);
    float p2k=p20;
    while(y!=0){
        if (p2k<=0){
            x=x+1;
            y=y-1;
            p2k=p2k+(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
        }
        else{
            x=x;
            y=y-1;
            p2k=p2k-(2*ry*ry*x)+(rx*rx);
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