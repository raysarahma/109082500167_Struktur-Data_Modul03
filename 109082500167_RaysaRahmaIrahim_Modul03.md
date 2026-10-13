# <h1 align="center"> Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>

<p align="center"> Raysa Rahma Irahim - 109082500167 </p>

## Dasar Teori
### A. Konsep Abstract Data Type (ADT)<br/>
ADT adalah tipe data yang dilengkapi sekumpulan operasi dasar (primitif) untuk mengolah data tersebut [1][3].
### 1. Pengertian ADT<br/>
ADT terdiri dari sebuah type dan primitif yang berlaku pada type itu. ADT yang lengkap juga punya invarian dan aksioma, dan bersifat statis [3]. Dengan ADT, data dan operasinya dikelompokkan dalam satu kesatuan sehingga program lebih terstruktur [1].
### 2. Tipe Data dan Primitif pada ADT<br/>
Di C++, type dibuat dengan struct, sedangkan primitif dibuat dalam bentuk fungsi atau prosedur [3].
### 3. Jenis-Jenis Primitif<br/>
Jenis primitif antara lain konstruktor/kreator (biasanya diawali Make atau create), selector (diawali Get), prosedur pengubah nilai, validator, destruktor, baca/tulis, operator relasional, aritmatika, dan konversi tipe [3].

### B. Implementasi ADT<br/>
ADT di C++ diterapkan dengan struct sebagai type serta fungsi dan prosedur sebagai operasinya, lalu dipisah ke beberapa file agar program lebih teratur [3].
### 1. Struct sebagai Tipe Data <br/>
Struct adalah tipe data bentukan yang menyimpan beberapa data dengan tipe berbeda dalam satu nama. Struct juga bisa dibuat array untuk menyimpan banyak data sekaligus (array of struct) [2].
### 2. Fungsi dan Prosedur sebagai Primitif <br/>
Fungsi mengembalikan sebuah nilai, sedangkan prosedur (void) tidak mengembalikan nilai [2]. Pada ADT, keduanya dipakai sebagai primitif.
### Pemisahan File .h dan .cpp <br/>
File .h berisi definisi type dan header fungsi, file .cpp berisi realisasi fungsinya, dan main.cpp berperan sebagai driver [3]. Header diberi #ifndef, #define, dan #endif supaya tidak ter-include dua kali.

## Guided

### GUIDE 1

```C++
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
```

penjelasan singkat guided 1 : Program ini membuat type mahasiswa dengan field nim, nilai1, dan nilai2. Prosedur inputMhs memakai parameter by reference (&m) supaya data yang diinput tersimpan di variabel mhs pada main. Fungsi rata2 menghitung rata-rata dua nilai dan hasilnya diubah ke float supaya tidak dibulatkan seperti pembagian integer. Pada contoh ini type, primitif, dan program utama masih ada dalam satu file.

### GUIDE 2

### mahasiswa.h
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```
### mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
}
```

### main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs) << endl;
    return 0;
}
```

penjelasan singkat guided 2 : Program guided 1 dipisah menjadi tiga file sesuai konsep ADT. mahasiswa.h berisi definisi type dan header fungsi, mahasiswa.cpp berisi realisasi fungsinya, dan main.cpp sebagai driver. File buatan sendiri di-include dengan tanda kutip ("mahasiswa.h"). Hasil outputnya sama dengan guided 1.


## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.


```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/raysarahma/109082500167_Struktur-Data_Modul03/blob/main/output/outputsoal01_1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/raysarahma/109082500167_Struktur-Data_Modul03/blob/main/output/outputsoal01(JAM).png)

penjelasan unguided 1 : Program ini memakai struct mahasiswa dan array mhs[10] untuk menyimpan data mahasiswa. Jika jumlah yang diinput lebih dari 10, jumlahnya otomatis dibatasi menjadi 10. Nama dibaca dengan getline supaya nama yang ada spasinya bisa tersimpan, dan cin.ignore() dipakai untuk membuang enter yang tersisa dari input sebelumnya. Nilai akhir dihitung oleh fungsi hitungAkhir dengan rumus 0.3uts + 0.4uas + 0.3tugas, lalu semua data ditampilkan. Contohnya untuk Budi: 0.380 + 0.485 + 0.390 = 24 + 34 + 27 = 85.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”: Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp” Cobalah hasil implementasi ADT pada file “main.cpp”

### pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```
### pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel){
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### soal02main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/raysarahma/109082500167_Struktur-Data_Modul03/blob/main/output/outputsoal02.png)

penjelasan unguided 2 : Pada unguided 2, ADT pelajaran dibuat dalam tiga file. pelajaran.h berisi type pelajaran (namaMapel dan kodeMapel) serta deklarasi primitif. Fungsi create_pelajaran berperan sebagai konstruktor yang membentuk nilai bertipe pelajaran dari dua string, sedangkan prosedur tampil_pelajaran menampilkan isinya. main.cpp hanya memanggil primitif tersebut. Tulisan "nilai : " pada output sengaja disamakan dengan contoh output di modul, padahal yang ditampilkan adalah kode mapel.

### 3. Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom){
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    int baris, kolom;

    cout << "Array A :" << endl;
    tampilArray(A);
    cout << "Array B :" << endl;
    tampilArray(B);

    cout << "\nTukar posisi (baris kolom) : ";
    cin >> baris >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi di luar array" << endl;
    } else {
        tukarArray(A, B, baris, kolom);
        cout << "\nSetelah ditukar" << endl;
        cout << "Array A :" << endl;
        tampilArray(A);
        cout << "Array B :" << endl;
        tampilArray(B);
    }

    cout << "\nSebelum tukar pointer : " << *p1 << " " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Setelah tukar pointer : " << *p1 << " " << *p2 << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/raysarahma/109082500167_Struktur-Data_Modul03/blob/main/output/outputsoal03.png)

penjelasan unguided 3 : Program ini memakai dua array 2D A dan B berukuran 3x3 dan dua pointer integer p1 dan p2 yang menunjuk ke variabel x dan y. Fungsi tampilArray menampilkan isi array memakai dua perulangan for. Fungsi tukarArray menukar elemen pada posisi (baris, kolom) yang diinput antara array A dan B. Karena array dikirim ke fungsi sebagai alamat, perubahan di dalam fungsi langsung mengubah array aslinya. Fungsi tukarPointer menukar nilai yang ditunjuk kedua pointer memakai operator *, sehingga nilai x dan y ikut tertukar. Pada posisi (0, 2), angka 3 di array A tertukar dengan angka 7 di array B.

## Kesimpulan
Dari praktikum modul 3 ini saya belajar bahwa Abstract Data Type (ADT) adalah cara menyusun program dengan menggabungkan sebuah type beserta operasi dasarnya (primitif). Di C++, ADT diterapkan dengan memisahkan program menjadi file header (.h) untuk definisi type dan deklarasi fungsi, file .cpp untuk realisasi fungsi, dan main.cpp sebagai driver, sehingga kode lebih rapi dan bisa dipakai ulang. Dari latihan saya juga memahami penggunaan struct dengan array untuk menyimpan banyak data, perbedaan pass by value, by reference, dan by pointer, serta cara kerja array 2D dan pointer untuk menukar nilai.

## Referensi
[1] Rahman, S., Hartono, Joni, Dafitri, H., Tanjung, J. P., & Chiuloto, K. (2025). Struktur Data dan Algoritma: Pendekatan Visual dan Praktis dalam C++. Medan: Universitas Medan Area Press. Diakses melalui https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf.<br/>
[2] Budiman, Alamsyah, N., & Al Rasyid, A. (2023). Buku Ajar Pemrograman C++. Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/531/1/PEMROGRAMAN%20C%2B%2B.pdf.<br/>
[3] Telkom University. (2023). Modul 3 Abstract Data Type (ADT), Modul Praktikum Struktur Data. Fakultas Informatika, Telkom University.<br/>