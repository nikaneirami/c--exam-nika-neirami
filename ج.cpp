
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

string separateFirstWord(string& str) {
    string s = "";
    while (str[0] != ' ') {
        s = s + str[0];
        str = str.substr(1);
    }
    str = str.substr(1);
    return s;
}

void partC_1() {
    fstream file;
    file.open("Station.txt", ios::in);
    if (file.fail())
        cout << "FILE ERROR: Station.txt not found.\n";
    else {
        vector<string> city;
        vector<int> quakeNumber;
        string line;
        string str;
        while (getline(file, line)) {
            separateFirstWord(line);
            separateFirstWord(line);
            separateFirstWord(line);
            str = separateFirstWord(line);
            int cityIndex = -1;
            for (int i = 0; i < city.size(); i++) {
                if (city[i] == str)
                    cityIndex = i;
            }
            if (cityIndex == -1) {
                city.push_back(str);
                cityIndex = city.size() - 1;
            }
            int number = 0;
            while (line.size()) {
                separateFirstWord(line);
                number++;
            }
            if (cityIndex == city.size() - 1)
                quakeNumber.push_back(number);
            else
                quakeNumber[cityIndex] = quakeNumber[cityIndex] + number;
        }
        for (int i = 0; i < city.size(); i++)
            cout << "City: " << city[i] << "   Earth Quake Number: " << quakeNumber[i] << "\n";
        file.close();
    }
}

void partC_2() {
    fstream file;
    file.open("Station.txt", ios::in);
    if (file.fail())
        cout << "FILE ERROR: Station.txt not found.\n";
    else {
        string line;
        string str;
        float maxQuake = 0;
        Station maxStation;
        while (getline(file, line)) {
            string str1, str2, str3, str4;
            str1 = separateFirstWord(line);
            str2 = separateFirstWord(line);
            str3 = separateFirstWord(line);
            str4 = separateFirstWord(line);
            while (line.size()) {
                str = separateFirstWord(line);
                float quack = stof(str);
                if (quack > maxQuake) {
                    maxQuake = quack;
                    maxStation.set(str1, stod(str2), stod(str3), str4);
                }
            }
        }
        cout << "Max Quake = " << maxQuake << " -> ";
        maxStation.print();
        file.close();
    }
}

void partC_3() {
    fstream file;
    file.open("Station.txt", ios::in);
    if (file.fail())
        cout << "FILE ERROR: Station.txt not found.\n";
    else {
        string line;
        string str;
        float sumQuake = 0;
        while (getline(file, line)) {
            separateFirstWord(line);
            separateFirstWord(line);
            separateFirstWord(line);
            separateFirstWord(line);
            while (line.size()) {
                str = separateFirstWord(line);
                float quack = stof(str);
                sumQuake = sumQuake + quack;
            }
        }
        cout << "Sum of Quake = " << sumQuake << "\n";
        file.close();
    }
}

int main()
{
    partC_1();
    cout << "----------------------------------------\n";
    partC_2();
    cout << "----------------------------------------\n";
    partC_3();
}