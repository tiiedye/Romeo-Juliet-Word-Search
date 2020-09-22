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
    std::cout << word_to_find << " was found " << match_count << " times." << std::endl;

    std::cout << "Would you like to run another search? (Y/N): ";
    get_choice();

}

void get_choice() {
    std::ifstream in_file{};
    char cont{};
    std::cin >> cont;

    if (cont == 'y' || 'Y') {
        run_search();
    } else if (cont == 'n' || 'N') {
        in_file.close();
        std::cout << "Goodbye!" << std::endl;
    } else {
        in_file.close();
        std::cout << "Unknown selection, program terminating. Goodbye!" << std::endl;
    }
}

int main() {
    std::ifstream in_file{};

    std::cout << std::setw(20) << "" << "Romeo & Juliet Word Search" << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << " " << std::endl;
    std::cout << std::setfill(' ');

    if (!in_file) {
        std::cerr << "There was a problem opening the file." << std::endl;
        return 1;
    }

    run_search();

    std::cout << std::endl << std::endl;
    return 0;
}
