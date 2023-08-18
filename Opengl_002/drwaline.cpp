#include <GLFW/glfw3.h>

void drawLine() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // 设置清屏颜色为黑色
    glClear(GL_COLOR_BUFFER_BIT);            // 清除颜色缓冲区

    glColor3f(1.0f, 0.0f, 1.0f);             // 设置直线颜色为白色

    glBegin(GL_LINES);                        // 开始绘制直线
    glVertex2f(-0.5f, 0.0f);                   // 直线起点坐标
    glVertex2f(0.5f, 0.0f);                    // 直线终点坐标
    glEnd();                                 // 结束绘制直线
}

int main() {
    glfwInit();                               // 初始化 GLFW

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Line", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        drawLine();                             // 调用绘制函数

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

