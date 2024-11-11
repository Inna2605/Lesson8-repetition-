/*1. Написати функцію, яка приймає дві дати (тобто функція приймає шість параметрів) 
та обчислює різницю в днях між цими датами. 
Для виконання цього завдання необхідно також написати функцію, яка визначає, чи є рік високосним.
2. Написати функцію, що визначає середнє арифметичне елементів переданого їй масиву.
3. Написати функцію, що визначає кількість додатних, від'ємних і нульових елементів переданого їй масиву.*/

#include<iostream> 
#include<stdlib.h>
#include<time.h>

#define Show(H)cout << H;
#define Default cout << "Ne virno obranui variant!\n\n";

using namespace std;

inline void Vubir_zadachi();
inline int Vvod_chisla();
inline char Vvod_sumbola();
void Switch(int n); 
int Perevirka_na_vusokosnui_rik(int r);
int Fevral_v_zaleznosti_vid_vusokosnogo_roky(int r);
int Pidraxynok_misaciv_dniv_za_rik(int d, int m, int r);
int Riznuca_miz_datamu(int md1, int md2, int r1, int r2);
void Random();
void Randomnui_masuv(int Array[], int n);
void Show_masuv(int Array[], int n);
float Znaxodzenna_serednogo_arefmetuchnogo(int arr[], int n);
int Kilkist_dodatnux(int arr[], int n);
int Kilkist_nulovux(int arr[], int n);
int Kilkist_videmnux(int arr[], int n);

int main() {
	Vubir_zadachi();
	int a = Vvod_chisla();
	Switch(a);
	Show('\n');
}
void Kilkist_dodatnux_nulovux_videmnux_elementiv() {
	//3. Написати функцію, що визначає кількість додатних, від'ємних і нульових елементів переданого їй масиву.
	const int N = 20;
	int Arr[N];
	Randomnui_masuv(Arr, N);
	Show_masuv(Arr, N);
	Show('\n');
	int d = Kilkist_dodatnux(Arr, N);
	int n = Kilkist_nulovux(Arr, N);
	int v = Kilkist_videmnux(Arr, N);
	cout << "Dodatnux elementiv: ";
	Show(d);
	Show('\n');
	cout << "Nulovux elementiv: ";
	Show(n);
	Show('\n');
	cout << "Videmnux elementiv: ";
	Show(v);
}
int Kilkist_dodatnux(int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			s++;
		}
	}
	return s;
}
int Kilkist_nulovux(int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			s++;
		}
	}
	return s;
}
int Kilkist_videmnux(int arr[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			s++;
		}
	}
	return s;
}
void Seredne_arufmetuchne() {
	//2. Написати функцію, що визначає середнє арифметичне елементів переданого їй масиву.
	const int N = 20;
	int Arr[N];
	Randomnui_masuv(Arr, N);
	Show_masuv(Arr, N);
	Show('\n');
	float SA = Znaxodzenna_serednogo_arefmetuchnogo(Arr, N);
	cout << "Seredne arefmetuchne elementiv masuvy: ";
	Show(SA);
}
float Znaxodzenna_serednogo_arefmetuchnogo(int arr[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (float)arr[i];
	}
	return sum / n;
}
void Random() {
	srand(time(NULL));
}
void Randomnui_masuv(int arr[], int n) {
	Random();
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 50 - 25;
	}
}
void Show_masuv(int Array[], int n) {
	for (int i = 0; i < n; i++) {
		Show(Array[i]);
		Show(' ');
	}
}
void Dvi_datu() {
	/*1. Написати функцію, яка приймає дві дати(тобто функція приймає шість параметрів)
		та обчислює різницю в днях між цими датами.
		Для виконання цього завдання необхідно також написати функцію, яка визначає, чи є рік високосним.*/
	cout << "Vvedite persy daty:";
	int D1 = Vvod_chisla();
	int M1 = Vvod_chisla();
	int R1 = Vvod_chisla();
	cout << "Vvedite drygy daty:";
	int D2 = Vvod_chisla();
	int M2 = Vvod_chisla();
	int R2 = Vvod_chisla();
	int md1 = Pidraxynok_misaciv_dniv_za_rik(D1, M1, R1);
	int md2 = Pidraxynok_misaciv_dniv_za_rik(D2, M2, R2);
	int r = Riznuca_miz_datamu(md1, md2, R1, R2);
	cout << "Kilkist dniv ";
	Show(r);
}
int Perevirka_na_vusokosnui_rik(int r) {
	int rd;
	if ((r % 4 != 0 && r % 100 != 0) || (r % 4 == 0 && r % 100 == 0 && r % 400 != 0)) {
		return rd = 365;
	}
	else {
		return rd = 366;
	}
}
int Fevral_v_zaleznosti_vid_vusokosnogo_roky(int r) {
	int df;
	int rd = Perevirka_na_vusokosnui_rik(r);
	if (rd == 365) {
		return df = 28;
	}
	else {
		return df = 29;
	}
}
int Pidraxynok_misaciv_dniv_za_rik(int d, int m, int r) {
	int md;
	int f = Fevral_v_zaleznosti_vid_vusokosnogo_roky(r);
	if (m == 1) {
		return md = d;
	}
	else if (m == 2) {
		return md = 31 + d;
	}
	else if (m == 3) {
		return md = (31 + f) + d;
	}
	else if (m == 4) {
		return md = (31 + f + 31) + d;
	}
	else if (m == 5) {
		return md = (31 + f + 31 + 30) + d;
	}
	else if (m == 6) {
		return md = (31 + f + 31 + 30 + 31) + d;
	}
	else if (m == 7) {
		return md = (31 + f + 31 + 30 + 31 + 30) + d;
	}
	else if (m == 8) {
		return md = (31 + f + 31 + 30 + 31 + 30 + 31) + d;
	}
	else if (m == 9) {
		return md = (31 + f + 31 + 30 + 31 + 30 + 31 + 31) + d;
	}
	else if (m == 10) {
		return md = (31 + f + 31 + 30 + 31 + 30 + 31 + 31 + 30) + d;
	}
	else if (m == 11) {
		return md = (31 + f + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) + d;
	}
	else if (m == 12) {
		return md = (31 + f + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) + d;
	}
}
int Riznuca_miz_datamu(int md1, int md2, int r1, int r2) {
	int mdn, rez, rd1, rd2;
	if (md1 >= md2) {
		mdn = md1 - md2;
	}
	else if (md1 < md2) {
		mdn = md2 - md1;
	}
	rd1 = Perevirka_na_vusokosnui_rik(r1);
	rd2 = Perevirka_na_vusokosnui_rik(r2);
	if (r1 > r2) {
		return rez = (((r1 - r2) * 365) + ((rd2 - md2) - (rd1 - md1)));
	}
	else if (r1 < r2) {
		return rez = (((r2 - r1) * 365) + ((rd1 - md1) - (rd2 - md2)));
	}
	else {
		return rez = mdn;
	}
}
inline void Vubir_zadachi() {
	
	cout << "Oberite zadachy:\n"
		<< "1. Dvi datu\n"
		<< "2. Seredne arufmetuchne\n"
		<< "3. Kilkist dodatnux, nulovux ta videmnux elementiv\n";
	Show('\n');
}
void Switch(int n) {
	switch (n) {
	case 1: Dvi_datu(); break;
	case 2: Seredne_arufmetuchne(); break;
	case 3: Kilkist_dodatnux_nulovux_videmnux_elementiv();  break;
	default:Default;
	}
}
inline int Vvod_chisla() {
	int H;
	cin >> H;
	return H;
}
inline char Vvod_sumbola() {
	char H;
	cin >> H;
	return H;
}