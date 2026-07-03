#include "config.h"
#include "gpu_device_info.h"
#include "power_metrics.h"
#include "input_handler.h"
#include "cmd_ui.h"
#include "app_controller.h"

#include <cstdio>
int main(int argc, char* argv[])
{
    // --- Step 1: Query GPU Device ---
    GPUDeviceInfo gpuInfo = queryGPUDevice();
    if (!gpuInfo.valid) {
        printf("WARNING: %s\n", gpuInfo.errorMessage.c_str());
        printf("The application will continue but GPU hashing will not be available.\n");
        printf("Press any key to continue...\n");
        getchar();
    }

    // --- Step 2: Initialize Power Metrics (NVML) ---
    PowerMetrics powerMetrics;
    bool nvmlOk = powerMetrics.init();
    if (!nvmlOk) {
        // NVML not available - power metrics will show 0
    }

    // --- Step 3: Create Input Handler ---
    InputHandler inputHandler;

    // --- Step 4: Create UI ---
    CmdUI ui;

    // --- Step 5: Create Controller & Run ---
    AppController controller(ui, inputHandler, gpuInfo, powerMetrics);
    controller.run();

    // --- Cleanup ---
    powerMetrics.shutdown();

    return 0;
}
