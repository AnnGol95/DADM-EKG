#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class ValueGet {
public:
	int data;
	ValueGet() {
		data = 0;
	}
	void ChooseData(int data1);
};
void ValueGet::ChooseData(int data1) {
	data1 = 0;
};

class ShowData : public ValueGet {
public:
	void Showchart(int data1);
};
void ShowData::Showchart(int data1) {

};

class CreateReport : public ValueGet {
public:
	void report(int data1);
};
void CreateReport::report(int data1) {

};
// czy stosowac funkcje wirtualne i tworzyc w klasie bazowej np virtual double getResult() 
//czy tak jak jest teraz
//w klasie pochodnej zmienia siê (nadpisuje sie) treœæ metod (zdefiniowanych jako „wirtualne”)
class R_PEAKS {
protected:
	int ecg;
public:
	void setData(int data);
	int getR_PEAKS();
};
void R_PEAKS::setData(int data) {
	ecg = data;
};
int R_PEAKS::getR_PEAKS() {
	return ecg = ecg + 1;
};

class HRV1 : public R_PEAKS {
public:
	HRV1();
	double getHRV1();
};
double HRV1::getHRV1() {
	return ecg;
};
class HRV2 : public R_PEAKS {
public:
	double getHRV2();
};
double HRV2::getHRV2() {
	return ecg;
};

class HRV_DFA : public R_PEAKS {
public:
	void getHRV_DFA();
};
void HRV_DFA::getHRV_DFA(){
};

class ECG_BASELINE : public R_PEAKS {
public:
	void getECG_BASELINE();
};
void ECG_BASELINE::getECG_BASELINE() {

};

class WAVES : public R_PEAKS {
public:
	void getWAVES();
};
void WAVES::getWAVES() {

};



	int main()
{
	string filename;
	//ValueGet vg;
	ShowData sd;
	ValueGet* vg;
	vg = &sd;


	ifstream fileC;
	cout << "Give the name of the file to open:";
	cin >> filename;

	fileC.open(filename.c_str(), fstream::binary | fstream::out); // Opens a file in binary mode for input operations i.e., getting data from file.
	if (!fileC)
		cout << "File Not Found." << endl;
	else {
		fileC.seekg(0); // To make sure that the data is read from the starting position of the file.
		while (fileC.read((char*)&sd, sizeof(sd))) // Iterates through the file till the pointer reads the last line of the file.
			cout << sd.data << endl;//sd dziedziczy konstruktor z vg
	}
	//system("pause");


	return 0;
}