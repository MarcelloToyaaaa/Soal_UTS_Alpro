#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    system ("cls");
        int n, a = 0, b = 0, streakA = 0, streakB = 0;
        string s;
    
        cin >> n >> s;
    
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a += 3;
                streakA++; streakB = 0;
                if (streakA == 3) { a += 2; streakA = 0; }
            } else if (s[i] == 'B') {
                b += 3;
                streakB++; streakA = 0;
                if (streakB == 3) { b += 2; streakB = 0; }
            } else {
                a++; b++;
                streakA = streakB = 0;
            }
        }
    
        cout << "Poin A: " << a << endl;
        cout << "Poin B: " << b << endl;
    
        if (a > b) cout << "Pemenangnya adalah pemain A\n";
        else if (b > a) cout << "Pemenangnya adalah pemain B\n";
        else cout << "Hasil pertandingan Seri!\n";
    
        return 0;
    }

/*
Penjelasan langkah:

1. Input jumlah babak (n) dan string hasil tiap babak (s).
2. Loop setiap babak:
   - Kalau A menang: tambah 3 poin ke A, hitung streak A, reset streak B.
   - Kalau B menang: tambah 3 poin ke B, hitung streak B, reset streak A.
   - Kalau seri (C): tambah 1 ke A dan B, reset kedua streak.
3. Kalau streak salah satu pemain sampai 3: kasih bonus 2 poin, lalu reset streak.
4. Setelah semua babak, tampilkan poin A dan B.
5. Bandingkan poin buat tentukan siapa pemenangnya atau seri.
*/