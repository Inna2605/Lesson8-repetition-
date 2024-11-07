/*1. Написати функцію, яка приймає два параметри: 
основа степеня і показник степеня, 
та обчислює степінь числа на основі отриманих даних.
2. Написати функцію, яка отримує в якості параметрів 2 цілих числа 
та повертає суму чисел із діапазону між ними.
3. Число називається досконалим, 
якщо сума всіх його дільників дорівнює йому самому. 
Напишіть функцію пошуку таких чисел у введеному інтервалі.
4. Написати функцію, що виводить на екран передану їй гральну карту.
5. Написати функцію, що визначає, чи є «щасливим» шестизначне число.
6. Написати функцію для переведення числа,
записаного у двійковому вигляді, у десяткову систему.*/

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
void Show_chisla_float(float H) {
	cout << H;
}
void Show_char(char H) {
	cout << H;
}
void Default() {
	cout << "Ne virno obranui variant!\n\n";
}
void Zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Chuslo v stepeni\n"
		<< "2. Suma chusel\n"
		<< "3. Doskonali chusla\n"
		<< "4. Gralna karta\n"
		<< "5. Shasluve chislo\n"
		<< "6. Perevedenna chusla iz 2 sustemu y 10\n";
}

float Vozvedenna_y_stepin(int A, int B) {
	float n = A;
	if (B == 0 ) {
		n = 1;
	}
	else if (B == -1) {
		n = -A;
	}
	else if (B == 1) {
		n == A;
	}
	else if (B < 0 && A > 0) {
		B *= -1;
		for (int i = 1; i < B; i++) {
			n *= float(A);
		}
		n = 1 / n;
	} 
	else if(B < 0 && A < 0) {
		B *= -1;
		A *= -1;
		n *= -1;
		for (int i = 1; i < B; i++) {
			n *= float(A);
		}
		n = 1 / n;
		if (B % 2 != 0) {
			n *= -1;
		}
	}
	else {
		for (int i = 1; i < B; i++) {
			n *= A;
		}
	}
	return n;
}
void Chuslo_v_stepeni() {
	/*1. Написати функцію, яка приймає два параметри: 
         основа степеня і показник степеня, 
         та обчислює степінь числа на основі отриманих даних.*/
	cout << "Vvedite chislo i stepin v iaky potribno vozvestu chislo: ";
	int ch = Vvod_chisla();
	int st = Vvod_chisla();
	float S = Vozvedenna_y_stepin(ch, st);
	Show_chisla_float(S);
	Show_char('\n');
}
int Znahodzenna_sumu_diapazonu(int A, int B) {
	int Sum = 0;
	for (int i = A; i <= B; i++) {
		Sum += i;
	}
	return Sum;
}
void Suma_chusel_diapazonu() {
	/*2. Написати функцію, яка отримує в якості параметрів 2 цілих числа 
         та повертає суму чисел із діапазону між ними.*/
	cout << "Vvedite dva tcilux chisla: ";
	int One = Vvod_chisla();
	int Two = Vvod_chisla();
	int Sum = Znahodzenna_sumu_diapazonu(One, Two);
	cout << "Suma chisel vdiapazoni miz " << One << " ta " << Two << " dorivnue "; 
	Show_chisla(Sum);
	Show_char('\n');
}
void Znahodzenna_doskonalux_chisel(int A, int B) {
	int Sum_dil, C;
	for (int i = A; i < B; i++) {
		Sum_dil = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				Sum_dil += j;
			}
		}
		if (Sum_dil == i) {
			Show_chisla(Sum_dil);
			Show_char(' ');
		}
	}
}
void Doskonali_chusla() {
	/*3. Число називається досконалим, 
         якщо сума всіх його дільників дорівнює йому самому. 
         Напишіть функцію пошуку таких чисел у введеному інтервалі.*/
	const int D = 10;
	int ArrD[D];
	cout << "Vvedite dva tcilux chisla: ";
	int Perse = Vvod_chisla();
	int Dryge = Vvod_chisla();
	cout << "V diapazoni vid " << Perse << " do " << Dryge << " doskonaly chisla: ";
	Znahodzenna_doskonalux_chisel(Perse, Dryge);
	Show_char('\n');
}
void Gralna_karta() {
	//4. Написати функцію, що виводить на екран передану їй гральну карту.
	cout << "Vvedite persy bykvy nazvu kartu\n"
		<<"(tref - \'T\', piku - \'P\', bybnu - \'B\', chervu - \'C\') i ii chislo: ";
	char Karta = Vvod_sumbola();
	int Chislo = Vvod_chisla();
	if (Karta == 't' || Karta == 'T') {
		Show_char(5);
	}
	else if (Karta == 'p' || Karta == 'P') {
		Show_char(6);
	}
	else if (Karta == 'b' || Karta == 'B') {
		Show_char(4);
	}
	else if (Karta == 'c' || Karta == 'C') {
		Show_char(3);
	}
	else cout << "Ne virno vvedena nazva kartu!";
	Show_char(' ');
	Show_chisla(Chislo);
	Show_char('\n');
}
void Znaxodzenna_shsluvogo_chisla(int A) {
	int N = 0, n = 0, Sum1 = 0, Sum2 = 0;
	while (A > 0) {
		N = A % 10;
		if (n < 3) {
			Sum1 += N;
		}
		else {
			Sum2 += N;
		}
		A /= 10;
		n++;
	}
	if (n == 6 && Sum1 == Sum2) {
		cout << "Vase chislo shasluve!";
		Show_char('\n');
	}
	else if (n == 6 && Sum1 != Sum2) {
		cout << "Vase chislo ne shasluve!";
		Show_char('\n');
	}else cout << "Vase chislo ne sestuznachne!";
}
void Shasluve_chislo() {
	//5. Написати функцію, що визначає, чи є «щасливим» шестизначне число.
	cout << "Vvedite sestuznachne chislo: ";
	int Num = Vvod_chisla();
	Znaxodzenna_shsluvogo_chisla(Num);
}
int Perevod_chisla(int A) {
	int B, i = 1, Des = 0;
	while (A > 0) {
		B = A % 10;
		Des += (B * i);
		A /= 10;
		i *= 2;
	}
	return Des;
}
void Chislo_iz_dviikovoi_v_desatkovy() {
	/*6. Написати функцію для переведення числа,
         записаного у двійковому вигляді, у десяткову систему.*/
	cout << "Vvedite chislo v 2 sustemi chislenna: ";
	int NumDV = Vvod_chisla();
	int NumDes = Perevod_chisla(NumDV);
	cout << "Vase chislo y 10 sustemi chislenna byde: ";
	Show_chisla(NumDes);
	Show_char('\n');
}
void Switch(int n) {
	switch (n) {
	case 1: Chuslo_v_stepeni(); break;
	case 2: Suma_chusel_diapazonu(); break;
	case 3: Doskonali_chusla(); break;
	case 4: Gralna_karta(); break;
	case 5: Shasluve_chislo(); break;
	case 6: Chislo_iz_dviikovoi_v_desatkovy(); break;
	default:Default();
	}
}
int main() {
	Zadachi();
	int a = Vvod_chisla();
	Switch(a);
}