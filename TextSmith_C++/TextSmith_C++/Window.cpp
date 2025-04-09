#include "Window.h"

/**
 * @brief Main Windows message handler (aka "Window Procedure").
 *
 * This function receives all messages sent to windows of the registered class.
 * It handles specific messages like closing and destruction, and falls back to
 * default behavior for anything unhandled.
 */
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CLOSE:
		// NOTE: Triggered when the user attempts to close the window (e.g., clicks the 'X')
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		// NOTE: Sent when the window is being destroyed. This is our chance to quit the app.
		PostQuitMessage(0); // Signals to end the message loop
		return 0;

		// TODO: Add more message handlers (e.g., WM_PAINT, WM_KEYDOWN) as the GUI expands

	default:
		break;
	}

	// Default processing for any messages we didn’t explicitly handle
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/**
 * @brief Constructor for the Window class. Handles window registration and creation.
 */
Window::Window()
	: m_hInstance(GetModuleHandle(nullptr)) // Retrieves the current app instance from the OS
{
	// Window class name must be consistent for registration and creation
	const wchar_t* CLASS_NAME = L"TextSmith";

	// Define and initialize the window class
	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);       // NOTE: Uses default Windows logo
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);     // NOTE: Uses default arrow cursor
	wndClass.lpfnWndProc = WindowProc;                  // Entry point for handling all messages

	
	if (!RegisterClass(&wndClass)) {
		MessageBox(NULL, L"Window class registration failed!", L"Error", MB_ICONERROR);
		return;
	}

	// Define window style flags (caption, minimize button, system menu)
	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	// Desired client area size (actual window will be slightly larger due to borders/title)
	int width = 640;
	int height = 480;

	// RECT defines screen coordinates; AdjustWindowRect ensures we reserve enough space
	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;
	AdjustWindowRect(&rect, style, false);

	// Create the window using Win32 API
	m_hWnd = CreateWindowEx(
		0,                        // Extended window styles
		CLASS_NAME,               // Class name (must match registration)
		L"TextSmith c++  || version 0.1", // Window title
		style,                    // Style flags defined above
		rect.left,
		rect.top,
		rect.right - rect.left,  // Width
		rect.bottom - rect.top,  // Height
		NULL,                    // No parent window
		NULL,                    // No menu
		m_hInstance,             // App instance
		NULL                     // No extra parameters
	);
	if (m_hWnd == NULL) {
		MessageBox(NULL, L"Window creation failed!", L"Error", MB_ICONERROR);
		return;
	}
	ShowWindow(m_hWnd, SW_SHOW); // Makes the window visible on screen
}

/**
 * @brief Destructor for the Window class. Cleans up registered class.
 */
Window::~Window()
{
	// NOTE: Cleanup — must unregister class to avoid leaks if multiple windows are created/destroyed
	const wchar_t* CLASS_NAME = L"TextSmith";
	UnregisterClass(CLASS_NAME, m_hInstance);
}

/**
 * @brief Processes the Windows message queue (non-blocking).
 *
 * This method should be called once per frame to handle any pending system messages.
 * It keeps the app responsive to input, resize, close, etc.
 *
 * @return false if WM_QUIT was received (signals main loop to exit); true otherwise.
 */
bool Window::ProcessMessages()
{
	MSG msg = {};

	// Loop through all pending messages in the queue (non-blocking)
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE)) {

		// Exit main loop when receiving WM_QUIT
		if (msg.message == WM_QUIT) {
			return false;
		}

		// Translates things like WM_KEYDOWN into character messages (e.g., WM_CHAR)
		TranslateMessage(&msg);

		// Dispatch message to the appropriate WindowProc
		DispatchMessage(&msg);
	}

	return true; // No quit signal received; continue running
}
