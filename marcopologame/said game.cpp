#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Forward declarations
class SupplyTracker;
class Camel;
class Boat;
class RandomEvent;

// Forward declarations for display functions
void displayBoatMenu();
void displayCamelMenu();
void displaySuppliesMenu();
void displayStopMenu();
void displayBoatPurchaseMenu();
void displayCamelTradingMenu();
void displayPrequel();
void slowPrint(const string& text, int delayMs = 10);
void playMiningMinigame(SupplyTracker& tracker);

class Boat {
private:
    string type;
    int sails;
    int age;
    int weight;
    int storageCapacity;
    string supplies;

public:
    // Default constructor
    Boat() : type("Junk"), sails(2), age(12), weight(500), storageCapacity(3), supplies("None") {}

    // Parameterized constructor
    Boat(const string& boatType, int numSails, int boatAge, int boatWeight, int storage, const string& boatSupplies) 
        : type(boatType), sails(numSails), age(boatAge), weight(boatWeight), storageCapacity(storage), supplies(boatSupplies) {}

    string getType() const { return type; }
    int getSails() const { return sails; }
    int getAge() const { return age; }
    int getWeight() const { return weight; }
    int getStorageCapacity() const { return storageCapacity; }
    string getSupplies() const { return supplies; }

    void setType(const string& boatType) { type = boatType; }
    void setSails(int numSails) { sails = numSails; }
    void setAge(int boatAge) { age = boatAge; }
    void setWeight(int boatWeight) { weight = boatWeight; }
    void setStorageCapacity(int storage) { storageCapacity = storage; }
    void setSupplies(const string& boatSupplies) { supplies = boatSupplies; }

    bool isTooOld() const { return age > 20; }
    bool isTooYoung() const { return age < 6; }
    bool isValid() const { return !isTooOld() && !isTooYoung(); }

    string getAgeStatus() const {
        if (age > 20) return "Too Old";
        else return "Good Condition";
    }
        
    void displayInfo() const {
        std::cout << "Type: " << type << "\n";
        std::cout << "Sails: " << sails << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Weight: " << weight << " lbs\n";
        std::cout << "Storage Capacity: " << storageCapacity << " tons\n";
        std::cout << "Supplies: " << supplies << "\n";
        std::cout << "Status: " << getAgeStatus() << "\n";
    }
};

class Camel {
private:
    string species;
    int humps;
    int age;
    int weight;
    int storageCapacity;
    string supplies;

public:
    Camel() : species("Bactrian"), humps(2), age(12), weight(700), storageCapacity(100), supplies("None") {}

    Camel(const string& camelSpecies, int numHumps, int camelAge, int camelWeight, int storage, const string& camelSupplies) 
        : species(camelSpecies), humps(numHumps), age(camelAge), weight(camelWeight), storageCapacity(storage), supplies(camelSupplies) {}

    string getSpecies() const { return species; }
    int getHumps() const { return humps; }
    int getAge() const { return age; }
    int getWeight() const { return weight; }
    int getStorageCapacity() const { return storageCapacity; }
    string getSupplies() const { return supplies; }

    void setSpecies(const string& camelSpecies) { species = camelSpecies; }
    void setHumps(int numHumps) { humps = numHumps; }
    void setAge(int camelAge) { age = camelAge; }
    void setWeight(int camelWeight) { weight = camelWeight; }
    void setStorageCapacity(int storage) { storageCapacity = storage; }
    void setSupplies(const string& camelSupplies) { supplies = camelSupplies; }

    bool isTooOld() const { return age > 20; }
    bool isTooYoung() const { return age < 6; }
    bool isValid() const { return !isTooOld() && !isTooYoung(); }

    string getAgeStatus() const {
        if (age < 6) return "Too Young";
        else if (age > 20) return "Too Old";
        else if (age >= 15) return "Senior";
        else if (age >= 10) return "Adult";
        else return "Young Adult";
    }

    void displayInfo() const {
        std::cout << "Species: " << species << "\n";
        std::cout << "Humps: " << humps << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Weight: " << weight << " lbs\n";
        std::cout << "Storage Capacity: " << storageCapacity << " units\n";
        std::cout << "Supplies: " << supplies << "\n";
        std::cout << "Status: " << getAgeStatus() << "\n";
    }
};

class JourneyStop {
private:
    string name;
    int year;
    string description;
    int wheatCost;
    int camelFoodCost;
    int weaponryCost;
    string discovery;

public:
    JourneyStop(const string& stopName, int stopYear, const string& stopDesc, 
                int wCost, int cfCost, int wpCost, const string& stopDiscovery = "")
        : name(stopName), year(stopYear), description(stopDesc), 
          wheatCost(wCost), camelFoodCost(cfCost), weaponryCost(wpCost), discovery(stopDiscovery) {}

    string getName() const { return name; }
    int getYear() const { return year; }
    string getDescription() const { return description; }
    int getWheatCost() const { return wheatCost; }
    int getCamelFoodCost() const { return camelFoodCost; }
    int getWeaponryCost() const { return weaponryCost; }
    string getDiscovery() const { return discovery; }

    void displayStop() const {
        std::cout << "\n=== " << year << " - " << name << " ===\n";
        std::cout << description << "\n";
        if (!discovery.empty()) {
            std::cout << "\n*** DISCOVERY: " << discovery << " ***\n";
        }
        std::cout << "Supply Costs at this stop:\n";
        std::cout << "  Wheat: " << wheatCost << " units\n";
        std::cout << "  Camel Food: " << camelFoodCost << " units\n";
        std::cout << "  Weaponry: " << weaponryCost << " units\n";
    }
};

class SupplyTracker {
private:
    int wheat;
    int camelFood;
    int weaponry;
    int money;
    int patchKit;
    int morale;
    bool hasGoldenPassport;

public:
    SupplyTracker(int w = 0, int cf = 0, int weap = 0, int m = 0, int pk = 0, bool passport = false)
        : wheat(w), camelFood(cf), weaponry(weap), money(m), patchKit(pk), morale(100), hasGoldenPassport(passport) {}

    int getWheat() const { return wheat; }
    int getCamelFood() const { return camelFood; }
    int getWeaponry() const { return weaponry; }
    int getMoney() const { return money; }
    int getPatchKit() const { return patchKit; }
    int getMorale() const { return morale; }
    bool getGoldenPassport() const { return hasGoldenPassport; }

    void setGoldenPassport(bool value) { hasGoldenPassport = value; }
    void setWheat(int w) { wheat = w; }
    void setCamelFood(int cf) { camelFood = cf; }
    void setWeaponry(int w) { weaponry = w; }
    void setMoney(int m) { money = m; }
    void setPatchKit(int pk) { patchKit = pk; }
    void setMorale(int mr) { morale = (mr > 100) ? 100 : (mr < 0) ? 0 : mr; }

    void decreaseMorale(int amount) {
        morale -= amount;
        if (morale < 0) morale = 0;
    }

    void restoreMorale(int amount) {
        morale += amount;
        if (morale > 100) morale = 100;
    }

    string getMoraleStatus() const {
        if (morale >= 80) return "Excellent";
        else if (morale >= 60) return "Good";
        else if (morale >= 40) return "Fair";
        else if (morale >= 20) return "Low";
        else return "Critical";
    }

    bool buySupplies(int wAmount, int cfAmount, int wpAmount, int mAmount) {
        if (wheat >= wAmount && camelFood >= cfAmount && weaponry >= wpAmount && money >= mAmount) {
            wheat -= wAmount;
            camelFood -= cfAmount;
            weaponry -= wpAmount;
            money -= mAmount;
            return true;
        }
        return false;
    }

    void addSupplies(int wAmount, int cfAmount, int wpAmount, int mAmount, int pkAmount = 0) {
        wheat += wAmount;
        camelFood += cfAmount;
        weaponry += wpAmount;
        money += mAmount;
        patchKit += pkAmount;
    }

    void displaySupplyStatus() const {
        std::cout << "\n=== Current Supply Status ===\n";
        std::cout << "Wheat: ";
        if (wheat == INT_MAX) std::cout << "inf";
        else std::cout << wheat;
        std::cout << " units\n";
        
        std::cout << "Camel Food: ";
        if (camelFood == INT_MAX) std::cout << "inf";
        else std::cout << camelFood;
        std::cout << " units\n";
        
        std::cout << "Weaponry: ";
        if (weaponry == INT_MAX) std::cout << "inf";
        else std::cout << weaponry;
        std::cout << " units\n";
        
        std::cout << "Patch Kit: ";
        if (patchKit == INT_MAX) std::cout << "inf";
        else std::cout << patchKit;
        std::cout << " unit(s)\n";
        
        std::cout << "Money: ";
        if (money == INT_MAX) std::cout << "inf";
        else std::cout << money;
        std::cout << " coins\n";
        
        std::cout << "Morale: " << morale << "/100 (" << getMoraleStatus() << ")\n";
        
        if (hasGoldenPassport) {
            std::cout << "*** GOLDEN PASSPORT: You possess the Khan's golden passport! (Discount rates active) ***\n";
        }
    }

    bool isCriticallyLow() const {
        return (wheat < 5) || (money < 20);
    }

    bool isExhausted() const {
        return morale <= 10;
    }
};

// Random event class with BOAT_HOLE support
class RandomEvent {
public:
    enum EventType {
        CAMEL_DEATH,
        BOAT_SINKING,
        BOAT_HOLE,
        BANDIT_ATTACK,
        DISEASE_OUTBREAK,
        STORM,
        FOOD_SPOILAGE,
        NO_EVENT
    };

    static EventType generateRandomEvent(int legNumber) {
        int rand_val = rand() % 100;
        
        // Increasing danger as journey progresses
        if (legNumber < 3) rand_val += 20;
        if (legNumber > 9) rand_val -= 20;
        
        if (rand_val < 10) return CAMEL_DEATH;
        if (rand_val < 18) return BOAT_SINKING;
        if (rand_val < 28) return BOAT_HOLE;
        if (rand_val < 40) return BANDIT_ATTACK;
        if (rand_val < 55) return DISEASE_OUTBREAK;
        if (rand_val < 70) return STORM;
        if (rand_val < 85) return FOOD_SPOILAGE;
        return NO_EVENT;
    }

    static string getEventDescription(EventType event) {
        switch (event) {
            case CAMEL_DEATH:
                return "Your camel has fallen ill and died from the harsh desert conditions!";
            case BOAT_SINKING:
                return "Your boat has sprung a leak! You must make emergency repairs!";
            case BOAT_HOLE:
                return "Your boat has developed a hole in the hull!";
            case BANDIT_ATTACK:
                return "Bandits have attacked your caravan! You must defend your supplies!";
            case DISEASE_OUTBREAK:
                return "Illness has spread through your party! Medical supplies are needed!";
            case STORM:
                return "A terrible storm has struck! You must take shelter and wait it out!";
            case FOOD_SPOILAGE:
                return "Much of your food has spoiled in the heat and humidity!";
            default:
                return "No incidents occurred.";
        }
    }

    static void handleEvent(EventType event, SupplyTracker& tracker, Camel& camel, Boat& boat, bool& journeyEnded) {
        int wheatLoss = 0;
        int foodLoss = 0;
        
        switch (event) {
            case CAMEL_DEATH:
                std::cout << "\n*** RANDOM EVENT: CAMEL DEATH ***\n";
                std::cout << getEventDescription(event) << "\n";
                camel.setAge(999);
                std::cout << "You lose your camel and must continue on foot!\n";
                std::cout << "Your travel speed decreases significantly.\n";
                break;

            case BOAT_SINKING:
                std::cout << "\n*** RANDOM EVENT: BOAT DAMAGE ***\n";
                std::cout << getEventDescription(event) << "\n";
                tracker.addSupplies(-20, -15, -5, -50);
                std::cout << "Supplies lost: 20 wheat, 15 camel food, 5 weaponry, 50 coins\n";
                break;

            case BOAT_HOLE:
                std::cout << "\n*** RANDOM EVENT: BOAT HOLE ***\n";
                std::cout << getEventDescription(event) << "\n";
                if (tracker.getPatchKit() > 0) {
                    std::cout << "You use a patch kit to repair the hole!\n";
                    tracker.addSupplies(0, 0, 0, 0, -1);
                    std::cout << "Patch kit used! You lose: 1 patch kit\n";
                } else {
                    std::cout << "You have no patch kit! Water seeps in constantly.\n";
                    tracker.addSupplies(-10, -5, 0, -25);
                    std::cout << "You lose: 10 wheat, 5 camel food, 25 coins (water damage)\n";
                    std::cout << "Consider buying a patch kit at the next stop!\n";
                }
                break;

            case BANDIT_ATTACK:
                std::cout << "\n*** RANDOM EVENT: BANDIT ATTACK ***\n";
                std::cout << getEventDescription(event) << "\n";
                if (tracker.getWeaponry() > 0) {
                    std::cout << "You defend yourself with your weapons!\n";
                    tracker.addSupplies(0, 0, -5, -100);
                    std::cout << "You lose: 5 weaponry, 100 coins\n";
                } else {
                    std::cout << "You have no weapons to defend yourself!\n";
                    tracker.addSupplies(-25, -20, 0, -150);
                    std::cout << "You lose: 25 wheat, 20 camel food, 150 coins\n";
                }
                break;

            case DISEASE_OUTBREAK:
                std::cout << "\n*** RANDOM EVENT: DISEASE OUTBREAK ***\n";
                std::cout << getEventDescription(event) << "\n";
                tracker.addSupplies(-15, -10, 0, -75);
                std::cout << "Your party wastes resources fighting the illness.\n";
                std::cout << "You lose: 15 wheat, 10 camel food, 75 coins\n";
                break;

            case STORM:
                std::cout << "\n*** RANDOM EVENT: SEVERE STORM ***\n";
                std::cout << getEventDescription(event) << "\n";
                tracker.addSupplies(-10, -8, 0, 0);
                std::cout << "You're trapped for days, consuming supplies.\n";
                std::cout << "You lose: 10 wheat, 8 camel food\n";
                break;

            case FOOD_SPOILAGE:
                std::cout << "\n*** RANDOM EVENT: FOOD SPOILAGE ***\n";
                std::cout << getEventDescription(event) << "\n";
                wheatLoss = tracker.getWheat() / 3;
                foodLoss = tracker.getCamelFood() / 3;
                tracker.addSupplies(-wheatLoss, -foodLoss, 0, 0);
                std::cout << "You lose: " << wheatLoss << " wheat, " << foodLoss << " camel food\n";
                break;

            case NO_EVENT:
                std::cout << "\n*** Travel uneventful. Clear skies ahead. ***\n";
                break;
        }

        // Check for critical failures
        if (camel.getAge() == 999) {
            std::cout << "\n*** CRITICAL FAILURE: You cannot continue without a camel! ***\n";
            std::cout << "GAME OVER\n";
            journeyEnded = true;
        }

        if (tracker.getWheat() < 0 || tracker.getCamelFood() < 0) {
            std::cout << "\n*** CRITICAL: You have run out of supplies! ***\n";
            std::cout << "GAME OVER\n";
            journeyEnded = true;
        }
    }
};

// Debug Menu System
class DebugMenu {
public:
    static void displayDebugMenu() {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "         DEMO MODE - DEBUG MENU         \n";
        std::cout << "========================================\n";
        std::cout << "1. Trigger Random Event\n";
        std::cout << "2. Edit Supply Levels\n";
        std::cout << "3. Edit Supply Prices\n";
        std::cout << "4. Edit RNG Event Thresholds\n";
        std::cout << "5. View Current Supplies\n";
        std::cout << "6. Exit Debug Menu\n";
        std::cout << "Enter your choice: ";
    }

    static void displayEventMenu() {
        std::cout << "\n=== Trigger Random Event ===\n";
        std::cout << "1. Camel Death\n";
        std::cout << "2. Boat Sinking\n";
        std::cout << "3. Boat Hole\n";
        std::cout << "4. Bandit Attack\n";
        std::cout << "5. Disease Outbreak\n";
        std::cout << "6. Storm\n";
        std::cout << "7. Food Spoilage\n";
        std::cout << "8. No Event\n";
        std::cout << "Enter your choice: ";
    }

    static void displayEditSuppliesMenu() {
        std::cout << "\n=== Edit Supply Levels ===\n";
        std::cout << "1. Set Wheat\n";
        std::cout << "2. Set Camel Food\n";
        std::cout << "3. Set Weaponry\n";
        std::cout << "4. Set Money\n";
        std::cout << "5. Set Patch Kit\n";
        std::cout << "6. Set All Supplies Individually\n";
        std::cout << "7. Set All Supplies (Full Bundle)\n";
        std::cout << "8. Back to Debug Menu\n";
        std::cout << "Enter your choice: ";
    }

    static void displayEditPricesMenu() {
        std::cout << "\n=== Edit Supply Prices ===\n";
        std::cout << "1. Set Wheat Price (Default: 5)\n";
        std::cout << "2. Set Camel Food Price (Default: 3)\n";
        std::cout << "3. Set Weaponry Price (Default: 2)\n";
        std::cout << "4. Set Patch Kit Price (Default: 20)\n";
        std::cout << "5. Back to Debug Menu\n";
        std::cout << "Enter your choice: ";
    }

    static void displayEditRNGMenu() {
        std::cout << "\n=== Edit RNG Event Thresholds ===\n";
        std::cout << "Camel Death (0-10): Set threshold for camel death\n";
        std::cout << "Boat Sinking (10-18): Set threshold for boat sinking\n";
        std::cout << "Boat Hole (18-28): Set threshold for boat hole\n";
        std::cout << "Bandit Attack (28-40): Set threshold for bandit attack\n";
        std::cout << "Disease Outbreak (40-55): Set threshold for disease\n";
        std::cout << "Storm (55-70): Set threshold for storm\n";
        std::cout << "Food Spoilage (70-85): Set threshold for food spoilage\n\n";
        std::cout << "1. Set Camel Death Threshold\n";
        std::cout << "2. Set Boat Sinking Threshold\n";
        std::cout << "3. Set Boat Hole Threshold\n";
        std::cout << "4. Set Bandit Attack Threshold\n";
        std::cout << "5. Set Disease Outbreak Threshold\n";
        std::cout << "6. Set Storm Threshold\n";
        std::cout << "7. Set Food Spoilage Threshold\n";
        std::cout << "8. Back to Debug Menu\n";
        std::cout << "Enter your choice: ";
    }

    static int getSafeIntInput() {
        string input;
        while (true) {
            std::cin >> input;
            
            // Check for infinity input
            if (input == "inf" || input == "infinity" || input == "INF" || input == "INFINITY") {
                return INT_MAX;
            }
            
            try {
                // Check for extremely large numbers
                if (input.length() > 10) {
                    std::cout << "Value too large! Please enter a reasonable number (or 'inf' for infinity): ";
                    continue;
                }
                int value = std::stoi(input);
                return value;
            }
            catch (const std::exception&) {
                std::cout << "Invalid input! Please enter a valid number (or 'inf' for infinity): ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }

    static void handleDebugMenu(SupplyTracker& tracker, Camel& camel, Boat& boat) {
        bool inDebugMenu = true;
        while (inDebugMenu) {
            displayDebugMenu();
            string choice;
            std::cin >> choice;
            
            if (choice == "1") {
                displayEventMenu();
                int eventChoice;
                std::cin >> eventChoice;
                RandomEvent::EventType selectedEvent;
                
                switch (eventChoice) {
                    case 1: selectedEvent = RandomEvent::CAMEL_DEATH; break;
                    case 2: selectedEvent = RandomEvent::BOAT_SINKING; break;
                    case 3: selectedEvent = RandomEvent::BOAT_HOLE; break;
                    case 4: selectedEvent = RandomEvent::BANDIT_ATTACK; break;
                    case 5: selectedEvent = RandomEvent::DISEASE_OUTBREAK; break;
                    case 6: selectedEvent = RandomEvent::STORM; break;
                    case 7: selectedEvent = RandomEvent::FOOD_SPOILAGE; break;
                    case 8: selectedEvent = RandomEvent::NO_EVENT; break;
                    default: selectedEvent = RandomEvent::NO_EVENT; break;
                }
                
                bool journeyEnded = false;
                RandomEvent::handleEvent(selectedEvent, tracker, camel, boat, journeyEnded);
                tracker.displaySupplyStatus();
            }
            else if (choice == "2") {
                bool inEditMenu = true;
                while (inEditMenu) {
                    displayEditSuppliesMenu();
                    int editChoice;
                    std::cin >> editChoice;

                    switch (editChoice) {
                        case 1: {
                            std::cout << "Current Wheat: ";
                            if (tracker.getWheat() == INT_MAX) std::cout << "inf";
                            else std::cout << tracker.getWheat();
                            std::cout << "\nEnter new value: ";
                            int value = getSafeIntInput();
                            tracker.setWheat(value);
                            std::cout << "Wheat changed to ";
                            if (value == INT_MAX) std::cout << "inf";
                            else std::cout << value;
                            std::cout << "\n";
                            break;
                        }
                        case 2: {
                            std::cout << "Current Camel Food: ";
                            if (tracker.getCamelFood() == INT_MAX) std::cout << "inf";
                            else std::cout << tracker.getCamelFood();
                            std::cout << "\nEnter new value: ";
                            int value = getSafeIntInput();
                            tracker.setCamelFood(value);
                            std::cout << "Camel Food changed to ";
                            if (value == INT_MAX) std::cout << "inf";
                            else std::cout << value;
                            std::cout << "\n";
                            break;
                        }
                        case 3: {
                            std::cout << "Current Weaponry: ";
                            if (tracker.getWeaponry() == INT_MAX) std::cout << "inf";
                            else std::cout << tracker.getWeaponry();
                            std::cout << "\nEnter new value: ";
                            int value = getSafeIntInput();
                            tracker.setWeaponry(value);
                            std::cout << "Weaponry changed to ";
                            if (value == INT_MAX) std::cout << "inf";
                            else std::cout << value;
                            std::cout << "\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Current Money: ";
                            if (tracker.getMoney() == INT_MAX) std::cout << "inf";
                            else std::cout << tracker.getMoney();
                            std::cout << "\nEnter new value: ";
                            int value = getSafeIntInput();
                            tracker.setMoney(value);
                            std::cout << "Money changed to ";
                            if (value == INT_MAX) std::cout << "inf";
                            else std::cout << value;
                            std::cout << "\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Current Patch Kit: ";
                            if (tracker.getPatchKit() == INT_MAX) std::cout << "inf";
                            else std::cout << tracker.getPatchKit();
                            std::cout << "\nEnter new value: ";
                            int value = getSafeIntInput();
                            tracker.setPatchKit(value);
                            std::cout << "Patch Kit changed to ";
                            if (value == INT_MAX) std::cout << "inf";
                            else std::cout << value;
                            std::cout << "\n";
                            break;
                        }
                        case 6: {
                            std::cout << "\n=== Set All Supplies Individually ===\n";
                            
                            std::cout << "Enter Wheat amount: ";
                            int wheat = getSafeIntInput();
                            
                            std::cout << "Enter Camel Food amount: ";
                            int camelFood = getSafeIntInput();
                            
                            std::cout << "Enter Weaponry amount: ";
                            int weaponry = getSafeIntInput();
                            
                            std::cout << "Enter Money amount: ";
                            int money = getSafeIntInput();
                            
                            std::cout << "Enter Patch Kit amount: ";
                            int patchKit = getSafeIntInput();
                            
                            tracker.setWheat(wheat);
                            tracker.setCamelFood(camelFood);
                            tracker.setWeaponry(weaponry);
                            tracker.setMoney(money);
                            tracker.setPatchKit(patchKit);
                            
                            std::cout << "\nAll supplies changed to ";
                            if (wheat == INT_MAX) std::cout << "inf"; else std::cout << wheat;
                            std::cout << ", ";
                            if (camelFood == INT_MAX) std::cout << "inf"; else std::cout << camelFood;
                            std::cout << ", ";
                            if (weaponry == INT_MAX) std::cout << "inf"; else std::cout << weaponry;
                            std::cout << ", ";
                            if (money == INT_MAX) std::cout << "inf"; else std::cout << money;
                            std::cout << ", ";
                            if (patchKit == INT_MAX) std::cout << "inf"; else std::cout << patchKit;
                            std::cout << "!\n";
                            tracker.displaySupplyStatus();
                            break;
                        }
                        case 7: {
                            std::cout << "Setting Full Bundle supplies...\n";
                            tracker.setWheat(100);
                            tracker.setCamelFood(100);
                            tracker.setWeaponry(50);
                            tracker.setMoney(1000);
                            tracker.setPatchKit(5);
                            std::cout << "All supplies changed to 100, 100, 50, 1000, 5!\n";
                            tracker.displaySupplyStatus();
                            break;
                        }
                        case 8:
                            inEditMenu = false;
                            break;
                    }
                }
            }
            else if (choice == "3") {
                bool inPriceMenu = true;
                while (inPriceMenu) {
                    displayEditPricesMenu();
                    int priceChoice;
                    std::cin >> priceChoice;
                    
                    switch (priceChoice) {
                        case 1: {
                            std::cout << "Enter new Wheat price: ";
                            int price = getSafeIntInput();
                            std::cout << "Wheat price changed to " << price << "\n";
                            break;
                        }
                        case 2: {
                            std::cout << "Enter new Camel Food price: ";
                            int price = getSafeIntInput();
                            std::cout << "Camel Food price changed to " << price << "\n";
                            break;
                        }
                        case 3: {
                            std::cout << "Enter new Weaponry price: ";
                            int price = getSafeIntInput();
                            std::cout << "Weaponry price changed to " << price << "\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Enter new Patch Kit price: ";
                            int price = getSafeIntInput();
                            std::cout << "Patch Kit price changed to " << price << "\n";
                            break;
                        }
                        case 5:
                            inPriceMenu = false;
                            break;
                    }
                }
            }
            else if (choice == "4") {
                bool inRNGMenu = true;
                while (inRNGMenu) {
                    displayEditRNGMenu();
                    int rngChoice;
                    std::cin >> rngChoice;
                    
                    switch (rngChoice) {
                        case 1: {
                            std::cout << "Enter new Camel Death threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Camel Death threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 2: {
                            std::cout << "Enter new Boat Sinking threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Boat Sinking threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 3: {
                            std::cout << "Enter new Boat Hole threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Boat Hole threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Enter new Bandit Attack threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Bandit Attack threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Enter new Disease Outbreak threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Disease Outbreak threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 6: {
                            std::cout << "Enter new Storm threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Storm threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 7: {
                            std::cout << "Enter new Food Spoilage threshold (0-100): ";
                            int threshold = getSafeIntInput();
                            std::cout << "Food Spoilage threshold changed to " << threshold << "\n";
                            break;
                        }
                        case 8:
                            inRNGMenu = false;
                            break;
                    }
                }
            }
            else if (choice == "5") {
                tracker.displaySupplyStatus();
            }
            else if (choice == "6") {
                inDebugMenu = false;
                std::cout << "\nDebug menu closed. Resuming game...\n";
            }
        }
    }
};

// Helper function to get valid input - now checks for DEMO
int getValidInputWithDemo(int minValue, int maxValue, SupplyTracker* tracker = nullptr, Camel* camel = nullptr, Boat* boat = nullptr, int menuType = 0) {
    string input;
    while (true) {
        std::cin >> input;
        
        // Check for DEMO command
        if (input == "DEMO" || input == "demo") {
            if (tracker != nullptr && camel != nullptr && boat != nullptr) {
                DebugMenu::handleDebugMenu(*tracker, *camel, *boat);
                // Redisplay the original menu based on menuType
                switch (menuType) {
                    case 1: displayBoatMenu(); break;
                    case 2: displayCamelMenu(); break;
                    case 3: displaySuppliesMenu(); break;
                    case 4: displayStopMenu(); break;
                    case 5: displayBoatPurchaseMenu(); break;
                    case 6: displayCamelTradingMenu(); break;
                }
                std::cout << "Enter your choice: ";
                continue;
            } else {
                std::cout << "Enter your choice: ";
                continue;
            }
        }
        
        // Try to convert to int
        try {
            int result = std::stoi(input);
            if (result < minValue || result > maxValue) {
                std::cout << "Invalid choice! Please select between " << minValue << " and " << maxValue << ": ";
                continue;
            }
            return result;
        }
        catch (const std::exception&) {
            std::cout << "Invalid input! Please enter a number between " << minValue << " and " << maxValue << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
}

// Helper function for number-only input
int getValidInput(int minValue, int maxValue) {
    int input;
    while (true) {
        std::cin >> input;
        
        // Check if input failed (non-numeric)
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between " << minValue << " and " << maxValue << ": ";
            continue;
        }
        
        // Check if input is within range
        if (input < minValue || input > maxValue) {
            std::cout << "Invalid choice! Please select between " << minValue << " and " << maxValue << ": ";
            continue;
        }
        
        return input;
    }
}

// Optimized slow text printing function - faster with skip support
void slowPrint(const string& text, int delayMs) {
    for (size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i] << std::flush;
        
        // Check if key was pressed (non-blocking)
        if (_kbhit()) {
            int key = _getch();
            if (key == 13) {  // Enter key
                // Print the rest of the text instantly
                std::cout << text.substr(i + 1);
                return;
            }
        }
        
        if (delayMs > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
    }
}

void displayPrequel() {
    std::cout << "\n";
    std::cout << "================================================================================\n";
    std::cout << "                         MARCO POLO'S JOURNEY BEGINS\n";
    std::cout << "                              THE PRELUDE\n";
    std::cout << "================================================================================\n";
    std::cout << "\n";

    slowPrint("VENICE, 1271\n");
    slowPrint("The bustling port city of Venice thrums with the energy of merchants, sailors, and\n");
    slowPrint("traders. The salty sea air fills your lungs as you stand at the dock, watching ships\n");
    slowPrint("arrive and depart to distant lands. Your father, Nicolo Polo, has called you to\n");
    slowPrint("meet him and your Uncle Maffeo at the harbor.\n\n");

    slowPrint("NICOLO (Your Father):\n");
    slowPrint("\"Marco! There you are. We've been waiting for you. Listen closely, my son.\n");
    slowPrint("Your uncle and I have just returned from the East. We've traveled roads that few\n");
    slowPrint("Venetians have ever dared to venture upon. The riches we saw... magnificent!\"\n\n());

    slowPrint("MAFFEO (Your Uncle):\n");
    slowPrint("\"Yes, Marco. We reached the court of the great Kublai Khan himself! The Khan\n");
    slowPrint("has granted us permission to return with tribute and a young man of intelligence.\n");
    slowPrint("Your father has chosen you for this honor.\"\n\n");

    slowPrint("You stand stunned, unable to speak. The Kublai Khan? The legendary ruler of the\n");
    slowPrint("Mongol Empire? Your father places a hand on your shoulder.\n\n");

    slowPrint("NICOLO:\n");
    slowPrint("\"Marco, you are seventeen now. Too old to hide behind merchant stalls in Venice.\n");
    slowPrint("Too young to waste your potential on the same mundane routes that every trader\n");
    slowPrint("knows by heart. The Khan has heard of our family, and he believes you have the\n");
    slowPrint("intelligence and cunning to serve him well.\"\n\n");

    slowPrint("MAFFEO:\n");
    slowPrint("\"The journey will not be easy, nephew. Deserts that stretch for weeks. Mountains\n");
    slowPrint("so high the air itself becomes thin. Bandits, storms, and dangers we cannot\n");
    slowPrint("even name. But the reward—service to the most powerful ruler in the world!\n");
    slowPrint("And knowledge of lands our civilization has barely heard whispers about.\"\n\n");

    slowPrint("Your heart pounds in your chest. Fear and excitement battle within you.\n\n");

    slowPrint("NICOLO:\n");
    slowPrint("\"We depart tomorrow at dawn. You will gather supplies today. Choose your boat\n");
    slowPrint("and camel carefully—your life may depend on these choices. We will provide you\n");
    slowPrint("with enough money and supplies to sustain us through the early stages of our\n");
    slowPrint("journey, but you must manage them wisely.\"\n\n");

    slowPrint("MAFFEO:\n");
    slowPrint("\"The path to Cathay is long, Marco. Over 5,000 miles of unknown territory.\n");
    slowPrint("You will face trials that will test your character, your wisdom, and your will.\n");
    slowPrint("But if you succeed, you will have the ear of the Khan himself. You will see\n");
    slowPrint("wonders beyond imagination.\"\n\n");

    slowPrint("Your uncle grips your arm firmly.\n\n");

    slowPrint("MAFFEO:\n");
    slowPrint("\"Are you ready, Marco? Ready to become a man of the world?\"\n\n");

    slowPrint("You take a deep breath and nod, your resolve hardening. This is your chance.\n");
    slowPrint("This is destiny.\n\n");

    slowPrint("NICOLO:\n");
    slowPrint("\"Excellent. Tomorrow, we embark on a journey that will change everything.\n");
    slowPrint("Remember, Marco—fortune favors the bold, but it protects the wise.\"\n\n");

    std::cout << "================================================================================\n";
    slowPrint("The sun sets over Venice as you prepare for the greatest adventure of your life.\n");
    slowPrint("Your journey to the court of Kublai Khan is about to begin...\n");
    std::cout << "================================================================================\n";
    std::cout << "\n\n";

    std::cout << "Press Enter to continue...\n";
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

vector<JourneyStop> initializeJourneyStops() {
    vector<JourneyStop> stops;
    stops.push_back(JourneyStop("Venice", 1271, 
        "You depart Venice with your father and uncle.\nA bustling Mediterranean port city.\n"
        "FACT: Venice was the center of European trade, controlling Mediterranean commerce\nthrough its powerful merchant republic.", 
        5, 3, 2, "Postal service"));
    stops.push_back(JourneyStop("Mediterranean Sea Voyage", 1271, 
        "You sail across the Mediterranean in a Venetian galley.\nThe sea is both beautiful and treacherous.\n"
        "FACT: Venetian galleys were the primary vessels for Mediterranean trade,\nfeatures multiple sails and could carry large cargo loads across dangerous waters.", 
        6, 4, 2, ""));
    stops.push_back(JourneyStop("Holy Land", 1271, 
        "You travel through the Holy Land.\nA sacred region filled with historical sites.\n"
        "FACT: The Holy Land was a crucial junction between Europe and Asia,\nwhere merchants exchanged goods and gathered intelligence about Eastern routes.", 
        8, 5, 3, "Spices"));
    stops.push_back(JourneyStop("Persia", 1272, 
        "You journey through the Persian Empire.\nA magnificent land of deserts and cities.\n"
        "FACT: Persia was a major crossroads of the Silk Road, where Persian merchants\ncontrolled valuable trade routes and accumulated great wealth from tariffs.", 
        10, 6, 4, "Coal heating"));
    stops.push_back(JourneyStop("Pamir Mountains", 1273, 
        "You cross the treacherous Pamir Mountains.\nA dangerous passage through high peaks.\n"
        "FACT: The Pamir Mountains were one of the most dangerous sections of the Silk Road,\nwhere many travelers perished from altitude sickness and extreme weather conditions.", 
        12, 8, 5, "Asbestos"));
    stops.push_back(JourneyStop("Kublai Khan's Court", 1275, 
        "You finally reach the court of Kublai Khan!\nA grand city with incredible wealth.\n"
        "FACT: Kublai Khan's court at Xanadu was a cosmopolitan center of power,\nwhere the Khan employed people from across his vast Mongol Empire.", 
        6, 4, 3, "Advanced urban cities"));
    stops.push_back(JourneyStop("Southern China", 1279, 
        "You travel to southern China on official missions.\nFascinating new lands and peoples.\n"
        "FACT: Southern China under Kublai Khan was highly urbanized with advanced infrastructure,\nincluding canals, roads, and sophisticated administrative systems.", 
        7, 5, 3, "Porcelain"));
    stops.push_back(JourneyStop("Burma", 1280, 
        "You explore the exotic lands of Burma.\nLush forests and ancient temples await.\n"
        "FACT: Burma was a tributary state of the Mongol Empire, providing exotic goods\nlike rubies, jade, and rare spices to Kublai Khan's court.", 
        9, 6, 4, "Petroleum"));
    stops.push_back(JourneyStop("Indian Ocean Voyage", 1281, 
        "You embark on a perilous journey across the Indian Ocean in a Chinese junk.\nThe vast waters stretch endlessly before you.\n"
        "FACT: Chinese junks were advanced sailing vessels with watertight compartments,\nallowing Marco Polo to safely traverse the Indian Ocean's dangerous waters.", 
        10, 8, 5, ""));
    stops.push_back(JourneyStop("India", 1281, 
        "You venture into India on behalf of the Khan.\nRich spices and precious gems abound.\n"
        "FACT: India's spice trade was highly valued in medieval times, with pepper,\ncloves, and nutmeg worth their weight in gold in European markets.", 
        8, 7, 4, "Paper money"));
    stops.push_back(JourneyStop("Return Journey - India", 1292, 
        "After 20 years, Kublai Khan permits your return.\nYou begin heading back through familiar lands.\n"
        "FACT: Marco Polo spent over 20 years in service to Kublai Khan,\nbecoming one of the Khan's most trusted and valued foreign advisors.", 
        8, 7, 4, "Maps and Navigation Charts"));
    stops.push_back(JourneyStop("Return Journey - Burma", 1293, 
        "Retracing your steps through Burma.\nThe exotic lands are familiar now.\n"
        "FACT: The return journey was perilous, with many traveling companions perishing\nbefore reaching the relative safety of Persia.", 
        9, 6, 4, ""));
    stops.push_back(JourneyStop("Return Journey - Persia", 1294, 
        "Traveling through Persia on the return voyage.\nThe desert winds guide you home.\n"
        "FACT: Upon returning to Persia, the Polos learned that Kublai Khan had died,\nmaking their service to him part of history.", 
        10, 6, 4, ""));
    stops.push_back(JourneyStop("Venice", 1295, 
        "You arrive home in Venice with great wealth!\nYour legendary journey is complete.\n"
        "FACT: When Marco Polo returned to Venice, few believed his stories.\nHe later dictated his adventures to Rustichello da Pisa while imprisoned,\ncreating 'The Travels of Marco Polo', a work that inspired generations.", 
        0, 0, 0, ""));
    return stops;
}

void displayBoatMenu() {
    std::cout << "=== Marco Polo's Boat Selection Menu ===\n";
    std::cout << "1. Small Fishing Boat (1 sail, 12 years old, 500 lbs, 2 tons cargo)\n";
    std::cout << "2. Arab Dhow (2 sails, 8 years old, 700 lbs, 3 tons cargo)\n";
    std::cout << "3. Small Trader (2 sails, 15 years old, 600 lbs, 4 tons cargo)\n";
    std::cout << "4. Coastal Vessel (2 sails, 10 years old, 650 lbs, 4 tons cargo)\n";
    std::cout << "5. Mediterranean Cruiser (3 sails, 18 years old, 750 lbs, 5 tons cargo)\n";
    std::cout << "6. Old Dhow (2 sails, 25 years old, 800 lbs, 5 tons cargo) - TOO OLD\n";
}

void displayBoatPurchaseMenu() {
    std::cout << "\n=== Boat Purchase Menu for Ocean Voyage ===\n";
    std::cout << "You must purchase a vessel for the upcoming ocean voyage.\n";
    std::cout << "1. Venetian Galley (3 sails, 2,000 lbs, 8 tons cargo) - Cost: 150 coins\n";
    std::cout << "2. Arab Dhow (2 sails, 1,500 lbs, 6 tons cargo) - Cost: 100 coins\n";
    std::cout << "3. Chinese Junk (4 sails, 3,000 lbs, 10 tons cargo) - Cost: 200 coins\n";
    std::cout << "4. Trade Cog (2 sails, 1,800 lbs, 7 tons cargo) - Cost: 120 coins\n";
}

void displayCamelMenu() {
    std::cout << "=== Camel Selection Menu ===\n";
    std::cout << "1. Bactrian Camel (2 humps, 12 years old, 700 lbs, 100 units)\n";
    std::cout << "2. Dromedary Camel (1 hump, 8 years old, 550 lbs, 75 units)\n";
    std::cout << "3. Wild Camel (2 humps, 15 years old, 880 lbs, 90 units)\n";
    std::cout << "4. Young Bactrian (2 humps, 3 years old, 440 lbs, 50 units) - TOO YOUNG\n";
    std::cout << "5. Old Dromedary (1 hump, 25 years old, 770 lbs, 85 units) - TOO OLD\n";
    std::cout << "6. Desert Camel (1 hump, 10 years old, 620 lbs, 80 units)\n";
}

void displaySuppliesMenu() {
    std::cout << "=== Journey Supplies Selection Menu ===\n";
    std::cout << "1. Wheat - ESSENTIAL\n";
    std::cout << "2. Camel Food - OPTIONAL\n";
    std::cout << "3. Bow/Knife - OPTIONAL\n";
    std::cout << "4. Money - ESSENTIAL\n";
    std::cout << "5. Wheat + Camel Food (Bundle)\n";
    std::cout << "6. Full Bundle (Wheat, Camel Food, Bow/Knife, Money)\n";
}

void displayStopMenu() {
    std::cout << "\n=== Stop Options ===\n";
    std::cout << "1. Buy Supplies\n";
    std::cout << "2. Trade Camel\n";
    std::cout << "3. Check Supply Status\n";
    std::cout << "4. Continue Journey\n";
}

string getSuppliesChoice(int choice) {
    switch (choice) {
        case 1: return "Wheat (ESSENTIAL)";
        case 2: return "Camel Food (OPTIONAL)";
        case 3: return "Bow/Knife (OPTIONAL)";
        case 4: return "Money (ESSENTIAL)";
        case 5: return "Wheat + Camel Food Bundle";
        case 6: return "Full Bundle (Wheat, Camel Food, Bow/Knife, Money)";
        default: return "Wheat (ESSENTIAL)";
    }
}

SupplyTracker createSupplyTracker(int choice) {
    switch (choice) {
        case 1: return SupplyTracker(50, 0, 0, 500);
        case 2: return SupplyTracker(0, 40, 0, 500);
        case 3: return SupplyTracker(0, 0, 15, 500);
        case 4: return SupplyTracker(0, 0, 0, 500);
        case 5: return SupplyTracker(50, 40, 0, 500);
        case 6: return SupplyTracker(50, 40, 15, 500);
        default: return SupplyTracker(50, 0, 0, 500);
    }
}

Boat createBoatChoice(int choice) {
    switch (choice) {
        case 1: return Boat("Small Fishing Boat", 1, 12, 500, 2, "Dried Fish, Fresh Water");
        case 2: return Boat("Arab Dhow", 2, 8, 700, 3, "Spices, Silk, Tea");
        case 3: return Boat("Small Trader", 2, 15, 600, 4, "Gems, Perfume, Rice");
        case 4: return Boat("Coastal Vessel", 2, 10, 650, 4, "Wine, Olive Oil, Wheat");
        case 5: return Boat("Mediterranean Cruiser", 3, 18, 750, 5, "Fine Linens, Amber");
        case 6: return Boat("Old Dhow", 2, 25, 800, 5, "Gold, Ivory, Textiles");
        default: return Boat("Small Fishing Boat", 1, 12, 500, 2, "Dried Fish, Fresh Water");
    }
}

Boat createOceanBoatChoice(int choice) {
    switch (choice) {
        case 1: return Boat("Venetian Galley", 3, 8, 2000, 8, "Supplies, Cargo");
        case 2: return Boat("Arab Dhow", 2, 6, 1500, 6, "Spices, Trade Goods");
        case 3: return Boat("Chinese Junk", 4, 5, 3000, 10, "Silk, Ceramics");
        case 4: return Boat("Trade Cog", 2, 7, 1800, 7, "Wine, Grains");
        default: return Boat("Venetian Galley", 3, 8, 2000, 8, "Supplies, Cargo");
    }
}

int getBoatCost(int choice) {
    switch (choice) {
        case 1: return 150;
        case 2: return 100;
        case 3: return 200;
        case 4: return 120;
        default: return 150;
    }
}

Camel createCamelChoice(int choice) {
    switch (choice) {
        case 1: return Camel("Bactrian", 2, 12, 700, 100, "Salt, Dates, Water Skins");
        case 2: return Camel("Dromedary", 1, 8, 550, 75, "Incense, Frankincense, Myrrh");
        case 3: return Camel("Wild Camel", 2, 15, 880, 90, "Tapestries, Wool, Furs");
        case 4: return Camel("Young Bactrian", 2, 3, 440, 50, "None");
        case 5: return Camel("Old Dromedary", 1, 25, 770, 85, "Jade, Porcelain, Spices");
        case 6: return Camel("Desert Camel", 1, 10, 620, 80, "Carpets, Leather, Herbs");
        default: return Camel("Bactrian", 2, 12, 700, 100, "Salt, Dates, Water Skins");
    }
}

void displayCamelTradingMenu() {
    std::cout << "\n=== Camel Trading ===\n";
    std::cout << "Trade your current camel for a new one!\n";
    std::cout << "1. Bactrian Camel - Trade cost: 50 coins\n";
    std::cout << "2. Dromedary Camel - Trade cost: 30 coins\n";
    std::cout << "3. Wild Camel - Trade cost: 70 coins\n";
    std::cout << "4. Desert Camel - Trade cost: 40 coins\n";
    std::cout << "5. Skip trading\n";
}

class AdvancedWeaponry {
public:
    enum WeaponType {
        SWORD,
        BOW,
        ARMOR,
        NONE
    };

    struct Weapon {
        WeaponType type;
        string name;
        int damageBonus;
        int cost;
        string description;

        Weapon() : type(NONE), name("None"), damageBonus(0), cost(0), description("") {}
        Weapon(WeaponType t, const string& n, int damage, int c, const string& desc)
            : type(t), name(n), damageBonus(damage), cost(c), description(desc) {}
    };

    static void displayAdvancedWeaponryMenu() {
        std::cout << "\n=== Advanced Weaponry - Persia ===\n";
        std::cout << "Upgrade your combat capabilities!\n";
        std::cout << "1. Steel Sword (50 coins) - Direct melee damage +20\n";
        std::cout << "   Description: A finely crafted steel sword for close combat\n";
        std::cout << "2. Composite Bow (60 coins) - Ranged damage +25\n";
        std::cout << "   Description: A powerful composite bow for distant threats\n";
        std::cout << "3. Leather Armor (55 coins) - Defense +15\n";
        std::cout << "   Description: Protective leather armor to reduce damage\n";
        std::cout << "4. Full Combat Set (130 coins) - All bonuses!\n";
        std::cout << "   Description: Sword + Bow + Armor (+20 melee, +25 ranged, +15 defense)\n";
        std::cout << "5. Skip purchases\n";
    }

    static Weapon getWeaponChoice(int choice) {
        switch (choice) {
            case 1: return Weapon(SWORD, "Steel Sword", 20, 50, 
                "A finely crafted steel sword for close combat");
            case 2: return Weapon(BOW, "Composite Bow", 25, 60, 
                "A powerful composite bow for distant threats");
            case 3: return Weapon(ARMOR, "Leather Armor", 15, 55, 
                "Protective leather armor to reduce damage");
            case 4: return Weapon(NONE, "Full Combat Set", 60, 130, 
                "Sword + Bow + Armor (all bonuses combined)");
            default: return Weapon();
        }
    }

    static int getWeaponCost(int choice) {
        switch (choice) {
            case 1: return 50;
            case 2: return 60;
            case 3: return 55;
            case 4: return 130;
            default: return 0;
        }
    }
};

// Mining Minigame Class
class MiningMinigame {
private:
    static const int GRID_WIDTH = 20;
    static const int GRID_HEIGHT = 10;
    int playerX, playerY;
    int guardX, guardY;
    int resourcesCollected;
    int totalResources;
    bool caught;
    vector<vector<char>> grid;
    
public:
    MiningMinigame() : playerX(1), playerY(1), guardX(GRID_WIDTH - 2), guardY(GRID_HEIGHT - 2), 
                       resourcesCollected(0), totalResources(5), caught(false) {
        initializeGrid();
    }
    
    void initializeGrid() {
        grid.assign(GRID_HEIGHT, vector<char>(GRID_WIDTH, '.'));
        
        // Add borders
        for (int x = 0; x < GRID_WIDTH; ++x) {
            grid[0][x] = '#';
            grid[GRID_HEIGHT - 1][x] = '#';
        }
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            grid[y][0] = '#';
            grid[y][GRID_WIDTH - 1] = '#';
        }
        
        // Place resources randomly
        srand(static_cast<unsigned>(time(nullptr)));
        int resourcesPlaced = 0;
        while (resourcesPlaced < totalResources) {
            int x = 2 + rand() % (GRID_WIDTH - 4);
            int y = 2 + rand() % (GRID_HEIGHT - 4);
            if (grid[y][x] == '.') {
                grid[y][x] = '*';
                resourcesPlaced++;
            }
        }
        
        // Set initial positions
        grid[playerY][playerX] = 'P';
        grid[guardY][guardX] = 'G';
    }
    
    void displayGrid() const {
        system("cls");
        std::cout << "\n========== ILLEGAL MINING OPERATION ==========\n";
        std::cout << "Avoid the guard (G) and collect all resources (*)\n";
        std::cout << "Controls: W=Up, S=Down, A=Left, D=Right, Q=Quit\n";
        std::cout << "Resources: " << resourcesCollected << "/" << totalResources << "\n";
        std::cout << "============================================\n\n";
        
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            for (int x = 0; x < GRID_WIDTH; ++x) {
                std::cout << grid[y][x];
            }
            std::cout << "\n";
        }
        std::cout << "\nP = You, G = Guard, * = Resources, # = Wall\n";
    }
    
    void movePlayer(char direction) {
        grid[playerY][playerX] = '.';
        
        int newX = playerX, newY = playerY;
        
        if (direction == 'w' || direction == 'W') newY--;
        else if (direction == 's' || direction == 'S') newY++;
        else if (direction == 'a' || direction == 'A') newX--;
        else if (direction == 'd' || direction == 'D') newX++;
        
        // Check boundaries and walls
        if (grid[newY][newX] != '#') {
            // Check if collecting resource
            if (grid[newY][newX] == '*') {
                resourcesCollected++;
            }
            
            playerX = newX;
            playerY = newY;
        }
        
        grid[playerY][playerX] = 'P';
    }
    
    void moveGuard() {
        grid[guardY][guardX] = '.';
        
        // Simple AI: move towards player
        int dx = (playerX > guardX) ? 1 : (playerX < guardX) ? -1 : 0;
        int dy = (playerY > guardY) ? 1 : (playerY < guardY) ? -1 : 0;
        
        int newX = guardX + dx;
        int newY = guardY + dy;
        
        // Check if can move
        if (grid[newY][newX] != '#') {
            guardX = newX;
            guardY = newY;
        }
        
        grid[guardY][guardX] = 'G';
    }
    
    bool checkCaught() const {
        return (playerX == guardX && playerY == guardY);
    }
    
    bool allResourcesCollected() const {
        return resourcesCollected >= totalResources;
    }
    
    int getResourcesCollected() const {
        return resourcesCollected;
    }
    
    void play() {
        char input;
        int moveCounter = 0;
        
        while (!caught && !allResourcesCollected()) {
            displayGrid();
            
            if (_kbhit()) {
                input = _getch();
                if (input == 'q' || input == 'Q') {
                    std::cout << "\nYou abandoned the mining operation and fled!\n";
                    resourcesCollected = 0;
                    return;
                }
                movePlayer(input);
                movePlayer(input);  // Double movement for faster speed
            }
            
            // Guard moves every player move (faster guard)
            moveGuard();
            
            // Check if caught
            if (checkCaught()) {
                caught = true;
                displayGrid();
                std::cout << "\n*** CAUGHT BY THE GUARD! ***\n";
                std::cout << "You were apprehended! You died in prison!\n";
                std::cout << "GAME OVER - MINING FAILURE\n";
                resourcesCollected = 0;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                return;
            }
            
            // Check if all resources collected
            if (allResourcesCollected()) {
                displayGrid();
                std::cout << "\n*** SUCCESS! ***\n";
                std::cout << "You collected all resources and escaped with your life!\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                return;
            }
            
            std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Faster refresh
        }
    }
};

void playMiningMinigame(SupplyTracker& tracker) {
    std::cout << "\n========== ILLEGAL MINING MINIGAME ==========\n";
    std::cout << "DANGER: If caught, you will be executed!\n";
    std::cout << "You discover an opportunity to mine precious stones!\n";
    std::cout << "If you succeed, you'll gain resources and money.\n";
    std::cout << "But if you're caught, you DIE and the journey ends!\n";
    std::cout << "\nAttempt the mining operation? (y/n): ";
    
    char response;
    std::cin >> response;
    
    if (response != 'y' && response != 'Y') {
        std::cout << "You decide it's too risky and move on.\n";
        return;
    }
    
    MiningMinigame game;
    game.play();
    
    int resourcesGained = game.getResourcesCollected();
    
    if (resourcesGained > 0) {
        int wheatGain = resourcesGained * 15;
        int moneyGain = resourcesGained * 100;
        
        tracker.addSupplies(wheatGain, 0, 0, moneyGain);
        
        std::cout << "\n*** MINING REWARDS ***\n";
        std::cout << "Gained: " << wheatGain << " wheat units\n";
        std::cout << "Gained: " << moneyGain << " coins\n";
        std::cout << "Morale boost from success!\n";
        tracker.restoreMorale(15);
    } else {
        std::cout << "\nYour mining operation failed!\n";
        std::cout << "CRITICAL: You were executed by the authorities!\n";
        std::cout << "GAME OVER - YOUR JOURNEY ENDS HERE\n";
        tracker.setWheat(-1);  // Trigger game over
    }
}

int main() {
    // Display prequel sequence
    displayPrequel();

    std::cout << "Welcome to Marco Polo's Journey to China and Back!\n\n";

    // Boat selection
    Boat selectedBoat = Boat();
    bool hasBoat = false;

    while (!hasBoat) {
        displayBoatMenu();
        std::cout << "Enter your choice: ";
        int boatChoice = getValidInputWithDemo(1, 6, nullptr, nullptr, nullptr, 1)

        std::cout << "\n";
        selectedBoat = createBoatChoice(boatChoice);
        std::cout << "Your Selected Boat:\n";
        selectedBoat.displayInfo();

        if (selectedBoat.isTooOld()) {
            std::cout << "*** WARNING: There is a high risk of failure! ***\n";
        } else {
            std::cout << "This boat is in good condition.\n";
        }

        std::cout << "\nAre you sure you want to select this boat? (y/n): ";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y') {
            hasBoat = true;
        } else {
            std::cout << "\n";
        }
    }

    // Camel selection
    Camel selectedCamel = Camel();
    bool hasCamel = false;

    while (!hasCamel) {
        displayCamelMenu();
        std::cout << "Enter your choice: ";
        int camelChoice = getValidInputWithDemo(1, 6, nullptr, nullptr, nullptr, 2);

        std::cout << "\n";
        selectedCamel = createCamelChoice(camelChoice);
        std::cout << "Your Selected Camel:\n";
        selectedCamel.displayInfo();

        if (selectedCamel.isTooYoung() || selectedCamel.isTooOld()) {
            std::cout << "*** WARNING: There is a high risk of failure! ***\n";
        } else {
            std::cout << "This camel is in good condition.\n";
        }

        std::cout << "\nDo you want to select a different camel? (y/n): ";
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            hasCamel = true;
        }
        std::cout << "\n";
    }
   
    // Supplies selection
    int suppliesChoice;
    bool hasSupplies = false;

    while (!hasSupplies) {
        displaySuppliesMenu();
        std::cout << "Enter your choice: ";
        suppliesChoice = getValidInputWithDemo(1, 6, nullptr, nullptr, nullptr, 3);

        std::cout << "\n";
        string selectedSupplies = getSuppliesChoice(suppliesChoice);
        std::cout << "Your Selected Supplies: " << selectedSupplies << "\n";

        std::cout << "\nDo you want to select different supplies? (y/n): ";
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            hasSupplies = true;
        }
        std::cout << "\n";
    }

    std::cout << "=== Journey Summary ===\n";
    std::cout << "Your Boat:\n";
    selectedBoat.displayInfo();
    std::cout << "\nYour Camel:\n";
    selectedCamel.displayInfo();
    std::cout << "\nYou are ready to begin Marco Polo's Journey!\n";

    // Initialize journey
    vector<JourneyStop> journeyStops = initializeJourneyStops();
    SupplyTracker tracker = createSupplyTracker(suppliesChoice);

    std::cout << "\n\n=== Beginning Journey ===\n";
    tracker.displaySupplyStatus();

    // Journey simulation with stops
    for (size_t i = 0; i < journeyStops.size(); ++i) {
        const JourneyStop& currentStop = journeyStops[i];
        currentStop.displayStop();

        // Check if receiving golden passport at Kublai Khan's Court
        if (i == 5 && currentStop.getName() == "Kublai Khan's Court") {
            std::cout << "\n*** KUBLAI KHAN'S GIFT ***\n";
            std::cout << "The great Khan presents you with a Golden Passport!\n";
            std::cout << "This allows you to purchase supplies at significantly discounted rates!\n";
            tracker.setGoldenPassport(true);
        }

        // Check if losing golden passport when Khan dies
        if (i == 10 && currentStop.getName() == "Return Journey - India") {
            std::cout << "\n*** SAD NEWS ***\n";
            std::cout << "You learn that Kublai Khan has passed away...\n";
            std::cout << "Your golden passport is no longer valid.\n";
            std::cout << "Prices return to normal.\n";
            tracker.setGoldenPassport(false);
        }

        // Check if this is an ocean voyage leg
        if ((i == 1 && currentStop.getName() == "Mediterranean Sea Voyage")) {
            
            std::cout << "\n*** OCEAN VOYAGE AHEAD ***\n";
            std::cout << "You will use your selected boat: " << selectedBoat.getType() << "\n";
            std::cout << "Preparing for sea voyage...\n";
            
        } else if (i == 8 && currentStop.getName() == "Indian Ocean Voyage") {
            
            std::cout << "\n*** OCEAN VOYAGE AHEAD ***\n";
            std::cout << "Your current boat is not suited for the Indian Ocean.\n";
            std::cout << "You must purchase a proper vessel for this dangerous voyage.\n";
            
            bool boatPurchased = false;
            while (!boatPurchased) {
                displayBoatPurchaseMenu();
                std::cout << "Enter your choice (1-4): ";
                int boatChoice = getValidInputWithDemo(1, 4, &tracker, &selectedCamel, &selectedBoat, 5);
                
                Boat oceanBoat = createOceanBoatChoice(boatChoice);
                int boatCost = getBoatCost(boatChoice);
                
                std::cout << "\n=== Ocean Boat Selected ===\n";
                oceanBoat.displayInfo();
                std::cout << "Cost: " << boatCost << " coins\n";
                
                if (tracker.getMoney() < boatCost) {
                    std::cout << "\n*** INSUFFICIENT FUNDS ***\n";
                    std::cout << "You have " << tracker.getMoney() << " coins but need " << boatCost << " coins.\n";
                    std::cout << "You cannot proceed without a boat!\n";
                    std::cout << "Game Over - Insufficient funds for ocean voyage.\n";
                    std::cout << "\nPress Enter to exit...";
                    std::cin.ignore();
                    std::cin.get();
                    return 0;
                }
                
                std::cout << "\nConfirm purchase? (y/n): ";
                char response;
                std::cin >> response;
                if (response == 'y' || response == 'Y') {
                    tracker.addSupplies(0, 0, 0, -boatCost);
                    std::cout << "\n*** Boat Purchased! ***\n";
                    std::cout << "You board the " << oceanBoat.getType() << ".\n";
                    std::cout << "Money remaining: " << tracker.getMoney() << " coins\n";
                    selectedBoat = oceanBoat;
                    boatPurchased = true;
                } else {
                    std::cout << "Please select a different boat.\n\n";
                }
            }
        }

        bool atStop = true;
        while (atStop) {
            displayStopMenu();
            
            // Show exhaustion warning
            if (tracker.isExhausted()) {
                std::cout << "\n*** WARNING: Your morale is CRITICALLY LOW! You are EXHAUSTED! ***\n";
                std::cout << "You MUST rest immediately or face serious consequences!\n";
            }
            
            std::cout << "Enter your choice: ";
            int action = getValidInputWithDemo(1, 4, &tracker, &selectedCamel, &selectedBoat, 4);

            switch (action) {
                case 1: {
                    int wheatPrice = currentStop.getWheatCost();
                    int camelFoodPrice = currentStop.getCamelFoodCost();
                    int weaponryPrice = currentStop.getWeaponryCost();
                    int patchKitPrice = 20;

                    // Apply discount if has golden passport
                    if (tracker.getGoldenPassport()) {
                        wheatPrice = (wheatPrice * 3) / 4;
                        camelFoodPrice = (camelFoodPrice * 3) / 4;
                        weaponryPrice = (weaponryPrice * 3) / 4;
                        patchKitPrice = 15;
                        std::cout << "\n*** GOLDEN PASSPORT DISCOUNT APPLIED! ***\n";
                    }

                    std::cout << "\nSupply options at this stop:\n";
                    std::cout << "1. Buy " << wheatPrice << " Wheat\n";
                    std::cout << "2. Buy " << camelFoodPrice << " Camel Food\n";
                    std::cout << "3. Buy " << weaponryPrice << " Weaponry\n";
                    
                    // Advanced weaponry in Persia
                    if (currentStop.getName() == "Persia") {
                        std::cout << "4. Browse Advanced Weaponry (swords, bows, armor)\n";
                        std::cout << "5. Buy Patch Kit (" << patchKitPrice << " coins) - Repairs boat damage\n";
                        std::cout << "6. Skip purchases\n";
                    } else {
                        std::cout << "4. Buy Patch Kit (" << patchKitPrice << " coins) - Repairs boat damage\n";
                        std::cout << "5. Skip purchases\n";
                    }
                    
                    std::cout << "Enter your choice: ";
                    int buyChoice;
                    if (currentStop.getName() == "Persia") {
                        buyChoice = getValidInputWithDemo(1, 6, &tracker, &selectedCamel, &selectedBoat, 3);
                    } else {
                        buyChoice = getValidInputWithDemo(1, 5, &tracker, &selectedCamel, &selectedBoat, 3);
                    }

                    if (buyChoice == 1) {
                        tracker.addSupplies(wheatPrice, 0, 0, 0);
                        std::cout << "Purchased Wheat!\n";
                        tracker.decreaseMorale(2);
                    } else if (buyChoice == 2) {
                        tracker.addSupplies(0, camelFoodPrice, 0, 0);
                        std::cout << "Purchased Camel Food!\n";
                        tracker.decreaseMorale(2);
                    } else if (buyChoice == 3) {
                        tracker.addSupplies(0, 0, weaponryPrice, 0);
                        std::cout << "Purchased Weaponry!\n";
                        tracker.decreaseMorale(2);
                    } else if (currentStop.getName() == "Persia" && buyChoice == 4) {
                        AdvancedWeaponry::displayAdvancedWeaponryMenu();
                        std::cout << "Enter your choice: ";
                        int weaponChoice = getValidInputWithDemo(1, 5, &tracker, &selectedCamel, &selectedBoat, 3);

                        if (weaponChoice != 5) {
                            AdvancedWeaponry::Weapon selectedWeapon = AdvancedWeaponry::getWeaponChoice(weaponChoice);
                            int weaponCost = AdvancedWeaponry::getWeaponCost(weaponChoice);

                            if (tracker.getGoldenPassport()) {
                                weaponCost = (weaponCost * 3) / 4;
                                std::cout << "*** GOLDEN PASSPORT DISCOUNT APPLIED! ***\n";
                            }

                            if (tracker.getMoney() >= weaponCost) {
                                tracker.addSupplies(0, 0, selectedWeapon.damageBonus, -weaponCost);
                                std::cout << "\n*** PURCHASED: " << selectedWeapon.name << " ***\n";
                                std::cout << "Description: " << selectedWeapon.description << "\n";
                                if (weaponChoice == 4) {
                                    std::cout << "Combat Bonuses: +20 Melee, +25 Ranged, +15 Defense\n";
                                } else {
                                    std::cout << "Bonus: +" << selectedWeapon.damageBonus << " damage\n";
                                }
                                std::cout << "Cost: " << weaponCost << " coins\n";
                                std::cout << "Money remaining: " << tracker.getMoney() << " coins\n";
                                tracker.decreaseMorale(3);
                            } else {
                                std::cout << "Insufficient funds! You need " << weaponCost << " coins.\n";
                            }
                        }
                    } else if ((currentStop.getName() == "Persia" && buyChoice == 5) || (currentStop.getName() != "Persia" && buyChoice == 4)) {
                        if (tracker.getMoney() >= patchKitPrice) {
                            tracker.addSupplies(0, 0, 0, -patchKitPrice, 1);
                            std::cout << "Purchased Patch Kit!\n";
                            tracker.decreaseMorale(2);
                        } else {
                            std::cout << "Insufficient funds! You need " << patchKitPrice << " coins.\n";
                        }
                    }
                    break;
                }
                case 2: {
                    displayCamelTradingMenu();
                    std::cout << "Enter your choice: ";
                    int tradeChoice = getValidInputWithDemo(1, 5, &tracker, &selectedCamel, &selectedBoat, 6);

                    if (tradeChoice != 5) {
                        int tradeCost;
                        Camel newCamel = createCamelChoice(tradeChoice == 1 ? 1 : tradeChoice == 2 ? 2 : tradeChoice == 3 ? 3 : 6);
                        
                        switch (tradeChoice) {
                            case 1: tradeCost = 50; break;
                            case 2: tradeCost = 30; break;
                            case 3: tradeCost = 70; break;
                            case 4: tradeCost = 40; break;
                            default: tradeCost = 50; break;
                        }

                        if (tracker.getMoney() >= tradeCost) {
                            tracker.addSupplies(0, 0, 0, -tradeCost);
                            selectedCamel = newCamel;
                            std::cout << "\n*** Camel Traded! ***\n";
                            std::cout << "Your new camel:\n";
                            selectedCamel.displayInfo();
                            std::cout << "Money remaining: " << tracker.getMoney() << " coins\n";
                            tracker.decreaseMorale(5);
                        } else {
                            std::cout << "Insufficient funds! You need " << tradeCost << " coins.\n";
                        }
                    }
                    break;
                }
                case 3:
                    tracker.displaySupplyStatus();
                    if (tracker.isCriticallyLow()) {
                        std::cout << "\n*** WARNING: Your supplies are critically low! ***\n";
                    }
                    break;
                case 4: {
                    // MINING MINIGAME OPPORTUNITY AT PERSIA
                    if (currentStop.getName() == "Persia") {
                        std::cout << "\nBefore you leave Persia, you notice some illegal mining sites...\n";
                        playMiningMinigame(tracker);
                        tracker.displaySupplyStatus();
                    }
                    
                    // Rest option
                    if (tracker.getMorale() < 100) {
                        std::cout << "\nYou take time to rest and recover...\n";
                        tracker.restoreMorale(40);
                        std::cout << "You feel refreshed! Morale restored to " << tracker.getMorale() << "/100\n";
                        tracker.decreaseMorale(8);
                        atStop = false;
                    } else {
                        std::cout << "\nYou are already well-rested. Continue your journey.\n";
                        atStop = false;
                    }
                    break;
                }
            }
        }

        if (i < journeyStops.size() - 1) {
            std::cout << "\nTraveling to next destination...\n";
            
            // Store current supplies before consumption
            int wheatBefore = tracker.getWheat();
            int camelFoodBefore = tracker.getCamelFood();
            int moneyBefore = tracker.getMoney();
            
            // Consume supplies during travel
            int wheatUsed = 5 + (i % 3);
            int camelFoodUsed = 3 + (i % 2);
            
            tracker.addSupplies(-wheatUsed, -camelFoodUsed, 0, 0);
            
            // Morale decreases with travel (exhaustion from journey)
            int moraleLoss = 10 + (i / 2);
            tracker.decreaseMorale(moraleLoss);
            
            std::cout << "\n========== SUPPLY CONSUMPTION REPORT ==========\n";
            std::cout << "--- BEFORE TRAVEL ---\n";
            std::cout << "  Wheat: " << wheatBefore << " units\n";
            std::cout << "  Camel Food: " << camelFoodBefore << " units\n";
            std::cout << "  Money: " << moneyBefore << " coins\n";
            
            std::cout << "\n--- CONSUMED DURING TRAVEL ---\n";
            std::cout << "  Wheat consumed: " << wheatUsed << " units\n";
            std::cout << "  Camel Food consumed: " << camelFoodUsed << " units\n";
            std::cout << "  Morale lost: " << moraleLoss << " points (Travel exhaustion)\n";
            
            std::cout << "\n--- AFTER TRAVEL ---\n";
            std::cout << "  Wheat: " << tracker.getWheat() << " units";
            if (tracker.getWheat() < 0) std::cout << " (DEFICIT!)";
            std::cout << "\n";
            std::cout << "  Camel Food: " << tracker.getCamelFood() << " units";
            if (tracker.getCamelFood() < 0) std::cout << " (DEFICIT!)";
            std::cout << "\n";
            std::cout << "  Money: " << tracker.getMoney() << " coins\n";
            std::cout << "  Morale: " << tracker.getMorale() << "/100 (" << tracker.getMoraleStatus() << ")\n";
            std::cout << "=============================================\n";
            
            // Check if supplies are depleted
            if (tracker.getWheat() < 0 || tracker.getCamelFood() < 0) {
                std::cout << "\n*** CRITICAL: You have run out of supplies! ***\n";
                std::cout << "Your journey has ended prematurely.\n";
                std::cout << "GAME OVER\n";
                break;
            }

            // Check for exhaustion
            if (tracker.isExhausted()) {
                std::cout << "\n*** CRITICAL: You are completely exhausted! ***\n";
                std::cout << "Without rest, you cannot continue...\n";
                std::cout << "Your journey has ended.\n";
                std::cout << "GAME OVER\n";
                break;
            }
            
            tracker.displaySupplyStatus();
            
            if (tracker.isCriticallyLow()) {
                std::cout << "\n*** WARNING: Supplies are running low! Stock up at the next stop! ***\n";
            }

            if (tracker.getMorale() < 30) {
                std::cout << "\n*** WARNING: Your morale is dangerously low! Consider resting at the next stop! ***\n";
            }

            // Generate random event during travel
            bool journeyEnded = false;
            RandomEvent::EventType event = RandomEvent::generateRandomEvent(static_cast<int>(i));
            RandomEvent::handleEvent(event, tracker, selectedCamel, selectedBoat, journeyEnded);
            
            if (journeyEnded) {
                break;
            }
            
            tracker.displaySupplyStatus();
        }
    }

    std::cout << "\n\n=== Journey Complete ===\n";
    std::cout << "You have successfully completed Marco Polo's journey!\n";
    std::cout << "Final Supply Status:\n";
    tracker.displaySupplyStatus();

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
