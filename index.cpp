#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

int currUser = -1;

inline float round_off_2places (int total_stars, int total_users) {
    float rating = total_stars/float(total_users);
    return rating = round(rating * 100.0) / 100.0;
}

class food_item {
    string name;
    int price;
    int total_stars;
    int total_users;
    float rating;

public:
    food_item () {}
    food_item (string name, int price, int total_stars, int total_users) {
        this->name = name;
        this->price = price;
        this->total_stars = total_stars;
        this->total_users = total_users;

        rating = -1;
        if (total_users > 0) {
            rating = round_off_2places (total_stars, total_users);
        }
    }

    void print_details() {
        cout << name << ", Rs. " << price << ". Rated " << rating << " (" << total_users << ")" << endl;
    }

    int get_price () const {
        return price;
    }

    string get_name () const {
        return name;
    }
};

class restaurants {
    string name;
    float distance;
    int time;
    int total_stars;
    int total_users;
    float rating;
    bool pure_veg;
    string cuisine;

    public:
    vector<food_item> food_array;
    restaurants (string name, float distance, int time, int total_stars, int total_users, bool pure_veg, string cuisine, vector<food_item>& food_array) {
        this->name = name;
        this->distance = distance;
        this->time = time;
        this->total_stars = total_stars;
        this->total_users = total_users;
        this->cuisine = cuisine;
        this->food_array = food_array;

        rating = -1;
        
        if (total_users > 0) {
            rating = -1;
            if (total_users > 0) {
                rating = round_off_2places (total_stars, total_users);
            }
        }

        this->pure_veg = pure_veg;
    }

    void print_details () {
        cout << "Welcome to " << name << '!' << endl;
        cout << "Rating: " << rating << " stars" << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Expected Delivery Time: " << time << " min" << endl;
        cout << "The restaurant is ";
        if (!pure_veg) {
            cout << "not ";
        }
        cout << "Pure Veg." << endl;
        cout << "Cuisines offered: " << cuisine << endl;
    }

    void display_menu () {
        for (int i = 0; i<food_array.size(); i++) {
            cout << i+1 << ' ';
            food_array[i].print_details();
        }
    }
};

vector<restaurants> restaurant_array;

void hotel_initiliazation() {
    string pizza_cuisine = {"Italian"};
    string burger_cuisine = {"American"};
    string rolls_cuisine = {"American"};
    string chinese_cuisine = {"Chinese"};
    string biryani_cuisine = {"Indian"};



    vector<food_item> pizza_palace_items = {
        food_item("Margherita Pizza", 200, 230, 60),
        food_item("Corn Pizza", 100, 327, 80),
        food_item("Paneer Pizza", 120, 275, 70),
        food_item("Onion Pizza", 60, 290, 75),
        food_item("BBQ Chicken Pizza", 150, 315, 85)
    };

    vector<food_item> burger_bliss_items = {
        food_item("Classic Burger", 50, 180, 50),
        food_item("Cheeseburger", 100, 210, 60),
        food_item("Chicken Burger", 150, 195, 55),
        food_item("Veggie Burger", 125, 190, 58),
        food_item("French Fries", 100, 240, 70)
    };

    vector<food_item> the_rolls_shop_items = {
        food_item("Chicken Roll", 120, 120, 35),
        food_item("Veg Roll", 80, 90, 26),
        food_item("Egg Roll", 90, 105, 30),
        food_item("Paneer Roll", 110, 130, 38),
        food_item("Hara Bhara Kabab Roll", 100, 100, 28)
    };

    vector<food_item> the_chinese_junction_items = {
        food_item("Spring Rolls", 120, 145, 40),
        food_item("Manchurian", 180, 210, 55),
        food_item("Fried Rice", 150, 180, 50),
        food_item("Chowmein", 160, 190, 58),
        food_item("Paneer Kurkure Gravy Momos", 200, 230, 65)
    };

    vector<food_item> biryani_kingdom_items = {
        food_item("Chicken Biryani", 250, 280, 65),
        food_item("Veg Biryani", 200, 220, 60),
        food_item("Paneer Biryani", 220, 320, 75),
        food_item("Mutton Biryani", 250, 250, 70),
        food_item("Fish Biryani", 280, 310, 80)
    };



    restaurants pizzaPalace (
        "Pizza Palace",
        3.4,
        30,
        557,
        120,
        false,
        pizza_cuisine,
        pizza_palace_items
    );

    restaurants burgerBliss(
        "Burger Bliss",
        1.2,
        24,
        1024,
        224,
        false,
        burger_cuisine,
        burger_bliss_items
    );

    restaurants TheRollsShop(
        "The Rolls Shop",
        2.6,
        36,
        245,
        61,
        false,
        rolls_cuisine,
        the_rolls_shop_items
    );

    restaurants TheChineseJunction(
        "The Chinese Junction",
        1.8,
        21,
        172,
        52,
        true,
        chinese_cuisine,
        the_chinese_junction_items
    );

    restaurants biryaniKingdom(
        "Biryani Kingdom",
        0.9,
        42,
        312,
        72,
        false,
        biryani_cuisine,
        biryani_kingdom_items
    );

    restaurant_array.push_back (pizzaPalace);
    restaurant_array.push_back (burgerBliss);
    restaurant_array.push_back (TheRollsShop);
    restaurant_array.push_back (TheChineseJunction);
    restaurant_array.push_back (biryaniKingdom);
}

class user_details {
    string first_name;
    string last_name;
    string phone_number;
    string email_id;
    string address;
    string password;

    public:
    user_details (string& first_name, string& last_name, string& phone_number, string& email_id, string& address, string& password) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone_number = phone_number;
        this->email_id = email_id;
        this->address = address;
        this->password = password;
    }

    void print_details () {
        cout << "Welcome " << first_name << ' ' << last_name << "!" << endl;
        cout << "User's phone number: " << phone_number << endl;
        cout << "User's email ID: " << email_id << endl;
        cout << "User's Address: " << address << endl;
    }

    string getPassword () {
        return password;
    }
};

vector<user_details> user_array;
unordered_map <string, int> userid_index;

class cart {
    unordered_map <string, pair<int, int>> cart_details;

    public:
    
    void cart_add (food_item product, int quantity) {
        string name = product.get_name();
        int price = product.get_price();

        if (cart_details.count (name)) {
            cart_details[name].second += quantity;
        }
        else {
            cart_details[name] = {price, quantity};
        }
    }

    void cart_display () {
        int i = 1;
        for (auto it: cart_details) {
            cout << i << ". " << it.first << ", x" << it.second.second << ", Rs. " << (it.second.first*it.second.second) << endl;
            i++;
        }
    }

    int total_value () {
        int tot = 0;
        for (auto it: cart_details) {
            tot += it.second.first*it.second.second;
        }
        return tot;
    }
};

cart rest_cart;

void checkout_page () {
    rest_cart.cart_display();
    cout << endl;
    cout << "Total Value: " << rest_cart.total_value() << endl;

    cout << "Do you want to confirm your order?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int final_choice;
    cin >> final_choice;

    if (final_choice == 1) {
        cout << "Order placed successfully!" << endl;
    }
    else {
        cout << "Going back to main page." << endl;
    }
}

void rest_page (int choice) {
    cout << "Select a choice: " << endl;
    cout << "1. Order from menu" << endl;
    cout << "2. More about the restaurant" << endl;
    int choice_2;
    cin >> choice_2;
    if (choice_2 == 1) {
        cout << "Select the food item: " << endl;
        restaurant_array[choice-1].display_menu();
        int food_choice;
        cin >> food_choice;
        cout << "Enter the quantity: "  << endl;
        int quant; 
        cin >> quant;

        rest_cart.cart_add(restaurant_array[choice-1].food_array[food_choice-1], quant);

        cout << quant << "x " << restaurant_array[choice-1].food_array[food_choice-1].get_name() << "added to the cart!" << endl;
        cout << endl;

        checkout_page();

    }
    else if (choice_2 == 2) {
        restaurant_array[choice-1].print_details();
    }
    else {
        cout << "Select a valid choice" << endl;
        rest_page (choice);
    }
}

void order_food () {
    cout << "Select which restaurant to order from: " << endl;
    cout << "1. Pizza Palace" << endl;
    cout << "2. Burger Bliss" << endl;
    cout << "3. The Roll Shop" << endl;
    cout << "4. The Chinese Junction" << endl;
    cout << "5. Biryani Kingdom" << endl;

    int choice;
    cin >> choice;

    rest_page(choice);
}

void user_homepage() {
    cout << endl;
    cout << "Select your choice: " << endl;
    cout << "1. Order food" << endl;
    cout << "2. Sign Out" << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        order_food();
        user_homepage();
        break;
    
    case 2:
        currUser = -1;
        break;
    
    default:
        cout << "Select a valid choice." << endl;
        user_homepage();
        break;
    }
}

void signin() {
    string temp_username;
    string temp_password;

    bool isValid = false;
    while (!isValid) {
        cout << "Enter your username: ";
        cin.ignore();
        getline (cin, temp_username);

        if (!userid_index.count (temp_username)) {
            cout << "Username doesn't exist. Try again." << endl;
        }
        else {
            isValid = true;
        }
    }

    int index = userid_index[temp_username];

    isValid = false;
    while (!isValid) {
        cout << "Enter your password: ";
        getline (cin, temp_password);
        string password = user_array[index].getPassword();
        if (password != temp_password) {
            cout << "Password is incorrect. Try again." << endl;
        }
        else {
            isValid = true;
        }
    }

    currUser = index;
    cout << endl;
    user_array[currUser].print_details();
    cout << endl;
    user_homepage();
}

void signup () {
    string username;
    string password;
    string first_name;
    string last_name = "";
    string phone_number;
    string email_id;
    string address;


    bool isValid = false;
    while (!isValid) {
        cout << "Enter your username: ";
        cin.ignore();
        getline (cin, username);
        if (username.size() < 6 || username.size() > 15) {
            cout << "Username's length should be between 6 and 15." << endl;
            continue;
        }
        bool whitspc = false;
        for (int i = 0; i<username.size(); i++) {
            if (username[i] == ' ') {
                cout << "Username should not contain whitespaces." << endl;
                whitspc = true;
                break;
            }
        }
        if (whitspc) {
            continue;
        }
        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your password: ";
        getline(cin, password);
        int size = password.size();
        if (size < 8 || size > 30) {
            cout << "Password length should be between 8 and 30" << endl;
            continue;
        }
        int upcs = 0, lwcs = 0, dig = 0;
        bool wtspc = false;
        for (int i = 0; i<password.size(); i++) {
            if (password[i] == ' ') {
                wtspc = true;
                break;
            }
            if (isupper (password[i])) {
                upcs++;
            }
            if (islower (password[i])) {
                lwcs++;
            }
            if (isdigit (password[i])) {
                dig++;
            }
        }
        if (wtspc) {
            cout << "Password cannot contain whitespaces. Try again." << endl;
            continue;
        }
        int spch = size - upcs - lwcs - dig;
        if (upcs == 0 || lwcs == 0 || dig == 0 || spch == 0) {
            cout << "Password should contain at least 1 lowercase, 1 uppercase, 1 digit and 1 special character. Try again" << endl;
            continue;
        }
        
        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Confirm your password again: ";
        string temp_pass;
        getline (cin, temp_pass);
        if (temp_pass == password) {
            isValid = true;
        }
        else {
            cout << "Passwords do not match. Try again" << endl;
        }
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your first name: ";
        getline (cin, first_name);
        bool oth = false;
        for (int i = 0; i<first_name.size(); i++) {
            if (!isalpha (first_name[i])) {
                cout << "Name should contain only alphabets." << endl;
                oth = true;
                break;
            }
            if (i == 0) {
                first_name[i] = toupper(first_name[i]);
            }
            else {
                first_name[i] = tolower(first_name[i]);
            }
        }
        if (oth) {
            continue;
        }
        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your last name: ";
        getline (cin, last_name);
        
        bool oth = false;
        for (int i = 0; i<last_name.size(); i++) {
            if (!isalpha (last_name[i])) {
                cout << "Name should contain only alphabets." << endl;
                oth = true;
                break;
            }
            if (i == 0) {
                last_name[i] = toupper(last_name[i]);
            }
            else {
                last_name[i] = tolower(last_name[i]);
            }
        }
        if (oth) {
            continue;
        }

        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your phone number: ";
        getline (cin, phone_number);
        if (phone_number.size() != 10) {
            cout << "Please enter a valid phone number. Try again" << endl;
            continue;
        }
        bool oth = false;
        for (int i = 0; i<phone_number.size(); i++) {
            if (!isdigit (phone_number[i])) {
                cout << "Please enter a valid phone number. Try again" << endl;
                oth = true;
                break;
            }
        }
        if (oth) {
            continue;
        }
        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your email id: ";
        getline (cin, email_id);
        regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); 
        if (!regex_match(email_id, pattern)) {
            cout << "Enter valid email address. Try again. " << endl;
        }

        isValid = true;
    }

    isValid = false;
    while (!isValid) {
        cout << "Enter your address: ";
        getline (cin, address);
        isValid = true;
    }
    
    userid_index[username] = user_array.size();
    user_details newUser (first_name, last_name, phone_number, email_id, address, password);
    user_array.push_back (newUser);

    cout << endl;
    cout << "Account with User ID: '" << username << "' created successfully!" << endl;
    cout << endl;
}

void main_homepage(bool& isOver) {
    cout << endl;
    cout << "Select your choice: " << endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Sign In" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        signup();
        break;
    
    case 2:
        signin();
        break;

    default:
        isOver = true;
        break;
    }
}

int main () {
    cout << "Made by Pratham Aggarwal, 2024" << endl;
    
    hotel_initiliazation();
    bool isOver = false;
    while (!isOver) {
        if (currUser != -1) {
            user_homepage;
        }
        else {
            main_homepage (isOver);
        }
    }
    return 0;
}