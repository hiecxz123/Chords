#include <iostream>
#include <render/render_system.h>

namespace Core
{
    namespace Render
    {
        RenderSystem::RenderSystem()
        {
            InitRenderSystem();
        }
        RenderSystem::~RenderSystem()
        {

        }

        void RenderSystem::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        void RenderSystem::ProcessInput(GLFWwindow* window)
        {

        }
        void RenderSystem::InitRenderSystem()
        {
            RenderSettings settings;
            settings.width = 800;
            settings.height = 600;
            settings.name = "GameEngine";
            InitRenderSystem(settings);
            
        }
        void RenderSystem::InitRenderSystem(RenderSettings settings)
        {
            // glfw: initialize and configure
            // ------------------------------
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

            // glfw window creation
            // --------------------
            window = glfwCreateWindow(settings.width, settings.height, settings.name, NULL, NULL);
            //windowPtr = std::shared_ptr<GLFWwindow>(window);
            if (window == NULL)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return;
            }
            glfwMakeContextCurrent(window);
            glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

            // glad: load all OpenGL function pointers
            // ---------------------------------------
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return;
            }
        }
        void RenderSystem::UpdateOneFrame()
        {
            if (!glfwWindowShouldClose(window))
            {
                // input
                // -----
                ProcessInput(window);

                // render
                // ------
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);

                // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
                // -------------------------------------------------------------------------------
                glfwSwapBuffers(window);
                glfwPollEvents(); 
                return;
            }
            ENGINE_CORE_ERROR("render window is closed!");
            
        }
    }
}
