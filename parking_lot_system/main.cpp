#include <bits/stdc++.h>
using namespace std;



class Vehicle {
protected:
    string licensePlate;
    int size;
public:
    virtual int getSize() = 0;
    virtual string getLicensePlate() = 0;
};

class Car: public Vehicle {
    public:
        Car(string plate) {
            licensePlate = plate;
            size = 2;
        }

        int getSize() override { return size; }
        string getLicensePlate() override { return licensePlate; }
};

class Bus: public Vehicle {
    public:
        Bus(string plate) {
            licensePlate = plate;
            size = 4;
        }

        int getSize() override { return size; }
        string getLicensePlate() override { return licensePlate; }
};

class ParkingSpot {
private:
    Vehicle* vehicle;
    bool occupied;
public:
    ParkingSpot() : vehicle(nullptr), occupied(false) {}
    bool isOccupied() { return occupied; }
    void parkVehicle(Vehicle* v) {
        vehicle = v;
        occupied = true;
    }
    void removeVehicle() {
        vehicle = nullptr;
        occupied = false;
    }
};


class Level {
    private:
        vector<ParkingSpot> spots;

    public:
        Level(int numOfSpots) {
            for(int i=0;i<numOfSpots;i++) {
                spots.push_back(ParkingSpot());
            }
        }
        int canPark(Vehicle *v) {
            int freeAvailableSpots = 0;
            for(int i=0;i<spots.size();i++) {
                if(!this->spots[i].isOccupied()) {
                    freeAvailableSpots++;
                } 
                else {
                    freeAvailableSpots = 0;
                }
                if(v->getSize() == freeAvailableSpots) {
                    fillSpots(i-freeAvailableSpots, i, v);
                    return i-v->getSize()+1;
                }
            }
            return -1;
        }

        void fillSpots(int start, int end, Vehicle *v) {
            for(int i=start;i<=end;i++) {
                spots[i].parkVehicle(v);
            }
            return;
        }
};


class ParkingLot {
    private:
        vector<Level> levels;
    public:
        ParkingLot(int numOfLevels, vector<int> numOfSpotsPerLevel) {
            for(int i=0; i<numOfLevels; i++) {
                levels.push_back(Level(numOfSpotsPerLevel[i]));
            }
        }

        pair<int, int> parkVehicle(Vehicle *v) {
            for(int i=0;i<levels.size();i++) {
                int spot = levels[i].canPark(v);
                if(spot != -1) return {i, spot};
            }
            return {-1,-1};
        }
};

int main() {
    ParkingLot parkingLot(2, {5, 10}); // 2 levels with 5 and 10 spots
    Car car1("ABC123"); // Creating a car with license plate "ABC123"
    Car car2("XYZ456"); // Creating another car with license plate "XYZ456"
    Bus bus1("DL9CBD"); // Creating another car with license plate "XYZ456"

    // Parking car1
    pair<int,int> parkingSpot = parkingLot.parkVehicle(&car1);
    cout<<"Spot for car "<<car1.getLicensePlate()<<" is on level "<<parkingSpot.first+1<<" at spot no. "<<parkingSpot.second+1<<endl;

    // Parking bus1
    parkingSpot = parkingLot.parkVehicle(&bus1);
    cout<<"Spot for bus "<<bus1.getLicensePlate()<<" is on level "<<parkingSpot.first+1<<" at spot no. "<<parkingSpot.second+1<<endl;

    // Parking car2
    parkingSpot = parkingLot.parkVehicle(&car2);
    cout<<"Spot for car "<<car2.getLicensePlate()<<" is on level "<<parkingSpot.first+1<<" at spot no. "<<parkingSpot.second+1<<endl;


    return 0;
}