# Bio-Inspired-Jump-Gliding-Robot

Inspired by recent studies of planetary jump robots and bio-inspired gliding mechanisms, we propose a novel robot capable of both repeated elastic-powered jumps and controlled gliding. The key innovation is the use of carbon fiber strips for energy storage and actuation, enabling jumping launches and mid-air wing deployment. So far, we detail the system architecture, mathematical modeling, and challenges encountered in the realization of this hybrid jump-gliding robot.

Our main goal was to design a robot capable of repeated jumps and gliding, expanding its operational range and adaptability. Our innovation lies in the integration of a carbon fiber strip-powered jumping mechanism with a deployable wing gliding system. Unlike prior robots that typically perform single-use or limited jumps, and compared to conventional flying robots, our design offers higher reliability and significantly lower energy consumption. So far, we detail the system architecture, mathematical modeling, and challenges encountered in the realization of this hybrid jump-gliding robot.

# So far, we have completed the following work...(And further tasks are ongoing and being continuously updated until the project is completed.)

-Jump Solution Selection: After comparing different jump actuation mechanisms, we found that biomimetic legged or complex multi-link jumping structures, are not suitable for our intended application. These mechanisms are generally too heavy and not conducive to achieving lightweight design and effective gliding. Based on further research, we selected the carbon fiber strip compression jumping mechanism, which best meets our requirements for both performance and weight.

![image](https://github.com/user-attachments/assets/2d52d127-d98d-43d5-9bd7-6597bf022ba3)
![image](https://github.com/user-attachments/assets/4d4eb47f-471b-48c0-a799-86d488b92b12)
![image](https://github.com/user-attachments/assets/55d0b6e8-46c2-4541-bafa-6aa68f54a510)



-Release Mechanism: The release mechanism works by using an electromagnetic clutch* to quickly connect or disconnect the winch from the motor. During energy storage, the motor—through the engaged clutch—pulls the UHMWPE line to stretch the carbon fiber strip and store elastic energy. When the target tension is reached, power to the clutch is cut, instantly disconnecting the winch from the motor. This allows the stored energy to be released rapidly, enabling the jump, while protecting the motor from any sudden forces or backlash during the release.

![image](https://github.com/user-attachments/assets/694cafcb-d208-42c9-b6f4-f1b8d906e2ee)
![image](https://github.com/user-attachments/assets/488834de-d14c-49c0-b084-9160e2fba12f)


-Design of Jump Energy Storage and Release: Utilizes a winch motor to tension a Ultra-high-molecular-weight polyethylene(UHMWPE) line attached to carbon fiber strips, storing elastic potential energy. 

![image](https://github.com/user-attachments/assets/f08731ea-73bc-4b44-99e7-35be05216e1c)
![image](https://github.com/user-attachments/assets/ce0810af-a8b4-4da1-b6ea-74f0b9d5a3af)


- Design of Gliding Mechanism: Wings are deployed at the apex of each jump, either by electronic control or mechanical triggering.
*An electromagnetic clutch engages or disengages power transmission between two shafts by using electromagnetic force. When current is applied, the clutch connects the shafts; when current is removed, the connection is released.

![image](https://github.com/user-attachments/assets/23fe3522-b2e0-4b5b-9c85-6e9ccd3a104b)
![image](https://github.com/user-attachments/assets/8002e049-6982-4139-b69c-9269329fd793)

![image](https://github.com/user-attachments/assets/1dbb64f0-a2ee-43ea-8911-7763eb12b03b)
![image](https://github.com/user-attachments/assets/e19473eb-4e7b-43fd-a649-bb6782251436)


# Ongoing efforts focus on: 
- Improving mechanical efficiency and alignment, 
- Optimizing the wing deployment strategy, 
- Designing and testing closed-loop feedback and control, 
- Validating the robot in more varied and realistic test scenarios.


Authors:
[RichardZZKK](url)
[llz077](url)
[Ianthomas-gee](url)
