# Density-Based-Traffic-Control-System-With-Emergency-Vehicle-Override-using-Arduino

Designed to be implemented in places nearing the junctions where the traffic signals are placed, in order to reduce the congestion in these junctions. It keeps a track of the vehicles in each road and accordingly adjusts the time for each traffic light signals. The higher the number of vehicles on the road the longer will be the time delay allotted for that corresponding traffic light signal.
 
The proposed system is to constantly monitor the vehicle density present in all parts of the road at the junction and also o focusing on giving priority to emergency vehicles like ambulance. The basic flow of operation is as follows: collection of vehicle density data from the roads; next is to send the same data to the device which com pares the same and arrives at a particular characteristic output pattern; then the execution of the output pattern which is reflected in the signal pattern. In this mode, On each road of the crossroad, two IR sensors are connected, acting as receiver and transmitter each. One sensor is interfaced at the very starting of that road, and the other one at some distance apart. Density of vehicles can be measured in this way. If on a particular road, both these sensors are detected to be high, that means the density of vehicles is maximum and traffic has reached it’s limit. When density is detected it sends a triggered output to Arduino Mega (ATmega 2560) which is the heart of the project. Then Arduino analyses the number of such triggered outputs from the set of sensors placed in the different roads at the junction and which road is to be given the highest priority and correspondingly triggers the different LED lights in the signals in order to felicitate the vehicle movement with the longest time delay for the corresponding lane. The time delay in the traffic signal is set based on the density of vehicles on the roads Thus, that road will be given a green signal. Priorities are assigned in this manner and according to them the assigned roads will open. For emergency vehicle detection sound sensor is used at each lane to detect the sound of the siren so that such vehicles are given priority and they don’t need to wait. When siren sound is detected an emergency light is turned ON indicating the presence of emergency in that particular lane and along with emergency light, the control signal turns on the green light for that lane, turning all the signals of other lanes to be red providing an emergency override. The sound sensor is given a higher priority than the IR sensor.

Block Diagram:

![image](https://user-images.githubusercontent.com/85994661/132083172-050a93a1-ec8d-4a81-8c8d-ab65e0a10171.png)

Road junction layout and possible movement of vehicles:

![image](https://user-images.githubusercontent.com/85994661/132083198-ade84515-1e75-4b54-ab71-70c262348ed1.png)

Hardware Used:

1. IR Sensor module
2. Sound sensor- LM386
3. Light emitting diodes(LEDs)
4. Arduino Mega 2560

Work Flow diagram :

![image](https://user-images.githubusercontent.com/85994661/132083252-bd8580d1-6014-4a30-bb1f-0f21191af9bf.png)


Flowchart of the proposed model:

![image](https://user-images.githubusercontent.com/85994661/132083271-55eca1ff-84f8-4d69-8f96-a2ce5fbb34ab.png)





