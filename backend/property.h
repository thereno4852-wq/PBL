
#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>
#include "DS.h"

using namespace std;

class Property {
private:
    int propertyId;
    int ownerId;
    string title;
    string location;
    string description;
    double price;
    double rating;
    string luxury;
    bool available;

public:
    Property();

    void addProperty();
    void displayProperty();
    void updateProperty();
    void searchProperty(string location);
    void displayAllProperties();

    int getPropertyId();
    int getOwnerId();
    double getPrice();
    double getRating();
    bool isAvailable();

    bool operator<(const Property& other) const {
        return rating < other.rating;
    }

    bool operator>(const Property& other) const {
        return rating > other.rating;
    }

    static DynamicArray<Property> properties;

    static void sortByRating();
};

#endif
