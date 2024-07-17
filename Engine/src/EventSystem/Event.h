#include <functional>
#include <vector>

#pragma once

namespace
{
	template <typename... Params>
	class Event
	{
	public:
		using EventCallback = std::function<void(const Params&...)>;

		Event()
		{
		}
		void Event::subscribe(EventCallback callback)
		{
			m_callbacks.push_back(callback);
		}

		template <class T>
		void subscribe(T* const object, void (T::*callback)(Params...))
		{
			m_callbacks.push_back([object, callback](const Params&... args) { (object->*callback)(args...); });
		}

		void operator()(const Params&... args)
		{
			for (auto& cb : m_callbacks)
			{
				cb(args...);
			}
		}

	private:
		std::vector<EventCallback> m_callbacks;
	};

}

#define DECL_EVENT_P0(n) using n = Event<>;
#define DECL_EVENT_P1(n, p1) using n = Event<p1>;
#define DECL_EVENT_P2(n, p1, p2) using n = Event<p1, p2>;
#define DECL_EVENT_P3(n, p1, p2, p3) using n = Event<p1, p2, p3>;
#define DECL_EVENT_P4(n, p1, p2, p3, p4) using n = Event<p1, p2, p3, p4>;
#define DECL_EVENT_P5(n, p1, p2, p3, p4, p5) using n = Event<p1, p2, p3, p4, p5>;
#define DECL_EVENT_P6(n, p1, p2, p3, p4, p5, p6) using n = Event<p1, p2, p3, p4, p5, p6>;
#define DECL_EVENT_P7(n, p1, p2, p3, p4, p5, p6, p7) using n = Event<p1, p2, p3, p4, p5, p6, p7>;
