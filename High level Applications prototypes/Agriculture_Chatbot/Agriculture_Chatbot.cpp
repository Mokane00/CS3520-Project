#include <iostream>
#include <string>

using namespace std;

// Simple string comparison helper
bool contains(const string& str, const string& substr) {
    if (str.length() < substr.length()) return false;
    for (int i = 0; i <= str.length() - substr.length(); i++) {
        bool match = true;
        for (int j = 0; j < substr.length(); j++) {
            // Case-insensitive comparison
            char c1 = str[i + j], c2 = substr[j];
            if (c1 >= 'A' && c1 <= 'Z') c1 += ('a' - 'A');
            if (c2 >= 'A' && c2 <= 'Z') c2 += ('a' - 'A');
            if (c1 != c2) { match = false; break; }
        }
        if (match) return true;
    }
    return false;
}

// Simple NLP-like query parser
string processQuery(const string& query) {
    if (contains(query, "weather")) {
        float temp = 25.0f;  // Dummy current temp
        float predicted_rain = 0.3f * temp - 5.0f;  // Simple equation
        char buffer[100];
        sprintf(buffer, "Weather update: Expect %.1fmm rain tomorrow. Plant drought-resistant crops.", predicted_rain);
        return string(buffer);
    } else if (contains(query, "crop advice") || contains(query, "yield")) {
        float soil_quality = 0.7f;  // Dummy input
        float predicted_yield = 1.2f * soil_quality + 0.5f;
        char buffer[100];
        sprintf(buffer, "Crop advice: Expect %.1f tons/ha. Use fertilizer sparingly.", predicted_yield);
        return string(buffer);
    } else {
        return "Sorry, query not recognized. Try 'weather' or 'crop advice'.";
    }
}

int main() {
    string user_query;
    cout << "Enter query: ";
    getline(cin, user_query);

    // Process in bursts (simulate conversation)
    for (int i = 0; i < 3; i++) {
        string response = processQuery(user_query);
        cout << response << endl;
        user_query += " more details";  // Dummy follow-up
    }

    return 0;
}
