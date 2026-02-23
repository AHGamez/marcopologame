#include <iostream>
#include <string>
#include <vector>
#include <limits>
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
    bool hasGoldenPassport;

public:
    SupplyTracker(int w = 0, int cf = 0, int weap = 0, int m = 0, int pk = 0, bool passport = false)
        : wheat(w), camelFood(cf), weaponry(weap), money(m), patchKit(pk), hasGoldenPassport(passport) {}

    int getWheat() const { return wheat; }
    int getCamelFood() const { return camelFood; }
    int getWeaponry() const { return weaponry; }
    int getMoney() const { return money; }
    int getPatchKit() const { return patchKit; }
    bool getGoldenPassport() const { return hasGoldenPassport; }

    void setGoldenPassport(bool value) { hasGoldenPassport = value; }
    void setWheat(int w) { wheat = w; }
    void setCamelFood(int cf) { camelFood = cf; }
    void setWeaponry(int w) { weaponry = w; }
    void setMoney(int m) { money = m; }
    void setPatchKit(int pk) { patchKit = pk; }

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
        std::cout << "Wheat: " << wheat << " units\n";
        std::cout << "Camel Food: " << camelFood << " units\n";
        std::cout << "Weaponry: " << weaponry << " units\n";
        std::cout << "Patch Kit: " << patchKit << " unit(s)\n";
        std::cout << "Money: " << money << " coins\n";
        if (hasGoldenPassport) {
            std::cout << "*** GOLDEN PASSPORT: You possess the Khan's golden passport! (Discount rates active) ***\n";
        }
    }

    bool isCriticallyLow() const {
        return (wheat < 5) || (money < 20);
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
        std::cout << "3. View Current Supplies\n";
        std::cout << "4. Exit Debug Menu\n";
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
        std::cout << "6. Set All Supplies (Full Bundle)\n";
        std::cout << "7. Back to Debug Menu\n";
        std::cout << "Enter your choice: ";
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
                            std::cout << "Current Wheat: " << tracker.getWheat() << "\n";
                            std::cout << "Enter new value: ";
                            int value;
                            std::cin >> value;
                            tracker.setWheat(value);
                            std::cout << "Wheat set to " << value << "\n";
                            break;
                        }
                        case 2: {
                            std::cout << "Current Camel Food: " << tracker.getCamelFood() << "\n";
                            std::cout << "Enter new value: ";
                            int value;
                            std::cin >> value;
                            tracker.setCamelFood(value);
                            std::cout << "Camel Food set to " << value << "\n";
                            break;
                        }
                        case 3: {
                            std::cout << "Current Weaponry: " << tracker.getWeaponry() << "\n";
                            std::cout << "Enter new value: ";
                            int value;
                            std::cin >> value;
                            tracker.setWeaponry(value);
                            std::cout << "Weaponry set to " << value << "\n";
                            break;
                        }
                        case 4: {
                            std::cout << "Current Money: " << tracker.getMoney() << "\n";
                            std::cout << "Enter new value: ";
                            int value;
                            std::cin >> value;
                            tracker.setMoney(value);
                            std::cout << "Money set to " << value << "\n";
                            break;
                        }
                        case 5: {
                            std::cout << "Current Patch Kit: " << tracker.getPatchKit() << "\n";
                            std::cout << "Enter new value: ";
                            int value;
                            std::cin >> value;
                            tracker.setPatchKit(value);
                            std::cout << "Patch Kit set to " << value << "\n";
                            break;
                        }
                        case 6: {
                            std::cout << "Setting Full Bundle supplies...\n";
                            tracker.setWheat(100);
                            tracker.setCamelFood(100);
                            tracker.setWeaponry(50);
                            tracker.setMoney(1000);
                            tracker.setPatchKit(5);
                            std::cout << "All supplies set to full bundle!\n";
                            tracker.displaySupplyStatus();
                            break;
                        }
                        case 7:
                            inEditMenu = false;
                            break;
                    }
                }
            }
            else if (choice == "3") {
                tracker.displaySupplyStatus();
            }
            else if (choice == "4") {
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
        catch (...) {
            std::cout << "Invalid input! Please enter a number between " << minValue << " and " << maxValue << ": ";
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

int main() {
    std::cout << "Welcome to My Game - Marco Polo's Journey to China and Back!\n\n";

    // Boat selection
    Boat selectedBoat = Boat();
    bool hasBoat = false;

    while (!hasBoat) {
        displayBoatMenu();
        std::cout << "Enter your choice: ";
        int boatChoice = getValidInputWithDemo(1, 6, nullptr, nullptr, nullptr, 1);

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
                        wheatPrice = (wheatPrice * 3) / 4;  // 25% discount
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
                        std::cout << "4. Buy Advanced Weaponry (50 coins) - Stronger defense!\n";
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
                    } else if (buyChoice == 2) {
                        tracker.addSupplies(0, camelFoodPrice, 0, 0);
                        std::cout << "Purchased Camel Food!\n";
                    } else if (buyChoice == 3) {
                        tracker.addSupplies(0, 0, weaponryPrice, 0);
                        std::cout << "Purchased Weaponry!\n";
                    } else if (currentStop.getName() == "Persia" && buyChoice == 4) {
                        if (tracker.getMoney() >= 50) {
                            tracker.addSupplies(0, 0, 30, -50);
                            std::cout << "Purchased Advanced Weaponry! (+30 weaponry damage)\n";
                        } else {
                            std::cout << "Insufficient funds! You need 50 coins.\n";
                        }
                    } else if ((currentStop.getName() == "Persia" && buyChoice == 5) || (currentStop.getName() != "Persia" && buyChoice == 4)) {
                        if (tracker.getMoney() >= patchKitPrice) {
                            tracker.addSupplies(0, 0, 0, -patchKitPrice, 1);
                            std::cout << "Purchased Patch Kit!\n";
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
                case 4:
                    atStop = false;
                    break;
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
            
            std::cout << "\n========== SUPPLY CONSUMPTION REPORT ==========\n";
            std::cout << "--- BEFORE TRAVEL ---\n";
            std::cout << "  Wheat: " << wheatBefore << " units\n";
            std::cout << "  Camel Food: " << camelFoodBefore << " units\n";
            std::cout << "  Money: " << moneyBefore << " coins\n";
            
            std::cout << "\n--- CONSUMED DURING TRAVEL ---\n";
            std::cout << "  Wheat consumed: " << wheatUsed << " units\n";
            std::cout << "  Camel Food consumed: " << camelFoodUsed << " units\n";
            
            std::cout << "\n--- AFTER TRAVEL ---\n";
            std::cout << "  Wheat: " << tracker.getWheat() << " units";
            if (tracker.getWheat() < 0) std::cout << " (DEFICIT!)";
            std::cout << "\n";
            std::cout << "  Camel Food: " << tracker.getCamelFood() << " units";
            if (tracker.getCamelFood() < 0) std::cout << " (DEFICIT!)";
            std::cout << "\n";
            std::cout << "  Money: " << tracker.getMoney() << " coins\n";
            std::cout << "=============================================\n";
            
            // Check if supplies are depleted
            if (tracker.getWheat() < 0 || tracker.getCamelFood() < 0) {
                std::cout << "\n*** CRITICAL: You have run out of supplies! ***\n";
                std::cout << "Your journey has ended prematurely.\n";
                std::cout << "GAME OVER\n";
                break;
            }
            
            tracker.displaySupplyStatus();
            
            if (tracker.isCriticallyLow()) {
                std::cout << "\n*** WARNING: Supplies are running low! Stock up at the next stop! ***\n";
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