/*1. �������� �������, ��� ������ �� �������� ���� ������� ����� � ������� ��������, 
� ��� �� ����� �� ������������ (������� �������� �� 2 �� 36). 
���������, ���� ������� ��������� ����� 27 � ������� �������� 16, �� ����� 1B; 
13 � 5-� � 23; 35 � 18-� � 1H.
2. ��� �������. 
�����: � ��� ������ ������ � ���������� �� 1 �� 6. 
��� ���������� � ����'������, ������ ��������� �� ����. 
���������� ���, � ���� �� ������������ �'��� ����� ���� �����. 
���������� ��������� ��������� ������� ���� ������� ��� ����'������.
������ ������������� �� ��������� �������. 
� ���� ��� ��������� �������� ������� ���� �� ������� ��� ���� ��������.
3. �������� �������, �� �������� �� ����� ����������� � ������� N � ������� K.
4. �������� �������, ��� �������� �������� ���������� �� �����.
5. �������� �������, ��� ��������, �� � �������� �� ����� �������. 
����� ���������� �������, ���� ���� ������� ��� ������� ����� �� ���� �� �� �������.
6. �������� �������, �� ������� ����� � �������� (�������� � �����) �������� ���������� �� ������.
7. �������� �������, ��� ���� ������� �������� ���������� �� ������ �� �����������.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
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
	/*1. �������� �������, ��� ������ �� �������� ���� ������� ����� � ������� ��������,
	� ��� �� ����� �� ������������ (������� �������� �� 2 �� 36).
	���������, ���� ������� ��������� ����� 27 � ������� �������� 16, �� ����� 1B;
	13 � 5-� � 23; 35 � 18-� � 1H.*/
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
		cout << ' ';
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
	/*2. ��� �������. 
    �����: � ��� ������ ������ � ���������� �� 1 �� 6. 
    ��� ���������� � ����'������, ������ ��������� �� ����. 
    ���������� ���, � ���� �� ������������ �'��� ����� ���� �����. 
    ���������� ��������� ��������� ������� ���� ������� ��� ����'������.
    ������ ������������� �� ��������� �������. 
    � ���� ��� ��������� �������� ������� ���� �� ������� ��� ���� ��������.*/
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
void Vusota(int h) {
	for (int i = 0; i < h; i++) {
		Show_char('|');
		Show_char('\n');
	}
}
void Suruna(int h) {
	for (int i = 0; i < h; i++) {
		Show_char('-');
	}
}
void Pramokytnuk() {
	//3. �������� �������, �� �������� �� ����� ����������� � ������� N � ������� K.
	cout << "Vvedite vusoty ta suruny pramokytnuka: ";
	int N = Vvod_chisla();
	int K = Vvod_chisla();
	Show(N);
	Show_char(' ');
	Show(K);
	Show_char('\n');
	for (int i = 0; i < 2; i++) {
		if (i == 0 || i == 2 - 1) {

		}
	}
}
void Vuxid() {
	return;
}
void Switch(int n) {
	switch (n) {
	case 1: Sustema_schuslenna(); break;
	case 2: Kybuku(); break;
	case 3: Pramokytnuk(); break;
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