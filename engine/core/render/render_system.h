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
		};
	}
}
