// Ivan Byju
// Lab 1, ECE 2161-002
// This lab uses the center coordinates as well as another coordinate on a circle to perform calculations based on.
// The user then decides what calculations he/she wants done using the coordinates.

#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2);
double radius(double x1, double y1, double x2, double y2);
double circumference(double radius);
double area(double radius);
void user_menu(double radius, double circumference, double area);

// Receives user input for coordinates and passes them into helper functions to perform calculations
int main() {
	double center_x, center_y, point_x, point_y;

	// Asking for user to input x and y coordinates for the center of the circle
	cout << "Center x coordinate: ";
	cin >> center_x;
	cout << "Center y coordinate: ";
	cin >> center_y;

	// Asking for user to input x and y coordinates for an additional point
	cout << "Additional x coordinate: ";
	cin >> point_x;
	cout << "Additional y coordinate: ";
	cin >> point_y;
	cout << endl;

	// Calculates the basic circle calculations using user's inputs to pass into the user_menu function
	double radius_calc = radius(center_x, center_y, point_x, point_y);
	double circum_calc = circumference(radius_calc);
	double area_calc = area(radius_calc);
	user_menu(radius_calc, circum_calc, area_calc);

	return 0;
}

// Calculates the distance between two points
double distance(double x1, double y1, double x2, double y2) {
	// Square the differences in distances between the x and y coordinates, respectively
	double squared_x_diff = (x2 - x1) * (x2 - x1);
	double squared_y_diff = (y2 - y1) * (y2 - y1);

	return sqrt((squared_x_diff + squared_y_diff));
}

// Calculates the radius of the circle using the distance formula
double radius(double x1, double y1, double x2, double y2) {
	return distance(x1, y1, x2, y2);
}

// Calculates the circumference of the circle using a radius input
double circumference(double radius) {
	return 2 * M_PI * radius;
}

// Calculates the area of the circle using a radius input
double area(double radius) {
	return (M_PI * (radius * radius));
}

// Displays the user_menu for the user to see options for calculations
void user_menu(double radius, double circumference, double area) {
	// Variable for user's selection of calculation
	int user_choice;
	// Declares boolean variable of true to input into a do-while loop until changed to false
	bool status = true;

	do {
		// Four options given to the user
		cout << "(1) Compute the radius of the circle" << endl;
		cout << "(2) Compute the circumference of the circle" << endl;
		cout << "(3) Compute the area of the circle" << endl;
		cout << "(4) Exit program" << endl;
		cin >> user_choice;

		// Switch statement to properly execute code according to user's interest
		switch (user_choice) {
			case 1:
				cout << "Radius: " << radius << endl << endl;
				break;
			case 2:
				cout << "Circumference: " << circumference << endl << endl;
				break;
			case 3:
				cout << "Area: " << area << endl << endl;
				break;
			case 4:
				// Changes status to false because user wants to exit program
				status = false;
				break;
			default:
				// This default handles any invalid options and prints new line for good display
				cout << endl;
				break;
		}
	} while (status);
}


