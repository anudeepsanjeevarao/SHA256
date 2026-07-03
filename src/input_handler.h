/*
 * input_handler.h - Input Reading and Validation Interface
 * Single Responsibility: Read text/file input and validate it
 *
 * Part of SHA256 CUDA Hasher Phase 1
 */

#pragma once

#include "config.h"
#include <string>
#include <vector>

class InputHandler {
public:
	InputHandler();
	~InputHandler();

	// Read input from plain text string
	std::vector<BYTE> readFromText(const std::string& text);



	// Error reporting
	bool hasError() const;
	std::string getErrorMessage() const;
	void clearError();

private:
	std::string lastError;
};
