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
			renderSettings.width = 800;
			renderSettings.height = 600;
			renderSettings.name = "GameEngine";
			camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
			deltaTime = 0.0f;
			lastFrame = 0.0f;
			InitRenderSystem(renderSettings);

		}

		void RenderSystem::InitRenderSystem(RenderSettings renderSettings)
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
			window = glfwCreateWindow(renderSettings.width, renderSettings.height, renderSettings.name, NULL, NULL);
			//windowPtr = std::shared_ptr<GLFWwindow>(window);
			if (window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return;
			}
			glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			glfwSetCursorPosCallback(window, mouse_callback);
			glfwSetScrollCallback(window, scroll_callback);

			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			// glad: load all OpenGL function pointers
			// ---------------------------------------
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return;
			}
			glEnable(GL_DEPTH_TEST);
			ourShader = Shader("E:\\GameEngine\\engine\\asset\\shader\\VertexShader.glsl", "E:\\GameEngine\\engine\\asset\\shader\\FragmentShader.glsl");

			
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);

			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			// position attribute
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			// texture coord attribute
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			// load and create a texture 
			// -------------------------

			// texture 1
			// ---------
			glGenTextures(1, &texture1);
			glBindTexture(GL_TEXTURE_2D, texture1);
			// set the texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			// set texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			// load image, create texture and generate mipmaps
			int width, height, nrChannels;
			stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
			unsigned char* data = stbi_load("E:/GameEngine/engine/asset/texture/container.jpg", &width, &height, &nrChannels, 0);
			if (data)
			{	
				ENGINE_CORE_LOG("Image Load Success");
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
			}
			stbi_image_free(data);
			// texture 2
   // ---------
			glGenTextures(1, &texture2);
			glBindTexture(GL_TEXTURE_2D, texture2);
			// set the texture wrapping parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			// set texture filtering parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_set_flip_vertically_on_load(true);
			// load image, create texture and generate mipmaps
			data = stbi_load("E:/GameEngine/engine/asset/texture/awesomeface.png", &width, &height, &nrChannels, 0);
			if (data)
			{
				ENGINE_CORE_LOG("Image Load Success");
				// note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				std::cout << "Failed to load texture" << std::endl;
			}
			stbi_image_free(data);

			// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
			// -------------------------------------------------------------------------------------------
			ourShader.Use();
			ourShader.SetInt("texture1", 0);
			ourShader.SetInt("texture2", 1);


		}
		void RenderSystem::UpdateOneFrame()
		{
			if (!glfwWindowShouldClose(window))
			{
				// per-frame time logic
				// --------------------
				float currentFrame = static_cast<float>(glfwGetTime());
				deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;

				// input
				// -----
				processInput(window);

				// render
				// ------
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				// bind textures on corresponding texture units
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, texture1);
				glActiveTexture(GL_TEXTURE1);
				glBindTexture(GL_TEXTURE_2D, texture2);

				// activate shader
				ourShader.Use();

				// camera/view transformation
				glm::mat4 view = camera.GetViewMatrix();
				ourShader.SetMat4("view", view);

				// pass projection matrix to shader (note that in this case it could change every frame)
				glm::mat4 projection = glm::perspective(glm::radians(camera.m_zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
				ourShader.SetMat4("projection", projection);

				

				// render boxes
				glBindVertexArray(VAO);
				for (unsigned int i = 0; i < 10; i++)
				{
					// calculate the model matrix for each object and pass it to shader before drawing
					glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
					model = glm::translate(model, cubePositions[i]);
					float angle = 20.0f * i;
					model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
					ourShader.SetMat4("model", model);

					glDrawArrays(GL_TRIANGLES, 0, 36);
				}

				// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
				// -------------------------------------------------------------------------------
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
			else
			{
				ENGINE_CORE_ERROR("render window is closed!");
			}
			

		}

		void RenderSystem::framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
		void RenderSystem::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
		{
			float xpos = static_cast<float>(xposIn);
			float ypos = static_cast<float>(yposIn);

			if (renderSettings.firstMouse)
			{
				renderSettings.lastX = xpos;
				renderSettings.lastY = ypos;
				renderSettings.firstMouse = false;
			}

			float xoffset = xpos - renderSettings.lastX;
			float yoffset = renderSettings.lastY - ypos; // reversed since y-coordinates go from bottom to top

			renderSettings.lastX = xpos;
			renderSettings.lastY = ypos;

			camera.CameraMovement(xoffset, yoffset);
		}
		void RenderSystem::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
			camera.CameraScroll(static_cast<float>(yoffset));
		}
		void RenderSystem::processInput(GLFWwindow* window)
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
				camera.ProcessKeyboard(CameraMovementEnum::FORWARD, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
				camera.ProcessKeyboard(CameraMovementEnum::BACKWARD, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
				camera.ProcessKeyboard(CameraMovementEnum::LEFT, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				camera.ProcessKeyboard(CameraMovementEnum::RIGHT, deltaTime);
		}
	}
}
