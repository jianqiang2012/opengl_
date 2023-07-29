#include <GLFW/glfw3.h>
#include <iostream>

void render() {
    // 渲染图形

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.6f, -0.4f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.6f, -0.4f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.6f);
    glEnd();
}

int main() {
    // 初始化GLFW库
    if (!glfwInit()) {
        std::cerr << "无法初始化GLFW" << std::endl;
        return -1;
    }

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "窗口", NULL, NULL);
    if (!window) {
        std::cerr << "无法创建窗口" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 将当前窗口设置为上下文
    glfwMakeContextCurrent(window);

    // 渲染循环
    while (!glfwWindowShouldClose(window)) {
        // 清除颜色缓冲区
        glClear(GL_COLOR_BUFFER_BIT);

        // 保存当前矩阵状态
        glPushMatrix();

        // 设置旋转角度
        static float angle = 0.0f;
        angle += 1.0f;

        // 进行旋转变换
        glTranslatef(0.0f, 0.0f, 0.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);

        // 渲染图形
        render();

        // 恢复矩阵状态
        glPopMatrix();

        // 交换前后缓冲区
        glfwSwapBuffers(window);

        // 处理事件
        glfwPollEvents();
    }

    // 关闭窗口并终止GLFW库
    glfwTerminate();
    return 0;
}

