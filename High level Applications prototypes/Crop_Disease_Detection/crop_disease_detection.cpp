#include <iostream>

using namespace std;

// Simulate 2D convolution for CNN-based disease detection
void convolve(float image[32][32], float kernel[3][3], float output[30][30]) {
    int img_height = 32, img_width = 32, kernel_size = 3;
    int pad = kernel_size / 2;

    for (int i = pad; i < img_height - pad; i++) {
        for (int j = pad; j < img_width - pad; j++) {
            float sum = 0.0f;
            for (int ki = 0; ki < kernel_size; ki++) {
                for (int kj = 0; kj < kernel_size; kj++) {
                    sum += image[i - pad + ki][j - pad + kj] * kernel[ki][kj];
                }
            }
            output[i - pad][j - pad] = sum;  // Simulate activation
        }
    }
}

int main() {
    // Dummy 32x32 image (grayscale, initialized to 0.5)
    float image[32][32];
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
            image[i][j] = 0.5f;

    // Dummy 3x3 kernel for edge detection
    float kernel[3][3] = { {-1, -1, -1},
                           {-1,  8, -1},
                           {-1, -1, -1} };
    // Output feature map (30x30)
    float output[30][30] = {0};

    // Simulate multiple layers (bursty computation)
    for (int layer = 0; layer < 3; layer++) {
        convolve(image, kernel, output);
        // Copy output back to image for next layer
        for (int i = 0; i < 30; i++)
            for (int j = 0; j < 30; j++)
                image[i][j] = output[i][j];
    }

    // Simulate classification: average-based thresholding
    float avg = 0.0f;
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            avg += output[i][j];
    avg /= (30 * 30);
    cout << (avg > 0.1f ? "Disease detected" : "Healthy crop") << endl;

    return 0;
}