#include<iostream>
namespace Core
{
	namespace Render
	{
		class RenderSystem
		{
		public:
			RenderSystem();
			~RenderSystem();

			void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
			void ProcessInput(GLFWwindow* window);

			void InitRenderSystem();
			void Update();

		public:
			const unsigned int RENDER_WIDTH = 800;
			const unsigned int RENDER_HEIGHT = 600;

		};
	}
}
