#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> generateSensorData(int jumlah_jari) {
    vector<int> data;
    for (int i = 0; i < jumlah_jari; i++) {
        data.push_back(rand() % 100 + 1);
    }
    return data;
}

void saveToFile(const vector<int>& data, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            file << "Jari " << i + 1 << ": " << data[i] << "\n";
        }
        file.close();
        cout << "Data berhasil disimpan di " << filename << endl;
    } else {
        cout << "Error: Gagal membuka file!" << endl;
    }
}

int main() {
    srand(time(0));
    vector<int> sensorData = generateSensorData(5);

    cout << "Menyimpan data sensor...\n";
    saveToFile(sensorData, "data_sensor.txt");

    return 0;
}
