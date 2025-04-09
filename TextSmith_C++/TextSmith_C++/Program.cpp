#include <iostream>
#include "Window.h"

/**
 * @brief Entry point of the application.
 *
 * Initializes and displays the main application window, then enters the game loop.
 * The loop processes OS messages each frame and exits cleanly when the user closes the window.
 */
int main() {
	std::cout << "Creating Window!\n";

	// Allocate a new Window object.
	// NOTE: For now, this is done via raw pointer. In production, consider using smart pointers (e.g., std::unique_ptr)
	Window* pWindow = new Window();

	// Main loop runs until ProcessMessages returns false (i.e., WM_QUIT is received)
	bool running = true;
	while (running) {
		// Poll and handle system messages (e.g., keyboard, mouse, close button)
		if (!pWindow->ProcessMessages()) {
			std::cout << "Closing Window!\n";
			running = false; // Exit loop if the window was closed
		}

		// TODO: Add rendering logic here (e.g., drawing game objects or GUI)

		Sleep(10); // NOTE: Temporary delay to reduce CPU usage while idle
		//       In the future, consider implementing proper frame timing (e.g., frame limiter or delta time)
	}

	// Clean up the allocated Window instance
	delete pWindow;

	// Exit the program
	return 0;
}
