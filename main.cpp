#include <iostream>
#include <string>
#include "metroStructs.h"
#include "metroNetWork.h"
using namespace std;

int main() {
	metroNetWork metro;
	int choice;
	cout << "\n====== Metro Network Menu ======\n";
	cout << "1. Add Station\n";
	cout << "2. Add Passenger\n";
	cout << "3. Connect Stations\n";
	cout << "4. Find Shortest Path\n";
	cout << "5. Move Passenger\n";
	cout << "6. Display Stations and Passengers\n";
	cout << "7. Exit\n";


	do {
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			int id;
			string name;
			cout << "Enter station ID: ";
			cin >> id;
			cout << "Enter station name: ";
			cin.ignore();
			getline(cin, name);
			metro.addStation(id, name);
			break;
		}

		case 2: {
			int pid, sid;
			string name;
			cout << "Enter passenger ID: ";
			cin >> pid;
			cout << "Enter passenger name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter station ID: ";
			cin >> sid;
			metro.addPassenger(pid, name, sid);
			break;
		}

		case 3: {
			int id1, id2;
			double distance;
			cout << "Enter first station ID: ";
			cin >> id1;
			cout << "Enter second station ID: ";
			cin >> id2;
			cout << "Enter distance between them: ";
			cin >> distance;
			metro.connectStations(id1, id2, distance);
			break;
		}

		case 4: {
			int startID, endID;
			cout << "Enter start station ID: ";
			cin >> startID;
			cout << "Enter end station ID: ";
			cin >> endID;
			metro.findShortestPath(startID, endID);
			break;
		}

		case 5: {
			int pid, fromID, toID;
			cout << "Enter passenger ID: ";
			cin >> pid;
			cout << "Enter current station ID: ";
			cin >> fromID;
			cout << "Enter destination station ID: ";
			cin >> toID;
			metro.movePassenger(pid, fromID, toID);
			break;
		}

		case 6: {
			metro.displayStationsAndPassengers();
			break;
		}

		case 7: {
			cout << "Exiting program. Goodbye!\n";
			break;
		}

		default: {
			cout << "Invalid choice. Please try again.\n";
		}
		}
	} while (choice != 7);

	return 0;
}