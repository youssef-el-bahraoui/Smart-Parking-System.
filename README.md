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


## 🔄 System States & Logic Verification

To verify the robust control firmware, the system was thoroughly tested across all possible logical states using Proteus simulation. Below is the state matrix showcasing how the LCD and Servo motor react to different sensor inputs:

| Scenario | Logic Inputs (Gate / Slot 1 / Slot 2) | LCD Display Status | Barrier Status (Servo) | Simulation Preview |
| :--- | :--- | :--- | :--- | :--- |
| **1. System Idle** | `0 / 1 / 1` | "PARK CAR HERE" | Closed (+90°) | <img src="Screenshot (65).png" width="250"> |
| **2. Both Slots Free** | `1 / 0 / 0` | "Available: Slot 1 & Slot 2" | Open (-4.9°) | <img src="Screenshot (68).png" width="250"> |
| **3. Partial Occupancy** | `1 / 0 / 1` | "Available: Slot 1" | Open (0.0°) | <img src="Screenshot (67).png" width="250"> |
| **4. Parking Full** | `1 / 1 / 1` | "Full Parking" | Locked / Closed (0.0°) | <img src="Screenshot (66).png" width="250"> |

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
