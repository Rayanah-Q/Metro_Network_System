# 🚇 Metro_Network_System

A simplified metro transportation system built using C++ and linked list data structures.
This project allows managing a metro network by adding stations, connecting them, and transporting passengers across the network.


## 🎯 Objectives

	•	Build a dynamic metro network using linked lists
	•	Implement nested linked lists (stations → connections & passengers)
	•	Provide a user-friendly interface
	•	Enable shortest path calculation for navigation


## 📌 Features

	•	➕ Add new stations and expand the metro network
	•	🔗 Connect stations with routes (two-way connections)
	•	👤 Add passengers to stations
	•	🚆 Move passengers between stations
	•	📋 Display all stations and their passengers
	•	🧭 Find the shortest path between two stations



## 🛠️ Implementation Details

The project is built using classes, objects, structures, and linked lists.

**Data Structures:**

	•	Passenger	 → stores passenger ID, name, and next pointer (linked list of passengers).
	•	Connection	 → represents a route between two stations with distance and next pointer (linked list of connections).
	•	Station		 → stores station ID, name, connections, passengers, and pointer to next station (linked list of stations).

**Core Functions in metroNetwork Class:**

	•	addStation(int sid, string name) 						 → Add new station
	•	findStation(int sid)									 → Search station by ID
	•	connectStations(int sid1, int sid2, double distance)	 → Connect two stations
	•	addPassenger(int pid, string name, int sid)				 → Add passenger to a station
	•	movePassenger(int pid, int fromSid, int toSid)			 → Move passenger between stations
	•	displayStationsAndPassengers()							 → Show all stations and passengers
	•	findShortestPath(int startSid, int endSid)				 → Find shortest path using queue traversal


## 📂 Project Structure
```
📦 Metro-Network-System
 ┣ 📜 main.cpp          # Program entry with menu interface
 ┣ 📜 metroNetwork.h    # Class definition
 ┣ 📜 metroStructs.h	 # Structures definitions 
 ┣ 📜 metroNetwork.cpp  # Function implementations
 ┗ 📜 README.md         # Project documentation
```
## 📋 Menu Options

When running the program, you’ll see a menu:

===== Metro Network Menu =====
1. Add Station
2. Connect Stations
3. Add Passenger
4. Move Passenger
5. Display Stations and Passengers
6. Find Shortest Path
7. Exit


## ✅ Conclusion

This project demonstrates how linked lists can effectively model a metro system.
It provides flexibility for adding new stations, tracking passengers, and finding the shortest routes efficiently.


👩‍💻 Authors
	•	Rayanah Alqoblan
	•	Dalia Alharbi
	•	Reema Alharbi
	•	Shatha Al Dubaib
