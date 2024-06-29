//operatori unari: ! ++ --
//binari: + - / += == * !=
//logici && ||
//relationali < > = !

//Modalitati de supraincarcare operatori:
//1.prin fuctie membra, cand primul operand este de tipul clasei
//este substituit de this(nu se primeste drept param)

//2. prin functie globala
//primul operand nu este de tipul clasei ->pt a accesa atributele private
//vom anunta op in clasa ca functie friend fie vom folosi metode de acces
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

//operatori unari->functie membra
//supraincarcare ! prin functie membra
//bool operator!()
//{
//	return nivelBaterie != 0; ->returneaza true daca e dif de 0
//}

//prin functie globala
//in clasa: friend bool operator!(TelefonMobil);
 //in afara clasei
//bool operator!(Telefon t)
//{
//	return t.nivelBaterie != 0;
//}
//in main:
// pt functie membra:
// telefonPersonal.operator!();
//pt functie globala:
//operator!(telefonPersonal);

//functie membra op ++ ->pre->modofica si apoi returneaza
//TelefonMobil operator++()
//{
//	nivelBaterie++;
//	return *this;
//}

//functie globala
// in clasa: friend TelefonMobil operator++(TelefonMobil&);
//TelefonMobil operator++(TelefonMobil& t)
//{
//	t.nivelBaterie++;
//	return t;
//}
//in main: telefonPersonal.operator++();
//pt functie globala operator++(telefonPersonal)

//operator++ post ->functie membra
//TelefonMobil operator++(int i)
//{
// TelefonMobil copie = *this;
//	nivelBaterie++;
//	return copie;
//}

//TelefonMobil operator++(TelefonMobil& t, int i)
//{
//	TelefonMobil copie = t;
//	t.nivelBaterie++;
//	return copie;
//}
//in main: telefonPersonal++;

class Student {
	int varsta;
	const int idStudent;
	string nume;
	int nrNote;
	int* note;
	static string facultate;
	static int nrStudenti;
public:
	Student():idStudent(nrStudenti)
	{
		this->varsta = 0;
		this->nume = "Necunosut";
		this->nrNote = 0;
		this->note = nullptr;
		nrStudenti++;
	}
	Student(int varsta,const int idStudent, string nume, int nrNote, int* note):idStudent(idStudent)
	{
		this->varsta = varsta;
		this->nume =nume;
		this->nrNote = nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < nrNote; i++)
		{
			this->note[i] = note[i];
		}
		nrStudenti++;
	}
	Student(const Student& s):idStudent(s.idStudent)
	{
		this->varsta = s.varsta;
		this->nume = s.nume;
		this->nrNote = s.nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < s.nrNote; i++)
		{
			this->note[i] = s.note[i];
		}
		
	}
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			if (this->note != nullptr)
			{
				delete[] this->note;
			}
			this->varsta = s.varsta;
			this->nume = s.nume;
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < s.nrNote; i++)
			{
				this->note[i] = s.note[i];
			}
			
		}
		return *this;
	}
	//getteri
	int getVarsta()
	{
		return this->varsta;
	}
	const int getIdStudent()
	{
		return this->idStudent;
	}
	string getNume()
	{
		return this->nume;
	}
	int getNrNote()
	{
		return this->nrNote;
	}
	int* getNote()
	{
		return this->note;
	}
	//setteri
	void setNume(string nume)
	{
		if (nume.length() != 0)
		{
			this->nume = nume;
		}
	}
	void setNrNote(int nrNote)
	{
		this->nrNote = nrNote;
	}
	void setNote(int* note, int nrNote)
	{
		if (this->note != nullptr)
		{
			delete[] this->note;
		}
		this->nrNote = nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < nrNote; i++)
		{
			this->note[i] = note[i];
		}
	}
	void setVarsta(int varsta)
	{
		this->varsta = varsta;
	}


	~Student()
	{
		if (this->note != NULL)
		{
			delete[] this->note;
		}
	}
	friend ostream& operator<<(ostream &out, const Student& s)
	{
		out << s.varsta << endl;
		out << s.idStudent << endl;
		out << s.nume << endl;
		out << s.nrNote << endl;
		for (int i = 0; i < s.nrNote; i++)
		{
			out << s.note[i] << endl;
		}
		out << s.facultate << endl;
		out << s.nrStudenti << endl;
		return out;
	}
	/*bool operator !()
	{
		return nrNote > 0;
	}*/
	friend bool operator!(Student s);

	/*Student operator++()
	{
		this->nrNote++;
		return *this;
	}*/
	friend Student operator++(Student& s);
	//Student operator++(int i)
	//{
	//	Student copie = *this;
	//	this->nrNote++;
	//	return copie;
	//}
	friend Student operator++(Student& s, int i);

	/*Student operator+(Student s)
	{
		Student copie = *this;
		copie.varsta = varsta + s.varsta;
		return copie;
	}*/
	friend Student operator+(Student, Student);
	Student operator+(int x)
	{
		
		Student copie = *this;
		copie.varsta = varsta + x;
		return copie;
	}
	friend  Student operator+(int x, Student);
	/*int operator[](int index)
	{
		if (nrNote > 0 && index < nrNote)
		{
			return note[index];
		}
		else return -1;
	}*/
	int& operator[](int index)
	{
		if (nrNote > 0 && index < nrNote)
		{
			return note[index];
		}
		
	}
	operator int()
	{
		return varsta;
	}
	
	int operator ()(int nr)
	{
		return nrNote + nr;
	}
};
bool operator!(Student s)
{
	return s.nrNote > 0;
}

Student operator++(Student& s)
{
	s.nrNote++;
	return s;
}

Student operator++(Student& s, int i)
{
	Student copie = s;
	s.nrNote++;
	return copie;
}
Student operator+(Student s1, Student s2)
{
	s1.varsta += s2.varsta;
	return s1;
}
Student operator+(int x, Student s2)
{
	s2.varsta += x;
	return s2;
}



string Student::facultate = "CSIE";
int Student::nrStudenti = 0;

int main()
{
	Student s;
	cout << s <<  endl;
	int nrNote[1] = { 9 };
	Student s1(17,2, "Dinita Cosmina", 1, nrNote);
	cout << s1 << endl;
	int nrNote2[2] = { 8,9};
	Student s2(20,3, "Simionescu Alexandru", 2, nrNote2);
	cout << s2 << endl;
	int nrNote3[3] = { 8, 7,7 };
	Student s3(21,4, "Neacsu David", 3, nrNote3);
	cout << s3 << endl;
	Student s4(s3);
	cout << s4 << endl;
	s4 = s;
	cout << s4 << endl;
	cout << endl << endl;

	//sa se afiseze studentul cu cel mai mare numar de note
	/*Student vectStudenti[] = { s1, s2, s3};
	int nrStudenti = 3;
	int maxim = 0;
	Student rezultat;
	for (int i = 0; i < nrStudenti; i++)
	{
		if (vectStudenti[i].getNrNote() >= maxim)
		{
			maxim = vectStudenti[i].getNrNote();
			rezultat = vectStudenti[i];
		}
	}
	cout << rezultat << endl;

	int minim = vectStudenti[0].getNrNote();
	Student rezultatMinim;
	for (int i = 0; i < nrStudenti; i++)
	{
		if (vectStudenti[i].getNrNote() <= minim)
		{
			minim = vectStudenti[i].getNrNote();
			rezultatMinim = vectStudenti[i];
		}
	}
	
	cout << rezultatMinim << endl;
	cout << s3.getNrNote() << endl;*/
	if (!s3)
	{
		cout << "Studentul are note" << endl;;
	}
	else
	{
		cout << "Studentul nu are note" << endl;
	}
	cout << endl << endl << endl;
	cout << s1.getNrNote() << endl;
	s2 = s1++;
	cout << s2 << endl;
	cout << s1 << endl;
	
	++s1;
	cout << s1 << endl;

	//sa se afiseze student cu cele mai multe ore
	Student vectStudenti[] = { s1, s2, s3 };
	int maxim = 0;
	int nrStudenti = 3;
	Student rezultat;
	for (int i = 0; i < nrStudenti; i++)
	{
		if (vectStudenti[i].getNrNote() > maxim)
		{
			maxim = vectStudenti[i].getNrNote();
			rezultat = vectStudenti[i];
		}
	}
	cout << rezultat << endl;

	Student vectStudentiNrMin[] = { s1, s2, s3 };
	int minim = vectStudentiNrMin[0].getNrNote();
	int nrStudentiMin = 3;
	Student rezultatMin = vectStudentiNrMin[0];
	for (int i = 0; i < nrStudentiMin; i++)
	{
		if (vectStudentiNrMin[i].getNrNote() < minim)
		{
			minim = vectStudentiNrMin[i].getNrNote();
			rezultatMin = vectStudentiNrMin[i];
		}
	}
	cout << rezultatMin << endl;
	
	cout << s1.getVarsta() << endl;
	cout << s2.getVarsta() << endl;
	s1 = s2 + s1;
	cout << s1.getVarsta();
	cout << endl << endl;
	cout << s1.getVarsta() << endl;
	s1 + 1;
	
	cout << s1.getVarsta() << endl;
	cout << endl << endl;
	cout << s2.getVarsta() << endl;
	2 + s2;
	cout << s2.getVarsta() << endl;
	cout << s3[1] << endl;
	s3[1] = 10;
	cout << s3[1] << endl;

	cout << endl << endl << endl << endl;
	int varsta = (int)s1;
	cout << varsta << endl << endl;;

	cout << s1.getNrNote() << endl;
	int nr = s1(10);
	cout << nr << endl;
}


/*
 //operatori binari
//op +
 functie membra
TelefonMobil operator+(TelefonMobil t)
{
TelefonMobil copie = *this;
copie.nivelBaterie = nivelBaterie + t.nivelBaterie;
return copie;
}
in main:
telefonMobil telefon = telefonPersonal + telefonDeServiciu;
sau
telefonPersonal.operator+(telefonDeServiciu);

functie globala
friend TelefonMobil operator+(TelefonMobil, TelefonMobil);
TelefonMobil operator+(TelefonMobil t1, TelefonMobil t2)
{
t1.nivelBaterie += t2.nivelBaterie;
return t1;
}
in main:
operator+(telefonPersonal, telefonDeServiciu)


//op + ->adunare cu un nr intreg
functie membra
TelefonMobil operator+(int x)
{
TelefonMobil copie = *this;
copie.nivelBaterie = nivelBaterie + x;
return copie;
}
--------------AICI TREBUIE SA EXISTE AMBELE DACA VREM SA FACEM SI t+20 si 20+t----------------

functie globala, sa putem face si 20+t nu doar t+20
friend TelefonMobil operator+(int x, TelefonMobil);
TelefonMobil operator+(int x, TelefonMobil t2)
{
t2.nivelBaterie += x;
return t2;
}

//operatorii de citire si de afisare la consola
<<
in clasa:
friend ostream& operator<<(ostream&, TelefonMobil);
in afara clasei:
ostream& operator<<(ostream& out, TelefonMobil t)
{
	out << t.nivelbaterie;
	....
	return out;
}
>>
friend istream& operator>>(istream&, TelefonMobil&);

istream& operator>>(istream& in, TelefonMobil& t)
{
in>>t.nivelBaterie;

return in;
}

*/

/*
operatori particulari: 
operatorul[] ->op de indexare(doar prin functie membra)
->are doi param(obiectul si un idex)
->se poate folosi pt citire->getter
->citire/scriere -> getter and setter

//doar pt citire
int operator[](int index)
{
if(index >= 0 && index < nrZile)
{
return durataZilniceUtilizare[index];
}
else return -1;
}

//si pt citire si pt modificare
int& operator[](int index)
{
if(index >= 0 && index < nrZile)
{
return durataZilniceUtilizare[index];
}

}


operatorul cast->transforma un telefon in alt tip de data
->are mereu in parametru obiectul de clasa
->nu are tip returnat

operator int()
{
return nivelBaterie;
}
in main:
int nivel = telefonPersonal;(implicit) ->nu e recomandat
int nivel = (int)telefonPersonal;(explicit)


operatorul functie->transforma obiectul intr-o functie->doar prin functie membra
int operator()(int nivel)
{
return nivelBaterie + nivel;
}
in main-->int nivel = telefonPersonal(50);

*/

