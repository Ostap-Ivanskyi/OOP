#include "Bridge.h"

class Device {
public:
    virtual ~Device() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int channel) = 0;
    virtual void printStatus() = 0;
};

// Конкретні реалізації
class TV : public Device {
public:
    void turnOn() override {
        std::cout << "TV is ON\n";
        isOn = true;
    }

    void turnOff() override {
        std::cout << "TV is OFF\n";
        isOn = false;
    }

    void setChannel(int channel) override {
        if (isOn) {
            currentChannel = channel;
            std::cout << "TV channel set to " << channel << "\n";
        } else {
            std::cout << "Cannot set channel - TV is OFF\n";
        }
    }

    void printStatus() override {
        std::cout << "TV is " << (isOn ? "ON" : "OFF")
                  << ", current channel: " << currentChannel << "\n";
    }

private:
    bool isOn = false;
    int currentChannel = 1;
};

class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio is ON\n";
        isOn = true;
    }

    void turnOff() override {
        std::cout << "Radio is OFF\n";
        isOn = false;
    }

    void setChannel(int channel) override {
        if (isOn) {
            currentChannel = channel;
            std::cout << "Radio tuned to " << channel << " FM\n";
        } else {
            std::cout << "Cannot tune - Radio is OFF\n";
        }
    }

    void printStatus() override {
        std::cout << "Radio is " << (isOn ? "ON" : "OFF")
                  << ", current station: " << currentChannel << " FM\n";
    }

private:
    bool isOn = false;
    int currentChannel = 88;
};

// Абстракція
class RemoteControl {
public:
    RemoteControl(Device* device) : device(device) {}
    virtual ~RemoteControl() = default;

    virtual void togglePower() {
        if (power) {
            device->turnOff();
            power = false;
        } else {
            device->turnOn();
            power = true;
        }
    }

    virtual void channelUp() {
        if (power) {
            device->setChannel(++currentChannel);
        }
    }

    virtual void channelDown() {
        if (power && currentChannel > 1) {
            device->setChannel(--currentChannel);
        }
    }

    void printStatus() {
        device->printStatus();
    }

protected:
    Device* device;
    bool power = false;
    int currentChannel = 1;
};

// Розширена абстракція
class AdvancedRemoteControl : public RemoteControl {
public:
    using RemoteControl::RemoteControl;

    void mute() {
        if (power) {
            std::cout << "Device muted\n";
        }
    }
};

// Демонстрація роботи Bridge
void demonstrateBridge() {
    std::cout << "\n=== Bridge Pattern Demo ===\n\n";

    TV tv;
    Radio radio;

    RemoteControl basicRemote(&tv);
    basicRemote.togglePower();
    basicRemote.channelUp();
    basicRemote.printStatus();

    AdvancedRemoteControl advancedRemote(&radio);
    advancedRemote.togglePower();
    advancedRemote.channelUp();
    advancedRemote.mute();
    advancedRemote.printStatus();

    // Можна легко змінити пристрій
    advancedRemote.togglePower();
    advancedRemote.togglePower();
    advancedRemote.printStatus();
}
