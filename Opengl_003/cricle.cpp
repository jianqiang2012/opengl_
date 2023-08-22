#include <GLFW/glfw3.h>
#include <cmath>

void renderScene(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // 设置颜色为红色

    const float radius = 0.5f; // 圆形半径
    const int numSegments = 1000; // 分段数，用于细化圆形的轮廓

    glBegin(GL_TRIANGLE_FAN); // 开始绘制三角形扇形
    glVertex2f(0.0f, 0.0f); // 圆心顶点

    for (int i = 0; i <= numSegments; ++i) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd(); // 结束绘制

    glfwSwapBuffers(window); // 刷新双缓冲区
}

int main() {
    glfwInit(); // 初始化GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Circle", nullptr, nullptr);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window); // 创建OpenGL上下文

    while (!glfwWindowShouldClose(window)) {
        renderScene(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

