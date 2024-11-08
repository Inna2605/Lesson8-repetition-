/*1. Написати функцію, яка повертає куб числа.
2. Написати функцію для знаходження найбільшого з двох чисел.
3. Написати функцію, яка повертає істину, якщо передане значення додатне, та брехню, якщо від’ємне.
4. Написати функцію, яка повертає кількість простих чисел у переданому їй масиві.*/

#include<iostream>
using namespace std;
int Vvod_chisla() {
	int H;
	cin >> H;
	return H;
}
char Vvod_sumbola() {
	char H;
	cin >> H;
	return H;
}
void Show_chisla(int H) {
	cout << H;
}
void Show_char(char H) {
	cout << H;
}
void Vubir_zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Kyb chisla\n"
		<< "2. Naibilse chislo\n"
		<< "3. True abo false\n"
		<< "4. Kilkist prostux chisel\n";
}
void Default() {
	cout << "Ne virno obranui variant!\n\n";
}
int Znahodzenna_kyba_chisla(int A) {
	int N = A;
	for (int i = 1; i < 3; i++) {
		A *= N;
	}
	return A;
}
void Kyb_chisla() {
	//1. Написати функцію, яка повертає куб числа.
	cout << "Vvedite chislo: ";
	int X = Vvod_chisla();
	int Y = Znahodzenna_kyba_chisla(X);
	cout << "Kyb chisla " << X << " dorivnye " << Y;
}
int Znahodzenna_naibilsogo_chisla(int A, int B) {
	return(A >= B) ? A : B;
}
void Naibilse_chislo() {
	//2. Написати функцію для знаходження найбільшого з двох чисел.
	cout << "Vvedite dva chisla: ";
	int X = Vvod_chisla();
	int Y = Vvod_chisla();
	int Z = Znahodzenna_naibilsogo_chisla(X, Y);
	cout << "Z dvox chisel " << X << " ta " << Y << " naibilse chislo " << Z;
}
bool Znahodzenna_true_false(int A) {
	return(A >= 0) ? true : false;
}
void True_abo_false() {
	//3. Написати функцію, яка повертає істину, якщо передане значення додатне, та брехню, якщо від’ємне.
	cout << "Vvedite chislo: ";
	int X = Vvod_chisla();
	bool Y = Znahodzenna_true_false(X);
	cout << "Vvedene chislo " << X;
	cout << ((Y == true) ? " e dodatne" : " e videmne" );
}
void Random() {
	srand(time(NULL));
}
void Randomnui_masuv(int A[], int N) {
	Random();
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 50 - 25;
	}
}
void Show_masuv(int A[], int N) {
	for (int i = 0; i < N; i++) {
		Show_chisla(A[i]);
		Show_char(' ');
	}
}
int Znahodzenna_prostux_chisel(int A[], int N) {
	int n, s = 0;
	Randomnui_masuv(A, N);
	for (int i = 0; i < N; i++) {
		n = 0;
		if(A[i] <= 1){
			n++;
		}
		else {
			for (int j = 2; j < A[i]; j++) {
				if (A[i] % j == 0) {
					n++;
					break;
				}
			}
		}
		if (n == 0) {
			s++;
			Show_chisla(A[i]);
			Show_char(' ');
		}
	}
	return s;
}
void Kilkist_prostux_chisel() {
	//4. Написати функцію, яка повертає кількість простих чисел у переданому їй масиві.
	const int Num = 50;
	int Arr[Num];
	cout << "Masuv:";
	Show_char('\n');
	Randomnui_masuv(Arr, Num);
	Show_masuv(Arr, Num);
	Show_char('\n');
	Show_char('\n');
	cout << "Prosti chisla y masuvi ";
	int n = Znahodzenna_prostux_chisel(Arr, Num);
	cout << " y kilkosti ";
	Show_chisla(n);
}
void Switch(int n) {
	switch (n) {
	case 1: Kyb_chisla(); break;
	case 2: Naibilse_chislo(); break;
	case 3: True_abo_false(); break;
	case 4: Kilkist_prostux_chisel(); break;
	default:Default();
	}
}
int main() {
	Vubir_zadachi();
	int a = Vvod_chisla();
	Switch(a);
	Show_char('\n');
}