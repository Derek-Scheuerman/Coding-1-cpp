#include <cstdlib> // Includes the necessary library for random number generation
#include <ctime> // Includes the necessary library to seed the random number generator
#include <iostream> // Includes classes like cin for input and cout for output.
#include <string> // This library offers a set of classes and functions to work with strings
#include <vector> // Vectors offer member functions like push_back, pop_back
using namespace std;

enum class WeaponType {
  Sword,
  FireBreath /* Enum Class: Defines a type with a fixed set of named constants.
                Scoped Enumeration: Enumerators are scoped within the enum
                class. Type Safety: Enum classes prevent implicit conversions to
                and from integers. Constants: Sword and FireBreath are the two
                constants defined in the WeaponType enum class.

                The code snippet declares an enum class WeaponType with two
                constants: Sword and FireBreath. Each constant represents a
                specific type of weapon. The enum class keyword ensures that the
                constants are scoped within the WeaponType enum class.*/
};

enum class EnemyType { Dragon };

class Weapon {
private:
  WeaponType type;
  int damage;
  string name;

public:
  Weapon(WeaponType type, int damage) : type(type), damage(damage) {
    setName(type);
  }
  Weapon(WeaponType type, int damage, string name)
      : type(type), damage(damage), name(name) {}
  /* Constructor: A constructor is a member function with the same name as the
     class. It                                          is automatically called
     when an object is created.

     Initialization List: The part after the colon : in the constructor is
     called the                                             initialization list.
     It initializes the member variables of the class.

     Parameters: Constructors can take parameters to initialize the object with
     specific                                          values.*/

  int getDamage() const {
    return damage; /* int getDamage() const: This line declares a member
                      function named getDamage that returns an integer value.

                      The const keyword at the end of the function signature
                      indicates that this member function does not modify the
                      object it is called on.

                      return damage;: This line returns the damage attribute of
                      the Weapon object when the getDamage function is called.*/
  }

  WeaponType getType() const {
    return type; /* Member Function: getType() is a member function that belongs
                    to a class and can access the class's data members from
                    Private: WeaponType type; allowing me to use it publicly.

                    Constant Member Function: The const keyword at the end of
                    the function declaration indicates that this function does
                    not modify the object's state.*/
  }

  string getName() const { return name; }

  void setDamage(int newDamage) {
    damage =
        newDamage; /* This code demonstrates a setter function setDamage that
                      takes an integer parameter newDamage and assigns its value
                      to a private member variable damage. By using setter
                      functions like setDamage, I can enforce data encapsulation
                      by providing a controlled mechanism to modify the internal
                      state of an object.*/
  }

  void setType(WeaponType newType) { type = newType; }

  void setName(string name) { this->name = name; }

  void setName(WeaponType type_) {
    /* Enum (WeaponType): Enumerations in C++ are user-defined data types that
     consist of integral constants. In this case, WeaponType is an enum that
     defines different types of weapons.

     Switch Statement: The switch statement allows a variable to be tested for
     equality against a list of values. Each value is called a case, and the
     switch statement evaluates the type parameter against these cases.*/
    switch (type) {
    case WeaponType::Sword:
      name = "Sword";
      break;
    case WeaponType::FireBreath:
      name = "Fire Breath";
      break;
    default:
      name = ""; /* The getWeaponName function takes a WeaponType enum as an
                  argument and sets the name of the
                  weapon. It uses a switch statement to determine the weapon
                  name based on the provided WeaponType.*/
      break;
    }
  }
};

class Enemy {
private:
  string name;
  int health;
  const int maxHealth = 100;
  Weapon weapon;
  int numHeals; /* The Enemy class consists of private member variables such as:
                   name: a string representing the enemy's name.
                   health: an integer indicating the current health of the
                   enemy. maxHealth: a constant integer set to 100, denoting the
                   maximum health the enemy can have. weapon: an object of the
                   Weapon class representing the enemy's weapon. numHeals: an
                   integer storing the number of healing items the enemy has.*/
public:
  Enemy(EnemyType type, string name, int health, Weapon weapon)
      : name(name), health(health), weapon(weapon), numHeals(0) {}

  /* Enemy(EnemyType type, string name, int health, Weapon weapon): This part
     declares                                            the constructor for the
     Enemy class. It takes parameters type of type EnemyType, name of type
     string, health of type int, and weapon of type Weapon. This constructor is
     used to create an Enemy object with the specified characteristics such as
     type, name, initial health, and weapon.

     : name(name), health(health), weapon(weapon), numHeals(0) {}: This section
     is the                                            initialization list of
     the constructor. It initializes the member variables name, health, weapon
     with the values passed as arguments (name, health, weapon) and initializes
     numHeals to 0.*/

  int getHealth() const { return health; }

  Weapon getWeapon() const {
    return weapon; /* This member function getWeapon allows an object of the
                      Weapon class to retrieve its own Weapon attribute. The
                      function is declared as const, ensuring that it does not
                      modify the object it is called on.*/
  }

  int getWeaponDamage() const { return weapon.getDamage(); }

  WeaponType getWeaponType() const { return weapon.getType(); }

  string getWeaponName() const { return weapon.getName(); }

  void setWeapon(Weapon newWeapon) {
    weapon = newWeapon; /* void setWeapon(Weapon newWeapon) {: This line
                        declares a member function named setWeapon. The purpose
                        of this function is to set a new weapon for the enemy.

                        weapon = newWeapon;: This line replaces the current
                        weapon of the enemy with the newly provided weapon.*/
  }

  void takeDamage(int damage) {
    health -= damage;
    /* health -= damage;: This line decreases the health of the enemy by the
     * amount of damage received. It then subtracts the damage value from the
     * health variable of the enemy. This operation reduces the enemy's health
     * based on the damage inflicted.*/
    if (health < 20) {
      heal(); // Heal 20% of health when falls below 20
    }
  }

  bool performCriticalHit() const {
    return rand() % 10 ==
           0; /* rand() Function: The rand() function is used to generate
                 pseudo-random numbers in C++. It returns a random integer
                 between 0 and RAND_MAX.

                 Modulus Operator (%): The modulus operator % calculates the
                 remainder of a division operation. In this context, it helps
                 determine the probability of a critical hit occurring.*/

    /* The performCriticalHit() function checks if the result of rand() % 10
     * equals 0. If                                           the condition is
     * met, the function returns true, indicating a critical hit. Otherwise, it
     * returns false.*/
  }

  void heal() {
    if (numHeals < 3) {
      int healAmount = static_cast<int>(0.2 * maxHealth);
      health += healAmount;
      cout << name << " heals for " << healAmount
           << " health using dragon's light.\n";
      numHeals++; /* Conditional Check: The code checks if the number of heals
                     (numHeals) is less than 3 before proceeding with the
                     healing process.

                     Healing Calculation: It calculates the amount to heal
                     (healAmount) as 20% of the maximum health of the character.

                     Healing Process: The calculated heal amount is then added
                     to the character's current health (health).

                     Output: The function outputs a message indicating the
                     character's name, the amount healed, and the source of
                     healing.*/

      /* Increment Operator (++): The ++ operator is used to increment the value
         of a                                                 variable by 1.

         Post-increment vs. Pre-increment: In the context of numHeals++;, the
         post-increment                                          operator is
         used, which means the current value of numHeals is used in the
         expression, and then numHeals is incremented by 1.

         Variable Update: After executing numHeals++;, the value of numHeals
         will be                                                  increased
         by 1.*/
    }
  }
};

class Player {
private:
  int health;
  int numPotionsRemaining;

public:
  Player(int health) : health(health), numPotionsRemaining(4) {}

  int getHealth() const { return health; }

  void takeDamage(int damage) { health -= damage; }

  void useWeapon(Weapon weapon, Enemy &enemy) {
    cout << "Player attacks with " << weapon.getName() << " for "
         << weapon.getDamage() << " damage.\n";
    enemy.takeDamage(weapon.getDamage());
    /* The function useWeapon takes a Weapon object weapon and an Enemy object
       enemy as                                             parameters. It uses
       cout to display a message indicating the attack. The message includes the
       weapon's name obtained from getWeaponName(weapon.getType()) and the
       damage inflicted retrieved from weapon.getDamage().

       The function calls enemy.takeDamage(weapon.getDamage()) to reduce the
       enemy's                                                health by the
       damage amount.*/
  }

  void useHealthPotion(int healthRestored) {
    if (numPotionsRemaining > 0) {
      health += healthRestored;

      cout << "Player uses a health potion and restores " << healthRestored
           << " health.\n";
      numPotionsRemaining--; /* The function useHealthPotion takes an integer
                         healthRestored as a parameter. It checks if the
                         player has more than 0 health potions
                         (numPotionsRemaining > 0). If the condition is met,
                         the player's health is increased by the
                         healthRestored amount.

                         A message is displayed using cout indicating the
                         health restored by the potion. The numHealthPotions
                         counter is then incremented to keep track of the
                         number of potions used.*/
    }
  }

  void checkHealthAndHeal() {
    if (health < 30) {
      useHealthPotion(50); // Restore health by 50 when it falls below 30
    }
  }
};

int main() {
  srand(time(0)); // Seed the random number generator

  Weapon sword(WeaponType::Sword, 10);
  Enemy dragon(EnemyType::Dragon, "Dragon", 50, sword);
  Player player(100); // Initializing Player object with 100 health

  dragon.setWeapon(Weapon(WeaponType::FireBreath, 20));
  while (player.getHealth() > 0 && dragon.getHealth() > 0) {
    player.useWeapon(sword, dragon);
    player.checkHealthAndHeal(); /* This code contains a while loop that
                                    continues as long as both the player and the
                                    dragon have health points greater than zero.
                                    Within the loop, the player uses a weapon on
                                    the dragon and then checks their health to
                                    heal if needed.*/

    if (dragon.getHealth() > 0) {

      /* Object Health Check: The code snippet checks the health of the dragon
         object. Weapon Assignment: If the dragon's health is above 0, a
         FireBreath weapon with a power of 20 is assigned to the dragon.*/
      if (dragon.performCriticalHit()) {
        int criticalDamage = dragon.getWeaponDamage() * 2;
        player.takeDamage(
            criticalDamage); /* The provided code snippet checks if the dragon
                                can perform a critical hit. If the condition is
                                met, the dragon's weapon damage is doubled, and
                                the player takes the increased damage.*/

        cout << "Dragon delivers a critical hit for " << criticalDamage
             << " damage!\n";
      } else {

        player.takeDamage(dragon.getWeaponDamage());
        cout
            << "Dragon attacks with " << dragon.getWeaponName() << " for "
            << dragon.getWeaponDamage()
            << " damage.\n"; /* The code snippet consists of a single line where
                                the player takes damage from the dragon's
                                weapon, followed by an output statement
                                displaying the details of the dragon's attack.*/
      }
    }

    cout << "Player health: " << player.getHealth()
         << ", Dragon health: " << dragon.getHealth() << "\n";
  }

  if (player.getHealth() <= 0) {
    cout << "Player has been defeated by the Dragon!\n";
  } else {
    cout << "Dragon has been vanquished by the Player!\n";
  }

  return 0;
}