#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/
class Produit{
	private: 
		string nom_;
	        string unite;
	
	public:
		Produit(string n, string u = "")
			:nom_(n), unite(u){}

		string getNom() const{ return nom_;  }
		string getUnite() const{ return unite; }

		virtual string toString( ) const{ 
			return  getNom();
		}
		
		virtual const Produit* adapter( double ) const{
			//Produit* p = new Produit( nom_, unite  );
			//return p;
			return this;
		}

		virtual double quantiteTotale( const string& nomProduit  ) const{
			return nomProduit==getNom()?1:0;
		}
};

#include <iomanip>

class Ingredient{
	private:
		const Produit& produit_;
		double quantity_;
	
	public:
		Ingredient(const Produit& p, double q )
			:produit_(p),quantity_(q){ }

		const Produit& getProduit() const{ return produit_;  }
		double getQuantite() const{ return quantity_; }

		string descriptionAdaptee( ) {
			std::ostringstream os;

			os<< std::fixed << std::setprecision(6) << getQuantite() ;
			return os.str() + " " + getProduit().getUnite() 
				+ " de " + (getProduit().adapter( getQuantite()))->toString() ;
//				+ " de " + getProduit().toString() ;
		}

		string toString( ) const {
			return getProduit().toString();
		}

		double quantiteTotale(const string& nomProduit ) const{
			return getQuantite()*getProduit().quantiteTotale(nomProduit);
		}
};

class Recette{
	private:
		vector<Ingredient> listIn;
		double nbFois_;
		string nom_;
	
	public:
		Recette(string n, double t = 1 )
			:nom_(n), nbFois_(t){}

		void ajouter( const Produit& p, double q){
			Ingredient temp(p, q*nbFois_);
			listIn.push_back( temp);
//			listIn.push_back(  Ingredient(p, q*nbFois_) );
		}

		Recette adapter(double n) const{
			Recette  r( nom_, nbFois_*n  );
			for(auto it: listIn ) r.listIn.push_back( Ingredient( it.getProduit(), it.getQuantite()*n  ) );

			return r;
		}	

		string getNom() const { return nom_;}
		double getnbFois() const { return nbFois_; }
		vector<Ingredient> getIngredients () const { return listIn; }

		void setNom(string n) { nom_ = n; }
		void setnbFois( double n) { nbFois_ = n; }
		void setIngredients( vector<Ingredient> v ) { for(auto it : v)   listIn.push_back(it);  }

		string toString( ) const{
			string temp;
			std::ostringstream os;			

			os << nbFois_;

			temp = " Recette \"" + nom_ + "\" x " + os.str() + ":" ;

			double t=1; 
			
			for(auto it: listIn) 
			{
				std::ostringstream os;			
				os << t;
				temp +=  "\n " + os.str() + ". " + it.descriptionAdaptee();
			//	temp +=  "\n " + os.str() + ". " + it.toString();
				t+=1;
			}

			return temp;
		}		
		
		double quantiteTotale(const string& nomProduit) const  {
			double sum = 0;

			for (auto it: listIn) sum+= it.quantiteTotale(nomProduit);

			return sum;
		}

};

class ProduitCuisine: public Produit{
	private: 
		Recette recette;

	public: 
		ProduitCuisine(string n, string t = "portion(s)")
			:Produit(n,t),recette(n){}

		void ajouterARecette(const Produit& produit, double quantity ){
			recette.ajouter(produit, quantity);
		}

		const ProduitCuisine* adapter(double n) const override{
			ProduitCuisine*	p = new ProduitCuisine(getNom());
			p->setRecette( getRecette().adapter( n ) );
			return p;
			
		}

		const Recette& getRecette() const{ return recette; }
		void setRecette(const Recette& r ) {
		       	recette.setNom( r.getNom()  ); 
			recette.setnbFois( r.getnbFois() );
			recette.setIngredients( r.getIngredients() ); 
	       	}

		string  toString( ) const override {
			return getNom()+"\n"+recette.toString();
		}
		
		double quantiteTotale( const string& nomProduit  ) const override{
			return nomProduit==getNom()?1:getRecette().quantiteTotale( nomProduit);
		}

};


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
