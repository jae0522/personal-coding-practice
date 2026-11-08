
#include <iostream>
#include <climits>
using namespace std;

//Defining Member Functions out of class. Lesson 8.8.3A
//Energy Transfer System
// Implement your Counter class here

/*
 * LESSON 8.3A - BLOCK 4
 * ADVANCED EXERCISE: ENERGY TRANSFER
 *
 * TODO: Implement the EnergyCell class.
 *
 * REQUIREMENTS:
 *
 * 1. Each object stores a private integer representing
 *    its energy, initially 0.
 * 
 * 2. Energy must remain between 0 and 200, inclusive.
 *
 * 3. Support adding a specified amount of energy.
 *
 * 4. Support transferring energy from one cell
 *    to another.
 *
 *    Successful transfers must update both original
 *    objects and preserve their combined energy.
 *
 * 5. Reject operations when:
 *    - The amount is zero or negative.
 *    - There is insufficient energy to transfer.
 *    - The resulting energy would exceed 200.
 *    - A cell attempts to transfer to itself.
 *
 * 6. Rejected operations must leave both objects
 *    unchanged and increase a shared rejection
 *    counter exactly once.
 *
 * 7. Provide a way to retrieve each cell's energy
 *    and the total number of rejected operations.
 *
 * DESIGN CONSTRAINTS:
 *
 * - All data members must be private.
 * - Declare methods inside the class.
 * - Define ALL methods outside the class using ::.
 * - Use const correctness where appropriate.
 * - Use appropriate parameter passing.
 * - Avoid unnecessary copies and integer overflow.
 * - No custom constructors or global variables.
 * - No dynamic memory or STL containers.
 *
 * Choose your own method names and signatures.
 */

class EnergyCell {
private:
    // TODO: Declare private data.
    int energy = 0;
    inline static int rejection_count = 0;

public:
    // TODO: Declare member functions only.
    void add (int amount);
    
    void transfer (EnergyCell& cell, int amount);

    int getEnergy() const;

    static int getRejectionCount();
};


// TODO: Define all member functions here.
void EnergyCell::add (int amount) {
        if ((amount <= 0) || (amount > 200 - energy)) {
            ++rejection_count;
            return;
        }
        energy += amount;
    }
    
void EnergyCell:: transfer (EnergyCell& cell, int amount) {
    if ((amount <= 0) || (amount > (this -> energy)) || (amount > 200 - cell.energy) || (this == &cell)) {
        ++rejection_count;     
        return;
    }

    
    cell.energy += amount;
    this -> energy -= amount;
    }

int EnergyCell::getEnergy() const {
    return this -> energy;
}

int EnergyCell::getRejectionCount() {
    return rejection_count;
}

int main() {
    /**
     * TODO: Create two EnergyCell objects, A and B.

     * TEST SCENARIO:
     *
     * 1. Add 150 to A.           Accepted
     * 2. Add 80 to B.            Accepted
     * 3. Transfer 50 A -> B.     Accepted
     * 4. Transfer 75 B -> A.     Accepted
     * 5. Add 30 to A.           Rejected
     * 6. Transfer 80 B -> A.     Rejected
     * 7. Transfer 1 A -> A.      Rejected
     * 8. Add INT_MAX to B.      Rejected
     *
     * TODO: Print both final energy values and
     * the total number of rejected operations.
     *
     * EXPECTED OUTPUT:
     *
     * Cell A: 175
     * Cell B: 55
     * Rejected operations: 4
     */

    EnergyCell A;
    EnergyCell B;
    
    A.add (150);
    B.add (80);

    A.transfer(B, 50);
    B.transfer(A, 75);

    A.add (30);
    B.transfer(A, 80);
    A.transfer(A, 1);
    B.add(INT_MAX);

    cout << "Cell A: " << A.getEnergy() << '\n';
    cout << "Cell B: " << B.getEnergy() << '\n';
    cout << "Rejected operations: " << EnergyCell::getRejectionCount()<< '\n';


    
     return 0;
}
