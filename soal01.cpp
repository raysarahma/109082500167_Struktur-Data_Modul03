#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungAkhir(float uts, float uas, float tugas){
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main()
{
    mahasiswa mhs[10];
    int jumlah;

    cout << "Jumlah mahasiswa (maks 10) : ";
    cin >> jumlah;

    if (jumlah > 10) {
        jumlah = 10;
        cout << "Maksimal 10, jumlah diubah jadi 10" << endl;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = hitungAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\nData Mahasiswa" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << mhs[i].nama << " - " << mhs[i].nim
             << " - UTS " << mhs[i].uts
             << ", UAS " << mhs[i].uas
             << ", Tugas " << mhs[i].tugas
             << ", Nilai Akhir " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}