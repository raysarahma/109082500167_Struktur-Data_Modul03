#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[15];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs) << endl;
    return 0;
}

void inputMhs(mahasiswa &m){
    cout << "input nim = ";
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;
}