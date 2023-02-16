#include <cstdio>
#include <string>

using namespace std;

class Hewan {
	public:
		Hewan(string nm) {
            this->nama = nm;
        } 

        ~Hewan() {
            printf("Hewan mati ");
            printf("%s\n", this->nama.c_str());
        }

        virtual void print() {
            printf("Hewan ini namanya ");
            printf("%s\n", this->nama.c_str());
        }

	protected:
		string nama;
};

class Kucing : public Hewan {
	public:
		Kucing(string nm) : Hewan(nm) {};

        virtual ~Kucing() {
            printf("Kucing mati ");
            printf("%s\n", this->nama.c_str());
        }
};

class KucingAnggora : public Kucing {
	public:
		KucingAnggora(string namaHewan, string namaPemilik) : Kucing(namaHewan) {
            this->pemilik = namaPemilik;
        }

        ~KucingAnggora() {
            printf("Kucing anggora mati ");
            printf("%s\n", this->nama.c_str());
        }

        void print() {
            printf("Kucing anggora ini namanya ");
            printf("%s", this->nama.c_str());
            printf(". Pemiliknya adalah ");
            printf("%s\n", this->pemilik.c_str());
        }
    protected:
        string pemilik;
};

class Anjing : public Hewan {
    public:
		Anjing(string nm) : Hewan(nm) {};

        ~Anjing() {
            printf("Anjing mati ");
            printf("%s\n", this->nama.c_str());
        }

        void print() {
            printf("Anjing ini namanya ");
            printf("%s\n", this->nama.c_str());
        }
};

class AnjingBulldog : public Anjing {
	public:
		AnjingBulldog(string namaHewan, string namaPemilik) : Anjing(namaHewan) {
            this->pemilik = namaPemilik;
        }

        ~AnjingBulldog() {
            printf("Anjing bulldog mati ");
            printf("%s\n", this->nama.c_str());
        }

        void print() {
            printf("Anjing bulldog ini namanya ");
            printf("%s", this->nama.c_str());
            printf(". Pemiliknya adalah ");
            printf("%s\n", this->pemilik.c_str());
        }
	private:
		string pemilik;
};