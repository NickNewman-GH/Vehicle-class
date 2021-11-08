#pragma once
class Vehicle
{
public:
	Vehicle(int max_speed = 0,
			double lpkm = 0,
			double tank_capacity = 0,
			double current_fuel_level = 0.0,
			int current_speed = 0,
			int kilometrage = 0);

	virtual ~Vehicle();

	//some Vehicle class methods
	int get_max_speed();
	double get_lpkm();
	double get_tank_capacity();
	void set_max_speed(int speed);
	void set_lpkm(double lperkm);
	void set_tank_capacity(double tankCapacity);
	void fill_the_tank();
	void show_tank_fill_percentage();
	void move(int kilometers);
	void speed_up(int speed);
	void slow_down(int speed);
	virtual void show_stats();

private:

	/*  lpkm - liters per kilometer
	    current_fuel_level - the number of liters of fuel in the vehicle
	    tank_capacity - vehicle fuel tank capacity in liters  */

	double lpkm, current_fuel_level, tank_capacity;

	/*  current_speed, max_speed in km/h
	    kilometrage - the number of km-s the car has traveled  */

	int current_speed,
		max_speed,
		kilometrage;
};



class Light_vehicle : public Vehicle
{
public:
	Light_vehicle(int number_of_passenger_seats = 0,
				  int number_of_doors = 0,
				  int current_number_of_passengers = 0);

	~Light_vehicle();

	void put_a_passengers(int num = 1);
	void drop_off_a_passenger();
	
private:
	int number_of_passenger_seats,
		number_of_doors,
		current_number_of_passengers;
};



class Truck : public Vehicle
{
public:
	Truck(int carrying_capacity = 0,
		  int cargo_area_volume = 0,
		  int current_cargo_area_volume = 0,
		  int current_cargo_weight = 0);

	~Truck();

	void add_cargo(int volume, int weight);
	void unload_cargo_area();

private:

	/*  carrying_capacity, current_cargo_weight - kg
		cargo_area_volume, current_cargo_area_volume  - m^3 */

	int carrying_capacity,
	    cargo_area_volume,
		current_cargo_area_volume,
		current_cargo_weight;
};
