#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // 初始化GLFW库
    if (!glfwInit()) {
        std::cerr << "无法初始化GLFW" << std::endl;
        return -1;
    }

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "Opengl_创建一个窗体", NULL, NULL);
    if (!window) {
        std::cerr << "无法创建窗口" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 将当前窗口设置为上下文
    glfwMakeContextCurrent(window);

    // 记录开始时间
   // double startTime = glfwGetTime();

    // 渲染循环
    while (!glfwWindowShouldClose(window)) {
        // 检查是否达到指定时间
//        if (glfwGetTime() - startTime >= 3.0) {
  //          break;
    //    }

        // 渲染图形

        // 交换前后缓冲区
        glfwSwapBuffers(window);

        // 处理事件
        glfwPollEvents();
    }

    // 关闭窗口并终止GLFW库
    glfwTerminate();
    return 0;
}

