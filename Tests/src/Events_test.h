#include "gtest/gtest.h"
#include "EventSystem/Event.h"

DECL_EVENT_P0(TestEvent)
TEST(EventSystem, BasicCallbackNoParams) 
{
	struct TestListener
	{
		void onEvent() { triggered = true; }
		bool triggered = false;
	} listener;

    TestEvent myEvent;
    myEvent.subscribe(&listener, &TestListener::onEvent);

    myEvent();

    ASSERT_TRUE(listener.triggered);
}

DECL_EVENT_P2(TestEvent2, int, float);
TEST(EventSystem, BasicCallbackWithParams)
{
	struct TestListenerWithParams
	{
		void  onEvent(int a, float b) { this->sum = a + b; }
		float sum = 0;
	} listener;

	TestEvent2 myEvent;
	myEvent.subscribe(&listener, &TestListenerWithParams::onEvent);

	myEvent(5, 3.2f); // ֲûחמג סמבûעטÿ

	ASSERT_FLOAT_EQ(listener.sum, 8.2f);
}

DECL_EVENT_P0(TestEvent3);
TEST(EventSystem, CallbackOrder)
{
	TestEvent3 myEvent;
	int order = 0;
	int	firstOrder = 0;
	int secondOrder = 0;

	myEvent.subscribe([&]() { firstOrder = ++order; });
	myEvent.subscribe([&]() { secondOrder = ++order; });

	myEvent(); // ֲûחמג סמבûעטÿ

	ASSERT_EQ(firstOrder, 1);
	ASSERT_EQ(secondOrder, 2);
}

DECL_EVENT_P1(TestEvent4, int)
TEST(EventSystem, LambdaCallback)
{
	TestEvent4 myEvent;
	int	result = 0;

	myEvent.subscribe([&](int value) { result = value; });

	myEvent(42); // ֲûחמג סמבûעטÿ

	ASSERT_EQ(result, 42);
}