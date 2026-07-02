# 🚗 Automated Smart Parking System

An IoT-based automated hardware and software solution designed to optimize parking space management, reduce traffic congestion, and improve urban mobility.

---

## 📝 Project Description

The **Smart Parking System** leverages the processing power of an **Arduino** microcontroller integrated with high-precision **IR (Infrared) Proximity Sensors** to intelligently monitor vehicle entry, exit, and individual slot occupancy. 

The real-time status of available spaces is dynamically computed by the micro-controller firmware and displayed instantly on a **LiquidCrystal LCD screen** to guide drivers efficiently before entering the zone.

---

## ⚡ Key Features

* **Real-Time Space Tracking:** Uses dedicated IR sensors positioned at each parking slot to instantly detect the presence or absence of a vehicle.
* **Automated Counter Logic:** Dynamically calculates total capacity and decreases/increases slot availability as cars enter or leave.
* **Live Display Interface:** Keeps users informed with a 16x2 LCD display showing the exact number of free spaces or a "PARKING FULL" warning.
* **Hardware-Software Synergy:** Built on optimized Embedded C++ logic to ensure minimal latency between sensor triggering and display updates.

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno.
* **Sensors:** IR Infrared Obstacle Avoidance Sensors (one per slot + entry/exit), we replace them by a  "3 LOGIC GATES" ( 2 for parking slots and 1 for detect arriving cars).
* **Display:** 16x2 LCD Display (parallel interface)
* **Actuators (Optional):** Servo Motor (for automated gate control)
* **Prototypes Tools:** Breadboard & Jumper Wires

---

## 📐 System Logic & Simulation Flow

The firmware manages a **2-slot parking facility** by processing binary digital inputs (simulated via **Logic States / Gates** in Proteus) to control the entry barrier and handle real-time user feedback on the display.

1. **Vehicle Entry Sequence:** 
   * The Entry Logic Gate triggers (`HIGH` state indicating a vehicle is present at the gate).
   * The microcontroller commands the **Servo Motor barrier** to rotate and open.
   * The overall space counter decreases, and the **LCD display** dynamically updates the current capacity.

2. **Real-time Slot Monitoring (2 Slots):**
   * The system polls **2 dedicated digital inputs** representing Slot 1 and Slot 2.
   * When a slot's Logic State changes to occupied (`HIGH`), the core loop registers the exact spot as full.
   * The LCD reflects the absolute state of the remaining slots without needing external hardware indicators (like LEDs).

3. **Vehicle Exit Sequence:**
   * The Exit Logic Gate triggers (`HIGH` state).
   * The **Servo Motor barrier** opens to clear the vehicle's path.
   * The space counter increases, and the **LCD display** updates immediately.
  
---

---



## 🔄 System States & Logic Verification

To verify the control firmware, the system was thoroughly simulated and validated across all 5 core operational scenarios using Proteus. The matrix below demonstrates the exact truth table of the system inputs, the resulting LCD feedback, and the servo barrier angles:

| Scenario | Logic Inputs <br> `(GATE / SLOT_1 / SLOT_2)` | LCD Display Status | Barrier Status (Servo) | Simulation Preview |
| :--- | :---: | :--- | :---: | :---: |
| **1. System Idle** <br> *(No car at the entry gate)* | `0 / X / X` <br> *(0/0/0 or 0/1/1)* | "PARK CAR HERE" | Closed (-4.96°) | <img src="https://github.com/user-attachments/assets/dd87d640-a77c-49e3-81e0-3d85b2ed3091" width="200"><br><img src="https://github.com/user-attachments/assets/8af40018-6879-4cbf-807a-1ffc2a61ed94" width="200"> |
| **2. Active Entry:** <br> *Both Slots Free* | `1 / 0 / 0` | "Available:<br>Slot 1 & Slot 2" | Open (-90.0°) | <img src="https://github.com/user-attachments/assets/d446b033-695f-4c36-9db4-efb39d2cdca1" width="220"> |
| **3. Active Entry:** <br> *Slot 1 Free / Slot 2 Full* | `1 / 0 / 1` | "Available:<br>Slot 1" | Open (-90.0°) | <img src="https://github.com/user-attachments/assets/87e5abe1-e6ca-49e4-8b6e-9544cfa0876c" width="220"> |
| **4. Active Entry:** <br> *Slot 1 Full / Slot 2 Free* | `1 / 1 / 0` | "Available:<br>Slot 2" | Open (-90.0°) | <img src="https://github.com/user-attachments/assets/3354b4e6-920d-40e5-96a1-0f0676f4613c" width="220"> |
| **5. Parking Full** <br> *(Entry Denied / Locked)* | `1 / 1 / 1` | "Full Parking" | Locked / Closed (-4.95°) | <img src="https://github.com/user-attachments/assets/596994a6-1e24-466b-8489-4614cbde4925" width="220"> |

---

---

## 💻 Code Structure

The repository includes:
* `Smart_Parking.ino` - The core firmware containing sensor polling loops, display driver commands, and counter logic.

---

## 🚀 How to Run the Project
1. Clone the repository to your local machine.
2. Open `Smart_Parking.ino` in the Arduino IDE.
3. Install the required `LiquidCrystal` and `servo_motor` library.
4. Upload the code to your Arduino board and connect the hardware according to the schematics.
<br><br><br>
<div align="center">

![Profile Views](https://komarev.com/ghpvc/?username=YB-Bank&style=flat-square&color=0078d4&label=PROFILE+VIEWS)]

</div>
