#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

ostream& operator<<(ostream& output,const Coordonnees& autre)
{
	output << "(" << autre.x() << ", " << autre.y()  << ")";
	return output;
}

double distance(Coordonnees const& c1, Coordonnees const& c2 )
{
	return  (double) sqrt( sq(c1.x()-c2.x()) + sq(c1.y()-c2.y()) );
}

ostream& operator<<(ostream& output, Pavillon e)
{
	switch(e)
	{
 		case JollyRogers:
			output << "pirate";
			break;
		case CompagnieDuSenegal:
		        output << "français";
			break;
		case CompagnieDOstende:
			output << "autrichien";
			break;
		default:
			output << "pavillon inconnu";
			break;
	}
	return output;
}

ostream& operator<<(ostream& output, Etat e)
{
	switch(e)
	{
		case Intact:
			output << "intact";
			break;
		case Endommage:
			output << "ayant subi des dommage";
			break;
		case Coule:
		        output << "coulé";
	       	        break;	       
		default: 
			output << "";
	}

	return output;
}


class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	private:
		Coordonnees position_;
		Pavillon pavillon_;
		Etat etat_;
		const static int rayon_rencontre = 10;
	public:
		Navire(int x, int y, Pavillon flag)
			:position_(x,y), pavillon_(flag), etat_(Intact){}

		Coordonnees const& position() const { return position_; }
		Etat const& getEtat() const { return etat_; }
		Pavillon const& getPavillion() const { return pavillon_; }

        void setEtat(Etat const& et) { etat_ = et; }

		void avancer ( int de_x, int de_y  ){
			if ( etat_ != Coule )	position_+= Coordonnees( de_x, de_y );
		}

		void renflouer() { etat_ = Intact; }

        virtual ostream& printNavireType(ostream& output) const = 0; 

		virtual void attaque( Navire& other ) = 0;

		virtual void replique( Navire& other  ) = 0;

		virtual void est_touche( ) = 0;

		ostream& afficher(ostream& output) const 
		{
            output << "en " << position() << " battant pavillion "
			       << pavillon_ << ", " << etat_;	
			return output;
		}

		void rencontrer( Navire& other ) {
			if (this->etat_ != Coule && other.getEtat() != Coule 
			  	&& this->pavillon_ != other.getPavillion() 
			  	&& distance(this->position(), other.position() ) <=  rayon_rencontre ){
			    attaque(other);
                if (other.getEtat() != Coule ) other.replique(*this); 
			}
		
		}

};

class Pirate:public virtual Navire{
	public:
		Pirate(int x, int y, Pavillon flag)
			:Navire(x, y, flag){}

        void attaque( Navire& other) override{
            cout << "A l'abordage !" << endl;
            other.est_touche();
        }

        void replique( Navire& other) override{
            if( this->getEtat() != Coule ){
                cout << "Non mais, ils nous attaquent! On riposte!!" << endl;
                this->attaque(other);
            }
        }

        void est_touche() override{
            Etat et = getEtat();
            if (et == Intact) 
               setEtat(Endommage);
            if ( et == Endommage)
               setEtat(Coule); 
        }

        ostream& printNavireType(ostream& output) const override{
            output << "bateu pirate ";
            return output;
        }

};

class Marchand:public virtual Navire{
	public:
		Marchand(int x, int y, Pavillon flag)
			:Navire(x, y, flag){}
        
        void attaque(Navire& other) override{
            cout << "On vous aura! (insultes)" << endl;
        }

        void replique(Navire& other) override {
            if (getEtat() == Coule)
                cout << "SOS je coule !" << endl;
            else
                cout << "Même pas peur !" << endl;
        }

        void est_touche() override{
            setEtat(Coule);
        }
      
        ostream& printNavireType(ostream& output) const override{
            output << "navire marchand ";
            return output;
        } 
};

class Felon: public Pirate, public Marchand{
	public:
		Felon(int x, int y, Pavillon flag)
			:Navire(x, y, flag),
             Pirate(x, y, flag),
             Marchand(x, y, flag){}

        void attaque(Navire& other) override { Pirate::attaque(other); } 
        void replique(Navire& other) override { Marchand::replique(other);}
        void est_touche() override { Pirate::est_touche();  }
        
        ostream& printNavireType(ostream& output) const override{
            output << "navire félon ";
            return output;
        }

};
	
void Coordonnees::operator+=(Coordonnees const& autre)
{
  // à définir ici
	this->x_ += autre.x();
	this->y_ += autre.y();
}

ostream& operator<<(ostream& output, Navire const& ship)
{
    ship.printNavireType(output);
	return ship.afficher(output);
}

double distance(Navire const& s1, Navire const& s2)
{
	return  distance(s1.position(), s2.position() );
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
