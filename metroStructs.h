#include <iostream>
#include <string>
using namespace std;

struct station {
	int sid;
	string name;
	connection* connections;
	passenger* passengers;
	station* next;

	station(int sid, const string& name) : sid(sid), name(name), connections(nullptr), passengers(nullptr), next(nullptr) {}
};

struct passenger {
	int pid;
	string name;
	passenger* next;

	passenger(int pid, const string& name): pid(pid), name(name), next(nullptr) {}
};

struct connection {
	station* destStation;
	double distance;
	connection* next;

	connection(station* dest, double dist) : destStation(dest), distance(dist), next(nullptr) {}
};