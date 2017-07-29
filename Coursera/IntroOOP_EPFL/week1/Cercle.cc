#include <cmath>
#include <iostream>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Cercle{
	private:
		double x_, y_;
		double radio_ = 5.0;
	public:
		void getCentre (double& x, double& y) const;
		void setCentre (double& x, double& y) ;
		double surface () const;
		bool estInterieur (double& x, double& y) const;
		
};

	void Cercle::getCentre(double& x, double& y) const{
		x = x_*2;
		y = y_*2;
	}
	
	void Cercle::setCentre(double& x, double& y) {
		x_ = x;
		y_ = y;
	}

	double Cercle::surface() const{
		return M_PI*radio_*radio_;
	}
	
	bool Cercle::estInterieur(double& x, double& y) const{
		return (x<=x_ && y<=y_);
	}
	
	
int main(int argc, char *argv[]){
	double x,y;
	
	cin >> x >> y;
		
	Cercle cer;
	
	cer.setCentre(x,y);
	cer.getCentre(x,y);
	
	cout << x << "\t" << y << endl;
	cout << "Surface: " << cer.surface() << endl;
	
	cout << "> choose a point (x,y) " << endl;
	cin >> x >> y;
	
	cout << "is interior Point? "<< boolalpha <<  cer.estInterieur(x,y) << endl;
	
	return 0;
}
