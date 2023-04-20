#include <iostream>
#include <string>
#include <list>

using namespace std;

class Bakery {
private:
    string name;
    int numEmployees;
    bool isFranchise;
public:
    Bakery(string name, int numEmployees, bool isFranchise) :
        name(name), numEmployees(numEmployees), isFranchise(isFranchise) {}

    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    int getNumEmployees() const { return numEmployees; }
    void setNumEmployees(int numEmployees) { this->numEmployees = numEmployees; }

    bool getIsFranchise() const { return isFranchise; }
    void setIsFranchise(bool isFranchise) { this->isFranchise = isFranchise; }

    virtual void printInfo() const {
        cout << "Bakery name: " << name << endl;
        cout << "Number of employees: " << numEmployees << endl;
        cout << "Is franchise? " << (isFranchise ? "Yes" : "No") << endl;
    }

    Bakery operator+(const Bakery& other) const {
        int totalEmployees = numEmployees + other.numEmployees;
        bool isFranchise = this->isFranchise || other.isFranchise;
        return Bakery("Combined Bakery", totalEmployees, isFranchise);
    }

    bool operator>=(const Bakery& other) const {
        return numEmployees >= other.numEmployees;
    }
};

class PastryBakery : public Bakery {
private:
    bool hasVeganOptions;
    bool hasGlutenFreeOptions;
public:
    PastryBakery(string name, int numEmployees, bool isFranchise,
        bool hasVeganOptions, bool hasGlutenFreeOptions) :
        Bakery(name, numEmployees, isFranchise),
        hasVeganOptions(hasVeganOptions), hasGlutenFreeOptions(hasGlutenFreeOptions) {}

    bool getHasVeganOptions() const { return hasVeganOptions; }
    void setHasVeganOptions(bool hasVeganOptions) { this->hasVeganOptions = hasVeganOptions; }

    bool getHasGlutenFreeOptions() const { return hasGlutenFreeOptions; }
    void setHasGlutenFreeOptions(bool hasGlutenFreeOptions) { this->hasGlutenFreeOptions = hasGlutenFreeOptions; }

    virtual void printInfo() const override {
        Bakery::printInfo();
        cout << "Has vegan options? " << (hasVeganOptions ? "Yes" : "No") << endl;
        cout << "Has gluten-free options? " << (hasGlutenFreeOptions ? "Yes" : "No") << endl;
    }
};

class BreadBakery : public Bakery {
private:
    bool hasGlutenFreeOptions;
public:
    BreadBakery(string name, int numEmployees, bool isFranchise,
        bool hasGlutenFreeOptions) :
        Bakery(name, numEmployees, isFranchise), hasGlutenFreeOptions(hasGlutenFreeOptions) {}

    bool getHasGlutenFreeOptions() const { return hasGlutenFreeOptions; }
    void setHasGlutenFreeOptions(bool hasGlutenFreeOptions) { this->hasGlutenFreeOptions = hasGlutenFreeOptions; }

    virtual void printInfo() const override {
        Bakery::printInfo();
        cout << "Has gluten-free options? " << (hasGlutenFreeOptions ? "Yes" : "No") << endl;
    }
};

int main() {
    // create some bakery
    PastryBakery pastryBakery("Sweet Delights", 10, true, true, true);
    BreadBakery breadBakery("Loafers", 5, false, false);

    // print bakery info
    cout << "Pastry Bakery Info: " << endl;
    pastryBakery.printInfo();
    cout << endl;

    cout << "Bread Bakery Info: " << endl;
    breadBakery.printInfo();
    cout << endl;

    // combine two bakeries and print info
    Bakery combinedBakery = pastryBakery + breadBakery;
    cout << "Combined Bakery Info: " << endl;
    combinedBakery.printInfo();
    cout << endl;

    // compare number of employees of two bakeries
    if (pastryBakery >= breadBakery) {
        cout << pastryBakery.getName() << " has more employees than " << breadBakery.getName() << endl;
    }
    else {
        cout << breadBakery.getName() << " has more employees than " << pastryBakery.getName() << endl;
    }

    // demonstrate STL list with bakeries
    list<Bakery> bakeryList;
    bakeryList.push_back(pastryBakery);
    bakeryList.push_back(breadBakery);
    bakeryList.push_back(combinedBakery);

    cout << "Bakery List: " << endl;
    for (const Bakery& bakery : bakeryList) {
        bakery.printInfo();
        cout << endl;
    }

    return 0;
}
