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
void Show(int H) {
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
		cout<<Arr[j];
	}
	cout << endl;
}

void Default() {
	cout << "Ne virno obranui variant!\n";
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
void Kybuku() {
	/*2. Гра «кубики». 
    Умова: є два гральні кубики зі значеннями від 1 до 6. 
    Гра відбувається з комп'ютером, кубики кидаються по черзі. 
    Переможець той, у кого за результатами п'яти кидків сума більше. 
    Передбачте можливість отримання першого ходу людиною або комп'ютером.
    Кубики відображаються за допомогою символів. 
    У кінці гри необхідно виводити середню суму за кидками для обох учасників.*/
}
void Vuxid() {
	return;
}
void Switch(int n) {
	switch (n) {
	case 1: Sustema_schuslenna(); break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	case 6: break;
	case 7: break;
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