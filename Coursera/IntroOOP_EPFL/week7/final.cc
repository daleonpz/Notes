#include <iostream>
#include <memory> // for unique_ptr
#include <vector>

using namespace std;


/* ------------------------------------------- */
/*   Classes                              */
/* ------------------------------------------- */
class Produit{
    private:
        const double valeur; // base value, it must not change
    public:
        Produit( double valeur = 0.0):
            valeur(valeur){}
        virtual ~Produit() = 0 ; // to make the class abstract

        // the price is not fixed, it may change
        virtual double prix() const { return valeur; }
        virtual void afficher( ostream& sortie) const { sortie << prix(); }
};

// needed by the pure virtual function, even if it does not do anything
Produit::~Produit() {}; 

ostream& operator<<(ostream& sortie, Produit const& machin){
    machin.afficher(sortie);
    return sortie;
}

//------------------------------------------------------------
class Accessoire: public Produit{
    private:
        const string nom;
    public:
        Accessoire(string const& un_nom, double prix_de_base):
            Produit(prix_de_base), nom(un_nom){};

        virtual ~Accessoire() {};

        virtual void afficher(ostream& sortie) const override{
            sortie << nom << " coutant ";
            Produit::afficher(sortie);
        }
};

//------------------------------------------------------------
class Bracelet: public Accessoire{
    public: 
        Bracelet(string const& un_nom, double prix_de_base):
            Accessoire("bracelet " + un_nom, prix_de_base){};

        virtual ~Bracelet() {};
};

//------------------------------------------------------------
class Fermoir: public Accessoire{
    public:
        Fermoir(string const& un_nom, double prix_de_base):
            Accessoire("fermoir " + un_nom, prix_de_base){};

        virtual ~Fermoir() {};
};

//------------------------------------------------------------
class Boitier : public Accessoire {
public:
  Boitier(string const& un_nom, double prix_de_base)
    : Accessoire("boitier " + un_nom, prix_de_base)
  {}
  virtual ~Boitier() {}
};

//------------------------------------------------------------
class Vitre : public Accessoire {
public:
  Vitre(string const& un_nom, double prix_de_base)
    : Accessoire("vitre " + un_nom, prix_de_base)
  {}
  virtual ~Vitre() {}
};

//------------------------------------------------------------
class Mecanisme: public Produit{
    private:
        string heure;
        virtual void afficher_type(ostream& sortie) const = 0;

    public:
        Mecanisme(double valeur_de_base, string heure = "12:00"):
            Produit(valeur_de_base), heure(heure){};

        virtual ~Mecanisme() {}

        // use final to block subclasses be able to override
        virtual void afficher(ostream& sortie) const override final {
            sortie << "mécanisme ";
            afficher_type(sortie);
            sortie << " (affichage : ";
            afficher_cadran(sortie);
            sortie << "), prix : ";
            Produit::afficher(sortie);
        }

        // to be able to display the subclasses
    protected:  
        virtual void afficher_cadran(ostream& sortie) const {
            sortie << heure;
        }
};

//------------------------------------------------------------
// we declare virtual public since we just one instance of mecanisme when
// creating a mecanismedouble
class MecanismeAnalogique: virtual public Mecanisme{
    private:
        int date;

    public:
        MecanismeAnalogique(double valeur_de_base, string une_heure, int une_date): 
            Mecanisme(valeur_de_base, une_heure), date(une_date) {}

        // to match the constructor when hour is by default 
        MecanismeAnalogique(double valeur_de_base, int une_date): 
            Mecanisme(valeur_de_base), date(une_date) {}

        virtual ~MecanismeAnalogique() {}

    protected:
        virtual void afficher_type(ostream& sortie) const override {
            sortie << "analogique";
        }

        virtual void afficher_cadran(ostream& sortie) const override {
            Mecanisme::afficher_cadran(sortie);
            sortie << ", date " << date;
        }

};

//------------------------------------------------------------
class MecanismeDigital: virtual public Mecanisme{
    private:
        string reveil;

    public:
        MecanismeDigital(double valeur_de_base, string une_heure, string heure_reveil):
            Mecanisme(valeur_de_base, une_heure), reveil(heure_reveil) {}

        MecanismeDigital(double valeur_de_base, string heure_reveil):
            Mecanisme(valeur_de_base), reveil(heure_reveil) {}

        virtual ~MecanismeDigital() {}

    protected:
        virtual void afficher_type(ostream& sortie) const override {
            sortie << "digital";
        }

        virtual void afficher_cadran(ostream& sortie) const override {
            Mecanisme::afficher_cadran(sortie);
            sortie << ", réveil " << reveil;
        }
};

//------------------------------------------------------------
class MecanismeDouble: public MecanismeAnalogique, public MecanismeDigital{
    public:
          MecanismeDouble(double valeur_de_base, string une_heure, int une_date, string heure_reveil)
          : Mecanisme(valeur_de_base, une_heure)
          , MecanismeAnalogique(valeur_de_base, une_heure, une_date)
          , MecanismeDigital(valeur_de_base, une_heure, heure_reveil) {}

          MecanismeDouble(double valeur_de_base, int une_date, string heure_reveil)
          : Mecanisme(valeur_de_base)
          , MecanismeAnalogique(valeur_de_base, une_date)
          , MecanismeDigital(valeur_de_base, heure_reveil) {}

          virtual ~MecanismeDouble() {}

    protected:
          virtual void afficher_type(ostream& sortie) const override {
                sortie << "double"; }

          virtual void afficher_cadran(ostream& sortie) const override {
                sortie << "sur les aiguilles : ";
                MecanismeAnalogique::afficher_cadran(sortie);
                sortie << ", sur l'écran : ";
                MecanismeDigital::afficher_cadran(sortie);
              }
};

//------------------------------------------------------------
// watches
class Montre:public Produit{
    private:
//        Mecanisme coeur; // heart
        unique_ptr<Mecanisme> coeur;
//         vector<Accessoire> accessoire ; // different accessories
        vector<unique_ptr<Accessoire>> accessoires;

        Montre(const Montre&)   = delete;
        Montre& operator=(Montre)   = delete;
    public:

         Montre( Mecanisme* depart):
             coeur(unique_ptr< Mecanisme>(depart)) {}
        virtual ~Montre() {};

        void operator+=( Accessoire*);

        virtual double prix() const override{
            double prix_final(Produit::prix());

            for( auto const& p_acc: accessoires){
                prix_final += p_acc->prix();
            }

            return prix_final;
        }

        virtual void afficher(ostream& sortie) const override{
            sortie << "Une montre composee de :" << endl;

            for( auto const& p_acc: accessoires){
                sortie << "  * " << *p_acc << endl;
            }

            sortie << "==> Prix total: " << prix() << endl;
        }
};

void Montre::operator+=( Accessoire* ajout){
    accessoires.push_back(unique_ptr<Accessoire>(ajout));
}


/* ------------------------------------------- */
/*   MAIN                              */
/* ------------------------------------------- */

int main(){
    
    // test de l'affichage des mécanismes
    MecanismeAnalogique v1(312.00, 20141212);
    MecanismeDigital    v2( 32.00, "11:45", "7:00");
    MecanismeDouble     v3(543.00, "8:20", 20140328, "6:30");
    cout << v1 << endl << v2 << endl << v3 << endl;

    // Test des montres
    Montre m(new MecanismeDouble(468.00, "9:15", 20140401, "7:00"));
    m += new Bracelet("cuir", 54.0);
    m += new Fermoir("acier", 12.5);
    m += new Boitier("acier", 36.60);
    m += new Vitre("quartz", 44.80);
    cout << endl << "Montre m :" << endl;
    cout << m << endl;

    return 0;
}
