/*
 * input_handler.cpp - Input Reading and Validation Implementation
 * Single Responsibility: Read text/file input and validate it
 *
 * Part of SHA256 CUDA Hasher Phase 1
 */

#include "input_handler.h"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

std::vector<BYTE> InputHandler::readFromText(const std::string& text)
{
	clearError();

	if (text.empty()) {
		lastError = "Input text is empty.";
		return {};
	}

	std::vector<BYTE> data(text.begin(), text.end());
	return data;
}

bool InputHandler::hasError() const
{
	return !lastError.empty();
}

std::string InputHandler::getErrorMessage() const
{
	return lastError;
}

void InputHandler::clearError()
{
	lastError.clear();
}
