#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
private:
  const string nom_;
  int niveau_;
  int points_de_vie_;
  int force_;
  int position_;

public:
  Creature(const string nom_,
           int niveau_,
           int points_de_vie_,
           int force_,
           int position_ = 0
           ):nom_(nom_),  niveau_(niveau_),    points_de_vie_(points_de_vie_), force_(force_), position_(position_) {}

  int get_hp() const { return points_de_vie_;  }
  int get_nivel() const { return niveau_; }
  int get_force() const { return force_; }
  int position() const { return position_; }
  const string get_nom() const { return nom_; }

  void set_position(int p){  position_ += p; }
  void set_lvl(int n) { niveau_ +=n; }
  void set_hp(int p){
   points_de_vie_ -= p;
   points_de_vie_ = (points_de_vie_>0)?points_de_vie_:0;
   if ( !vivant() )  adieux();
  }

  bool vivant (){
    return points_de_vie_>0?true:false; 
  }

  int points_attaque (){
    return this->vivant()?(  get_nivel() * get_force() ): 0;
  }

  void deplacer(int x) {
    if( vivant() )  set_position(x);
  }

  void adieux (){
    cout   << get_nom() << " n'est plus !" << endl;
  }

  void faiblir(int  point) {
    vivant()?set_hp(point):set_hp(0);
  }

  void afficher() {
    cout << get_nom()<< ", niveau: " << get_nivel()
         << ", points de vie: " << get_hp()
         << ", force: " << get_force()
         << ", points d'attaque: " << points_attaque()
         << ", position: " << position() << endl;
  }

};

class Dragon : public Creature{
public:
  Dragon (string nom_, int niveau_, int points_de_vie_, int force_ , int portee_flamme_, int position_ = 0  )
    : Creature(nom_, niveau_, points_de_vie_, force_, position_), portee_flamme_(portee_flamme_) {}

  void voler (int pos){
    deplacer(pos-position());
  }

  void souffle_sur(Creature& bete){
    if(  vivant() &&  bete.vivant() &&  distance(bete.position(), position()) <= get_range()) {
      bete.faiblir(  points_attaque() );
      faiblir( distance( bete.position(), position()  ) );

      if (vivant() && !bete.vivant()) {set_lvl(1);}

    }
  }

  int get_range() const { return portee_flamme_; }

private:
  int portee_flamme_;
};

class Hydre: public Creature {
private:
  int longueur_cou_;
  int dose_poison_;

public:
  Hydre(string nom_, int niveau_, int points_de_vie_, int force_, int longueur_cou_, int dose_poison_, int position_ = 0)
    :Creature(nom_, niveau_, points_de_vie_, force_, position_), longueur_cou_(longueur_cou_), dose_poison_(dose_poison_){}

  int get_range() const { return longueur_cou_; }
  int get_dose() const { return dose_poison_; }

  void empoisonne(Creature& bete ){
    if (  vivant() && bete.vivant() &&  distance(bete.position(), position()) <= get_range()  )   {
      bete.faiblir(  points_attaque() + get_dose());
      if (vivant() && !bete.vivant()) {set_lvl(1);}
  }
  }

};

void combat(Dragon& d, Hydre& h){
  h.empoisonne(d);
  d.souffle_sur(h);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
