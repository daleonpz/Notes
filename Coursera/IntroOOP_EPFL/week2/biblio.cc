#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur{
	private:
		string nom;
		bool prix;
	public:
		Auteur(string nom, bool prix = false)
			:nom(nom), prix(prix){}
		
		string getNom () const{ return nom;}
		bool getPrix () const{ return prix;}
};

class Oeuvre{
	private:
		string titre;
		const Auteur& auteur;
		string langue;
	public:
		// Constructors & destructors
		Oeuvre(string titre, const Auteur& auteur_, string langue)
			:titre(titre), auteur(auteur_), langue(langue){}
			
		~Oeuvre(){
			cout <<"L'oeuvre \"";
			this->affiche();
			cout << "\" n'est plus disponible."<< endl;
		}
				
		// Methods
		string 	getTitre() 			const{ return titre;}
		const Auteur& getAuteur() 	const{ return auteur;}
		string 	getLangue() 		const{ return langue;}
		
		void affiche() const{
			cout<< titre<< ", "<< auteur.getNom()<< ", en "<< langue;
			}
		
		//  Operator overloading
		bool operator==(const Oeuvre& oeuvre) const{
			return (
				this->titre.compare(oeuvre.titre)==0
				 && this->auteur.getNom().compare(oeuvre.auteur.getNom() )==0
				 && this->langue.compare(oeuvre.langue) ==0
				);
		}
};

class Exemplaire{
	private:
		const Oeuvre &oeuvre_;
	public:
		Exemplaire(Oeuvre& other)
			:oeuvre_(other)	
			{
				cout<< "Nouvel exemplaire de : ";
				oeuvre_.affiche();
				cout <<endl;
			}
		
		Exemplaire(Exemplaire& other )
			:oeuvre_( other.oeuvre_)
			{
				cout<< "Copie d'un exemplaire de : ";
				oeuvre_.affiche();
				cout <<endl;
			}
		
		~Exemplaire(){
			cout<< "Un exemplaire de \"";
			oeuvre_.affiche();
			cout<<"\" a été jeté !"<< endl; 
			//delete &oeuvre_;
		}
		
		const Oeuvre& getOeuvre() { return oeuvre_;}
		
		void affiche() const{
			cout<< "Exemplaire de : ";
			oeuvre_.affiche();
		}
};

class Bibliotheque{
	private:
		string nom;
		vector<Exemplaire*> exemplaire;
	
	public:
		// Constructors & Destructors
		Bibliotheque(string nom):nom(nom){
			cout <<"La bibliothèque "<< nom<<" est ouverte !"<< endl;
			}
		
		~Bibliotheque(){
			cout << "La bibliothèque "<< nom<<" ferme ses portes,\n" 
				 << "et détruit ses exemplaires :"<< endl;
				 
			for(auto it:exemplaire) delete it;
			}
		
		
		// methods
		string getNom() const{ return nom;}
		
		void stocker(Oeuvre& oeuvre,int numbers){
			for(int i=0; i<numbers; i++ ) exemplaire.push_back(new Exemplaire(oeuvre));		
			}
		
		void stocker(Oeuvre& oeuvre){ exemplaire.push_back(new Exemplaire(oeuvre));}
	
	
		void lister_exemplaires(string langue) {
			for(auto  it: exemplaire) {
				if ( langue.compare(it->getOeuvre().getLangue())==0 ) { it->affiche(); cout<< endl;}
			}
			}
		
		void lister_exemplaires() {
			for(auto it: exemplaire) {it->affiche(); cout<< endl;}
			}
		
		
		int compter_exemplaires(const Oeuvre& oeuvre) {
			int total=0;
			for(auto it: exemplaire) if( (it->getOeuvre()) == oeuvre) {total +=1;}	
			return total;
			}
		
		void afficher_auteurs(bool a) const {
			if(a) {
				for(auto it: exemplaire) if(it->getOeuvre().getAuteur().getPrix()) 
					{
						cout << it->getOeuvre().getAuteur().getNom() <<endl;
					}
			}
			else{
				for(auto it: exemplaire) cout << it->getOeuvre().getAuteur().getNom()<<endl;
			}
			}
		
		void afficher_auteurs() const {
				for(auto it: exemplaire) cout << it->getOeuvre().getAuteur().	getNom()<<endl;
			}

		
};

// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
