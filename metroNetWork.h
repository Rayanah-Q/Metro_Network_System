#include <iostream>
#include <string>
#include <metroStructs.h>
using namespace std;

class metroNetWork {
private:
	station* head;

public:
	metroNetWork();
	void addStation(int sid, string name);
	void connectStations(int sid1, int sid2, double distance);
	station* findStation(int sid);
	void addPassenger(int pid, string name, int sid);
	void movePassenger(int pid, int fromSid, int toSid);
	void displayStationsAndPassengers();
	void findShortestPath(int startID, int endID);
};