#include <iostream>
#include <vector>
#include <string>

using namespace std;

//=============================================================
class Article{
	private:
		const string nom_;
		double prix_;
		bool action_;
	public:
		Article(string const& nom, double const prix, bool const action = false)
			: nom_(nom), prix_(prix), action_(action) {};
		string nom() const{ return nom_;}
		double prix() const{ return prix_;}
		bool action() const{ return action_;}
};

//=============================================================
class Achats{
	private:
		Article achete_;
		double quantite_;
	public:
		Achats(Article const& achete, double const quantite = 1)
			:achete_(achete), quantite_(quantite){}; // achete_(achete) is copy constructor
		void afficher() const;	
		double getTotal() const;
};

	double Achats::getTotal() const{
		double total;
		total = achete_.prix() * quantite_;
		if(achete_.action()) { total *= 0.5;}
		return total;
	}
	
	void Achats::afficher() const{
			cout << achete_.nom() << " "
				 << achete_.prix() << "x" 
				 << quantite_ << " = "
				 << this->getTotal() <<" F";
			if(achete_.action()) { cout << " (en action)"<< endl;}
			else{ cout << endl;}
		}
		
//=============================================================

class Caddie{
	private:
		vector<Achats> achats_;
	public:
		void remplir(Article article, double quantite);
		vector<Achats> getAchat() const;
		double calculateSubTotal ();		
};

	void Caddie::remplir(Article article, double quantite = 1){
		//Achats temp(article, quantite);
		//achats_.push_back(temp);
		// it also could be
		achats_.push_back(Achats(article, quantite));
	}
	
	
	double Caddie::calculateSubTotal (){ 
		double subtotal = 0;
		for( auto it: achats_ ) 
			{
				it.afficher();
				subtotal += it.getTotal();		
			}
		return subtotal;
	}
	
	vector<Achats> Caddie::getAchat() const{
		 return achats_;
		}

//=============================================================	
	
class Caisse{
	private:
		double total_  ;
	public:
		Caisse():total_(0.0){}; 
		void scanner(Caddie& caddie) ;
		void afficher() const;	
		void addTotal(double);
};
	
	void Caisse::scanner(Caddie& caddie) {
		double total=0;
		// This for could be called from caddie like caddie.total
	/*	for( auto achat: caddie.getAchat() ) 
			{achat.afficher();
				total += achat.getTotal();		
			}
			**/
		total = caddie.calculateSubTotal();
		
		cout<< "----"<< endl<< "Total à payer : "<< total<< " F."<< endl;
		total_ += total;
	}

	void Caisse::afficher()const{
		cout<< total_<< " F";
	}

// ======================================================================
int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
