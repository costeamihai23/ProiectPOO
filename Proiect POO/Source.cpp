#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <fstream>

using namespace std;
class IndexOutOfBoundsException : public exception
{
public:
	virtual char* what() 
	{
		char* iob = new char[strlen("Index in afara limitelor") + 1];
		strcpy(iob, "Index in afara limitelor");
		return iob;
	}
};

class NullPointerException : public exception
{
public:
	char* what()
	{
		char* np = new char[strlen("NullPointer - vectorul este gol") + 1];
		strcpy(np, "NullPointer - vectorul este gol");
		return np;
	}
};


class Magazin 
{
private:
	string tipPlata;
	string descriereComanda;
	int nrComenzi;
	int dataComanda[2021];
	char* numeMagazin;
	int nrProduse;
	const int nrInregistrare;
	static int nrComanda;

public:

	//constructor fara parametrii
	Magazin() : nrInregistrare(1532) 
	{
		this->tipPlata = "Numerar";
		this->descriereComanda = "Comanda efectuata contine: ";
		this->nrComenzi = 100000;
		for (int i = 0; i < this->nrComenzi; i++) {
			this->dataComanda[i] = rand() % 100000 + 1;
		}
		this->numeMagazin = new char[strlen("eMAG") + 1];
		strcpy(this->numeMagazin, "eMAG");
		this->nrProduse = 3;
	}
	//constructor cu parametrii
	Magazin(string tipPlata, string descriereComanda, int nrComenzi, int dataComanda[2021], const char* numeMagazin, int nrComanda) :nrInregistrare(1533)
	{
		this->tipPlata = tipPlata;
		this->descriereComanda = descriereComanda;
		this->nrComenzi = nrComenzi;
		for (int i = 0; i < this->nrComenzi; i++)
		{
			this->dataComanda[i] = dataComanda[i];
		}
		this->numeMagazin = new char[strlen(numeMagazin) + 1];
		strcpy(this->numeMagazin, numeMagazin);
		this->nrProduse = nrProduse;
		//Incrementare camp static
		this->nrComanda++;
	}
	//Constructor de copiere

	Magazin(const Magazin& magazin) : nrInregistrare(1534)
	{
		this->tipPlata = magazin.tipPlata;
		this->descriereComanda = magazin.tipPlata;
		this->nrComenzi = magazin.nrComenzi;
		for (int i = 0; i < this->nrComenzi; i++) 
		{
			this->dataComanda[i] = magazin.dataComanda[i];
		}
		this->numeMagazin = new char[strlen(magazin.numeMagazin) + 1];
		strcpy(this->numeMagazin, magazin.numeMagazin);
		this->nrProduse = magazin.nrProduse;
	}

	//Supraincarcarea operatorului =
	Magazin& operator =(const Magazin& magazin)
	{
		this->tipPlata = magazin.tipPlata;
		this->descriereComanda = magazin.tipPlata;
		this->nrComenzi = magazin.nrComenzi;
		for (int i = 0; i < this->nrComenzi; i++)
		{
			this->dataComanda[i] = magazin.dataComanda[i];
		}
		this->numeMagazin = new char[strlen(magazin.numeMagazin) + 1];
		strcpy(this->numeMagazin, magazin.numeMagazin);
		this->nrProduse = magazin.nrProduse;
		return *this;
	}

	//Supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Magazin& magazin)
	{
		out << magazin.tipPlata << endl;
		out << magazin.descriereComanda << endl;
		out << magazin.nrComenzi << endl;
		for (int i = 0; i < magazin.nrComenzi; i++)
		{
			out << magazin.dataComanda[i] << endl;
		}
		out << magazin.numeMagazin << endl;
		out << magazin.nrProduse << endl;

		return out;
	}

	//Supraincarcarea operatorului >>

	friend istream& operator>>(istream& in, Magazin& magazin)
	{
		cout << "Tipul platii efectuate este: ";
		in >> magazin.tipPlata;
		cout << endl << "Descrierea comenzii: ";
		in >> magazin.descriereComanda;
		cout << endl << "Numarul de comenzi efectuate de acest utilizator este: ";
		in >> magazin.nrComenzi;
		cout << endl << "Anul in care a efectuat aceasta comanda: ";
		for (int i = 0; i < magazin.nrComenzi; i++) 
		{
			in >> magazin.dataComanda[i];

		}
		cout << endl << "Numele magazinului de unde a comandat este: ";
		in >> magazin.numeMagazin;
		cout << endl << "Numarul de produse achizitionate: ";
		in >> magazin.nrProduse;
		return in;

	}

	string getTip() 
	{
		return this->tipPlata;
	}
	string getDescriere() 
	{
		return this->descriereComanda;
	}
	int getNrComenzi()
	{
		return this->nrComenzi;
	}
	int* getDataComanda()
	{
		return this->dataComanda;
	}
	char* getNume() 
	{
		return this->numeMagazin;
	}
	int getNrProduse()
	{
		return this->nrProduse;
	}

	void setTip(string tipPlata)
	{
		this->tipPlata = tipPlata;
	}
	void setDescriere(string descriereComanda) 
	{
		if (descriereComanda.length() > 10 && descriereComanda.length() <= 40)
			this->descriereComanda = descriereComanda;
	}
	void setNrComenzi(int nrComenziN) 
	{
		this->nrComenzi = nrComenziN;
	}
	//void setAnComanda(int dataComanda[], int numar)
	//{
		//for (int i = 0; i < numar; i++) {
			//if (dataComanda > 2005 && dataComanda < 2022)
				//this->dataComanda[i] = dataComanda[i];
		//}
	//}
	void setNume(char* numeMagazin) 
	{
		if (strlen(numeMagazin) > 3)
			strcpy(this->numeMagazin, numeMagazin);
			
	}
	void setNrProduse(int nrProduse)
	{
		this->nrProduse = nrProduse;
	}

	//supraincarcarea operatorului []
	int& operator[](int index) 
	{
		if (index > 0 || index > this->nrComenzi) 
		{
			cout << "Indexul este in afara ariei de acoperire" << endl;
			throw new exception("Exception");
		}
		else
			return this->dataComanda[index];
		
	}
	
	//supraincarcarea operatorilor matematici
	Magazin operator+(int nr)
	{
		this->nrComenzi += nr;
		return*this;
	}
	Magazin operator-(int nr)
	{
		this->nrComenzi -= nr;
		return*this;
	}

	//Supraincarcarea ++ prefixat
	Magazin operator++()
	{
		this->nrComenzi++;
		int dataComanda2[2005];
		for (int i = 0; this->nrComenzi; i++)
		{
			dataComanda2[i] = this->dataComanda[i];
		}
		dataComanda[this->nrComenzi] = 2010;
		return*this;
	}

	//supraincarcare op. cast explicit

	explicit operator float() 
	{
		return this->nrComenzi;
	}

	//supraincarcarea op. negatie

	bool operator!()
	{
		if (this->dataComanda != NULL)return false;
		else return true;
	}
	//supraincare op. >=
	bool operator>=(Magazin m) 
	{
		if (this->nrComenzi >= m.nrComenzi)
			return true;
		else
			return false;
	}
	//supraincarcar op. ==
	
	bool operator==(Magazin m)
	{
		return this->nrProduse = m.nrProduse;
	}

	void afisare() 
	{
		cout << "Tipul platii efectuate: " << this->tipPlata << endl;
		cout << "Produsele comandate: " << this->descriereComanda << endl;
		cout << "Numarul de comenzi efectuate de catre acest utilizator" << this->nrComenzi << endl;
		for (int i = 0; i < this->nrComenzi; i++) {
			cout << "Anul in care a fost efectuata comanda este: " << this->dataComanda[i] << endl;
		}
		cout << "Numele magazinului de unde a fost efectuata comanda: " << this->numeMagazin;
	}
	
};

//clasa abstracta

class Altex : public Magazin 
{
private:
	string tipMagazin;
public:
	Altex() :Magazin()
	{
		this->tipMagazin = "Online";
	}
	Altex(string tipMagazin, string tipPlata, string descriereComanda, int nrComenzi, int dataComanda[2018], char* numeMagazin, int nrProduse) : Magazin(tipPlata, descriereComanda, nrComenzi, dataComanda, numeMagazin, nrProduse)
	{
		this->tipMagazin = tipMagazin;
	}
	string getTipMagazin() 
	{
		return this->tipMagazin;
	}
	void setTipMagazin(string tipMagazinM) 
	{
		this->tipMagazin = tipMagazinM;
	}
	virtual void calculProfit() = 0; 
	//metoda virtuala
	virtual ~Altex() 
	{

	}//destructor virtual
};

//interfata

class CalculComenzi 
{
public:
	virtual void calculValoareMedieComenzi() = 0;
	virtual void calculNrComenzi() = 0;
};

//clasa mostenitoare
class AltexMediaGalaxy : public Altex, public CalculComenzi
{
public:
	virtual void calculProfit() 
	{
		cout << "Calculeaza profitul" << endl;
	}
	virtual void calculValoareMedieComenzi() 
	{
		cout << "Valoarea medie a comenzilor efectuate" << endl;
	}
	virtual void calculNrComenzi() 
	{
		cout << "Calculeaza numarul de comenzi efectuate" << endl;
	}

	
};

//clasa "has a"

class Comanda
{
private:
	int nrLivrari;
	Magazin** tipLivrare;
public:
	Comanda()
	{
		this->nrLivrari = 0;
		this->tipLivrare = NULL;
	}
	Comanda(int nrLiv, Magazin** tipLiv) 
	{
		this->nrLivrari = nrLiv;
		this->tipLivrare = new Magazin*[this->nrLivrari];
		for (int i = 0; i < this->nrLivrari; i++) 
		{
			this->tipLivrare[i] = tipLiv[i];
		}

	}
	~Comanda()
	{
		cout << "Apelul destructorului din clasa Comanda" << endl;
	if (this->tipLivrare != NULL)
	{
		delete[] this->tipLivrare;
	}
	}
	void afisare()
	{
		cout << "Afisare livrare" << endl;
		cout << "Numarul de livrari efectuate este: " << this->nrLivrari << endl;
		for (int i = 0; i < this->nrLivrari; i++) 
		{
			this->tipLivrare[i]->afisare();
		}
	}
};

class Produs 
{
private:
	string numeProdus;
	string tipProdus;
	int serieProdus;
	int procentReducere[100];
	string* clasaProdus;
	float pretRedus;
	static int pretProdus;
	const int nrInregistrareProdus;
public:
	//constructor fara param.
	Produs() :nrInregistrareProdus(218432) 
	{
		this->numeProdus = "ASUS MA ROG LA DUMNEZEU SA MEARGA";
		this->tipProdus = "Laptop";
		this->serieProdus = 6000;
		this->clasaProdus = new string[this->serieProdus];
		for (int i = 0; i < this->serieProdus; i++) 
		{
			clasaProdus[i] = "Tip produs" + to_string(i + 1);
		}
		for (int i = 0; i < this->serieProdus; i++)
		{
			procentReducere[i] = i + rand() % 10;
		}
	}
	//const cu parametrii
	Produs(string numeProdus, string tipProdus, int serieProdus, int procentReducere[100], string* clasaProdus, float pretProdus) :nrInregistrareProdus(218433)
	{
		this->numeProdus;
		this->tipProdus;
		this->serieProdus;
		for (int i = 0; i < this->serieProdus; i++) 
		{
			this->procentReducere[i] = procentReducere[i];
		}
		this->clasaProdus = new string[this->serieProdus];
		for (int i = 0; i < this->serieProdus; i++) 
		{
			this->clasaProdus = clasaProdus;
		}
	}

	void afisare() {
		cout << "Numele produsului este: " << this->numeProdus << endl;
		cout << "Tipul produsului: " << this->tipProdus << endl;
		cout << "Seria produsului este: " << this->serieProdus << endl;
		cout << "Procentul de reducere: " << this->procentReducere << endl;
		for (int i = 0; i < this->serieProdus; i++)
		{
			cout << "Procentul de reducere: " << this->procentReducere[i] << endl;
		}
		cout << "Clasa produsului bazata pe pretul initial este: " << endl;
		for (int i = 0; this->serieProdus; i++)
		{
			cout << this->clasaProdus[i] << endl;
		}
	}
	//constructorul de copiere
	Produs(const Produs& produs) :nrInregistrareProdus(4)
	{
		this->tipProdus = produs.tipProdus;
		this->numeProdus = produs.numeProdus;
		this->serieProdus = produs.serieProdus;
		for (int i = 0; i < this->serieProdus; i++)
		{
			this->clasaProdus[i] = produs.clasaProdus[i];
		}
		for (int i = 0; i < this->serieProdus; i++)
		{
			this->procentReducere[i] = procentReducere[i];
		}
		this->pretRedus = produs.pretRedus;
		//increm. atrb static
		this->pretProdus++;
	}
	string getTipProdus() 
	{
		return this->tipProdus;
	}
	string getNumeProdus() 
	{
		return this->numeProdus;
	}

	int getSerieProdus() 
	{
		return this->serieProdus;
	}
	string* getClasaProdus()
	{
		return this->clasaProdus;
	}
	int* getReducere()
	{
		return this->procentReducere;
	}
	float getPretFinal()
	{
		return this->pretRedus;
	}
	//setteri
	void setTipProdus(string tipProdus)
	{
		if (tipProdus == "Laptop" || tipProdus == "Calculator" || tipProdus == "Consola" || tipProdus == "Controller" || tipProdus == "Scaun gaming")
			this->tipProdus = tipProdus;
	}
	void setNumeProdus(string numeProdus) 
	{
		if(numeProdus=="Asus"||numeProdus=="Playstation"||numeProdus=="XBOX"||numeProdus=="Lenovo"||numeProdus=="Kring")
		{
			this->numeProdus = numeProdus;
		}
	}
	void setSerieProdus(int serieProdusNoua)
	{
		this->serieProdus = serieProdusNoua;
	}
	void setClasaProdus(string* vectorClasaProdus, int serieProdusNoua) {
		if(this->clasaProdus!=NULL)
		{
			delete[] this->clasaProdus;
		}
		this->serieProdus = serieProdusNoua;
		this->clasaProdus = new string[this->serieProdus];
		for (int i = 0; i < this->serieProdus; i++) {
			this->clasaProdus[i] = vectorClasaProdus[i];
		}
	}
	void setPretRedus(float pretRedus) {
		if (pretRedus == pretProdus - (pretProdus * 10) / 100)
			this->pretRedus = pretRedus;
	}

	//supraincarcarea operatorului =
	Produs& operator=(const Produs& produs)
	{
		this->tipProdus = produs.tipProdus;
		this->numeProdus = produs.numeProdus;
		this->serieProdus = produs.serieProdus;
		this->clasaProdus = new string[this->serieProdus];
		for(int i=0;i<this->serieProdus;i++)
		{
			this->clasaProdus[i] = produs.clasaProdus[i];
		}
		for (int i = 0; i < this->serieProdus; i++)
		{
			procentReducere[i] = produs.procentReducere[i];
		}
		this->pretRedus = produs.pretRedus;
		return*this;
	}
	//Supraincarcarea operatorului <<

	friend ostream& operator<<(ostream& out, Produs& p)
	{
		out << "Tipul produsului " << p.tipProdus << endl;
		out << "Numele produsului este " << p.numeProdus << endl;
		out << "Seria produsului este " << p.serieProdus << endl;
		out << "Clasa produsului " << endl;
		for (int i = 0; i < p.serieProdus ; i++)
		{
			out << "Clasa: " << p.clasaProdus[i] << endl;
		}
		for (int i = 0; i < p.serieProdus; i++)
		{
			out << "Procentul de reducere: " << p.procentReducere[i] << endl;
		}
		out << "Pret produs dupa reducere: " << p.pretRedus <<endl;
		return out;
	}

	//Supraincarcare operator >>
	friend istream& operator>>(istream& in, Produs& p)
	{
		cout << "Tipul produsului: " << endl;
		in >> p.tipProdus;
		cout << "Numele:  " << endl;
		in >> p.numeProdus;
		cout << "Seria: " << endl;
		in >> p.serieProdus;
		cout << "Clase: " << endl;
		if (p.serieProdus != NULL)
		{
			delete[] p.clasaProdus;
		}
		p.clasaProdus = new string[p.serieProdus];
		for (int i = 0; i < p.serieProdus; i++)
		{
			cout << endl << "Clasa" << i + 1;
			in >> p.clasaProdus[i];
		}
		cout << "Pret redus: " << endl;
		in >> p.pretRedus;
		return in;

	}

	//Destructorul
	~Produs()
	{
		if (this->clasaProdus != NULL)
		{
			delete[] this->clasaProdus;
		}
		this->serieProdus--;
	}

	//supraincarcare operator [] pentru accesarea elementelor de pe pozitia index

	string& operator[](int index)
	{
		if (index < 0 || index >this->serieProdus) 
		{
			throw new IndexOutOfBoundsException();
		}
		else if (this->clasaProdus == NULL) 
		{
			throw new NullPointerException();
		}
		else 
		{
			return this->clasaProdus[index];
		}
	}

	//supraincarcarea operatorilor matematici
	Produs operator+(int numar)
	{
		this->serieProdus += numar;
		return*this;
	}
	Produs operator-(float numar)
	{
		this->serieProdus -= numar;
		return*this;
	}
	//supraincarcarea operatorului cast la float; afisarea pretului redus
	explicit operator float()
	{
		return this->pretRedus;
	}
	//supraincarcare +=
	Produs operator+=(int numar)
	{
		this->serieProdus += numar;
		return *this;
	}

	//supraincarcare operator ++ prefixat; apel+m1
	Produs operator++(int)
	{
		Produs copie = *this;
		string* clasaProdusNoua = new string[this->serieProdus + 1];
		for (int i = 0; i < this->serieProdus; i++)
		{
			clasaProdusNoua[i] = this->clasaProdus[i];
		}
		clasaProdusNoua[this->serieProdus] = "Clasa noua adaugata";
		this->serieProdus++;
		if (this->serieProdus != NULL)
		{
			delete[] this->clasaProdus;
		}
		this->clasaProdus = clasaProdusNoua;
		return copie;
	}
	//supraincarcare operator negatie
	bool operator !()
	{
		if (this->clasaProdus != NULL)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
	//Supraincarcare op. conditional >=
	bool operator>=(Produs& p)
	{
		if (this->pretRedus >= p.pretRedus)
		
			return true;
		else 
			return false;
	}

	//citire si afisare
	friend ofstream& operator<<(ofstream& out, Produs& p)
	{
		out << "Tipul produsului: " << p.tipProdus << endl;
		out << "Nume produs: " << p.numeProdus << endl;
		out << "Seria produsului: " << p.serieProdus << endl;
		out << "Clasa produs: " << endl;
		for (int i = 0; i < p.serieProdus; i++)
		{
			out << "Clasa: " << p.clasaProdus[i] << endl;
		}
		for (int i = 0; i < p.serieProdus; i++)
		{
			out << "Procent de reducere: " << p.procentReducere[i] << endl;
		}
		out << "Pret dupa reducere" << p.pretRedus << endl;
		return out;
	}
	friend ifstream& operator>>(ifstream& in, Produs& p)
	{
		cout << "Tipul produsului: " << endl;
		in >> p.tipProdus;
		cout << "Numele produsului: " << endl;
		in >> p.numeProdus;
		cout << "Seria produsului: " << endl;
		in >> p.serieProdus;
		cout << "Clasa produsului: ";
		if (p.serieProdus != NULL)
		{
			delete[] p.clasaProdus;
		}
		p.clasaProdus = new string[p.serieProdus];
		for (int i = 0; i < p.serieProdus; i++)
		{
			cout << endl << "Clasa: " << i + 1;
			in >> p.clasaProdus[i];
		}
		cout << "Pret redus: " << endl;
		in>>p.pretRedus;
		return in;
	}

};
