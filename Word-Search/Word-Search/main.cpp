#include <iostream>
#include <fstream>
#include <iomanip>

// prototypes
bool word_found(const std::string& word_to_find, const std::string& target_word);
void run_search();
void get_choice();

//definitions
bool word_found(const std::string& word_to_find, const std::string& target_word) {
    std::size_t found = target_word.find(word_to_find);
    
    if (found == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

void run_search() {
    std::ifstream in_file{};
    std::string word_to_find{};
    std::string word_read{};
    int word_count{ 0 };
    int match_count{ 0 };

    in_file.open("./RomeoAndJuliet.txt");

    std::cout << std::endl;
    std::cout << "Enter word to search for: ";
    std::cin >> word_to_find;

    while (in_file >> word_read) {
        ++word_count;
        if (word_found(word_to_find, word_read)) {
            ++match_count;
        }
    }

    std::cout << std::endl;
    std::cout << word_count << " words were searched... " << std::endl;
    std::cout << word_to_find << " was found " << match_count << " times." << std::endl << std::endl;

    std::cout << "Would you like to run another search? (Y/N): ";
    get_choice();

}

void get_choice() {
    std::ifstream in_file{};
    char cont{};
    std::cin >> cont;

    if (cont == 'y' || cont == 'Y') {
        run_search();
    } else if (cont == 'n' || cont == 'N') {
        in_file.close();
        std::cout << "Goodbye!" << std::endl;
    } else {
        in_file.close();
        std::cout << "Unknown selection, program terminating. Goodbye!" << std::endl;
    }
}

int main() {
    std::ifstream in_file{};
    std::string title{ "Romeo & Juliet Word Search" };
    std::string str_one{ "Hello!" };
    std::string str_two{ "This is a word search program that allows you to search for words" };
    std::string str_three{"within the script of Romeo & Juliet."};
    std::string str_four{"The search word is CASE SENSITIVE, so please keep that in mind."};
    std::string str_five{"Have fun!!"};

    std::cout << std::setw((70 - title.length()) / 2) << "" << title << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << " " << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw((70 - str_one.length()) / 2) << "" << str_one << std::endl;
    std::cout << std::setw((70 - str_two.length()) / 2) << "" << str_two << std::endl;
    std::cout << std::setw((70 - str_three.length()) / 2) << "" << str_three << std::endl;
    std::cout << std::setw((70 - str_four.length()) / 2) << "" << str_four << std::endl;
    std::cout << std::setw((70 - str_five.length()) / 2) << "" << str_five << std::endl;

    if (!in_file) {
        std::cerr << "There was a problem opening the file." << std::endl;
        return 1;
    }

    run_search();

    std::cout << std::endl;
    return 0;
}
