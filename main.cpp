#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class examen
{
protected:
    static int contor;
    int numar;
    float maxscris;  // Nota de trecere la scris este nota maxima la scris / 2
    float maxpartial; // Nota de trecere la partial este nota maxima la partial / 2
    float maxoral;
    float maxproiect;
    float maxquiz;
    string denumire;
public:
    static int getnumarexamene() {return contor;}
    const int getnumar() {return numar;}
    string getdenumire() {return denumire;}
    float getmaxscris() {return maxscris;}
    float getmaxpartial() {return maxpartial;}
    float getmaxoral() {return maxoral;}
    float getmaxproiect() {return maxproiect;}
    float getmaxquiz() {return maxquiz;}
    examen(string denumire = "")
    {
        this -> denumire = denumire;
        this -> numar = ++contor;
    }
    ~examen()
    {
        contor--;
        if(!denumire.empty()) denumire.erase(denumire.begin(), denumire.end());
    }
    friend istream& operator>>(istream& in, examen& e)
    {
        string nume;
        float x;
        cout << "Numele examenului cu id " << e.numar << ": ";
        cin >> nume;
        e.denumire = nume;
        cout << "Nota maxima la scris: ";
        do
        {
            cin >> x;
            if (x < 0) cout << "Nota invalida; introduceti alta valoare: ";
        }
        while (x < 0);
        x = e.maxscris;
        cout << "Nota maxima la partial: ";
        do
        {
            cin >> x;
            if (x < 0) cout << "Nota invalida; introduceti alta valoare: ";
        }
        while (x < 0);
        x = e.maxpartial;
        cout << "Nota maxima la oral: ";
        do
        {
            cin >> x;
            if (x < 0) cout << "Nota invalida; introduceti alta valoare: ";
        }
        while (x < 0);
        x = e.maxoral;
        cout << "Nota maxima la proiect: ";
        do
        {
            cin >> x;
            if (x < 0) cout << "Nota invalida; introduceti alta valoare: ";
        }
        while (x < 0);
        x = e.maxproiect;
        cout << "Nota maxima la quiz: ";
        do
        {
            cin >> x;
            if (x < 0) cout << "Nota invalida; introduceti alta valoare: ";
        }
        while (x < 0);
        x = e.maxquiz;
        return in;
    }
    friend ostream& operator<<(ostream& out, examen& e)
    {
        cout << "Examen la " << e.denumire << " (id = " << e.numar << ")" << endl;
        return out;
    }
};
class notare : public examen
{
    float nota_scris = 0;
    float nota_partial = 0;
    float nota_oral = 0;
    float nota_proiect = 0;
    float nota_quiz = 0;
    bool quiz = 0;
public:
    float getscris() {return nota_scris;}
    float getpartial() {return nota_partial;}
    float getoral() {return nota_oral;}
    float getproiect() {return nota_proiect;}
    float getquiz() {return nota_quiz;}
    bool getquizz() {return quiz;}
    void setmax (examen e)
    {
        this -> numar = e.getmaxscris();
        this -> maxscris = e.getmaxscris();
        this -> maxpartial = e.getmaxpartial();
        this -> maxoral = e.getmaxoral();
        this -> maxproiect = e.getmaxproiect();
        this -> maxquiz = e.getmaxquiz();
    }
    notare()
    {
        contor--; // pentru a pastra contorul corect in clasa examen
    }
    notare(examen e)
    {
        setmax(e);
        contor--; // pentru a pastra contorul corect in clasa examen
    }
    ~notare()
    {
        contor++; // pentru a pastra contorul corect in clasa examen
    }
    friend istream& operator>>(istream& in, notare& n)
    {
        cout << "Nota luata la oral: ";
        cin >> n.nota_oral;
        if (n.nota_oral > n.getmaxoral())
        {
            n.nota_oral = n.getmaxoral();
            cout << "S-a inserat " << n.getmaxoral() << " (maximul la oral)." << endl;
        }
        if (n.nota_oral < 0)
        {
            n.nota_oral = 0;
            cout << "S-a inserat 0." << endl;
        }
        cout << "Nota luata la partial: ";
        cin >> n.nota_partial;
        if (n.nota_partial > n.getmaxpartial())
        {
            n.nota_partial = n.getmaxpartial();
            cout << "S-a inserat " << n.getmaxpartial() << " (maximul la partial)." << endl;
        }
        if (n.nota_partial < 0)
        {
            n.nota_partial = 0;
            cout << "S-a inserat 0." << endl;
        }
        cout << "Nota luata la proiect: ";
        cin >> n.nota_proiect;
        if (n.nota_proiect > n.getmaxproiect())
        {
            n.nota_proiect = n.getmaxproiect();
            cout << "S-a inserat " << n.getmaxproiect() << " (maximul la proiect)." << endl;
        }
        if (n.nota_proiect < 0)
        {
            n.nota_proiect = 0;
            cout << "S-a inserat 0." << endl;
        }
        cout << "Nota luata la scris: ";
        cin >> n.nota_scris;
        if (n.nota_scris > n.getmaxscris())
        {
            n.nota_scris = n.getmaxscris();
            cout << "S-a inserat " << n.getmaxscris() << " (maximul la scris)." << endl;
        }
        if (n.nota_scris < 0)
        {
            n.nota_scris = 0;
            cout << "S-a inserat 0." << endl;
        }
        if (n.nota_partial < n.getmaxpartial() / 2)
        {
            cout << "Nota luata la partialul dat la examenul final: "; // partialul de la examen va inlocui partialul din timpul semestrului; conditia pentru trecerea materiei ramane ca si nota de la scris, si cea de la partial sa depaseasca jumatate din maximul acestora
            cin >> n.nota_partial;
            if (n.nota_partial > n.getmaxpartial())
            {
                n.nota_partial = n.getmaxpartial();
                cout << "S-a inserat " << n.getmaxpartial() << " (maximul la partial)." << endl;
            }
            if (n.nota_partial < 0)
            {
                n.nota_partial = 0;
                cout << "S-a inserat 0." << endl;
            }
        }
        if (n.nota_partial > n.getmaxpartial() / 2 && n.nota_scris > n.getmaxscris() / 2)
        {
            string op;
            cout << "Studentul a vrut sa dea quiz? (da/nu)" ;
            cin >> op;
            if (op == "da")
            {
                cout << "Nota luata la quiz: ";
                cin >> n.nota_quiz;
                if (n.nota_quiz > n.getmaxquiz())
                {
                    n.nota_quiz = n.getmaxquiz();
                    cout << "S-a inserat " << n.getmaxquiz() << " (maximul la quiz)." << endl;
                }
                if (n.nota_quiz < 0)
                {
                    n.nota_quiz = 0;
                    cout << "S-a inserat 0." << endl;
                }
                n.quiz = 1;
            }
            if (op == "nu") n.quiz = 0;
        }
        else cout << "Studentul are restanta la aceasta materie!" << endl;
        return in;
    }
    friend ostream& operator<<(ostream& out, notare& n)
    {
        cout << "Notele studentului la materia " << n.numar << ": oral - " << n.nota_oral << ", partial - " << n.nota_partial << ", proiect - " << n.nota_proiect << ", scris - " << n.nota_scris;
        if (n.nota_partial > n.getmaxpartial() / 2 && n.nota_scris > n.getmaxscris() / 2)
        {
            if (n.getquizz() == 1)
            {
                 cout << ", quiz - " << n.nota_quiz;
            }
            else cout << ", fara quiz";
            cout << endl << "Nota finala la aceasta materie este ";
            if (n.getoral() + n.getpartial() + n.getproiect() + n.getscris() + n.getquiz() > n.getmaxoral() + n.getmaxpartial() + n.getmaxscris()) cout << n.getmaxoral() + n.getmaxpartial() + n.getmaxscris();
            else cout << n.getoral() + n.getpartial() + n.getproiect() + n.getscris() + n.getquiz();
            cout << "/" << n.getmaxoral() + n.getmaxpartial() + n.getmaxscris();
        }
        else cout << endl << "Studentul are restanta la aceasta materie!";
        cout << endl;
        return out;
    }
};

template <class T>
class CatalogIndividual
{
    static int contor;
    int nr_matricol;
    unsigned int nr_examene;
    vector<T> v;
public:
    int getmat() {return nr_matricol;}
    int getex() {return nr_examene;}
    CatalogIndividual(int nr_examene = 0)
    {
        this -> nr_examene = nr_examene;
        this -> nr_matricol = ++contor;
    }
    ~CatalogIndividual()
    {
        contor--;
    }
    void operator+=(T fisa)
    {
        if (v.size() < nr_examene) v.push_back(fisa);
        else cout << "Studentul " << getmat() << " a dat deja " << getex() << " examene!" << endl;
    }
    friend istream& operator>>(istream& in, CatalogIndividual& c)
    {
        int x;
        cout << "Cate examene trebuie sa dea studentul " << c.getmat() << "? ";
        cin >> x;
        c.nr_examene = x;
        return in;
    }
    friend ostream& operator<<(ostream& out, CatalogIndividual<T>& c) // de incercat sa scot <T>
    {
        typename vector<T>::iterator it;
        for(it = c.v.begin(); it != c.v.end(); it++)
        {
            cout << *it;
        }
        return out;
    }
};

int examen::contor = 0;
template<class T>
int CatalogIndividual<T>::contor = 0;

class gestionare // clasa singleton pentru memorarea mai multor obiecte examen si CatalogIndividual
{
    vector<examen*> e;
    vector<CatalogIndividual<notare>*> c;
    unordered_map <int, vector<int>> restantieri;
    gestionare()
    {

    }
    gestionare(gestionare & ob)
    {
        e = ob.e;
        c = ob.c;
    }
    gestionare &operator=(gestionare & ob)
    {
        if (this != &ob)
        {
            e = ob.e;
            c = ob.c;
        }
        return *this;
    }
    static gestionare * instanta;
public:
    static gestionare *get_instanta();
    vector<examen*> getvex() {return e;}
    vector<CatalogIndividual<notare>*> getvc() {return c;}
    unordered_map<int,vector<int>>& getum() {return restantieri;}
    void addrestantieri(int numar, int nr_mat)
    {
        restantieri[numar].push_back(nr_mat);
    }
};
gestionare *gestionare::instanta = NULL;
gestionare *gestionare::get_instanta()
{
    if (instanta == NULL)
        instanta = new gestionare();
    return instanta;
}

int main()
{
    gestionare * g = gestionare::get_instanta();
    int o, x, y;
    while (1)
    {
        cout << "[1 - adaugare examen; 2 - adaugare student; 3 - adaugarea unei fise de examen la un student; 4 - vizualizare examene; 5 - vizualizare studenti; 6 - verificare restantieri; 7 - vizualizarea studentilor ce au dat minim 2 quizuri; 8 - exit]" << endl << "Optiunea ";
        cin>>o;
        if (o == 8) break;
        switch (o)
        {
            case 1:
            {
                examen ex;
                cin >> ex;
                g->getvex().push_back(&ex);
                break;
            }
            case 2:
            {
                CatalogIndividual<notare> c;
                cin >> c;
                g->getvc().push_back(&c);
                break;
            }
            case 3:
            {
                cout << "La ce materie? ";
                cin >> x; //verificare
                cout << "Carui student? ";
                cin >> y; // verificare
                unsigned int i;
                notare n;
                for(i = 0; i < (g -> getvex()).size(); i++)
                {
                    if ((g -> getvex())[i] -> getnumar() == x) break;
                }
                if (i < (g -> getvex()).size())
                {
                    n.setmax(*(g -> getvex())[i]);
                }
                for(i = 0; i < (g -> getvc()).size(); i++)
                {
                    if ((g -> getvc())[i] -> getmat() == y) break;
                }
                cout<<i<<(g -> getvc()).size();
                if (i < (g -> getvc()).size())
                {
                    cin >> n;
                    if (n.getpartial() < n.getmaxpartial() / 2 || n.getscris() < n.getmaxscris() / 2)
                    {
                        g->addrestantieri(x,y);
                    }
                    *(g -> getvc())[i] += n;
                }
                break;
            }
            case 4:
            {
                vector<examen*>::iterator it;
                for(it = (g->getvex()).begin(); it != (g->getvex()).end(); it++)
                {
                    cout<< **it;
                }
                break;
            }
            case 5:
            {
                vector<CatalogIndividual<notare>*>::iterator it;
                for(it = (g->getvc()).begin(); it != (g->getvc()).end(); it++)
                {
                    cout<< **it;
                }
                break;
            }
            case 6:
            {
                for(int i = 1; i <= examen::getnumarexamene(); i++)
                {
                    if (g->getum().find(i)!=g->getum().end())
                    {
                        cout << "La examenul " << i << " au restanta urmatorii studenti: ";
                        for(unsigned int j = 0; j < (g->getum())[i].size(); j++)
                        {
                            cout << (g->getum())[i][j] << " ";
                        }
                    }
                    else cout << "La examenul " << i << " nu are restanta nimeni.";
                    cout << endl;
                }
                break;
            }
            case 7:
            {
                cout << "Undefined";
                break;
            }
            default: cout<<"Optiune invalida!"<<endl;
        }
    }
}
