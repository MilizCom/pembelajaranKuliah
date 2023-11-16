#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <mmsystem.h>
using namespace std;

int HH = 0, MM = 0, SS = 0;

int main() {
	
    cout << "Masukkan mulai dari mana?" << endl;
    cout << "Jam: ";
    cin >> HH;
    cout << "Menit: ";
    cin >> MM;
    cout << "Detik: ";
    cin >> SS;

    do {
        system("CLS");
        cout << "\nStopwatch";
        cout << "\nHH:MM:SS";
        cout << "\n" << HH << " : " << MM << " : " << SS;
        cout << "\nTekan tombol apa saja untuk memulai";
        _getch();

        while (!kbhit()) {
            SS--;
            Sleep(1000);
            if (SS < 0) {
                MM--;
                SS = 59;
            }
            if (MM < 0) {
                HH--;
                MM = 59;
            }

            system("CLS");
            cout << "\nStopwatch";
            cout << "\nHH:MM:SS";
            cout << "\n" << HH << " : " << MM << " : " << SS;
        

        if (HH == 0 && MM == 0 && SS == 0) {
            cout << "File sedang diputar....\n";
            time_t t1 = time(0);
            mciSendString("open \"C:/Users/Axioo Pongo/Downloads/Music/tension-113661.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
            mciSendString("play mp3", NULL, 0, NULL);
            Sleep(10000);  // Sleep selama 10 detik untuk memainkan musik
            mciSendString("stop mp3", NULL, 0, NULL);
            mciSendString("close mp3", NULL, 0, NULL);
            time_t t2 = time(0);
            cout << "Durasi permainan: " << t2 - t1 << " detik." << endl;
           
        }
}
    } while (true);

    return 0;
}
