# Bio-Inspired-Jump-Gliding-Robot

Inspired by recent studies of planetary jump robots and bio-inspired gliding mechanisms, we propose a novel robot capable of both repeated elastic-powered jumps and controlled gliding. The key innovation is the use of carbon fiber strips for energy storage and actuation, enabling jumping launches and mid-air wing deployment. So far, we detail the system architecture, mathematical modeling, and challenges encountered in the realization of this hybrid jump-gliding robot.

Our main goal was to design a robot capable of repeated jumps and gliding, expanding its operational range and adaptability. Our innovation lies in the integration of a carbon fiber strip-powered jumping mechanism with a deployable wing gliding system. Unlike prior robots that typically perform single-use or limited jumps, and compared to conventional flying robots, our design offers higher reliability and significantly lower energy consumption. So far, we detail the system architecture, mathematical modeling, and challenges encountered in the realization of this hybrid jump-gliding robot.

# So far, we have completed the following work...

<span style="font-size:20px;">And further tasks are ongoing and being continuously updated until the project is completed.</span>

[Interm Review PPT 01](https://sutdapac-my.sharepoint.com/:p:/g/personal/zheng_zhang_mymail_sutd_edu_sg/EfePilspKQ1Gtsf8nFOdvJUBf0UiOSyuQf-EtbSmFA2OlQ?e=6Rr0wn)

[Interm Technical Report 01](https://github.com/RichardZZKK/Bio-Inspired-Jump-Gliding-Robot/blob/main/Interim%20Technical%20Report%2001.pdf)

- Jump Solution Selection: After comparing different jump actuation mechanisms, we found that biomimetic legged or complex multi-link jumping structures, are not suitable for our intended application. These mechanisms are generally too heavy and not conducive to achieving lightweight design and effective gliding. Based on further research, we selected the carbon fiber strip compression jumping mechanism, which best meets our requirements for both performance and weight.

<div align="center">
<table>
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/2d52d127-d98d-43d5-9bd7-6597bf022ba3" width="300"/>
    </td>
    <td>
      <img src="https://github.com/user-attachments/assets/4d4eb47f-471b-48c0-a799-86d488b92b12" width="300"/>
    </td>
  </tr>
</table>
</div>

<p align="center">
  <img src="https://github.com/user-attachments/assets/6e41ed2f-ce66-4a4c-a529-350ee9974658?raw=true" />
</p>
  
- Release Mechanism: The release mechanism works by using an electromagnetic clutch* to quickly connect or disconnect the winch from the motor. During energy storage, the motor—through the engaged clutch—pulls the UHMWPE line to stretch the carbon fiber strip and store elastic energy. When the target tension is reached, power to the clutch is cut, instantly disconnecting the winch from the motor. This allows the stored energy to be released rapidly, enabling the jump, while protecting the motor from any sudden forces or backlash during the release.
<div align="center">
<table>
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/694cafcb-d208-42c9-b6f4-f1b8d906e2ee" width="300"/>
    </td>
    <td>
      <img src="https://github.com/user-attachments/assets/488834de-d14c-49c0-b084-9160e2fba12f" width="300"/>
    </td>
  </tr>
</table>
</div>


- Design of Jump Energy Storage and Release: Utilizes a winch motor to tension a Ultra-high-molecular-weight polyethylene(UHMWPE) line attached to carbon fiber strips, storing elastic potential energy. 
<div align="center">
<table>
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/f08731ea-73bc-4b44-99e7-35be05216e1c" width="300"/>
    </td>
    <td>
      <img src="https://github.com/user-attachments/assets/ce0810af-a8b4-4da1-b6ea-74f0b9d5a3af" width="300"/>
    </td>
  </tr>
</table>
</div>


- Design of Gliding Mechanism: Wings are deployed at the apex of each jump, either by electronic control or mechanical triggering.
*An electromagnetic clutch engages or disengages power transmission between two shafts by using electromagnetic force. When current is applied, the clutch connects the shafts; when current is removed, the connection is released.
<div align="center">
<table>
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/23fe3522-b2e0-4b5b-9c85-6e9ccd3a104b" width="300"/>
    </td>
    <td>
      <img src="https://github.com/user-attachments/assets/8002e049-6982-4139-b69c-9269329fd793" width="300"/>
    </td>
  </tr>
</table>
</div>

<div align="center">
<table>
  <tr>
    <td>
      <img src="https://github.com/user-attachments/assets/1dbb64f0-a2ee-43ea-8911-7763eb12b03b" width="300"/>
    </td>
    <td>
      <img src="https://github.com/user-attachments/assets/e19473eb-4e7b-43fd-a649-bb6782251436" width="300"/>
    </td>
  </tr>
</table>
</div>

## Electronics Design

### MCU & Power

- **MCU**: Arduino Nano 33 BLE Sense Rev2 (NINA B306 + Cortex‑M4F)  
- **Input Voltage**: 3.3 V (all I/O 3.3 V TTL)  
- **Key Specs**: 64 MHz, 1 MB Flash + 256 kB RAM, BLE 5.0, onboard DC DC, BMI270/BMM150 IMU

### Bill of Materials

| # | Component                                    |
|---|----------------------------------------------|
| 1 | Arduino Nano 33 BLE Sense Rev2               |
| 2 | 6 V DC motor + MOSFET driver                 |
| 3 | 24 V electromagnetic clutch + MOSFET driver  |
| 4 | 2 × Hobby servos                             |
| 5 | Power modules (3.3 V, 6 V, 24 V rails)       |
| 6 | Assorted wiring                              |


### Wiring Diagram

![Schematic][schematic]

[schematic]: docs/schematic.png

### Pin Assignment

| Function               | Arduino Pin  | Description                                 |
|------------------------|--------------|---------------------------------------------|
| Motor MOSFET Gate      | D3           | Drives 6 V DC motor                         |
| Clutch MOSFET Gate     | D4           | Drives 24 V electromagnetic clutch          |
| Servo PWM Signals      | D9, D10      | Hobby servo control (future gliding)        |
| Limit Switch Inputs    | D2, D5…      | End‑stop switches                           |
| I²C (BMI270 IMU)       | SDA(A4), SCL(A5) | On‑board 9‑axis sensor                  |
| BLE UART               | Serial1      | UART on NINA B306 (debug/servo)             |
| Power & Ground         | VIN, GND     | 3.3 V input & common ground                 |

---

## Code Breakdown

Below is an annotated overview of `src/main.ino`.  

### 1. Include Statements & Libraries

```cpp
#include <ArduinoBLE.h>
#include "Arduino_BMI270_BMM150.h"
#include <Wire.h>
#include <Servo.h>
#include "include.h"
#include "SerialServo.h"
# Ongoing efforts focus on: 
* Improving mechanical efficiency and alignment, 
* Optimizing the wing deployment strategy, 
* Designing and testing closed-loop feedback and control, 
* Validating the robot in more varied and realistic test scenarios.


Authors:
[RichardZZKK](url)
[llz077](url)
[Ianthomas-gee](url)
