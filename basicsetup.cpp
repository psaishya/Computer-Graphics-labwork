#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

void errorCallback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main(){
    if (!glfwInit())
    {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwSetErrorCallback(errorCallback);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window)
    {
        cout << "Failed to create a window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

///////////////////////for mapping to 100x100
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); 
    // glMatrixMode(GL_MODELVIEW);


    while (!glfwWindowShouldClose(window))
    {

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


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