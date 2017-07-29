#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
  string nom;
  unsigned int annee;
  string pays;
  double valeur_faciale;

public:
  static constexpr unsigned int PRIX_BASE_TRES_RARE = 600;
  static constexpr unsigned int PRIX_BASE_RARE = 400; 
  static constexpr unsigned int PRIX_BASE_PEU_RARE = 50;

  Timbre (  string nom_,  unsigned int anne_, string pays_ = "Suisse", double valeur_faciale_ = 1.0)
    : nom(nom_) , annee(anne_), pays(pays_),  valeur_faciale(valeur_faciale_){}

  ostream& afficher(ostream  &output) const{
    output << "Timbre de nom "<< get_nom() << " datant de "<< get_anne() <<" (provenance "
           << get_pays() << ") ayant pour valeur faciale " << get_val() << " francs";
    return output;
 
  }

  double vente () const {
    if (   age () <= 5  ) {   return valeur_faciale ; }
    else { return valeur_faciale * age() *  2.5;}
  }

  string get_nom() const{ return nom;}
  string get_pays() const { return pays;}
  unsigned int get_anne() const { return annee;}
  double get_val() const { return valeur_faciale; }

  unsigned int age() const{
    return  (ANNEE_COURANTE - this->annee);
  }
};

ostream& operator<<(ostream  &output, const Timbre &timbre)
{
  return timbre.afficher(output);
}


class Rare: public Timbre
{ 
 private:
  unsigned int num_copies;

public:
  Rare (  string nom,  unsigned int anne, string pays = "Suisse",  double valeur_faciale = 1.0,    unsigned int num_copies = 100)
    :Timbre(nom, anne, pays, valeur_faciale),  num_copies(num_copies) {}

  friend ostream& operator<<(ostream  &output, const Rare&);

  double vente () const{
    if(   nb_exemplaires() <= 100) { return  (PRIX_BASE_TRES_RARE*age()/10.0); }
    else if ( nb_exemplaires() <= 1000) { return (PRIX_BASE_RARE*age()/10.0); }
    else { return PRIX_BASE_PEU_RARE*age()/10.0; }
  }

  unsigned int nb_exemplaires() const{return num_copies;
  }

};

ostream& operator<<(ostream  &output, const  Rare &rare)
{
  output << "Timbre rare ("<< rare.num_copies <<" ex.) de nom "<< rare.get_nom() << " datant de "<< rare.get_anne() <<" (provenance "
         << rare.get_pays() << ") ayant pour valeur faciale " << rare.get_val() << " francs";
  return output;
 
}

class Commemoratif: public Timbre
{
public:
  friend ostream& operator<<(ostream  &output, const Commemoratif&);

  Commemoratif (  string nom,  unsigned int anne, string pays = "Suisse",  double valeur_faciale = 1.0)
    :Timbre(nom, anne, pays, valeur_faciale) {}

  double vente() const{
  return  2*Timbre::vente();
  }
};

ostream& operator<<(ostream  &output, const Commemoratif &com)
{
  output << "Timbre commémoratif de nom "<< com.get_nom() << " datant de "<< com.get_anne() <<" (provenance "
         << com.get_pays() << ") ayant pour valeur faciale " << com.get_val() << " francs";
  return output;
 
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
