#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> //za sort
#include <vector> //za vektori
#include <cstdlib>
#include <iomanip> //za setw
#include <fstream> //za datotteka
using namespace std;

struct Profil //strukturata

{

    int IDbroj;

    string Nickname;

    float  Nivo;

    Profil(int ID, const string& Nickname)

        : IDbroj(IDbroj), Nickname(Nickname), Nivo(Nivo)
    {

    }

    bool operator<(const Profil& p) const

    {

        return Nickname < p.Nickname; //sortiranje po Nickname

    }

};


struct Sortiranjenapointeroodprofilo

{
    bool operator()(const Profil* j, const Profil* v) const

    {

        return *j < *v;

    }

};

int main()

{

    vector<Profil*> Profili;

    Profili.push_back(new Profil(2, "David"));

    Profili.push_back(new Profil(4, "Anabela"));

    Profili.push_back(new Profil(1, "Sanja"));

    Profili.push_back(new Profil(5, "Nikola"));

    Profili.push_back(new Profil(3, "Ivan"));

    auto copy_of_Profili = Profili;

    cout << "Pechatenje na podatocite" << endl;
    cout << setw(10) << "IDbroj" << setw(10) << "Nickname" << endl;

    for (const auto* p : Profili)
    {
        cout << setw(10) << p->IDbroj << setw(10) << p->Nickname << endl;
    }


    cout << endl << "Podatocite sortirani po rastecki A-Z" << endl;
    cout << setw(10) << "IDbroj" << setw(10) << "Nickname" << endl;

    sort(Profili.begin(), Profili.end(), Sortiranjenapointeroodprofilo());

    for (const auto* p : Profili)

        cout << p->IDbroj << ": " << p->Nickname << '\n';

    //vector vo nadvoreshen fajl txt fajlche
    ofstream outFile("INKI814DAVIDJORDANOSKI.txt");
    outFile << "Pechatenje na podatocite" << endl;
    outFile << setw(10) << "IDbroj" << setw(10) << "Nickname" << endl;
    for (const auto* p : copy_of_Profili)
    {
        outFile << setw(10) << p->IDbroj << setw(10) << p->Nickname << endl;
    }

    outFile << endl << "Podatocite sortirani po rastecki A-Z" << endl;
    outFile << setw(10) << "IDbroj" << setw(10) << "Nickname" << endl;
    sort(Profili.begin(), Profili.end(), Sortiranjenapointeroodprofilo());

    for (const auto* p : Profili)

        outFile << p->IDbroj << ": " << p->Nickname << '\n';
//konechen komit broj 4

}
