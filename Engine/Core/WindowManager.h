#pragma once
#include <string>

#include "xm/xm.h"

#include "Defines.h"

struct GLFWwindow;
struct GLFWmonitor;

class WindowManager
{
	friend class Engine;

	bool init(const std::string& title, uint width, uint height, bool fullscreen);
	bool initAsChild(const std::string& title, void* parent_handle = nullptr);

	void destroy();

public:
	WindowManager() = default;
	~WindowManager() = default;
	WindowManager(const WindowManager&) = delete;
	WindowManager& operator=(const WindowManager&) = delete;
	WindowManager(WindowManager&&) noexcept = delete;
	WindowManager& operator=(WindowManager&&) noexcept = delete;

	void pollEvents();

	void setWindowPos(size_t x, size_t y);

	void swapBuffers();

	void enableCursor();
	void disableCursor();

	void setVsync(bool vsync);

	void close();

	bool isShouldClose() const;

	xm::ivec2 getWindowSize() const;
	xm::ivec2 getFramebufferSize() const;
	xm::dvec2 getCursorPos();

private:
	GLFWwindow* getWindow();

	GLFWwindow*	 m_window = nullptr;
	GLFWmonitor* m_primary_monitor = nullptr;

	bool m_vsync = false;
};