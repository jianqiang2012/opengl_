#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawPoint()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 设置清屏颜色为黑色
    glClear(GL_COLOR_BUFFER_BIT); // 清屏

    glEnableClientState(GL_VERTEX_ARRAY); // 启用顶点数组

    GLfloat point[] = { 0.0f, 0.0f }; // 点的坐标为(0, 0)

    glVertexPointer(2, GL_FLOAT, 0, point); // 设置顶点指针

    glColor3f(1.0f, 1.0f, 1.0f); // 设置点的颜色为白色
    glPointSize(5.0f); // 设置点的大小为5个像素

    glDrawArrays(GL_POINTS, 0, 1); // 绘制点

    glDisableClientState(GL_VERTEX_ARRAY); // 禁用顶点数组

    glFlush(); // 刷新绘图命令
}

int main()
{
    // 初始化GLFW
    if (!glfwInit())
        return -1;

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "white-Point", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 初始化GLEW
    if (glewInit() != GLEW_OK)
        return -1;

    // 主循环
    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // 绘制
        drawPoint();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 清理资源
    glfwTerminate();
    return 0;
}
