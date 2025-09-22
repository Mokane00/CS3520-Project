#include <iostream>
using namespace std;

int main(){
	
	
	int quantityofgrains;
	int numlekopokopo;
	int litreofgrains;
	int lekopokopo;
	
	

	cout<<"enter the quantityofgrain: ";
	
	cin>>quantityofgrains;
	
	lekopokopo = 20;
		
	numlekopokopo = quantityofgrains/lekopokopo;
	
	float remainder = quantityofgrains % lekopokopo;
	
	if(quantityofgrains<lekopokopo){
		
		cout<<"there is no lekopokopo. ";
	}
	
	else{
	

	
	cout<<numlekopokopo<<" is the number of makopokopo"<<endl;
	
	cout<<remainder<<" litres"<<" is the number of remaining litres ";
	
	
}
	
	return 0;
	
	
	
	
	
	
	
}
