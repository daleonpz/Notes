#include <iostream>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	private:
		double poids; //grams
		string couleur; 
		int age; //months
		int esperance_vie; //months
		bool clonee; 
	
	public:
		Souris(double poids, string couleur, int age = 0, int esperance_vie = 36)
			:poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie), clonee(false)
			{ cout<< "Une nouvelle souris !"<< endl; }
		Souris(Souris const& other)
			:poids(other.poids), age(other.age), couleur(other.couleur), esperance_vie(other.esperance_vie*4/5  ),clonee(true) 
			{cout<< "Clonage d'une souris !"<< endl;} 
		~Souris(){ cout<< "Fin d'une souris..."<< endl;}
		
		
		/***************** METHODS ************************/
		void afficher() const{
			cout<< "Une souris "<< couleur ;
			if(clonee){ cout<< ", clonee,"; }
			cout<< " de "<< age<< " mois et pesant "<< poids<< " grammes"<< endl;
			}
			
		void vieillir(){
			age += 1;
			if(clonee){
				couleur = (age>esperance_vie/2)?"verte":couleur;
				}
		}
		
		void evolue(){
			age = esperance_vie;
			this->vieillir();
			age -= 1;
		}
		
	


  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();  
  return 0;
}
