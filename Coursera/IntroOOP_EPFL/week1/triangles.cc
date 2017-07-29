#include <cmath>
#include <iostream>
#include <iomanip> 

using namespace std;

struct Point3D{
	double x;
	double y;
	double z;
} ;


void create_newPoint(struct Point3D *point){
	
	double x;
	
	cout << "Construction d'un nouveau point" << endl;
	cout << "Veuillez entrer x : "; 
	cin >> point->x;
	cout << "Veuillez entrer y : ";
	cin >> point->y;
	cout << "Veuillez entrer z : ";
	cin >> point->z;
}

struct TriangleSides{
	double x, y, z;
};

double distance(struct Point3D *p1, struct Point3D *p2){
		return sqrtf(
				  (p1->x - p2->x)*(p1->x - p2->x) 
				+ (p1->y - p2->y)*(p1->y - p2->y)
				+ (p1->z - p2->z)*(p1->z - p2->z) 
				);
}

class Triangle {
	private:
		TriangleSides sides_;
	public:
		void init();
		void setSides(struct Point3D *p1, struct Point3D *p2, struct Point3D *p3);
		bool isIsocele() const;
		double getPerimetre() const;
};

	void Triangle::setSides(struct Point3D *p1, struct Point3D *p2, struct Point3D *p3){
		sides_.x = distance(p1, p2);
		sides_.y = distance(p2, p3);
		sides_.z = distance(p1, p3);
	}
	
	bool Triangle::isIsocele() const{
		return (sides_.x == sides_.y 
			&& sides_.y == sides_.z 
			&& sides_.x == sides_.x);
	}
	
	double Triangle::getPerimetre() const{
		return (sides_.x + sides_.y + sides_.z);
	}

	void Triangle::init() {
		Point3D p1,p2,p3;
		create_newPoint(&p1);
		create_newPoint(&p2);
		create_newPoint(&p3);
		
		this->setSides(&p1, &p2, &p3);
	}


int main (int argc, char *argv[]){
	
	double x, y, z;
	
	Triangle tri;
	
	tri.init();
	
	cout << "Périmètre: " << setprecision(32) << tri.getPerimetre() << endl;
	
	if (tri.isIsocele() ){
		cout << "Ce triangle est isocèle !" << endl;
	} 
	else {
		cout << "Ce triangle est isocèle pas!" << endl;
	}
	
	
	return 0;
	
	
}
