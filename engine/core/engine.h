#include<render/render_system.h>
#include<log/Log.h>
namespace Core
{
	
	class GameEngine
	{
		
	public:
		GameEngine();
		~GameEngine();
		
		void OnTick();
		void Run();
	private:
		
		std::shared_ptr<Render::RenderSystem> renderSystem;
	};
}