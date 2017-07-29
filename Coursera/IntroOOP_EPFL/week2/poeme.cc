#include <iostream>

using namespace std;

class Fleur{
	private:
		string s1,s2;
	
	public:
		Fleur(string s1, string s2):s1(s1),s2(s2) {cout << s1 << " fraichement cueillie" << endl; }
		Fleur( Fleur const& other):s1("Fragile"),s2(other.s2) { cout << s1 << " corolle taillée" << endl;} 
		~Fleur(){ cout << "qu'un simple souffle.." << endl;}
		void eclore() const{  cout << "de " << s2 << endl; }
};


int main ()
{
  Fleur f1("Violette", "bleu");
  Fleur f2(f1);
  cout << "dans un cristal ";
  f2.eclore();
  cout << "Donne un poème un peu fleur bleue" << endl
       << "ne laissant plus ";
  return 0;
}
