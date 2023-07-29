#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main()
{
    // 初始化GLFW
    glfwInit();

    // 创建一个窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "窗口旋转", nullptr, nullptr);
    if (window == nullptr)
    {
        // 窗口创建失败
        glfwTerminate();
        return -1;
    }

    // 将当前线程的上下文设置为新创建的窗口的上下文
    glfwMakeContextCurrent(window);

    // 主循环
    while (!glfwWindowShouldClose(window))
    {
        // 清除颜色缓冲区
        glClear(GL_COLOR_BUFFER_BIT);

        // 设置视口大小
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // 设置投影矩阵
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        // 设置模型视图矩阵
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        // 设置旋转角度
        float angle = (float)glfwGetTime() * 50.0f;
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        // 绘制三角形
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.6f, -0.4f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.6f, -0.4f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.6f);
        glEnd();

        // 交换前后缓冲区
        glfwSwapBuffers(window);

        // 处理事件
        glfwPollEvents();
    }

    // 终止GLFW
    glfwTerminate();

    return 0;
}

