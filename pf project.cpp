#include <iostream>
using namespace std;
const int MAX_MEMBERS = 100;

// Function to display available membership plans
void displayPlans() {
    cout << "Choose a Membership Plan:" << endl;
    cout << "1. Basic" << endl;
    cout << "2. Standard" << endl;
    cout << "3. Premium" << endl;
}
// Function to get user input for plan selection
int getPlanChoice() {
    int choice;
    cout << "Enter the number corresponding to your choice: ";
    cin >> choice;
    return choice;
}
//funtion to display benefits of selected plan.
void displayBenefits(const string& plan) {
    cout << "Membership Benefits for " << plan << " Plan:" << endl;
    if (plan == "Basic") {
        cout << "- Access to basic gym facilities" << endl;
        cout << "- Personalized workout plan: Starter Workout" << endl;
    } else if (plan == "Standard") {
        cout << "- Access to gym facilities and group classes" << endl;
        cout << "- Personalized workout plan: Intermediate Workout" << endl;
    } else if (plan == "Premium") {
        cout << "- Unlimited access to all facilities, group classes, and personal training sessions" << endl;
        cout << "- Personalized workout plan: Advanced Workout" << endl;
    }
}

// Function to display weekly gym routine based on age
void displayWeeklyGymRoutine(const string& plan, int age) {
    cout << "Weekly Gym Routine for " << plan << " Plan:" << endl;
    if (age < 18) {
        cout << "- Monday: Light Cardio" << endl;
        cout << "- Wednesday: Stretching" << endl;
        cout << "- Friday: Bodyweight Exercises" << endl;
    } else if (age >= 18 && age < 28) {
        cout << "- Monday: Cardio and Stretching" << endl;
        cout << "- Wednesday: Strength Training" << endl;
        cout << "- Friday: Full-body Workout" << endl;
    } else if (age >= 28 && age < 36) {
        cout << "- Monday: Cardio and Strength Training" << endl;
        cout << "- Wednesday: High-Intensity Interval Training (HIIT)" << endl;
        cout << "- Friday: Core Exercises" << endl;
    } else if (age >= 36 && age < 45) {
        cout << "- Monday: Cardio and Strength Training" << endl;
        cout << "- Wednesday: Functional Training" << endl;
        cout << "- Friday: Flexibility Exercises" << endl;
    } else {
        cout << "- Monday: Low-Impact Cardio" << endl;
        cout << "- Wednesday: Gentle Strength Training" << endl;
        cout << "- Friday: Balance and Stability Exercises" << endl;
    }
}

// Function to display weekly food routine
void displayWeeklyFoodRoutine(const string& plan) {
    cout << "Weekly Food Routine for " << plan << " Plan:" << endl;
    // Add specific food routines for each plan
    if (plan == "Basic") {
        cout << "- Balanced meals with a focus on lean proteins, whole grains, and vegetables" << endl;
    } else if (plan == "Standard") {
        cout << "- Balanced meals with a mix of proteins, carbohydrates, and healthy fats" << endl;
        cout << "- Adequate hydration throughout the day" << endl;
    } else if (plan == "Premium") {
        cout << "- Personalized nutrition plan based on individual goals and preferences" << endl;
        cout << "- Regular consultations with a nutritionist" << endl;
        cout << "- Hydration plan tailored to individual needs" << endl;
    }
}


double applyDiscount(const double monthlyCost, const string& plan) {
    if (plan == "Premium") {
        return 0.9 * monthlyCost;  // Apply a 10% discount for Premium plan
    }
    return monthlyCost;
}

//start of main function.
int main() {
    cout << "Welcome to the Gym Membership Management System!" << endl;
    const string plans[] = {"Basic", "Standard", "Premium"}
    const double costs[] = {2000, 4000, 6000}

    int membersCount = 0;  // Counter for the number of members

    while (true) {
        cout << "Enter Member Details:" << endl;
        cout << "Name: ";
        string memberName;
        cin.ignore();  
        getline(cin, memberName);

        cout << "Age: ";
        int Age;
        cin >> Age;

        cout << "Contact Number: ";
        string contactNumber;
        cin >> contactNumber;

        //calling functions that we defined.
        displayPlans();

        int choice = getPlanChoice();

        // Validate user choice
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Exiting program." << endl;
            break;
        }
        
        cout << "You selected the " << plans[choice - 1] << " Plan." << endl;

        // Display benefits.
        displayBenefits(plans[choice - 1]);

        // Display weekly gym routine.
        displayWeeklyGymRoutine(plans[choice - 1], Age);

        // Display weekly food routine
        displayWeeklyFoodRoutine(plans[choice - 1]);

        // Ask if the user wants a personal trainer
        char personalTrainer;
        cout << "Do you want a personal trainer? (y/n): ";
        cin >> personalTrainer;

        double totalCost = costs[choice - 1];

        if (tolower(personalTrainer) == 'y') {
             double personalTrainerFee = 1000;  
            totalCost += personalTrainerFee;
            cout << "Personal Trainer Fee: Rs" << personalTrainerFee << " added to the total cost." << endl;
        }

        // Ask if the user wants a locker
        char locker;
        cout << "Do you want a locker? (y/n): ";
        cin >> locker;

        if (tolower(locker) == 'y') {
             double lockerFee = 500;  
            totalCost += lockerFee;
            cout << "Locker Fee: Rs" << lockerFee << " added to the total cost." << endl;
        }

        // Nutrition tracking and personalized workout plan
        char nutritionAndWorkout;
        cout << "Do you want nutrition tracking and a personalized workout plan? (y/n): ";
        cin >> nutritionAndWorkout;

        if (to_lower(nutritionAndWorkout) == 'y') {
             double additionalCost =500 ;
            totalCost += additionalCost;
            cout << "Additional Cost for Nutrition Tracking and Personalized Workout Plan: Rs"
                 << additionalCost << " added to the total cost." << endl;
        }

        // Apply discount or promotion for friends
        
        // Display total cost
        cout << "Total Cost: Rs" << totalCost << endl;

        // Increment members count
        membersCount++;

        // Display current members count and check capacity
        cout << "Current Members Count: " << membersCount << endl;
        if (membersCount >= MAX_MEMBERS) {
            cout << "The gym is at full capacity. No more memberships available." << endl;
            break;
        }

        // Ask if the user wants to add another member
        char addMember;
        cout << "Do you want to add another member? (y/n): ";
        cin >> addMember;

        if (tolower(addMember) != "y") {
            break;  // Exit the loop if the user does not want to add another member
        }
    }

    return 0;
}
