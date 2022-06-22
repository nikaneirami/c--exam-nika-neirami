#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Station {
    string name;
    double x;
    double y;
    string city;
    vector<float> quake;
public:
    Station() {
        name = "";
        x = 0;
        y = 0;
        city = "";
    }
    void set(string n, double xx, double yy, string c) {
        name = n;
        x = xx;
        y = yy;
        city = c;
    }
    void setEarthQuake(float q) {
        quake.push_back(q);
    }
    string getName() {
        return name;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    string getCity() {
        return city;
    }
    int getQuakeSize() {
        return quake.size();
    }
    float getQuakeInIndex(int index) {
        return quake[index];
    }
    void print() {
        cout << name << " " << x << " " << y << " " << city << "\n";
    }
};

void partA(Station stations[], int size) {
    fstream file;
    file.open("Station.txt", ios::out);
    for (int i = 0; i < size; i++) {
        file << stations[i].getName() << " " << stations[i].getX() << " " << stations[i].getY() << " " << stations[i].getCity() << " ";
        for (int j = 0; j < stations[i].getQuakeSize(); j++)
            file << stations[i].getQuakeInIndex(j) << " ";
        file << "\n";
    }
    file.close();       
}

int main()
{
    //Define an array for stations with constant values.
    ///*
    Station stations[7];
    stations[0].set("Alpha", 1515, 7789, "Tehran");
    stations[0].setEarthQuake(3.4);
    stations[0].setEarthQuake(5.7);
    stations[0].setEarthQuake(1.2);
    stations[0].setEarthQuake(2.4);
    stations[0].setEarthQuake(3.1);
    stations[0].setEarthQuake(4.2);
    stations[1].set("Beta", 1003, 9238, "Bam");
    stations[1].setEarthQuake(0.8);
    stations[1].setEarthQuake(2.8);
    stations[1].setEarthQuake(4.6);
    stations[2].set("Gamma", 7945, 1210, "Kermanshah");
    stations[2].setEarthQuake(1.6);
    stations[2].setEarthQuake(3.1);
    stations[2].setEarthQuake(3.0);
    stations[2].setEarthQuake(1.7);
    stations[3].set("Delta", 230, 856, "Bam");
    stations[3].setEarthQuake(2.0);
    stations[3].setEarthQuake(2.1);
    stations[4].set("Epsilon", 2541, 7854, "Roodbar");
    stations[4].setEarthQuake(3.5);
    stations[4].setEarthQuake(3.6);
    stations[4].setEarthQuake(4.1);
    stations[4].setEarthQuake(4.0);
    stations[5].set("Zeta", 9856, 1241, "Ahvaz");
    stations[5].setEarthQuake(1.9);
    stations[5].setEarthQuake(2.8);
    stations[6].set("Eta", 1032, 7784, "Tehran");
    stations[6].setEarthQuake(3.1);
    stations[6].setEarthQuake(1.6);
    stations[6].setEarthQuake(2.9);

    partA(stations, 7);
    //*/
    //=============================================================================
    //Reading stations information from console.
    /*    
    int size = 0;
    cout << "Enter the number of stations: ";
    cin >> size;
    Station* stationArray = new Station[size];
    for (int i = 0; i < size; i++) {
        string name = "";
        double x = 0;
        double y = 0;
        string city = "";
        cout << "Enter name of staion: ";
        cin >> name;
        cout << "Enter X of staion: ";
        cin >> x;
        cout << "Enter Y of staion: ";
        cin >> y;
        cout << "Enter city of staion: ";
        cin >> city;
        stationArray[i].set(name, x, y, city);
        int quakeNumber;
        cout << "Enter the number of quack: ";
        cin >> quakeNumber;
        for (int j = 0; j < quakeNumber; j++) {
            float q;
            cout << "Enter quake: ";
            cin >> q;
            stationArray[i].setEarthQuake(q);
        }
        cout << "\n";
    }

    partA(stationArray, size);
    */
}