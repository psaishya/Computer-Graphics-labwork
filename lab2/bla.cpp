#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void calculatePointsWithBLA(float x1,float y1,float x2, float y2);
void plotPoints(float x,float y);

int main(){
    float x1,y1,x2,y2;
    cout<<"Enter (x1,y1): "<<endl;
    cin>>x1>>y1;
    cout<<"Enter (x2,y2): "<<endl;
    cin>>x2>>y2;
    calculatePointsWithBLA(x1,y1,x2,y2);
    if (!glfwInit())
    {   cout << "Failed to initialize GLFW" << endl;
        return -1;  }
    glfwSetErrorCallback(errorCallback);
    GLFWwindow* window = glfwCreateWindow(800, 800, "Bresenham Line Drawing algorithm", NULL, NULL);
    if (!window)
    {   cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;   } 
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
        calculatePointsWithBLA(x1,y1,x2,y2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void calculatePointsWithBLA(float x1,float y1,float x2, float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float m=abs(dy)/abs(dx);
    cout<<m;
    float x,y,p0,pk;
    x=x1;
    y=y1;
    plotPoints(x,y);
    if (m<1){
        p0=2*dy-dx;
        pk=p0;
        for(int i=1;i<=abs(dx);i++){
            if(pk<0){
                if(x2>x1){x++;}
                else{x--;}
                y=y;
                pk=pk+2*dy;     }
            else{
                if(x2>x1){x++;}
                else{x--;}
                if(y2>y1){y++;}
                else{y--;}
                pk=pk+2*dy-2*dx;   }
            plotPoints(x,y);     } 
    }
    else {
        p0=2*dx-dy;
        pk=p0;
        for(int i=1;i<=abs(dy);i++){
            if(pk<0) {
                if(y2>y1){y++;}
                else{y--;}
                x=x;
                pk=pk+2*dx; }
            else{
                if(y2>y1){y++;}
                else{y--;}
                if(x2>x1){x++;}
                else{x--;}
                pk=pk+2*dx-2*dy;  }
            plotPoints(x,y);    } 
    }
}

void plotPoints(float x,float y){  
    cout<<"x:"<<x<<" y:"<<y<<endl; 
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