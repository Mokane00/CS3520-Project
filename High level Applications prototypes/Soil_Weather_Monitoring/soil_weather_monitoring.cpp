#include <iostream>

using namespace std;

// Simple forecasting (moving average)
float predictNextValue(float data[], int size) {
    if (size == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < size; i++) sum += data[i];
    float avg = sum / size;
    // Basic linear trend
    float trend = (data[size - 1] - data[0]) / (size - 1);
    return data[size - 1] + trend;
}

// Fuse soil and weather data
void processData(float soil_moisture[], float weather_temps[], int size) {
    for (int i = 0; i < size; i++) {
        soil_moisture[i] = 0.6f * soil_moisture[i] + 0.4f * (weather_temps[i] / 30.0f);  // Normalize temp
    }
}

int main() {
    // Dummy time-series data (7 days)
    float soil_moisture[7] = {0.2f, 0.25f, 0.18f, 0.22f, 0.3f, 0.28f, 0.26f};
    float weather_temps[7] = {22.0f, 24.0f, 20.0f, 23.0f, 25.0f, 24.0f, 23.0f};
    int size = 7;

    // Burst processing: fuse then forecast
    processData(soil_moisture, weather_temps, size);
    float predicted_soil = predictNextValue(soil_moisture, size);

    cout << "Predicted next soil moisture: " << predicted_soil << endl;
    if (predicted_soil < 0.2f) {
        cout << "Alert: Water shortage likely. Irrigate soon." << endl;
    } else {
        cout << "Soil health stable." << endl;
    }

    return 0;
}