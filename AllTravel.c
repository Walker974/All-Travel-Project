/**
 * Author: Idriss CHERKI - I.Cherki@aui.ma
*/
// Include the output/input library
#include <stdio.h>
// Define the macro constants
#define AIR_TYPE_FIRST_CLASS_PRICE 300.0
#define AIR_TYPE_SECOND_CLASS_PRICE 100.0
#define WATER_TYPE_FIRST_CLASS_PRICE 80.0
#define WATER_TYPE_SECOND_CLASS_PRICE 60.0
#define LAND_TYPE_TRAIN_FIRST_CLASS_PRICE 90.0
#define LAND_TYPE_TRAIN_SECOND_CLASS_PRICE 70.0
#define LAND_TYPE_BUS_PRICE 50.0
#define LAND_TYPE_CAR_DRIVER_PRICE 400.0
#define LAND_TYPE_SELF_DRIVE_PRICE 200.0
#define LAND_TYPE_CAR_AUTONOMOUS_PRICE 500.0
#define TAX_VALUE 0.03
#define DISCOUNT_5000_CONDITION 5000
#define DISCOUNT_3000_CONDITION 3000
#define DISCOUNT_1000_CONDITION 1000
#define DISCOUNT_5000 0.15
#define DISCOUNT_3000 0.10
#define DISCOUNT_1000 0.05
#define AIR_TYPE 1
#define WATER_TYPE 2
#define LAND_TYPE_TRAIN 3
#define LAND_TYPE_BUS 4
#define LAND_TYPE_CAR_DRIVER 5
#define LAND_TYPE_SELF_DRIVE 6
#define LAND_TYPE_CAR_AUTONOMOUS 7

// Define the availability of seats
static unsigned int air_type_first_class_availability = 50;
static unsigned int air_type_second_class_availability = 200;
static unsigned int water_type_first_class_availability = 150;
static unsigned int water_type_second_class_availability = 350;
static unsigned int land_type_train_first_class_availability = 100;
static unsigned int land_type_train_second_class_availability = 250;
static unsigned int land_type_bus_availability = 300;
static unsigned int land_type_car_driver_availability = 20;
static unsigned int land_type_self_drive_availability = 40;
static unsigned int land_type_car_autonomous_availability = 10;

// Function to greet the user and show the options
void greet_show_options() {
    printf("Welcome! To book your preferred transport mode, enter the corresponding number:\n");
    printf("1. Air\n2. Water(Ship)\n3. Land(Train)\n4. Land(Bus)\n5. Land(CarDriver)\n6. Land(CarSelf-drive)\n7. Land(CarAutonomous)\n");
}

// Function to get the user choice to stop the application or begin a new booking
char stop_app_choice() {
    char stop_choice;
    printf("Waiting for input. Type B to begin a new booking. Type X to stop the application and display the summary.\n");
    scanf(" %c", &stop_choice);
    return stop_choice;
}

// Function to get the user choice to quit the application
char quit_possibility() {
    char quit_choice;
    printf("Do you want to quit? (y/n): ");
    scanf(" %c", &quit_choice);
    return quit_choice;
}

// Function to display the summary
void display_summary(int user_count, int booking_count, float total_revenue) {
    printf("\n\nSummary:\n");
    printf("Number of users: %d\n", user_count);
    printf("Number of bookings: %d\n", booking_count);
    printf("Total revenue: %.2f\n", total_revenue);
}

// Function to get the transport mode
int get_transport_mode() {
    int transport_mode;
    printf("Enter the transport mode: ");
    scanf("%d", &transport_mode);
    return transport_mode;
}

// Function to get the transport class
int get_transport_class() {
    int transport_class;
    printf("Enter the transport class: ");
    scanf("%d", &transport_class);
    return transport_class;
}

// Function to get the number of seats
int get_transport_seats() {
    int transport_seats;
    printf("Enter the number of seats: ");
    scanf("%d", &transport_seats);
    return transport_seats;
}

// Function to book the transport
float book_transport(int transport_mode, int transport_seats) {
    int transport_class;
    float net_price = 0.0;
    // Check the transport mode
    switch (transport_mode) {
        // Air transport
        case AIR_TYPE:
            transport_class = get_transport_class();
            // Check the transport class
            if (transport_class == 1) {
                if (transport_seats <= air_type_first_class_availability) {
                    air_type_first_class_availability -= transport_seats;
                    net_price = AIR_TYPE_FIRST_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else if (transport_class == 2) {
                if (transport_seats <= air_type_second_class_availability) {
                    air_type_second_class_availability -= transport_seats;
                    net_price = AIR_TYPE_SECOND_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else {
                printf("Invalid class.\n");
            }
            break;
        // Water transport
        case WATER_TYPE:
            transport_class = get_transport_class();
            // Check the transport class
            if (transport_class == 1) {
                // Check the availability
                if (transport_seats <= water_type_first_class_availability) {
                    water_type_first_class_availability -= transport_seats;
                    net_price = WATER_TYPE_FIRST_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else if (transport_class == 2) {
                if (transport_seats <= water_type_second_class_availability) {
                    water_type_second_class_availability -= transport_seats;
                    net_price = WATER_TYPE_SECOND_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else {
                printf("Invalid class.\n");
            }
            break;
        // Land transport
        case LAND_TYPE_TRAIN:
            transport_class = get_transport_class();
            // Check the transport class
            if (transport_class == 1) {
                // Check the availability
                if (transport_seats <= land_type_train_first_class_availability) {
                    land_type_train_first_class_availability -= transport_seats;
                    net_price = LAND_TYPE_TRAIN_FIRST_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else if (transport_class == 2) {
                if (transport_seats <= land_type_train_second_class_availability) {
                    land_type_train_second_class_availability -= transport_seats;
                    net_price = LAND_TYPE_TRAIN_SECOND_CLASS_PRICE * transport_seats;
                } else {
                    printf("Sorry, the number of seats exceeds the availability.\n");
                }
            } else {
                printf("Invalid class.\n");
            }
            break;
        // Land transport
        case LAND_TYPE_BUS:
            // Check the availability
            if (transport_seats <= land_type_bus_availability) {
                land_type_bus_availability -= transport_seats;
                net_price = LAND_TYPE_BUS_PRICE * transport_seats;
            } else {
                printf("Sorry, the number of seats exceeds the availability.\n");
            }
            break;
        // Land transport Car Driver
        case LAND_TYPE_CAR_DRIVER:
            // Check the availability
            if (transport_seats <= land_type_car_driver_availability) {
                land_type_car_driver_availability -= transport_seats;
                net_price = LAND_TYPE_CAR_DRIVER_PRICE * transport_seats;
            } else {
                printf("Sorry, the number of seats exceeds the availability.\n");
            }
            break;
        // Land transport Car Self-drive
        case LAND_TYPE_SELF_DRIVE:
            // Check the availability
            if (transport_seats <= land_type_self_drive_availability) {
                land_type_self_drive_availability -= transport_seats;
                net_price = LAND_TYPE_SELF_DRIVE_PRICE * transport_seats;
            } else {
                printf("Sorry, the number of seats exceeds the availability.\n");
            }
            break;
        // Land transport Car Autonomous
        case LAND_TYPE_CAR_AUTONOMOUS:
            // Check the availability
            if (transport_seats <= land_type_car_autonomous_availability) {
                land_type_car_autonomous_availability -= transport_seats;
                net_price = LAND_TYPE_CAR_AUTONOMOUS_PRICE * transport_seats;
            } else {
                printf("Sorry, the number of seats exceeds the availability.\n");
            }
            break;
        default:
            printf("Invalid transport mode.\n");
            break;
    }
    // Return the net price
    return net_price;
}

// Function to get the discount
float get_discount(float price) {
    if (price >= DISCOUNT_5000_CONDITION) {
        return price * DISCOUNT_5000;
    } else if (price >= DISCOUNT_3000_CONDITION) {
        return price * DISCOUNT_3000;
    } else if (price >= DISCOUNT_1000_CONDITION) {
        return price * DISCOUNT_1000;
    } else {
        return 0;
    }
}

// Function to get the discount type
int get_discount_type(float price) {
    if (price >= DISCOUNT_5000_CONDITION) {
        return 15;
    } else if (price >= DISCOUNT_3000_CONDITION) {
        return 10;
    } else if (price >= DISCOUNT_1000_CONDITION) {
        return 5;
    } else {
        return 0;
    }
}

// Function to get the tax
float get_tax(float price) {
    return price * TAX_VALUE;
}

// Function to show the user bill
void show_user_bill(float net_price, int discount_type, float discount, float net_discount, float tax, float total_price) {
    printf("\nBill:\n");
    printf("Net price: %.2f\n", net_price);
    printf("Discount: %d%%\n", discount_type);
    printf("Discount amount: %.2f\n", discount);
    printf("Net discount: %.2f\n", net_discount);
    printf("Tax: %.2f\n", tax);
    printf("Total price: %.2f\n", total_price);
}

// Function to display the current stock
void display_current_stock() {
    printf("\nCurrent Stock:\n");
    printf("Air - First Class: %u\n", air_type_first_class_availability);
    printf("Air - Second Class: %u\n", air_type_second_class_availability);
    printf("Water - First Class: %u\n", water_type_first_class_availability);
    printf("Water - Second Class: %u\n", water_type_second_class_availability);
    printf("Land - Train First Class: %u\n", land_type_train_first_class_availability);
    printf("Land - Train Second Class: %u\n", land_type_train_second_class_availability);
    printf("Land - Bus: %u\n", land_type_bus_availability);
    printf("Land - Car Driver: %u\n", land_type_car_driver_availability);
    printf("Land - Car Self-drive: %u\n", land_type_self_drive_availability);
    printf("Land - Car Autonomous: %u\n", land_type_car_autonomous_availability);
}

void show_summary_for_each_customer(int current_customer, int customer_ids[], int seat_quantities[][7], float seat_unit_prices[][7], float net_prices[], float discounts[], float taxes[], float total_prices[]) {
    int i, j;
    float grand_net_total_price = 0.0;
    float grand_discount = 0.0;
    float grand_tax = 0.0;
    float grand_total_price = 0.0;
    for (i = 0; i < current_customer; i++) {
        printf("\nCustomer ID: %u\n", customer_ids[i]);
        printf("Ordered Seats/Vehicles:\n");
        // Display the seat quantities and unit prices
        for (j = 0; j < 7; j++) {
            // Check if the seat quantity is greater than 0
            if (seat_quantities[i][j] > 0) {
                // Display the transport mode, seat quantity, and unit price
                printf("  Transport Mode %d: %d seats, Unit Price: %.2f\n", j + 1, seat_quantities[i][j], seat_unit_prices[i][j]);
            }
        }
        // Display the total prices
        printf("Net Total Price: %.2f\n", net_prices[i]);
        printf("Total Discount: %.2f\n", discounts[i]);
        printf("Total Tax: %.2f\n", taxes[i]);
        printf("Total Price: %.2f\n", total_prices[i]);
    }

    // Find the customer with the lowest total price
    int lowest_total_price_index = 0;
    // Loop through the customers
    for (i = 1; i < current_customer; i++) {
        if (total_prices[i] < total_prices[lowest_total_price_index]) {
            lowest_total_price_index = i;
        }
    }
    // Display the customer with the lowest total price
    printf("\nCustomer with the lowest total price: %u\n", customer_ids[lowest_total_price_index]);
    printf("Net Total Price: %.2f\n", net_prices[lowest_total_price_index]);
    printf("Total Discount: %.2f\n", discounts[lowest_total_price_index]);
    printf("Total Tax: %.2f\n", taxes[lowest_total_price_index]);
    printf("Total Price: %.2f\n", total_prices[lowest_total_price_index]);

    // Find the customer with the highest total price
    int highest_total_price_index = 0;
    for (i = 1; i < current_customer; i++) {
        if (total_prices[i] > total_prices[highest_total_price_index]) {
            highest_total_price_index = i;
        }
    }
    printf("\nCustomer with the highest total price: %u\n", customer_ids[highest_total_price_index]);
    printf("Net Total Price: %.2f\n", net_prices[highest_total_price_index]);
    printf("Total Discount: %.2f\n", discounts[highest_total_price_index]);
    printf("Total Tax: %.2f\n", taxes[highest_total_price_index]);
    printf("Total Price: %.2f\n", total_prices[highest_total_price_index]);

    // Display grand totals
    // Loop through the customers
    for (i = 0; i < current_customer; i++) {
        grand_net_total_price += net_prices[i];
        grand_discount += discounts[i];
        grand_tax += taxes[i];
        grand_total_price += total_prices[i];
    }
    // Display the grand totals
    printf("\nGrand Net Total Price: %.2f\n", grand_net_total_price);
    printf("Grand Discount: %.2f\n", grand_discount);
    printf("Grand Tax: %.2f\n", grand_tax);
    printf("Grand Total Price: %.2f\n", grand_total_price);
}