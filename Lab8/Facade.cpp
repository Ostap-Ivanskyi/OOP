#include "Facade.h"
class LightingSystem {
public:
    void turnOnLights() {
        std::cout << "Lighting: all lights on\n";
    }

    void turnOffLights() {
        std::cout << "Lighting: all lights off\n";
    }

    void dimLights(int level) {
        std::cout << "Lighting: brightness adjustment to " << level << "%\n";
    }
};

class ClimateControl {
public:
    void setTemperature(double temp) {
        std::cout << "Climate control: set temperature " << temp << "°C\n";
    }

    void setHumidity(int level) {
        std::cout << "Climate control: set humidity " << level << "%\n";
    }

    void turnOnAirConditioner() {
        std::cout << "Climate control: AC on\n";
    }
};

class SecuritySystem {
public:
    void armAlarm() {
        std::cout << "Security system: alarm activated\n";
    }

    void disarmAlarm() {
        std::cout << "Security system: alarm deactivated\n";
    }

    void lockAllDoors() {
        std::cout << "Security system: all doors locked\n";
    }
};

class EntertainmentSystem {
public:
    void turnOnTV() {
        std::cout << "Entertainment system: TV on\n";
    }

    void playMusic(const std::string& song) {
        std::cout << "Entertainment system: playing music - \"" << song << "\"\n";
    }

    void setAmbientMode() {
        std::cout << "Entertainment system: 'Atmosphere 'mode is set\n";
    }
};

// Фасад для системи домашньої автоматизації
class SmartHomeFacade {
public:
    SmartHomeFacade() {
        lighting = new LightingSystem();
        climate = new ClimateControl();
        security = new SecuritySystem();
        entertainment = new EntertainmentSystem();
    }

    ~SmartHomeFacade() {
        delete lighting;
        delete climate;
        delete security;
        delete entertainment;
    }

    // Сценарії для різних режимів
    void leaveHome() {
        std::cout << "\n=== 'I live the house' mode ===\n";
        lighting->turnOffLights();
        climate->setTemperature(18.0);
        security->armAlarm();
        security->lockAllDoors();
        entertainment->turnOnTV();  // Симуляція присутності
        std::cout << "=== House is in safe mode ===\n\n";
    }

    void comeHome() {
        std::cout << "\n=== 'Returning home' mode ===\n";
        security->disarmAlarm();
        lighting->turnOnLights();
        lighting->dimLights(70);
        climate->setTemperature(22.5);
        entertainment->playMusic("Welcome Home");
        std::cout << "=== Welcome Home! ===\n\n";
    }

    void eveningRelax() {
        std::cout << "\n=== 'Evening rest' mode ===\n";
        lighting->dimLights(30);
        climate->setTemperature(21.0);
        entertainment->setAmbientMode();
        entertainment->playMusic("Relaxing Jazz");
        std::cout << "=== Enjoy your rest ===\n\n";
    }

    void nightMode() {
        std::cout << "\n=== 'Night' mode ===\n";
        lighting->turnOffLights();
        climate->setTemperature(19.0);
        security->lockAllDoors();
        security->armAlarm();
        std::cout << "=== Good dreams! ===\n\n";
    }

private:
    LightingSystem* lighting;
    ClimateControl* climate;
    SecuritySystem* security;
    EntertainmentSystem* entertainment;
};
void demonstrateFacade() {
    SmartHomeFacade smartHome;

    std::cout << "=== Facade pattern demo ===\n\n";
    std::cout << "=== Demonstrate smart home ===\n\n";

    smartHome.leaveHome();
    smartHome.comeHome();
    smartHome.eveningRelax();
    smartHome.nightMode();

}