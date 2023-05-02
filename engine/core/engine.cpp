#include "engine.h"
namespace Core
{
	using namespace Render;
	GameEngine::GameEngine()
	{
		Log::Init();
		ENGINE_CORE_INFO("StartEngine");
		renderSystem = std::make_shared<Render::RenderSystem>();
		
	}

	void GameEngine::OnTick()
	{
		renderSystem->UpdateOneFrame();
	}

	void GameEngine::Run()
	{
		while (true)
		{
			OnTick();
		}
	}

	GameEngine::~GameEngine()
	{

	}
	
}

