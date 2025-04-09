#pragma once

#include <Windows.h>

// Forward declaration of the Windows message handler (Window Procedure).
// This function handles all OS-level events for the window (e.g., input, resizing, close requests).
// It must be provided to Windows during window class registration and should match this signature.
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/**
 * @class Window
 * @brief Encapsulates a Win32 window and its lifecycle management.
 *
 * This class serves as the base window setup for the GUI-based version of the game engine.
 * It handles window creation, message processing, and basic teardown. Future GUI elements
 * will likely build on or integrate with this foundational window.
 */
class Window
{
public:
	/**
	 * @brief Constructs and displays the main application window.
	 *
	 * Registers a window class, creates the window, and makes it visible.
	 * Throws or asserts on failure in a complete implementation.
	 */
	Window();

	// Disable copy constructor and assignment operator.
	// The Window class manages system resources (HWND), so copying would be unsafe.
	Window(const Window&) = delete;
	Window& operator = (const Window&) = delete;

	/**
	 * @brief Destructor for cleaning up resources.
	 *
	 * Unregisters the window class. Windows are destroyed automatically by the OS
	 * when closed, but explicit resource management is still important.
	 */
	~Window();

	/**
	 * @brief Processes any pending OS messages for this window.
	 *
	 * This function should be called every frame (typically inside the game loop).
	 * Returns false if the window received a quit message (e.g., user clicked the "X").
	 *
	 * @return true if the window should continue running, false if it should close.
	 */
	bool ProcessMessages();

private:
	/**
	 * @brief Handle to the application instance.
	 *
	 * Provided by the operating system. Used when registering the window class and creating the window.
	 */
	HINSTANCE m_hInstance;

	/**
	 * @brief Handle to the created window.
	 *
	 * Used by many Win32 API calls to identify and interact with the window.
	 */
	HWND m_hWnd;
};
