#include<bits/stdc++.h>
using namespace std;
enum class Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    NONE  // Optional: Represents no active signals
};

// Define priority order (lower index = higher priority)
const std::vector<Color> priorityOrder = { Color::RED, Color::GREEN, Color::BLUE, Color::YELLOW };
std::map<std::string, Color> signalToColor = {
    {"sig1", Color::RED},
    {"sig2", Color::GREEN},
    {"sig3", Color::BLUE},
    {"sig4", Color::YELLOW},
    {"sig5", Color::RED},
    {"sig6", Color::GREEN},
    {"sig7", Color::BLUE},
    {"sig8", Color::YELLOW},
    {"sig9", Color::RED},
    {"sig10", Color::RED}
};

void setValue(Color color) {
    // Implement how to set value here, e.g.:
    switch (color) {
        case Color::RED:    std::cout << "Set to RED\n"; break;
        case Color::GREEN:  std::cout << "Set to GREEN\n"; break;
        case Color::BLUE:   std::cout << "Set to BLUE\n"; break;
        case Color::YELLOW: std::cout << "Set to YELLOW\n"; break;
        case Color::NONE:   std::cout << "No active signal\n"; break;
    }
}
std::set<std::string> activeSignals;

void updateValueBasedOnSignals() {
    std::set<Color> activeColors;

    for (const auto& sig : activeSignals) {
        activeColors.insert(signalToColor[sig]);
    }

    for (Color color : priorityOrder) {
        if (activeColors.count(color)) {
            setValue(color);
            return;
        }
    }

    // Optional: handle if no signal is active
    setValue(Color::NONE);
}
void signalActivated(const std::string& signalName) {
    activeSignals.insert(signalName);
    updateValueBasedOnSignals();
}

void signalDeactivated(const std::string& signalName) {
    activeSignals.erase(signalName);
    updateValueBasedOnSignals();
}
int main() {
    signalActivated("sig2");  // GREEN
    signalActivated("sig9");  // RED (higher priority)
    signalDeactivated("sig9");  // Back to GREEN
    signalActivated("sig3");
    signalActivated("sig3");  // BLUE (lower priority than GREEN)
    signalActivated("sig3");
    signalActivated("sig3");
    signalActivated("sig3");
    signalActivated("sig9"); 
    signalDeactivated("sig9");
    signalDeactivated("sig2");

}
