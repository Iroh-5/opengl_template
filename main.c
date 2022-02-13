#include "include/libs.h"
#include "include/api.h"

#define SCREEN_WIDTH 1200 
#define SCREEN_HEIGHT 900 
#define TITLE "Application"
#define REDIR_OUT_TO_FILE 0
#define DEBUG 0

static void log_init_time(void);

int main(void)
{

#if REDIR_OUT_TO_FILE == 1
    freopen("logging", "a", stderr);
#endif
    log_init_time();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE, NULL, NULL);
    if (!window)
    {
	glfwTerminate();
	logger_log(ERROR, "Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
	logger_log(ERROR, "Failed to initialize GLAD");
    }

    logger_log(INFO, "OpenGL version: %s\n", glGetString(GL_VERSION));

    while (!glfwWindowShouldClose(window))
    {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(window);
	glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}

static void log_init_time(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    putc('\n', stderr);
    logger_log(INFO, "Application started: %s", asctime(&tm));
}
