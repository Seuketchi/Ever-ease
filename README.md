# Ever-ease: Arduino Laptop Cooling System

Ever-ease is a project that uses an **Arduino-based PID controller** to manage laptop cooling effectively. By utilizing temperature sensors for real-time feedback, Ever-ease dynamically adjusts fan speeds to maintain optimal performance and thermal efficiency for your laptop.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Development Environment Setup](#development-environment-setup)
- [How It Works](#how-it-works)
- [Testing Results](#testing-results)
- [Performance Analysis](#performance-analysis)
- [Safety Considerations](#safety-considerations)
- [Potential Issues & Future Actions](#potential-issues--future-actions)
- [License](#license)

---

## Overview

Ever-ease is designed to address laptop overheating issues by intelligently controlling cooling fans. Using a **PID (Proportional-Integral-Derivative) controller**, the system measures real-time temperatures through sensors and adjusts the fan speed to maintain a user-defined target temperature.

---

## Features

- **PID Control**: Provides precise fan control by dynamically calculating proportional, integral, and derivative responses.
- **Real-Time Feedback**: Continuously monitors laptop temperature using sensors for optimal adjustments.
- **Arduino-Based**: A simple, affordable, and highly customizable hardware solution.
- **Dynamic Cooling**: Adjusts fan speed adaptively to balance efficient cooling and low noise levels.

---

## Hardware Requirements
![Hardware Design](https://github.com/user-attachments/assets/8c281f8b-9e66-43ef-99c8-f425783ecd85)

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

   These constants were fine-tuned through experimentation to balance responsiveness and stability. Further optimization may be necessary based on the laptop’s performance and environmental conditions.

   ### PID Tuning Values
   The **PID constants** used in this project are as follows:

   - **Proportional (Kp)**: `10.0`
   - **Integral (Ki)**: `2.0`
   - **Derivative (Kd)**: `5.0`

   ### Output Limits
   The fan speed is controlled by Pulse Width Modulation (PWM), and its output is limited to a range of **0-255**, corresponding to the PWM values that control the fan speed. The fan speed should not exceed 100% (PWM = 255) or fall below a certain threshold for optimal operation.

   - **Fan Speed Limits**:
     - **Minimum**: `PWM = 30` (represents minimal fan activity)
     - **Maximum**: `PWM = 255` (full-speed operation)

   The limits are applied to prevent the fan from running at insufficient speeds (which would be ineffective for cooling) or excessive speeds (which could cause unnecessary noise and energy waste).

3. **Fan Control**  
   The computed fan speed is applied using **PWM (Pulse Width Modulation)** via a transistor or MOSFET to control the cooling fan.

4. **Feedback Loop**  
   The system dynamically adjusts fan speed based on real-time temperature readings, ensuring stability and optimal cooling. The PID algorithm ensures that the fan reacts precisely to changing temperatures without excessive noise or inefficient power usage.

---

### Special Behavior Explanation

- **Preventing Overheating**:  
   Once the temperature drops below the target **setpoint**, the system does not allow the fan speed to increase above a certain point. This is because there is no heating actuator in the system to raise the temperature back to the setpoint. Therefore, the cooling process stops once the temperature is close to the target, and the fan speed remains low.

- **Avoiding Zero Fan Speed**:  
   To prevent the fan from turning off completely, which might leave the system without cooling entirely, the PID controller is configured to keep the fan speed above a minimum threshold. Once the system reaches a steady-state temperature, the PID algorithm will only generate small adjustments in fan speed, typically in the range of **0-10** PWM values. At this level, the fan will still spin, but at a very low speed, ensuring that minimal cooling is applied while avoiding fan stasis (which could lead to overheating).

---

## Testing Results

![Testing Graph](https://github.com/user-attachments/assets/edc9b302-863f-4d33-aa60-8d33f65e5295)


Steady State
![image](https://github.com/user-attachments/assets/25b97546-73e4-41d8-b213-1e0f4d0ae5e1)
![image](https://github.com/user-attachments/assets/d405da5e-9800-4626-8e1d-fb4c6dc59453)

---

## Performance Analysis

- **Fan Speed Control**: The PID controller responds well to both rapid and gradual changes in temperature, adjusting fan speed accordingly.
- **Cooling Efficiency**: The system successfully maintains the temperature close to the setpoint with minimal oscillations, demonstrating the effectiveness of the PID algorithm in regulating fan speed.
- **Power Consumption**: The system optimizes fan usage, only increasing speed when necessary to maintain the target temperature.

---

## Safety Considerations

- **Electrical Safety**: Ensure that the power supply to the Arduino and the cooling fan is stable and within recommended voltage and current ranges to prevent damage.
- **Fan Overload**: Avoid running the fan at full speed for prolonged periods, as it could overheat. Always test with appropriate fan specifications.
- **Component Ratings**: Ensure that the components used, such as the motor driver (L298N) and Arduino, are rated for the power requirements of your system to avoid overheating or failure.

---

## Potential Issues & Future Actions

### Reasons the system might not achieve the setpoint:
1. **Inadequate Fan Power**
   - The fan may not provide sufficient cooling power to reach the setpoint, especially under heavy loads or high environmental temperatures.
   - **Action**: Use a more powerful fan or add multiple fans to increase cooling capacity.

2. **Incorrect Temperature Sensor Readings**
   - If the LM35 sensor is not properly calibrated or is affected by noise, the temperature readings may not be accurate.
   - **Action**: Calibrate the sensor and use averaging techniques or filtering methods to smooth out readings.

3. **PID Parameter Tuning**
   - Incorrect PID tuning (e.g., too high or too low KP, KI, or KD values) can result in oscillations or an inability to reach the setpoint.
   - **Action**: Fine-tune the PID constants using methods like the Ziegler-Nichols approach or trial and error.

4. **Inconsistent Power Supply**
   - Fluctuations or insufficient voltage in the power supply can affect the performance of the fan or Arduino.
   - **Action**: Ensure the power supply is stable and meets the voltage and current requirements of the system.

5. **Insufficient Feedback Loop**
   - The fan may not respond quickly enough to temperature changes, or the PID loop may not be updating frequently enough.
   - **Action**: Increase the loop update frequency or use a faster response fan.

6. **High Ambient Temperature**
   - In an environment with high ambient temperatures, the cooling system might struggle to bring the temperature down to the setpoint.
   - **Action**: Improve airflow around the laptop or add additional cooling solutions like external fans.

---

## Documentation

Project photos and video clips can be found in the [Documentation Folder](https://drive.google.com/drive/folders/1XgEvxE-ASJG3Hiq4p9qc1ua79MdXJOUg?usp=sharing).

