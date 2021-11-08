#include <iostream>
#include "Vehicle.h"
using namespace std;

int main()
{
	// creating just a class Vehicle object
	Vehicle vehicle;

	// creating a class Vehicle object first (beacause this is a parent class), second a class Light_vehicle object
	Light_vehicle vehicle1(1); 

	// creating a class Vehicle object first (beacause this is a parent class), second a class Truck object
	Truck vehicle2;

	//vehicle1.unload_cargo_area(); -> Error
	vehicle2.unload_cargo_area();
	//vehicle2.put_a_passengers(2); -> Error
	vehicle1.put_a_passengers();
	cout << vehicle.get_max_speed() << endl;
	cout << vehicle1.get_max_speed() << endl;
	cout << vehicle2.get_max_speed() << endl;
	vehicle.set_max_speed(100);
	vehicle1.set_max_speed(200);
	vehicle2.set_max_speed(300);
	cout << vehicle.get_max_speed() << endl;
	cout << vehicle1.get_max_speed() << endl;
	cout << vehicle2.get_max_speed() << endl;

	//etc.

	//at the end of programm destroying objects in order, from child to parent.
	//first destroyed object - first created object
}