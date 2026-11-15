
#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;

class Booking {
private:
    int bookingId;
    int userId;
    int propertyId;
    string checkIn;
    string checkOut;
    double totalAmount;
    string status;

    static Queue<int> pendingBookings;
    static Stack<int> recentlyViewed;

public:
    Booking();

    void createBooking(int userId, int propertyId);
    void cancelBooking();
    void displayBooking();
    void displayUserBookings(int userId);

    // Queue operations
    static void addPendingBooking(int bookingId);
    static void processNextBooking();

    // Stack operations
    static void addRecentlyViewed(int propertyId);
    static void displayRecentlyViewed();

    int getBookingId();
    int getUserId();
    int getPropertyId();
};

#endif