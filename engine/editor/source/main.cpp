#include<iostream>
#include<engine.h>
using namespace std;
int main()
{
	//RenderLoop();
	
	std::shared_ptr<Core::GameEngine> engine = std::make_shared<Core::GameEngine>();
	
	engine->Run();
}