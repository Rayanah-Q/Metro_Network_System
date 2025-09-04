#include "metroNetWork.h"
#include <iostream>
#include <string>
using namespace std;

metroNetWork::metroNetWork() {
	head = nullptr;
}

void metroNetWork::addStation(int sid, string name) {
	station* newStation = new station(sid, name);

	if (head == nullptr) {
		head = newStation;
	} else {
		station* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = newStation;
	}
}

station* metroNetWork::findStation(int sid) {
	station* temp = head;
	while (temp != nullptr) {
		if (temp->sid == sid)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

void metroNetWork::connectStations(int sid1, int sid2, double distance) {
	station* s1 = findStation(sid1);
	station* s2 = findStation(sid2);

	if (!s1 || !s2) {
		cout << "One of the stations is not found!" << endl;
		return;
	}

	// Connect s1 to s2
	connection* c1 = new connection(s2, distance);
	c1->next = s1->connections;
	s1->connections = c1;

	// Connect s2 to s1
	connection* c2 = new connection(s1, distance);
	c2->next = s2->connections;
	s2->connections = c2;
}

void metroNetWork::addPassenger(int pid, string name, int sid) {
	station* s = findStation(sid);
	if (!s) {
		cout << "Station is not found!" << endl;
		return;
	}

	passenger* newPassenger = new passenger(pid, name);
	newPassenger->next = s->passengers;
	s->passengers = newPassenger;
}

void metroNetWork::movePassenger(int pid, int fromSid, int toSid) {
	station* from = findStation(fromSid);
	station* to = findStation(toSid);
	if (!from || !to) {
		cout << "One of the stations is not found!" << endl;
		return;
	}

	passenger* previous = nullptr;
	passenger* current = from->passengers;

	while (current != nullptr && current->pid != pid) {
		previous = current;
		current = current->next;
	}

	if (!current) {
		cout << "Passenger not found in source station!" << endl;
		return;
	}

	// Remove passenger from source station
	if (previous)
		previous->next = current->next;
	else
		from->passengers = current->next;

	// Add passenger to destination station
	current->next = to->passengers;
	to->passengers = current;

	cout << "Passenger " << current->name << " moved from "
	     << from->name << " to " << to->name << endl;
}

// display all stations and their passengers
void metroNetWork::displayStationsAndPassengers() {
	station* currentStation = head;
	while (currentStation != nullptr) {
		cout << "Station ID: " << currentStation->sid << ", Name: " << currentStation->name << endl;

		passenger* currentPassenger = currentStation->passengers;
		if (!currentPassenger) {
			cout << "  No passengers at this station." << endl;
		} else {
			cout << "  Passengers:" << endl;
			while (currentPassenger != nullptr) {
				cout << "    ID: " << currentPassenger->pid << ", Name: " << currentPassenger->name << endl;
				currentPassenger = currentPassenger->next;
			}
		}

		cout << endl;
		currentStation = currentStation->next;
	}
}
void metroNetWork::findShortestPath(int startSid, int endSid) {
	const int MAX = 100;

	station* stations[MAX];
	bool visited[MAX] = { false };
	station* parent[MAX] = { nullptr };
	int count = 0;

	station* temp = head;
	while (temp != nullptr && count < MAX) {
		stations[count++] = temp;
		temp = temp->next;
	}

	int startIndex = -1, endIndex = -1;
	for (int i = 0; i < count; i++) {
		if (stations[i]->sid == startSid) startIndex = i;
		if (stations[i]->sid == endSid) endIndex = i;
	}

	if (startIndex == -1 || endIndex == -1) {
		cout << "Station not found.\n";
		return;
	}

	int queue[MAX];
	int front = 0, rear = 0;

	queue[rear++] = startIndex;
	visited[startIndex] = true;
	parent[startIndex] = nullptr;

	bool found = false;

	while (front < rear) {
		int currentIndex = queue[front++];
		station* currentStation = stations[currentIndex];

		if (currentIndex == endIndex) {
			found = true;
			break;
		}

		connection* conn = currentStation->connections;
		while (conn != nullptr) {
			int neighborIndex = -1;
			for (int i = 0; i < count; i++) {
				if (stations[i] == conn->destStation) {
					neighborIndex = i;
					break;
				}
			}

			if (neighborIndex != -1 && !visited[neighborIndex]) {
				visited[neighborIndex] = true;
				parent[neighborIndex] = currentStation;
				queue[rear++] = neighborIndex;
			}

			conn = conn->next;
		}
	}

	if (!found) {
		cout << "No path found between the stations." << endl;
		return;
	}

	station* path[MAX];
	int pathLen = 0;
	station* current = stations[endIndex];
	while (current != nullptr && pathLen < MAX) {
		path[pathLen++] = current;

		for (int i = 0; i < count; i++) {
			if (stations[i] == current) {
				current = parent[i];
				break;
			}
		}
	}

	cout << "Shortest Path: ";
	for (int i = pathLen - 1; i >= 0; i--) {
		cout << path[i]->name;
		if (i != 0) cout << " -> ";
	}
	cout << endl;
}