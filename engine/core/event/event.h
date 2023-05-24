namespace Core
{
	namespace Event
	{
		enum class EventType
		{
			None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			AppTick, AppUpdate, AppRender,
			KeyPressed, KeyReleased, KeyTyped,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};
		class Event
		{
		public:
			Event();
			virtual ~Event() = default;


		};
	}
}
