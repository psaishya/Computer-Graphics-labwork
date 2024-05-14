#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void renderResolutionText(int screenWidth, int screenHeight, int displayscreenWidth,int displayscreenHeight );


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }
    glfwSetErrorCallback(errorCallback);

    GLFWwindow *window = glfwCreateWindow(800, 600, "Displaying Resolution", NULL, NULL);
    if (!window)
    {
        cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    int displayscreenWidth, displayscreenHeight;
    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(primaryMonitor);
    displayscreenWidth = mode->width;
    displayscreenHeight = mode->height;
    int screenWidth, screenHeight;

    while (!glfwWindowShouldClose(window))
    {

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
        cout << "Window Resolution: " << screenWidth << "x" << screenHeight << endl;
        cout << "Screen Resolution: " << displayscreenWidth << "x" << displayscreenHeight << endl;
        renderResolutionText(screenWidth, screenHeight,displayscreenWidth,displayscreenHeight);

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
void renderResolutionText(int screenWidth, int screenHeight, int displayscreenWidth,int displayscreenHeight)
{
    
    glColor3f(1.0f, 0.0f, 0.0f); 

    string windowsizeText = "Window Size: " + to_string(screenWidth) + "x" + to_string(screenHeight);
    glRasterPos2f(-0.3f,0.0f);

    for (char c : windowsizeText)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glColor3f (0.2f, 0.2f, 0.5f); 

    string resolutionText = "Display resolution : " + to_string(displayscreenWidth) + "x" + to_string(displayscreenHeight);
    glRasterPos2f(-0.3f,-0.2f);

    for (char c : resolutionText)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}