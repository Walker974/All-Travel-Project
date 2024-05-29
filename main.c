/**
 * Author: Idriss CHERKI - I.Cherki@aui.ma
*/
// Include the output/input library
#include <stdio.h>
// Include the string library
#include <string.h>
// Include the all travel library
#include "AllTravel.h"
// Define the maximum number of bookings
#define MAX_BOOKING 3
// Define the maximum number of customers
#define MAX_CUSTOMERS 100
// Define the tax value
#define TAX_VALUE 0.03
// main function
int main(void) {
    // Declare variables
    int user_count = 0, count_bookings = 0, total_count_bookings = 0;
    float total_revenue = 0.0;
    float total_net_price;
    char user_choice = 'B', quit_choice = 'N', stop_user_choice = 'B';
    int transport_mode, discount_type;
    int current_customer = 0;
    int i, j, transport_seats;
    float cumulative_net_price, cumulative_discount, cumulative_tax, cumulative_total_price, total_net_discount;

    // Parallel arrays to store customer data
    unsigned int customer_ids[MAX_CUSTOMERS] = {0};
    float net_prices[MAX_CUSTOMERS] = {0.0};
    float discounts[MAX_CUSTOMERS] = {0.0};
    float taxes[MAX_CUSTOMERS] = {0.0};
    float total_prices[MAX_CUSTOMERS] = {0.0};
    int seat_quantities[MAX_CUSTOMERS][7] = {{0}};
    float seat_unit_prices[MAX_CUSTOMERS][7] = {{0.0}};

    // loop to handle multiple customers
    do {
        // Display the welcome message and show options
        greet_show_options();
        printf("\nPlease, are you interested in our service? (y/n): ");
        scanf(" %c", &user_choice);
        // Check if the user is interested in the service
        if (user_choice == 'Y' || user_choice == 'y') {
            user_count++;
            unsigned int customer_id;
            // Get the customer ID
            printf("Enter customer ID (1-999999): ");
            scanf("%u", &customer_id);
            
            // Check if the customer ID already exists
            int customer_index = -1;
            for (i = 0; i < current_customer; i++) {
                if (customer_ids[i] == customer_id) {
                    customer_index = i;
                    break;
                }
            }
            
            // If the customer is new, use a new index
            if (customer_index == -1) {
                customer_index = current_customer;
                customer_ids[customer_index] = customer_id;
                current_customer++;
            }

            count_bookings = 0;
            // Initialize the cumulative values
            cumulative_net_price = net_prices[customer_index];
            cumulative_discount = discounts[customer_index];
            cumulative_tax = taxes[customer_index];
            cumulative_total_price = total_prices[customer_index];
            // loop to handle multiple bookings
            do {
                quit_choice = 'N';
                // Check if the customer has already made bookings
                if (count_bookings > 0) {
                    quit_choice = quit_possibility();
                    if (quit_choice == 'Y' || quit_choice == 'y') {
                        break;
                    }
                }
                // Get the transport mode and seats
                transport_mode = get_transport_mode();
                transport_seats = get_transport_seats();
                // Calculate the total net price
                total_net_price = book_transport(transport_mode, transport_seats);
                count_bookings++;

                // Store booking details
                seat_quantities[customer_index][transport_mode - 1] += transport_seats;
                seat_unit_prices[customer_index][transport_mode - 1] = total_net_price / transport_seats;

                // Accumulate net price
                cumulative_net_price += total_net_price;

                if (count_bookings == MAX_BOOKING) {
                    printf("You have reached the maximum number of bookings allowed.\n");
                    break;
                }
            } while ((user_choice == 'Y' || user_choice == 'y') && count_bookings < MAX_BOOKING);

            // Calculate discount, tax, and total price based on cumulative net price
            discount_type = get_discount_type(cumulative_net_price);
            cumulative_discount = get_discount(cumulative_net_price);
            total_net_discount = cumulative_net_price - cumulative_discount;
            cumulative_tax = get_tax(total_net_discount);
            cumulative_total_price = total_net_discount + cumulative_tax;
            // Store customer data
            net_prices[customer_index] = cumulative_net_price;
            discounts[customer_index] = cumulative_discount;
            taxes[customer_index] = cumulative_tax;
            total_prices[customer_index] = cumulative_total_price;
            // Display the user bill
            show_user_bill(cumulative_net_price, discount_type, cumulative_discount, total_net_discount, cumulative_tax, cumulative_total_price);
        }
        // Check if the user wants to stop the application
        stop_user_choice = stop_app_choice();
        if (stop_user_choice == 'X' || stop_user_choice == 'x') {
            break;
        }
        total_count_bookings += count_bookings;
    } while (stop_user_choice == 'B' || stop_user_choice == 'b');

    // Display summary for each customer
    show_summary_for_each_customer(current_customer, customer_ids, seat_quantities, seat_unit_prices, net_prices, discounts, taxes, total_prices);
    // Display current stock
    display_current_stock();
    return 0;
}