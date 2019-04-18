/* 
 * File:   Lab_2.cpp
 * Author: Alyssa Gibson
 *
 * Created on January 14, 2019, 8:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void speed_calc(string, int, int, int, int);

int main(int argc, char** argv) {
    // @params: none
    // returns: 0 (hopefully)
    string plate_num;
    // the plate number of the car
    string h1, m1, h2, m2;
    // temporary variables to store hour and minute variables
    //     before they are converted to integers.
    int hour1, min1, hour2, min2;
    // hour1, min1 = time arrived at the first toll booth
    // hour2, min2 = time arrived at the second toll booth
    bool end_flag = false;
    // end_flag = boolean value to determine whether 
    //     '0;0;0;0;0' has been inputed by the user or not.
    //     Used to prevent the program from trying to
    //     calculate a speed using the values before quitting.
    
    // Output the main menu to the console:
    cout << "\n-Illinois Toll Authority Official Speeding Test-"
            "\nPlease input the destination times in the following format:"
            "\n\tLicense Plate Number;Hour;Minute;Hour;Minute (Ex: 111111;12;05;12;20)"
            "\nAlternatively, enter '0;0;0;0;0' to quit the program." << endl;
    
    while (end_flag == false) { 
        // Keep calling calc_speed method until '0;0;0;0;0'
        //    has been inputed.
        
        // getline() chops the user's input up and stores it
        //    into the plate_num variable and temporary
        //    hour and minute variables, delimited by 
        //    a semicolon.
        getline(cin, plate_num, ';');
        getline(cin, h1, ';');
        getline(cin, m1, ';');
        getline(cin, h2, ';');
        getline(cin, m2);   //Note: the last one does not need to be
                            //      delimited because it will be
                            //      automatically delimited by /n.
        
        // Now that we have individual strings containing just the
        //    numbers for the times, we can convert them to ints
        //    using the stoi() function.
        hour1 = stoi(h1);
        min1 = stoi(m1);
        hour2 = stoi(h2);
        min2 = stoi(m2);
        
        if (plate_num == "0" && hour1 == min1 == hour2 == min2 && hour1 == 0) {
            // This if statement checks if all variables are equal to 0 and
            //    if this is true, then the end flag will be marked as true
            //    and the while loop will be broken.
            end_flag = true;
        }
        else {
            // If the prior if statement is false, then we can call the
            //    speed_calc function.
            speed_calc(plate_num, hour1, min1, hour2, min2);
        }
    }
    // If the program has reached here, it must mean that
    //    '0;0;0;0;0' has been inputed, so it is safe to end
    //    the program.
    
    cout << "Quitting..." << endl;
    return 0;
} // End main method.

void speed_calc (string plate_num, int hour1, int min1, int hour2, int min2) {
    // @params: time of arrival at each toll booth, 24hr format
    // returns: none
    const double distance = 14.5;
    // distance between the two will never change, hence constant
    double dif, speed;
    // initialize variables used for speed calculation
    // dif = difference between arrival time 1 and arrival time 2
    // speed = average speed the car was traveling (in mph)
    while (hour1 != hour2) {
        // if the hours are not equal, we require a bit of
        //    calculation before we can determine the 
        //    difference between arrival times
        if (hour1 < hour2) {
            // if the first hour is less than the second
            // ex: 12:40, 13:10
            min2 += 60;
            hour2--;
            // then add 60 to the second minute
            //    and subtract 1 from the hour.
            // ex: 13:10 -> 12:70
        }
        // Originally, I had an else statement determining
        //   what to do when hour2 is smaller than hour1, but
        //   the Lab1 rubric outlines that such a thing shouldn't
        //   happen, since the only way for 24hr time to have that
        //   happen is for it to go to another day.
        else {
            // To prevent an inescapable loop, I decided to 
            //    change it to an error message and return to main.
            cout << "Invalid times, please try again." << "\n" << endl;
            return;
        }
    }
    // Now that we are sure the hours are equal, we can work with
    //    just minutes for this next part.
    if (min1 > min2) {
        // If the first arrival time's minute value is greater
        //    than the second's
        dif = min1 - min2;
        // Subtract min1 from min2 and assign it to the dif variable
    }
    else {
        // If the second arrival time's minute value is greater
        //    than the first's
        dif = min2 - min1;
        // Subtract min2 from min1 and assign it to the dif variable
    }
    // Below, calculate the speed traveled using the formula provided
    //     in the rubric, then multiply by 60 to get it from miles
    //     per minute to miles per hour.
    speed = ((distance)/(dif))*60;
    
    // Finally, figure out whether the speed traveled exceeds the 
    //     speed limit, 60 mph.
    if (speed < 60) {
        cout << plate_num << " " << speed << " mph. Not speeding." << "\n" << endl;
    }
    // If they are speeding, calculate the fine based on how much
    //     the driver exceeds the speed limit.
    else {
        if (60 < speed && speed <= 70) {
            cout << plate_num << " " << speed << " mph. Speeding. $125" << "\n" << endl;
        }
        else if (70 < speed && speed <= 85) {
            cout << plate_num << " " << speed << " mph. Speeding. $275" << "\n" << endl;
        }
        else {
            cout << plate_num << " " << speed << " mph. Speeding. $500" << "\n" << endl;
        }
        
    }
        
}// End speed_calc method. 





