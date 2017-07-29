#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	
	Flacon(string _nom, double _vol, double _pH)
		:nom(_nom), volume(_vol), pH(_pH) {}
	
	string get_nom() const{ return nom;}
	double get_volume() const{ return volume;}
	double get_ph() const{return pH;} 
	
	void set_nom(string _nom) { this->nom = _nom; }
	void set_volume(double _vol) {this->volume = _vol; }
	void set_pH(double pH) {this->pH = pH;}
	
	ostream& etiquette(ostream& sortie) const{
		sortie << get_nom() << " : " 
			<< get_volume() << " ml, pH " << get_ph();
		return sortie;
	}	
	
	double cal_pH(Flacon const& f2){
		
		return ( -log10f ((  this->get_volume() * powf(10.0, -1.0*this->get_ph())  
							+  f2.get_volume() * powf(10.0, -1.0*f2.get_ph()))
					    / (this->get_volume() + f2.get_volume() ) 	)
				);
	}
	
	void operator+=(Flacon const& f2){
			this->set_nom( this->get_nom() + " + " + f2.get_nom());
			this->set_pH( this->cal_pH(f2) );
			this->set_volume( this->get_volume() + f2.get_volume());
			
	}
};

#define BONUS

	ostream& operator<<(ostream& sortie, const Flacon& flacon){
		return flacon.etiquette(sortie);
	}
	
	const Flacon operator+(Flacon f1, const Flacon& f2){
		f1 += f2;
		return f1;
	}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
