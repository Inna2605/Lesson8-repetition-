/*1. Написати функцію, яка отримує як аргумент ціле додатне число і систему числення, 
у яку це число має переводитися (системи числення від 2 до 36). 
Наприклад, коли потрібно перевести число 27 у систему числення 16, має вийти 1B; 
13 у 5-у — 23; 35 у 18-у — 1H.
2. Гра «кубики». 
Умова: є два гральні кубики зі значеннями від 1 до 6. 
Гра відбувається з комп'ютером, кубики кидаються по черзі. 
Переможець той, у кого за результатами п'яти кидків сума більше. 
Передбачте можливість отримання першого ходу людиною або комп'ютером.
Кубики відображаються за допомогою символів. 
У кінці гри необхідно виводити середню суму за кидками для обох учасників.
3. Написати функцію, що виводить на екран прямокутник з висотою N і шириною K.
4. Написати функцію, яка обчислює факторіал переданого їй числа.
5. Написати функцію, яка перевіряє, чи є передане їй число простим. 
Число називається простим, якщо воно ділиться без залишку тільки на себе та на одиницю.
6. Написати функцію, що визначає мінімум і максимум (значення й номер) елементів переданого їй масиву.
7. Написати функцію, яка міняє порядок елементів переданого їй масиву на протилежний.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
using namespace std;
void Vubir_zadachi() {
	cout << "Oberite zadachy:\n"
		<< "1. Sustema schuslenna\n"
		<< "2. Gra \"Kubuku\"\n"
		<< "3. Pramokytnuk\n"
		<< "4. Faktorial\n"
		<< "5. Proste chislo\n"
		<< "6. Minimym ta maksumym\n"
		<< "7. Zmina elementiv v masuvi\n"
		<< "8. Vuxid\n";
	cout << endl;
}
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
void Show(int H) {
	cout << H;
}
void Show_char(char H) {
	cout << H;
}

int Dvoichna_Vosmerichna_sustema(int H, int K) {
	int D, B = 0, n = 0;
	while (H > 0) {
		D = H % K;
		H /= K;
		for (int i = 0; i < n; i++) {
			D *= 10;
		}
		B += D;
		n++;
	}
	return B;
}

void Shesnadcaterichna_sustema(int H) {
	int Arr[100];
	int M, n = 0;
	char A = 'A', B = 'B', C = 'C', D = 'D', E = 'E', F = 'F';
	for (int i = 0; H > 0; i++) {
		M = H % 16;
		Arr[i] = M;
		H /= 16;
		n++;
	}
	for (int j = n - 1; j >= 0; j--) {
		if (Arr[j] == 10) {
			Arr[j] = A;
			cout << (char)Arr[j];
		}
		else if (Arr[j] == 11) {
			Arr[j] = B;
			cout << (char)Arr[j];
		}
		else if (Arr[j] == 12) {
			Arr[j] = C;
			cout << (char)Arr[j];
		}
		else if (Arr[j] == 13) {
			Arr[j] = D;
			cout << (char)Arr[j];
		}
		else if (Arr[j] == 14) {
			Arr[j] = E;
			cout << (char)Arr[j];
		}
		else if (Arr[j] == 15) {
			Arr[j] = F;
			cout << (char)Arr[j];
		}
		else
			Show(Arr[j]);
	}
	cout << endl;
}

void Default() {
	cout << "Ne virno obranui variant!\n\n";
}
void Peretvorenna_za_sustemoy_shuslenna(int X, int Y) {
	if (Y == 10) {
		Show(X);
		cout << endl;
	}
	else if (Y == 2 || Y == 8) {
		int D = Dvoichna_Vosmerichna_sustema(X, Y);
		Show(D);
		cout << endl;
	}
	else if (Y == 16) {
		Shesnadcaterichna_sustema(X);
	}
	else {
		Default();
	}
}
void Sustema_schuslenna() {
	/*1. Написати функцію, яка отримує як аргумент ціле додатне число і систему числення,
	у яку це число має переводитися (системи числення від 2 до 36).
	Наприклад, коли потрібно перевести число 27 у систему числення 16, має вийти 1B;
	13 у 5-у — 23; 35 у 18-у — 1H.*/
	int Ch = 0, S = 0;
	cout << "Vvedite chislo ta sustemy schuslenna: ";
	Ch = Vvod_chisla();
	S = Vvod_chisla();
	Peretvorenna_za_sustemoy_shuslenna(Ch, S);
}
void Random() {
	srand(time(NULL));
}
int Random_broskiv() {
	Random();
	int x = rand() % 6 + 1;
	for (int i = 0; i < x; i++) { 
		Show_char('*');
		Show_char(' ');
	}
	cout << endl;
	return x;
}
int Brosku() {
	int Sum = 0;
	for (int i = 0; i < 2; i++) {
			cout << "Kybuk " << i + 1 << " : ";
			Sum += Random_broskiv();
			Sleep(1000);
	}
	Sleep(500);
	return Sum;
}
int Vubir_xody() {
	char sb = Vvod_sumbola();
	if (sb == 'k'|| sb == 'K') {
		Random();
		int a = rand() % 2;
		cout << "Randomnui vubir (\'0\' - kompyter, \'1\' - luduna): ";
		Show(a);
		if (a == 0) {
			cout << "\n\nPersui hid za kompyterom";
		}
		else if (a == 1) {
			cout << "\n\nPersui hid za vamu!"
				<< "\nRobite brosok!";
		}
		return a;
	}
	else Default();
}
int Brosku(int B) {
	B += Brosku();
	return B;
}
void Porivnanna(int X, int Y) {
	if (X > Y) {
		cout << "\n!!!VITAY VU VUGRALU!!!\n"
			<< "Suma vasux broskiv " << X
			<< "\nSuma broskiv kompytera " << Y
			<< "\n\n";
	}
	else if (X == Y) {
		cout << "\nNichia! Peremogla dryzba!\n"
			<< "Suma vasux broskiv " << X
			<< "\nSuma broskiv kompytera " << Y
			<< " odnakova!\n\n";
	}
	else {
		cout << "\nVugrav compyter.\n"
			<< "Suma broskiv kompytera " << Y
			<< " \nSumma vasux broskiv " << X
			<< "\nVam posastut nastypnoi gru.\n\n";
	}
}
void Kybuku() {
	/*2. Гра «кубики». 
    Умова: є два гральні кубики зі значеннями від 1 до 6. 
    Гра відбувається з комп'ютером, кубики кидаються по черзі. 
    Переможець той, у кого за результатами п'яти кидків сума більше. 
    Передбачте можливість отримання першого ходу людиною або комп'ютером.
    Кубики відображаються за допомогою символів. 
    У кінці гри необхідно виводити середню суму за кидками для обох учасників.*/
	int Sum_comp = 0, Sum_lyd = 0;
	cout << "Vuznachte y kogo pravo persogo xody.\n"
		<< "Vvedite sumbol \"K\" dla randomnogo vubory: ";
	int x = Vubir_xody();
	cout << endl;
	int N = 0, n = 0;
	char sb = 's';
	for (int k = 0; k < 10; k++) {
		if ((x == 0 && (k == 0 || k % 2 == 0)) || (x == 1 && (k % 2 != 0))) {
			n++;
			cout << "\nBrosok kompytera:\nBrosok: " << n << endl;
			Sum_comp = Brosku(Sum_comp);
		}
		else if ((x == 0 && (k % 2 != 0)) || (x == 1 && (k == 0 || k % 2 == 0))) {
			N++;
			cout << "\nVas hid:\nBrosok: " << N << endl;
			while (true) {
				cout << "Vvedite sumbol \"K\" dla broska kybukiv: ";
				sb = Vvod_sumbola();
				if (sb == 'k' || sb == 'K') {
					Sum_lyd = Brosku(Sum_lyd);
					break;
				}
				else Default();
			}
		}
	}
	Porivnanna(Sum_lyd, Sum_comp);
}
void Suruna(int h) {
	for (int i = 0; i < h; i++) {
		Show_char('-');
		Show_char(' ');
	}
	Show_char('\n');
}
void Tilo_pramokytnuka(int h, int s) {
	for (int j = 0; j < s; j++) {
		for (int i = 0; i <= h + 1; i++) {
			if (i == 0 || i == h + 1) {
				Show_char('|');
			}
			else { 
				Show_char(' '); 
				Show_char(' ');
			}
		}
		Show_char('\n');
	}
}
void Pramokytnuk() {
	//3. Написати функцію, що виводить на екран прямокутник з висотою N і шириною K.
	cout << "Vvedite vusoty ta suruny pramokytnuka: ";
	int N = Vvod_chisla();
	int K = Vvod_chisla();
	Show(N);
	Show_char(' ');
	Show_char('\n');
	Show(K);
	Show_char('\n');
	for (int i = 0; i < 3; i++) {
		if (i == 0 || i == 3 - 1) {
			Show_char(' ');
			Suruna(K);
		}
		else {			
			Tilo_pramokytnuka(K, N);
		}
	}
	Show_char('\n');
}
int Znahodzenna_faktorialy(int R) {
	int F = 1;
	if (R > 0) {
		for (int i = 1; i <= R; i++) {
			F *= i;
		}
	}
	else if (R == 0) {
		F = 1;
	}
	return F;
}
void Faktorial() {
	//4. Написати функцію, яка обчислює факторіал переданого їй числа.
	int f = 0;
	cout << "Vvedite chislo: ";
	int n = Vvod_chisla();
	while (true) {
		if (n < 0) {
			cout << "Faktorial znaitu ne mozluvo!\n"
				<< "Videmne chuslo!\n";
		}
		else {
			f = Znahodzenna_faktorialy(n);
			break;
		}
	}
	cout << "Faktarial chusla " << n << " raven " << f << endl;
	Show_char('\n');
}
int Znahodzenna_prostogo_chisla(int s) {
	int n = 0;
	for (int i = 2; i < s; i++) {
		if (s % i == 0 || s < 1) {
			n++;
			break;
		}
	}
	return n;
}
void Perevirka_na_proste_chislo(int S) {
	int N = Znahodzenna_prostogo_chisla(S);
	if (N == 0) {
		cout << "Vashe chuslo ";
		Show(S);
		cout << " e prostum chislom!\n";
	}
	else {
		cout << "\nChuslo ";
		Show(S);
		cout << " ne e prostum chislom!\n";
	}
}
void Proste_chislo() {
	/*5. Написати функцію, яка перевіряє, чи є передане їй число простим. 
         Число називається простим, якщо воно ділиться без залишку тільки на себе та на одиницю.*/
	cout << "Vvedite chislo: ";
	int n = Vvod_chisla();
	Perevirka_na_proste_chislo(n);
	Show_char('\n');
}
void Masuv_odnovumirnui(int Arrey[], int E) {
	Random();
	for (int i = 0; i < E; i++) {
		Arrey[i] = rand() % 50 - 25;
	}
}
void Show_Masuv_odnovumirnui(int Arrey[], int E) {
	for (int i = 0; i < E; i++) {
		cout << Arrey[i];
		Show_char(' ');
	}
	Show_char('\n');
}
void Masuv_dvovumirnui(int Arrey[][10], int E, int K) {
	Random();
	for (int i = 0; i < E; i++) {
		for (int j = 0; j < K; j++) {
			Arrey[i][j] = rand() % 20 - 10;
		}
	}
}
void Show_Masuv_dvovumirnui(int Arrey[][10], int E, int K) {
	for (int i = 0; i < E; i++) {
		for (int j = 0; j < K; j++) {
			cout << Arrey[i][j];
			Show_char(' ');
		}
		Show_char('\n');
	}
	Show_char('\n');
}
void Max_chislo_Masuva_odnovumirnogo(int Arrey[], int E) {
	int Max = Arrey[0], max = 0;
	for (int i = 0; i < E; i++) {
		if (Max < Arrey[i]) {
			Max = Arrey[i];
			max = i;
		}
	}
	cout << "Maksumalne znachenna macuvy ";
	Show(Max);
	cout << " pid nomerom ";
	Show(max + 1);
}
void Min_chislo_Masuva_odnovumirnogo(int Arrey[], int E) {
	int Min = 0, min = 0;
	for (int i = 0; i < E; i++) {
		if (Min > Arrey[i]) {
			Min = Arrey[i];
			min = i;
		}
	}
	cout << "Minimalne znachenna macuvy ";
	Show(Min);
	cout << " pid nomerom ";
	Show(min + 1);
}
void Max_chislo_Masuva_dvovumirnogo(int Arrey[][10], int E, int K) {
	int Max = Arrey[0][0];
	for (int i = 0; i < E; i++) {
		for (int j = 0; j < K; j++) {
			if (Max < Arrey[i][j]) {
				Max = Arrey[i][j];
			}
		}
	}
	cout << "Maksumalne znachenna macuvy ";
	Show(Max);
}
void Min_chislo_Masuva_dvovumirnogo(int Arrey[][10], int E, int K) {
	int Min = 0;
	for (int i = 0; i < E; i++) {
		for (int j = 0; j < K; j++) {
			if (Min > Arrey[i][j]) {
				Min = Arrey[i][j];
			}
		}
	}
	cout << "Maksumalne znachenna macuvy ";
	Show(Min);
}
void Rabota_z_masuvom(int H, int A1[], int A2[][10], int R, int C) {
	switch (H) {
	case 1: 
		Masuv_odnovumirnui(A1, C);
		Show_Masuv_odnovumirnui(A1, C);
		Show_char('\n');
		Max_chislo_Masuva_odnovumirnogo(A1, C);
		Show_char('\n');
		Min_chislo_Masuva_odnovumirnogo(A1, C);
		Show_char('\n');
	break;
	case 2: 
		Masuv_dvovumirnui(A2, R, C);
		Show_Masuv_dvovumirnui(A2, R, C);
		Show_char('\n');
		Max_chislo_Masuva_dvovumirnogo(A2, R, C);
		Show_char('\n');
		Min_chislo_Masuva_dvovumirnogo(A2, R, C);
		Show_char('\n');
	break;
	case 3:break;
	default:Default();
	}
}
void Minimym_ta_maksumym() {
	//6. Написати функцію, що визначає мінімум і максимум (значення й номер) елементів переданого їй масиву.
	int i = 0;
	const int col = 10;
	const int row = 5;
	int Arr1[col], Arr2[row][col];
	while (true) {
		cout << "\nVvedite vumirnost masuva:\n"
			<< "1. Odnovumirnui\n"
			<< "2. Dvovumirnui\n"
			<< "3. Vuhid\n";
		int R = Vvod_chisla();
		if (R == 3) {
			Show_char('\n');
			break;
		}
		Rabota_z_masuvom(R, Arr1, Arr2, row, col);
	}
}
void Zmina_elementiv(int Arrey1[], int Arrey2[], int nom) {
	int a = 0;
	for (int i = nom - 1; i >= 0; i--) {
		Arrey2[a] = Arrey1[i];
		a++;
	}
}
void Zmina_elementiv_v_masuvi() {
	//7. Написати функцію, яка міняє порядок елементів переданого їй масиву на протилежний.
	const int N = 10;
	int Arr1[N], Arr2[N];
	Masuv_odnovumirnui(Arr1, N);
	cout << "Dan masuv\n";
	Show_Masuv_odnovumirnui(Arr1, N);
	Zmina_elementiv(Arr1, Arr2, N);
	cout << "\nZminenuy poradok elementiv na protulezni\n";
	Show_Masuv_odnovumirnui(Arr2, N);
	Show_char('\n');
}
void Vuxid() {
	return;
}
void Switch(int n) {
	switch (n) {
	case 1: Sustema_schuslenna(); break;
	case 2: Kybuku(); break;
	case 3: Pramokytnuk(); break;
	case 4: Faktorial(); break;
	case 5: Proste_chislo(); break;
	case 6: Minimym_ta_maksumym(); break;
	case 7: Zmina_elementiv_v_masuvi(); break;
	case 8: Vuxid(); break;
	default:Default();
	}
}

int main() {
	int A = 0;
	while (A < 8) {
		Vubir_zadachi();
		A = Vvod_chisla();
		Switch(A);
	}
}