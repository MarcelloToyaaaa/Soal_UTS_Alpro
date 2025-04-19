#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    system ("cls");
    long long kode;
    int d[8], jenis_hari, jenis_member, jumlah, poin;
    string hari, member;

    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    for (int i = 7; i >= 0; i--) {
        d[i] = kode % 10;
        kode /= 10;
    }

    jenis_hari = d[0] * 10 + d[1];
    jenis_member = d[2] * 10 + d[3];
    jumlah = d[4] * 1000 + d[5] * 100 + d[6] * 10 + d[7];

    if (jenis_hari == 1) hari = "Hari kerja";
    else if (jenis_hari == 2) hari = "Akhir pekan";
    else if (jenis_hari == 3) hari = "Hari libur nasional";
    else {
        cout << "Jenis hari tidak valid\n";
        return 0;
    }

    if (jenis_member == 1) member = "Pelanggan biasa";
    else if (jenis_member == 2) member = "Member silver";
    else if (jenis_member == 3) member = "Member gold";
    else {
        cout << "Jenis member tidak valid\n";
        return 0;
    }

    if (jenis_hari == 1) {
        if (jenis_member == 1) poin = jumlah * 1;
        else if (jenis_member == 2) poin = jumlah * 2;
        else poin = jumlah * 3;
    } else if (jenis_hari == 2) {
        if (jenis_member == 1) poin = jumlah * 2;
        else if (jenis_member == 2) poin = jumlah * 3;
        else poin = jumlah * 5;
    } else {
        if (jenis_member == 1) poin = jumlah * 3;
        else if (jenis_member == 2) poin = jumlah * 5;
        else poin = jumlah * 7;
    }

    cout << "\n--- Ringkasan Transaksi ---\n";
    cout << "Jenis hari      : " << hari << endl;
    cout << "Jenis pelanggan : " << member << endl;
    cout << "Jumlah belanja  : Rp " << jumlah * 100000 << endl;
    cout << "Total poin      : " << poin << endl;

    return 0;
}

/*
Penjelasan logika:

1. Input kode transaksi 8 digit.
2. Pecah kode jadi array digit (biar gampang ambil masing-masing bagian).
3. Ambil jenis hari dari 2 digit pertama → tentukan nama hari.
4. Ambil jenis member dari 2 digit berikutnya → tentukan tipe pelanggan.
5. Ambil 4 digit terakhir sebagai jumlah kelipatan Rp100.000.
6. Hitung total poin berdasarkan kombinasi jenis hari dan jenis member.
7. Tampilkan semua info lengkap: hari, member, total belanja, dan poin.
*/