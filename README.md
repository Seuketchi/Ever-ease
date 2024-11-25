# Everest: Arduino Laptop Cooling System

Everest is a project that uses an **Arduino-based PID controller** to manage laptop cooling effectively. By utilizing temperature sensors for real-time feedback, Everest dynamically adjusts fan speeds to maintain optimal performance and thermal efficiency for your laptop.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
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

## How It Works

1. **Temperature Monitoring**:  
   A temperature sensor continuously measures the laptop's temperature and sends the data to the Arduino.

2. **PID Algorithm**:  
   The Arduino calculates the error (difference between the target and actual temperature) and computes the required fan speed using the PID formula.

3. **Fan Control**:  
   The computed fan speed is applied using **PWM (Pulse Width Modulation)** via a transistor or MOSFET to control the cooling fan.

4. **Feedback Loop**:  
   The system dynamically adjusts fan speed based on real-time temperature readings, ensuring stability and optimal cooling.

---

## License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, and distribute this software for personal or commercial purposes.

---

**"Cool smarter, not harder."**
