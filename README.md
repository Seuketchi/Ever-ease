# Ever-ease: Arduino Laptop Cooling System

Ever-ease is a project that uses an **Arduino-based PID controller** to manage laptop cooling effectively. By utilizing temperature sensors for real-time feedback, Everest dynamically adjusts fan speeds to maintain optimal performance and thermal efficiency for your laptop.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Development Environment Setup](#development-environment-setup)
- [How It Works](#how-it-works)
- [License](#license)

---

## Overview

Everest is designed to address laptop overheating issues by intelligently controlling cooling fans. Using a **PID (Proportional-Integral-Derivative) controller**, the system measures real-time temperatures through sensors and adjusts the fan speed to maintain a user-defined target temperature.

---

## Features

- **PID Control**: Provides precise fan control by dynamically calculating proportional, integral, and derivative responses.
- **Real-Time Feedback**: Continuously monitors laptop temperature using sensors for optimal adjustments.
- **Arduino-Based**: A simple, affordable, and highly customizable hardware solution.
- **Dynamic Cooling**: Adjusts fan speed adaptively to balance efficient cooling and low noise levels.

---

## Hardware Requirements
![Hardware Design](https://github.com/user-attachments/assets/9b2caf2a-ea04-418c-aa78-6a9f46d860f5)

To implement **Ever-ease**, you will need the following hardware components:

1. **Arduino Board**  
   - Acts as the central controller, running the PID algorithm and handling inputs/outputs.

2. **LM35 Temperature Sensor**  
   - Used for real-time temperature monitoring of the laptop.  
   - Provides an analog signal proportional to the temperature.

3. **Cooling Fan**  
   - A DC fan that serves as the active cooling component.  
   - Controlled via PWM signals for dynamic speed adjustments.

4. **L298N Motor Driver**
   - Interfaces the Arduino with the cooling fan, enabling precise control of fan speed using PWM signals.

5. **Power Supply (5V)**  
   - Supplies power to the Arduino and connected components like the sensor and fan.

6. **Wiring and Connectors**  
   - Ensures all components are properly connected for signal and power transmission.

---

## Development Environment Setup

### PlatformIO Extension for VS Code  
- Install the [PlatformIO IDE](https://platformio.org/install/ide?install=vscode) in **Visual Studio Code** for an easy development environment.  
- Use it to write, compile, and upload the Arduino-based code to your board.  

### Arduino IDE (Optional)  
- Alternatively, you can use the [Arduino IDE](https://www.arduino.cc/en/software) to upload the source code.  
- Note: You cannot clone the repository directly in Arduino IDE. Instead, manually copy the provided source code into a new sketch.  

### Source Code  
- Clone this repository (for PlatformIO) or copy the provided source code manually (for Arduino IDE).  

---

## How It Works

1. **Temperature Monitoring**  
   A temperature sensor continuously measures the laptop's temperature and sends the data to the Arduino.

2. **PID Algorithm**  
   The Arduino calculates the error (difference between the target and actual temperature) and computes the required fan speed using the PID formula. The PID controller works as follows:
   
   - **Proportional (P)**: Calculates the error between the target and actual temperature. The larger the error, the faster the fan will spin to bring the temperature down.
   - **Integral (I)**: Summing up past errors over time, helping eliminate small discrepancies in temperature and ensuring the system corrects persistent issues, if any.
   - **Derivative (D)**: Measures the rate of change in temperature, predicting trends and adjusting fan speed before the temperature rises excessively, ensuring a proactive cooling response.

3. **Fan Control**  
   The computed fan speed is applied using **PWM (Pulse Width Modulation)** via a transistor or MOSFET to control the cooling fan.

4. **Feedback Loop**  
   The system dynamically adjusts fan speed based on real-time temperature readings, ensuring stability and optimal cooling. The PID algorithm ensures that the fan reacts precisely to changing temperatures without excessive noise or inefficient power usage.

---

## License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and distribute this software for personal or commercial purposes.

---

**"Achieve Peak Performance"**
