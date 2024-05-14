#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
using namespace std;
void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void drawHistogram(float frequencies[]);
void calculatePointsWithBLA(float x1,float y1,float x2, float y2);
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
    GLFWwindow* window = glfwCreateWindow(800, 600, "Histogram using BLA", NULL, NULL);
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
    r=0.265f;
    g=0.373f;
    b=0.995f;
    for (int i=0;i<10;i++){
        glColor3f (r,g,b); 
        r+=0.08;
        g+=0.05;
        b-=0.14;
        calculatePointsWithBLA(x,15,x,15+frequencies[i]) ;
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
    calculatePointsWithBLA(10,10,10,90) ;
    calculatePointsWithBLA(10,10,90,10) ;
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