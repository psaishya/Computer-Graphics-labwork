#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;
void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void calculatePointsWithDDA(float x1,float y1,float x2, float y2);
void plotPoints(float x,float y);

int main(){
    float x1,y1,x2,y2;
    cout<<"Enter (x1,y1): "<<endl;
    cin>>x1>>y1;
    cout<<"Enter (x2,y2): "<<endl;
    cin>>x2>>y2;
    calculatePointsWithDDA(x1,y1,x2,y2);
    if (!glfwInit())
    {   cout << "Failed to initialize GLFW" << endl;
        return -1;  }
    glfwSetErrorCallback(errorCallback);
    GLFWwindow* window = glfwCreateWindow(800, 800, "Digital Differential Analyzer", NULL, NULL);
    if (!window)
    {   cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;   }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
///////for mapping the window to BL=0 AND TR=100
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window))
    {   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        calculatePointsWithDDA(x1,y1,x2,y2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
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
    // cout<<"x:"<<x<<" y:"<<y<<endl; 
    glPushMatrix();
    glPointSize(10.0f);
    glColor3f (0.2039f, 0.2353f, 0.5765f); 
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