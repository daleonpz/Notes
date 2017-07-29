#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Brique(Forme _forme, Couleur _couleur)
		:forme(_forme), couleur(_couleur) {}
		
	ostream& afficher(ostream& sortie) const{
		if (!this->couleur.empty()){
			sortie << "(" <<  forme <<", " << couleur << ")" ;
		}
		else { sortie << forme ;	}
		
		return sortie;
		}
};

	ostream& operator<<(ostream& sortie, const Brique& brique){
		return brique.afficher(sortie);
	}

class Construction
{
  friend class Grader;
 
  private:
	vector<vector<vector<Brique>>> contenu;
	
  public:
	Construction(const Construction& other)
		:contenu(other.getContenu()){}

	Construction(const Brique& brique )
		:contenu(1,vector<vector<Brique>>(1,vector<Brique>(1,brique))){
		 }
	
	ostream& afficher(ostream& sortie) const{
		for (int i=contenu.size()-1; i>=0;i--){
			sortie << "Couche " << i <<" :" << endl;
			for (int j=0; j<contenu[i].size(); j++){
				for( int k=0; k<contenu[i][j].size(); k++)
					sortie << contenu[i][j][k] << " " ;
				sortie << endl;
			}		
		}
		return sortie;
	}
	
	vector<vector<vector<Brique>>> getContenu () const{
		return contenu;
	}
	
	void operator^=(const Construction& top){
		/*for(int i=top.getContenu().size()-1;i>=0;i--  ){
			this->contenu.push_back(top.getContenu()[i]);
		}*/
		for(auto it:top.getContenu() )
			this->contenu.push_back(it);
	}
	
	void operator-=(const Construction& behind){
		 if (this->contenu.size() <= behind.getContenu().size() )
				for (int i=0; i<contenu.size();i++)
					for (int j=0; j<behind.getContenu()[i].size(); j++)
						contenu[i].push_back(behind.getContenu()[i][j]);			 
	}
	
	void operator+=(const Construction& right){
		bool cond = true;
		 if (this->contenu.size() >= right.getContenu().size() )
				for (int i=0; i<contenu.size();i++)
						cond = cond && (contenu[i].size() >= right.getContenu()[i].size() ); 
			 		
		 if (cond)
				for (int i=0; i<contenu.size();i++)
					for (int j=0; j<contenu[i].size(); j++)
						for( int k=0; k<right.getContenu()[i][j].size(); k++)
							contenu[i][j].push_back(right.getContenu()[i][j][k]);
		
	}
};

const Construction operator^(Construction bottom, const Construction& top){
	bottom ^= top;
	return bottom;
}
const Construction operator-(Construction front, const Construction& behind){
	front -= behind;
	return front;
}
const Construction operator+(Construction left, const Construction& right){
	left += right;
	return left;
}
	
ostream& operator<<(ostream& sortie, const Construction& construction){
	return construction.afficher(sortie);
}

const Construction operator*(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(int i=1; i<n; i++) b+=a;
	return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(int i=1; i<n; i++)	b^=a;
	return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
	Construction b(a);
	for(int i=1; i<n; i++) b-=a;
	return b;	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
