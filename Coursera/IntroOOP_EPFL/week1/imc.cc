#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient{
	private:
		double masse; // weight
		double hauteur; // height
	public:
		void init(double poids, double taille);
		void afficher() const;
		double poids() const;
		double taille() const;
		double imc() const;
};

	void Patient::init(double poids, double taille){
		masse = (poids<0||taille<0)?0:poids;
		hauteur = (poids<0||taille<0)?0:taille;
	}
	
	void Patient::afficher() const{
		cout<< "Patient: "<< masse<< " kg pour "<< hauteur<< " m"<< endl;	
	}

	double Patient::poids() const{
		return masse;
	}
	
	double Patient::taille() const{
		return hauteur;
	}
	
	double Patient::imc() const{
		return (hauteur==0)?0:masse/(hauteur*hauteur);
	}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
