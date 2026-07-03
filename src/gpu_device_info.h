#pragma once

#include <string>
#include <cuda_runtime.h>

struct GPUDeviceInfo {
	std::string deviceName;
	int cudaCoreCount;
	int multiProcessorCount;
	int maxThreadsPerBlock;
	int maxTotalThreads;
	size_t totalMemory;         // bytes
	size_t freeMemory;          // bytes
	int computeCapabilityMajor;
	int computeCapabilityMinor;
	bool valid;
	std::string errorMessage;
};

// Query the first available CUDA device and populate GPUDeviceInfo
GPUDeviceInfo queryGPUDevice();

// Validate that the requested batch count is feasible given input size and device memory
// Returns true if valid, sets errorMessage in info if not
bool validateBatchCount(const GPUDeviceInfo& info, int n_batch, size_t inputLen, std::string& errorMessage);

// Get CUDA cores per SM based on compute capability
int getCoresPerSM(int major, int minor);
