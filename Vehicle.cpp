#include "Vehicle.h"
#include <iostream>
using namespace std;

/*************************************************
Vehicle model
**************************************************/

//Vehicle constructor
Vehicle::Vehicle(
	int max_speed,
	double lpkm,
	double tank_capacity,
	double current_fuel_level,
	int current_speed,
	int kilometrage) :

	max_speed(max_speed),
	lpkm(lpkm),
	tank_capacity(tank_capacity),
	current_fuel_level(current_fuel_level),
	current_speed(current_speed),
	kilometrage(kilometrage)
	{ cout << "class \"Vehicle\" -> object created" << endl; }

//Vehicle destructor
Vehicle::~Vehicle() {
	cout << "class \"Vehicle\" -> object destroyed" << endl;
}

//Description of Vehicle methods
int Vehicle::get_max_speed() { return max_speed; }

double Vehicle::get_lpkm() { return lpkm; }

double Vehicle::get_tank_capacity() { return tank_capacity; }

void Vehicle::set_max_speed(int speed) { max_speed = speed; }

void Vehicle::set_lpkm (double lperkm){ lpkm = lperkm; }

void Vehicle::set_tank_capacity(double tankCapacity) { tank_capacity = tankCapacity; }

void Vehicle::fill_the_tank() { current_fuel_level = tank_capacity; }

void Vehicle::show_tank_fill_percentage() {
	cout << "Tank is " << current_fuel_level / tank_capacity * 100 <<  "% full" << endl;
}

void Vehicle::move(int kilometers) {
	if (current_speed <= 0) {
		cout << "Speed of your car is " << current_speed << "!" << endl;
	}
	else if (lpkm * kilometers > current_fuel_level) {
		cout << "Attention! Your car is out of fuel!" << endl;
		kilometrage += current_fuel_level / lpkm;
		current_fuel_level = 0;
	}
	else {
		current_fuel_level -= lpkm * kilometers;
		kilometrage += kilometers;
	}
}

void Vehicle::speed_up(int speed) {
	if (current_speed + speed > max_speed) {
		cout << "You can't increase the speed more than the maximum" << endl;
	}
	else {
		current_speed += speed;
	}
}

void Vehicle::slow_down(int speed) {
	if (current_speed - speed < 0) {
		cout << "You can't reach the negative speed" << endl;
	}
	else {
		current_speed -= speed;
	}
}

void Vehicle::show_stats() {
	cout << "Liters per km = " << lpkm
		 << "\nCurrent fuel level = " << current_fuel_level
		 << "\nTank capacity = " << tank_capacity
		 << "\nCurrent speed = " << current_speed
		 << "\nMaxspeed = " << max_speed
		 << "\nKilometrage = " << kilometrage << endl;
}

/*************************************************
Light_vehicle model
**************************************************/

//Light_vehicle constructor
Light_vehicle::Light_vehicle(
	int number_of_passenger_seats,
	int number_of_doors,
	int current_number_of_passengers) :
	number_of_passenger_seats(number_of_passenger_seats),
	number_of_doors(number_of_doors),
	current_number_of_passengers(current_number_of_passengers)
	{ cout << "class \"Light_vehicle\" -> object created" << endl; }

//Light_vehicle destructor
Light_vehicle::~Light_vehicle() {
	cout << "class \"Light_vehicle\" -> object destroyed" << endl;
}

void Light_vehicle::put_a_passengers(int num) {
	if (current_number_of_passengers + num > number_of_passenger_seats)
		cout << "Can't add that many passengers" << endl;
	else
		current_number_of_passengers += num;
}

void Light_vehicle::drop_off_a_passenger() {
	if (current_number_of_passengers == 0) 
		cout << "Vehicle is empty" << endl;
	else
		current_number_of_passengers--;
}

/*************************************************
Truck model
**************************************************/

//Truck constructor
Truck::Truck(
	int carrying_capacity,
	int cargo_area_volume,
	int current_cargo_area_volume,
	int current_cargo_weight) :
	carrying_capacity(carrying_capacity),
	cargo_area_volume(cargo_area_volume),
	current_cargo_area_volume(current_cargo_area_volume),
	current_cargo_weight(current_cargo_weight)
	{ cout << "class \"Truck\" -> object created" << endl; }

//Truck destructor
Truck::~Truck() {
	cout << "class \"Truck\" -> object destroyed" << endl;
}

void Truck::add_cargo(int volume, int weight) {
	long long int total_w = current_cargo_weight + weight;
	long long int total_v = current_cargo_area_volume + volume;
	if (carrying_capacity >= total_w && cargo_area_volume >= total_v) {
		current_cargo_weight = total_w;
		current_cargo_area_volume = total_v;
	}
	else if (carrying_capacity < total_w)
		cout << "It is not possible to place a load. Not enough load capacity." << endl;
	else
		cout << "It is not possible to place a load. Not enough space." << endl;
}

void Truck::unload_cargo_area() {
	current_cargo_area_volume = 0;
	current_cargo_weight = 0;
}