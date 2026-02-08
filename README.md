# Line-following-Robot
it is used to follow line
# Line Follower Robot using ESP32

## 📌 Project Overview
This project implements a **Line Follower Robot** using an **ESP32 microcontroller**.  
The robot detects and follows a predefined path (black/white line) using **IR sensors** and controls its movement through **N20 gear motors** driven by a **TB6612FNG motor driver**.

---

## 🧠 Working Principle
- IR sensors detect the line by measuring reflected infrared light.
- Sensor outputs are processed by the ESP32.
- Based on sensor readings, the ESP32 sends control signals to the motor driver.
- The motor driver drives the N20 motors to move the robot left, right, or forward.

---

## 🧰 Components Used

### 🔹 Microcontroller
- **ESP32 Development Board**
  - Dual-core processor
  - Built-in Wi-Fi and Bluetooth
  - Operates at 3.3V logic level

### 🔹 Sensors
- **IR Line Following Sensors**
  - Used to detect the line path
  - Consists of IR LED and photodiode
  - Output: Digital / Analog (based on module)

### 🔹 Motor Driver
- **TB6612FNG Dual Motor Driver**
  - Controls direction and speed of motors
  - Supports PWM speed control
  - Low power loss compared to L298N

### 🔹 Motors
- **N20 DC Gear Motors**
  - Compact and lightweight
  - High torque at low speed
  - Ideal for small robotic applications

### 🔹 Power Supply
- Lithium-ion Battery / Battery Pack
- Voltage regulator (if required)

### 🔹 Other Components
- Robot chassis
- Wheels
- Jumper wires
- Breadboard / PCB
- On/Off switch

---

## 🔌 Pin Configuration (Example)
| Component | ESP32 Pin |
|---------|----------|
| IR Sensor Left | GPIO 34 |
| IR Sensor Right | GPIO 35 |
| Motor A IN1 | GPIO 25 |
| Motor A IN2 | GPIO 26 |
| Motor B IN1 | GPIO 27 |
| Motor B IN2 | GPIO 14 |
| PWM (Speed Control) | GPIO 33 |

*(Pins can be modified based on design)*

---

## 🛠️ Software Used
- Arduino IDE
- ESP32 Board Package
- C/C++ Programming Language

---

## 🚀 Applications
- Autonomous robots
- Path-following systems
- Educational robotics
- Industrial automation basics

---

## 📷 Project Images / Videos
(Add images or demo videos here)

---

## 📄 License
This project is open-source and available under the MIT License.

---

## 🙋‍♂️ Author
Your Name  
GitHub: https://github.com/your-username
## 🔌 Circuit Diagram

The circuit connects the **ESP32**, **IR sensors**, **TB6612FNG motor driver**, and **N20 gear motors** as follows:

### 🔹 Connections Overview
- IR sensors are connected to ESP32 GPIO pins to detect the line.
- TB6612FNG motor driver receives control signals from ESP32.
- Motor driver outputs are connected to N20 gear motors.
- Motors are powered through the motor driver.
- ESP32 is powered using a regulated power source.

### 🔹 Power Connections
- ESP32 operates at **3.3V logic**
- TB6612FNG motor supply (VM): **6–9V**
- Common **GND** between ESP32, motor driver, and sensors is mandatory.

### 🖼️ Circuit Diagram
(Add your circuit diagram image here)

Example:
```text
ESP32  →  TB6612FNG  →  N20 Motors
ESP32  →  IR Sensors
Battery → Motor Driver → Motors
        START
          |
          v
   Initialize ESP32
   & GPIO Pins
          |
          v
   Read IR Sensors
          |
          v
   Is Line Detected?
      /        \
    YES        NO
     |          |
     v          v
 Adjust Motor   Stop /
 Direction      Search Line
     |
     v
 Move Forward /
 Turn Left /
 Turn Right
     |
     v
   Repeat Loop
## 📸 Project Images

Below are some images of the **Line Follower Robot hardware and setup**:

### 🔹 Robot Prototype
![Robot Front View](images/robot_front.jpg)
![Robot Top View](images/robot_top.jpg)

### 🔹 Circuit Setup
![Circuit Diagram](images/circuit_diagram.png)

> 📌 Make sure all images are placed inside an `images/` folder in your repository.

---

## 🎥 Project Demo Videos

### 🔹 Line Follower Robot Working Demo
Click the link below to watch the robot in action:

▶️ **Demo Video:**  
[Watch on GitHub](videos/line_follower_demo.mp4)

OR (Recommended for better compatibility)

▶️ **YouTube Demo:**  
https://youtube.com/your-video-link

---

## 📁 Recommended Folder Structure

```text
Line-Follower-Robot/
│
├── images/
│   ├── robot_front.jpg
│   ├── robot_top.jpg
│   └── circuit_diagram.png
│
├── videos/
│   └── line_follower_demo.mp4
│
├── src/
│   └── main.ino
│
└── README.md
