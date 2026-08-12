/*
 * main.cpp
 *
 *  Created on: 2026/07/08
 *      Author: shun
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

struct ECGData
{
	string name;
	int heartRate;
	int highBP;
	int lowBP;
};

ECGData readCSV()
{
	ECGData data;
	
	
　　// Git練習用に変更
  
  
   // ecg-chartブランチでの練習
	ifstream file("ecg.csv");

	if (!file)
	{
		cout << "CSVファイルが開けません" << endl;
		exit(1);
	}

	string line;
	getline(file, line);

	stringstream ss(line);

	string heartRate;
	string highBP;
	string lowBP;

	getline(ss, data.name, ',');
	getline(ss, heartRate, ',');
	getline(ss, highBP, ',');
	getline(ss, lowBP);

    data.heartRate = stoi(heartRate);
    data.highBP = stoi(highBP);
    data.lowBP = stoi(lowBP);

    return data;
}

void display(ECGData data)
{
	cout << "====================" << endl;
	cout << "    心電図モニター    " << endl;
	cout << "====================" << endl;
	cout << endl;
	cout << "患者名:" << data.name << endl;
	cout << "心拍数" << data.heartRate << " bpm" << endl;
	cout << "血圧" << data.highBP << "/" << data.lowBP << " mmHg" << endl;
	cout << endl;
	cout << "====================" << endl;
}

int main()
{
	while(true)
	{
		ECGData data = readCSV();

		display(data);

		// 待ち
		this_thread::sleep_for(chrono::seconds(1));
		cout << string(50, '\n');
	}

	return 0;
}

