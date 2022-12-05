#include<iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include<fstream>
using namespace std;
class Node
{
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node() { value = 0; next = NULL; prev = NULL; }
	void setValue(int _value) { value = _value; }   	char getValue() { return value; }
	void setNext(Node* _next) { next = _next; }     	Node* getNext() { return next; }
	void setPrev(Node* _prev) { prev = _prev; }     	Node* getPrev() { return prev; }
};

class Link
{
private:
	Node* head;
	Node* tail;
public:
	Link() { head = NULL; tail = NULL; }
	void addValue(char value)
	{
		Node* temp = new Node;
		temp->setValue(value);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->setPrev(tail);
			tail->setNext(temp);
			tail = temp;
		}
	}
	void viewAll()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->getValue() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
	void deleteValue(int value)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->getValue() == value)
			{
				if (temp == head)
				{
					head = head->getNext();
					if (head)
					{
						head->setPrev(NULL);
					}
					temp = head;
				}
				else if (temp->getNext() == NULL)
				{
					temp->getPrev()->setNext(temp->getNext());
					tail = temp->getPrev();
				}
				else
				{
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());
				}
			}
			temp = temp->getNext();
		}
	}
	void deleteMass(int startIndex, int count = 26)
	{
		Node* temp = head;
		if (startIndex == 0)
		{
			for (int i = 0; i < count; i++)
			{
				head = head->getNext();
			}
			head->setPrev(NULL);
		}
		else
		{
			int counterIndex = 0;
			while (counterIndex != startIndex - 1)
			{
				temp = temp->getNext();
				counterIndex++;
			}
			for (int i = 0; i < count; i++)
			{
				temp->setNext(temp->getNext()->getNext());
			}
			if (temp->getNext() == NULL)
			{
				tail = temp;
			}
			else
			{
				temp->getNext()->setPrev(temp);
			}
		}
	}
	void deleteAllNodes() {
		Node* temp = new Node();
		while (head != NULL) {
			temp = head;
			head = head->getNext();
			free(temp);
		}
	}
	int operator[](int index)
	{
		Node* temp = head;
		int counterindex = 0;
		while (counterindex != index)
		{
			temp = temp->getNext();
			counterindex++;
		}
		return temp->getValue();
	}
};

class Hangman {
private:

public:
	void printHangman(int nyawa) {
		cout << endl;
		cout << " ________" << endl;
		cout << " |      |" << endl;
		if (nyawa == 6) {
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 5) {
			cout << " |    (o_o)" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 4) {
			cout << " |    (o_o)" << endl;
			cout << " |      |" << endl;
			cout << " |      |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 3) {
			cout << " |    (o_o)" << endl;
			cout << " |     /|" << endl;
			cout << " |      |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 2) {
			cout << " |    (o_o)" << endl;
			cout << " |     /|\\" << endl;
			cout << " |      |" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 1) {
			cout << " |    (o_o)" << endl;
			cout << " |     /|\\" << endl;
			cout << " |      |" << endl;
			cout << " |     /" << endl;
			cout << " |" << endl;
		}
		else if (nyawa == 0) {
			cout << " |    (x_x)" << endl;
			cout << " |     /|\\" << endl;
			cout << " |      |" << endl;
			cout << " |     / \\" << endl;
			cout << " |" << endl;
		}
		cout << "----------" << endl;
	}
	void rules() {
		cout << "---------------------------------------------Selamat datang di game HANGMAN---------------------------------------------" << endl;
		cout << "\n                                       	Game ini merupakan game menebak kata" << endl;
		cout << "Peraturan : " << endl;
		cout << "1. Player hanya dapat menginput huruf " << endl;
		cout << "2. 1x permainan di game ini akan mendapatkan kesempatan 6 nyawa" << endl;
		cout << "3. Setiap huruf yang di input benar, akan mendapat skor 1 poin" << endl;
		cout << "4. Setiap huruf yang di input salah, tidak akan mendapat pengurangan poin, namun nyawa akan dikurangi 1" << endl;
		cout << "5. Jika kata sudah berhasil ditebak, namun nyawa masih > 0, maka pemain dapat melanjutkan untuk menebak kata lain untuk meningkatkan skor" << endl;
		cout << "6. Jika nyawa = 0, pemain dapat melihat highscore yang tertera pada menu highscore" << endl;
		cout << "7. Jika pemain berhasil menebak 50 kata, pemain akan mendapat tambahan 50 poin dan game berakhir" << endl;
		cout << "8.Setiap kata, pemain diijinkan untuk meminta hint sebanyak 1x" << endl;
		cout << "Pemain dapat meminta hint dengan cara memencet tombol 1" << endl;
		cout << "Hint berupa munculnya 1 huruf dalam 1 kata yang harus ditebak oleh pemain" << endl;
		cout << endl << endl << endl;
		cout << "--------------------------------------------------Selamat Bermain!!!---------------------------------------------------" << endl;
	}
	void resetall(int& nyawa, int& skor, int& nyawahint)
	{
		nyawa = 6;
		skor = 0;
		nyawahint = 1;
	}
	void resetlink(Link& link)
	{
		link.deleteAllNodes();
		inisiasilink(link);
	}
	void inisiasilink(Link& link)
	{
		link.addValue('A'); 	link.addValue('B'); 	link.addValue('C'); 	link.addValue('D'); 	link.addValue('E'); 	link.addValue('F');
		link.addValue('G'); 	link.addValue('H'); 	link.addValue('I'); 	link.addValue('J'); 	link.addValue('K'); 	link.addValue('L');
		link.addValue('M'); 	link.addValue('N'); 	link.addValue('O'); 	link.addValue('P'); 	link.addValue('Q'); 	link.addValue('R');
		link.addValue('S'); 	link.addValue('T'); 	link.addValue('U'); 	link.addValue('V'); 	link.addValue('W'); 	link.addValue('X');
		link.addValue('Y'); 	link.addValue('Z');
	}
	void inisiasikata(string* kata)
	{
		kata[0] = "makan"; kata[10] = "anjing"; kata[20] = "siang"; kata[30] = "gelas"; kata[40] = "angin";
		kata[1] = "tidur"; kata[11] = "kucing"; kata[21] = "malam"; kata[31] = "piring"; kata[41] = "tanah";
		kata[2] = "minum"; kata[12] = "tikus"; kata[22] = "hidung"; kata[32] = "sendok"; kata[42] = "bunga";
		kata[3] = "cinta"; kata[13] = "gajah"; kata[23] = "dendam"; kata[33] = "garpu"; kata[43] = "laptop";
		kata[4] = "sayang"; kata[14] = "harimau"; kata[24] = "suami"; kata[34] = "kompor"; kata[44] = "komputer";
		kata[5] = "marah"; kata[15] = "singa"; kata[25] = "plastik"; kata[35] = "istri"; kata[45] = "mouse";
		kata[6] = "sedih"; kata[16] = "kabel"; kata[26] = "buku"; kata[36] = "kecap"; kata[46] = "keyboard";
		kata[7] = "jengkel"; kata[17] = "kebun"; kata[27] = "listrik"; kata[37] = "sambal"; kata[47] = "speaker";
		kata[8] = "mati"; kata[18] = "rumput"; kata[28] = "lampu"; kata[38] = "kencan"; kata[48] = "tissue";
		kata[9] = "hidup"; kata[19] = "pohon"; kata[29] = "tembok"; kata[39] = "kendaraan"; kata[49] = "televisi";
	}
	void cekarray(bool* checkarray)
	{
		for (int i = 0; i < 26; i++)
		{
			checkarray[i] = true;
		}
	}
	void tolower(char huruf)
	{
		if (huruf <= 90 && huruf >= 65)
		{
			huruf += 32;
		}
	}
	void cekhint(int nyawahint, int huruf)
	{
		if (nyawahint == 0 && huruf == 49)
		{
			cout << "Hint telah digunakan, selesaikan kata ini untuk mendapatkan hint lagi!" << endl;
			system("pause");
			system("cls");
		}
	}
	void cekhuruf(char huruf)
	{
		if (huruf < 97 && huruf > 122 || huruf != 49)
		{
			cout << "Input hanya bisa a-z, silahkan input lagi!" << endl;
			system("pause");
			system("cls");
		}
	}
	void show(int nyawa, int skor)
	{
		cout << "Nyawa tersisa :" << nyawa << endl;
		cout << "Skor : " << skor << " poin " << endl;
	}

};
void main()
{
	Link link;
	Link hurufinput;
	Hangman game;
	string highscorepemain[10], kata[50], namaplayer, kataterpilih, temp;
	int  highscoreskor[10], input, angka, nyawa = 6, nyawahint = 1, hint = 1, acak, skor = 0, finish = 0, counterhurufinput = 0;
	bool checkarray[26], ketemu;
	char huruf;
	game.inisiasikata(kata);
	srand(time(0));
	game.cekarray(checkarray);
	cout << "Welcome to HANGMAN !!!" << endl;
	while (true)
	{
		cout << "Menu" << endl;
		cout << "1. Main" << endl;
		cout << "2. Lihat Highscore" << endl;
		cout << "3. Lihat peraturan" << endl;
		cout << "4. Exit" << endl;
		cout << "Input : ";
		cin >> input;
		system("cls");
		if (input == 1)
		{
			cout << "Input nama player : "; cin >> namaplayer;
			game.inisiasilink(link);
		next:
			nyawahint = 1;
			ketemu = false;
			acak = rand() % 50;
			kataterpilih = kata[acak];
			temp = kataterpilih;
			for (int i = 0; i < temp.length(); i++)
			{
				temp[i] = '_';
			}
			while (nyawa != 0)
			{
			pilih:
				game.show(nyawa, skor);
				game.printHangman(nyawa);
				cout << endl;
				for (int i = 0; i < temp.length(); i++)
				{
					cout << temp[i] << " ";
				}
				cout << endl;
				link.viewAll();
				cout << "Huruf yang sudah di input : ";
				hurufinput.viewAll();
				cout << endl;

				cout << "Input huruf : "; cin >> huruf;
				game.tolower(huruf);
				if (huruf >= 97 && huruf <= 122 || huruf == 49)
				{
					if (huruf == 49 && nyawahint > 0)
					{
						nyawahint--;
					cariindex:
						int indexhint = rand() % temp.length();
						char hurufhint = kataterpilih[indexhint];
						int angka2 = hurufhint - 97;
						if (checkarray[angka2] == true)
						{
							char hurufhint = kataterpilih[indexhint];
							int angka2 = hurufhint - 97;
							checkarray[angka2] = false;
							hurufinput.addValue(hurufhint);
							counterhurufinput++;
							for (int i = 0; i < temp.length(); i++)
							{
								if (i == indexhint)
								{
									temp[i] = hurufhint;
								}
							}
							cout << "Hint telah digunakan!" << endl;
							cout << "Huruf " << hurufhint << " telah dihapus dari linked list!" << endl;
							int hapus2 = hurufhint;
							hapus2 -= 32;
							link.deleteValue(hapus2);
							system("pause");
							system("cls");
						}

						/*int angka2 = hurufhint - 97;
						if (checkarray[angka2] == true)
						{
							char hurufhint = kataterpilih[indexhint];
							int angka2 = hurufhint - 97;
							checkarray[angka2] = false;
							hurufinput.addValue(hurufhint);
							counterhurufinput++;
							for (int i = 0; i < temp.length(); i++)
							{
								if (i == indexhint)
								{
									temp[i] = hurufhint;
								}
							}
							cout << "Hint telah digunakan!" << endl;
							cout << "Huruf " << hurufhint << " telah dihapus dari linked list!" << endl;
							int hapus2 = hurufhint;
							hapus2 -= 32;
							link.deleteValue(hapus2);
							system("pause");
							system("cls");
						}
						else
						{
							goto cariindex;
						}*/
						if (temp == kataterpilih)
						{

							game.resetlink(link);
							nyawahint = 1;
							game.cekarray(checkarray);
							hurufinput.deleteAllNodes();
							finish++;
							cout << "Kata yang ditebak : " << kataterpilih;
							cout << endl;
							system("pause");
							system("cls");
							goto next;
						}
					}
					else if (nyawahint == 0 && huruf == 49) { game.cekhint(nyawahint, huruf); }
					else
					{
						int angka = huruf - 97;
						if (checkarray[angka] == true)
						{
							checkarray[angka] = false;
							hurufinput.addValue(huruf);
							link.deleteValue(angka);
						}
						else
						{
							link.deleteValue(angka);
							cout << "Huruf " << huruf << " sudah di input, silahkan pilih huruf lain!" << endl;
							/*nyawa--;*/
							system("pause");
							system("cls");
							goto pilih;
						}
						cout << endl;
						for (int i = 0; i < temp.length(); i++)
						{
							if (kataterpilih[i] == huruf)
							{
								skor++;
								temp[i] = huruf;
								ketemu = true;
								int hapus = huruf;
								hapus -= 32;
								link.deleteValue(hapus);
							}
						}
						if (ketemu == false)
						{
							int hapus = huruf;
							hapus -= 32;
							link.deleteValue(hapus);
							cout << endl;
							cout << "Huruf " << huruf << " tidak ada dalam kata tersebut!" << endl;
							nyawa--;
						}
						else
						{
							int angka = huruf - 97;
							link.deleteValue(angka);
							cout << endl;
							cout << "Huruf " << huruf << " telah dihapus dari linked list!" << endl;
						}
						ketemu = false;
						if (temp == kataterpilih)
						{

							game.resetlink(link);
							nyawahint = 1;
							game.cekarray(checkarray);
							hurufinput.deleteAllNodes();
							finish++;
							cout << "Kata yang ditebak : " << kataterpilih;
							cout << endl;
							system("pause");
							system("cls");
							goto next;
						}
						system("pause");
						system("cls");
					}
				}
				else
				{
					game.cekhuruf(huruf);
					goto pilih;
				}
			}
			if (nyawa == 0)
			{
				cout << "";
				link.deleteAllNodes();
				hurufinput.deleteAllNodes();
				cout << "GAME OVER !" << endl;
				cout << "Kata yang ditebak : " << kataterpilih << endl;
				fstream out("highscore.txt", ios::app);
				if (out.is_open())
				{
					out << namaplayer << " " << skor << endl;
				}
				else
				{
					cout << "File can't be opened / doesn't exist!" << endl;
				}
				out.close();
				string namapemain, temppemain;
				int skorpemain, tempskor;
				for (int i = 0; i < 10; i++)
				{
					highscorepemain[i] = "xxx";
					highscoreskor[i] = 0;
				}
				fstream in("highscore.txt", ios::in);
				if (in.is_open())
				{
					int i = 0;
					while (in >> namapemain >> skorpemain)
					{
						highscorepemain[i] = namapemain;
						highscoreskor[i] = skorpemain;
						i++;
					}

					for (int i = 0; i < 10; i++)
					{
						if (highscoreskor[i + 1] > highscoreskor[i])
						{
							tempskor = highscoreskor[i + 1];
							highscoreskor[i + 1] = highscoreskor[i];
							highscoreskor[i] = tempskor;
							temppemain = highscorepemain[i + 1];
							highscorepemain[i + 1] = highscorepemain[i];
							highscorepemain[i] = temppemain;
							i = -1;
						}
					}
					cout << "Highscore :" << endl;
					for (int i = 0; i < 10; i++)
					{
						cout << i + 1 << ". Nama : " << highscorepemain[i] << "      	Skor : " << highscoreskor[i] << endl;
					}
					if (finish == 50)
					{
						skor += 50;
						fstream out("highscore.txt", ios::app);
						if (out.is_open())
						{
							out << namaplayer << " " << skor;
						}
						else
						{
							cout << "File can't be opened / doesn't exist!" << endl;
						}
					}
					game.resetall(nyawa, skor, nyawahint);
					game.cekarray(checkarray);
					system("pause");
					system("cls");
				}
			}
		}
		else if (input == 2)
		{
			string namapemain, temppemain;
			int skorpemain, tempskor;
			for (int i = 0; i < 10; i++)
			{
				highscorepemain[i] = "xxx";
				highscoreskor[i] = 0;
			}
			fstream in("highscore.txt", ios::in);
			if (in.is_open())
			{
				int i = 0;
				while (in >> namapemain >> skorpemain)
				{
					highscorepemain[i] = namapemain;
					highscoreskor[i] = skorpemain;
					i++;
				}

				for (int i = 0; i < 10; i++)
				{
					if (highscoreskor[i + 1] > highscoreskor[i])
					{
						tempskor = highscoreskor[i + 1];
						highscoreskor[i + 1] = highscoreskor[i];
						highscoreskor[i] = tempskor;
						temppemain = highscorepemain[i + 1];
						highscorepemain[i + 1] = highscorepemain[i];
						highscorepemain[i] = temppemain;
						i = -1;
					}
				}
				cout << "Highscore :" << endl;
				for (int i = 0; i < 10; i++)
				{
					cout << i + 1 << ". Nama : " << highscorepemain[i] << "      	Skor : " << highscoreskor[i] << endl;
				}
				system("pause");
				system("cls");
			}
			else
			{
				cout << "File can't be opened / doesn't exist!" << endl;
			}
			in.close();
		}
		else if (input == 3)
		{
			game.rules();
			system("pause");
			system("cls");
		}
		else if (input == 4) { break; }
	}
}




