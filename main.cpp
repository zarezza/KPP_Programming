// NAMA		: Naufal Ahmad Fahreza
// NRP		: 5025221079
// Jurusan	: Teknik Informatika

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 // jujur masih belum mengerti ini maksudnya apa jadi tidak saya pakai
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int jarak, int loss) { 
    int res = jarak - loss;
    return res;
}

double speed_dgn_loss(int speed) { //constrain tabel
    int res = 0;
    if (speed >= 1 && speed <= 10) {
        res = 1;
    }else if (speed >= 11 && speed <=20) {
        res = 3;
    }else if (speed >= 21 && speed <= 30) {
        res = 5;
    }
    return res;
}

int main() {
    /* tulis kode utama kalian disini */
    int input, hasil1, vLoss; 
    double hasil2;
    std::cin >> input;

    vLoss = (int) pow(mencari_V0(input, speed_dgn_loss(input)),2); //cari v0 loss
    hasil1 = vLoss * sin(3.14*2*SUDUT/180)/GRAVITASI; // v0^2 * sin(2.45˚)/g
    hasil2 = sqrt(hasil1*GRAVITASI/sin(3.14*2*SUDUT/180)) + speed_dgn_loss(input); // modifikasi rumus hasil1 (yang di cari v, bukan jarak)

    std::cout << hasil1 << " " << hasil2 << std::endl; // hasil1 = jarak, hasil2 = vTangensial robot

    return 0;
}