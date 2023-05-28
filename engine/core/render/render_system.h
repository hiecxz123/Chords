#include<iostream>
#include<log/Log.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
namespace Core
{
	namespace Render
	{
		
		struct RenderSettings
		{
			int width = 800;
			int height = 600;
			char* name = "GameEngine";
		};

		class RenderSystem
		{
		public:
			RenderSystem();
			~RenderSystem();

			static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
			void ProcessInput(GLFWwindow* window);

			void InitRenderSystem();
			void InitRenderSystem(RenderSettings settings);
			void UpdateOneFrame();
			

		private:
			GLFWwindow* window;

			const char* vertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			const char* fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main()\n"
				"{\n"
				"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
				"}\n\0";
			unsigned int shaderProgram;
			unsigned int VBO, VAO, EBO;
		};
	}
}
