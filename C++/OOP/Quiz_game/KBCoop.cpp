#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_QUESTIONS = 100;  // Maximum number of questions
const int MAX_PLAYERS = 100;    // Maximum number of players

class Player {
public:
    string playerName;
    int playerScore;

    Player(string name = "", int score = 0) : playerName(name), playerScore(score) {}
    
    // Friend functions to handle input and output of Player objects
    friend ostream& operator<<(ostream& os, Player& p);
    friend istream& operator>>(istream& is, Player& p);
};

// Overload the output stream operator for Player class
ostream& operator<<(ostream& os, Player& p) {
    os << p.playerName << "\t" << p.playerScore;
    return os;
}

// Overload the input stream operator for Player class
istream& operator>>(istream& is, Player& p) {
    getline(is, p.playerName, '\t');
    is >> p.playerScore;
    is.ignore();
    return is;
}

// Base class for a Question
class Question {
protected:
    int id;  
    int type;  
    string question, option1, option2, option3, option4; 
public:
    char correctOption; 

    // Constructor for initializing question details
    Question(int id = 0, int t = 0, string q = "", string o1 = "", string o2 = "", string o3 = "", string o4 = "", char co = 'A')
        : id(id), type(t), question(q), option1(o1), option2(o2), option3(o3), option4(o4), correctOption(co) {}

    int getId() { return id; }  // Getter for question ID

    // Virtual methods for input, display, saving to file, and loading from file
    virtual void input();
    virtual void display() const;
    virtual void saveToFile(ofstream& ofs) const;
    virtual void loadFromFile(ifstream& ifs);
};

// Method to take input for a question
void Question::input() {
    cout << "Enter question: ";
    getline(cin, question);
    cout << "Enter options:\n";
    cout << "Option 1: ";
    getline(cin, option1);
    cout << "Option 2: ";
    getline(cin, option2);
    cout << "Option 3: ";
    getline(cin, option3);
    cout << "Option 4: ";
    getline(cin, option4);
    cout << "Enter correct option's position (A, B, C, D): ";
    cin >> correctOption;
    correctOption = toupper(correctOption);
    cin.ignore();
}

// Method to display a question and its options
void Question::display() const {
    cout << question << "\nA. " << option1 << "\tB. " << option2 << "\nC. " << option3 << "\tD. " << option4 << endl;
}

// Method to save question details to a file
void Question::saveToFile(ofstream& ofs) const {
    ofs << id << "\t" << question << "\t" << option1 << "\t" << option2 << "\t" << option3 << "\t" << option4 << "\t" << correctOption << "\n";
}

// Method to load question details from a file
void Question::loadFromFile(ifstream& ifs) {
    string line;
    if (getline(ifs, line)) {
        istringstream iss(line);
        if (!(iss >> id)) {
            cerr << "Error: Failed to read question ID from file." << endl;
            return;
        }
        iss.ignore();
        if (!getline(iss, question, '\t') ||
            !getline(iss, option1, '\t') ||
            !getline(iss, option2, '\t') ||
            !getline(iss, option3, '\t') ||
            !getline(iss, option4, '\t')) {
            cerr << "Error: Failed to read question or options from file." << endl;
            return;
        }
        if (!(iss >> correctOption)) {
            cerr << "Error: Failed to read correct option from file." << endl;
            return;
        }
    }
}

// Derived classes for different question types
class QuestionType1 : public Question {
public:
    QuestionType1() : Question(1) {}
    void input() override { Question::input(); }
};

class QuestionType2 : public Question {
public:
    QuestionType2() : Question(2) {}
    void input() override { Question::input(); }
};

class QuestionType3 : public Question {
public:
    QuestionType3() : Question(3) {}
    void input() override { Question::input(); }
};

class QuestionType4 : public Question {
public:
    QuestionType4() : Question(4) {}
    void input() override { Question::input(); }
};

// Game class to handle the quiz game logic
class Game {
private:
    Question* questions[MAX_QUESTIONS];
    int questionCount; 
    Player players[MAX_PLAYERS];
    int playerCount; 
    set<int> askedQuestions;  // Set to keep track of asked questions

    int findprize(int x) const;  // Function to calculate the prize based on question number
    Question* getRandomQuestion(int type);  // Function to get a random question of a specific type
    void displayHighScore() const;  // Function to display the highest score
    void savePlayer(Player& p);  // Function to save player details to a file
    Question** getAllQuestions(int type, int& count);  // Function to get all questions of a specific type

public:
    Game() : questionCount(0), playerCount(0) {}  // Constructor to initialize counts
    ~Game();  // Destructor to free memory
    void addQuestion();  // Function to add a new question
    int play();  // Function to start the game
    void run();  // Function to run the game loop
};

// Destructor to delete all dynamically allocated questions
Game::~Game() {
    for (int i = 0; i < questionCount; i++) {
        delete questions[i];
    }
}

// Function to get a random question of a specific type
Question* Game::getRandomQuestion(int type) {
    if (type < 1 || type > 4) {
        throw invalid_argument("Invalid question type");
    }

    int count;
    Question** allQuestions = getAllQuestions(type, count);

    Question* selectedQuestion = nullptr;
    for (int i = 0; i < count; i++) {
        if (askedQuestions.find(allQuestions[i]->getId()) == askedQuestions.end()) {
            selectedQuestion = allQuestions[i];
            askedQuestions.insert(selectedQuestion->getId());
            break;
        }
    }

    delete[] allQuestions;

    if (!selectedQuestion) {
        throw runtime_error("No available questions of the requested type.");
    }

    return selectedQuestion;
}

// Function to find the price based on the number of questions answered correctly
int Game::findprize(int x) const {
    switch (x) {
        case 1: return 1000;
        case 2: return 2000;
        case 3: return 3000;
        case 4: return 5000;
        case 5: return 10000;
        case 6: return 20000;
        case 7: return 40000;
        case 8: return 80000;
        case 9: return 160000;
        case 10: return 320000;
        case 11: return 640000;
        case 12: return 1250000;
        case 13: return 2500000;
        case 14: return 5000000;
        case 15: return 7500000;
        case 16: return 10000000;
        case 17: return 30000000;
        case 18: return 50000000;
        default: return 0;
    }
}

// Function to display the highest score from the player file
void Game::displayHighScore() const {
    ifstream ifs("player_file.txt");
    if (!ifs) {
        cerr << "Error reading player scores!\n";
        return;
    }

    Player highestScorePlayer("", -1);
    Player p;
    while (ifs >> p) {
        if (p.playerScore > highestScorePlayer.playerScore) {
            highestScorePlayer = p;
        }
    }
    ifs.close();

    if (highestScorePlayer.playerScore != -1) {
        cout << "High score: " << highestScorePlayer.playerName << " - " << highestScorePlayer.playerScore << endl;
    } else {
        cout << "No high score available.\n";
    }
}

// Function to save a player's data to a file
void Game::savePlayer(Player& p) {
    ofstream ofs("player_file.txt", ios::app);
    if (!ofs) {
        cerr << "Error opening file to save player data!" << endl;
        return;
    }
    ofs << p;
    ofs.close();
}

// Function to get all questions of a specific type from a file
Question** Game::getAllQuestions(int type, int& count) {
    Question** allQuestions = new Question*[MAX_QUESTIONS];
    count = 0;

    string fileName = "type_" + to_string(type) + "_file.txt";
    ifstream ifs(fileName);
    if (!ifs) {
        cerr << "Error opening file: " << fileName << endl;
        throw runtime_error("Error opening file: " + fileName);
    }

    while (true) {
        Question* q = nullptr;
        switch (type) {
            case 1: q = new QuestionType1(); break;
            case 2: q = new QuestionType2(); break;
            case 3: q = new QuestionType3(); break;
            case 4: q = new QuestionType4(); break;
            default: throw invalid_argument("Invalid question type");
        }
        try {
            q->loadFromFile(ifs);
            if (ifs.eof()) break;
            allQuestions[count++] = q;
        } catch (runtime_error& e) {
            cerr << e.what() << endl;
            delete q;
        }
    }
    ifs.close();
    return allQuestions;
}

// Function to add a new question to the game
void Game::addQuestion() {
    int type;
    cout << "Enter question type (1-4): ";
    cin >> type;
    cin.ignore();

    Question* q = nullptr;
    switch (type) {
        case 1: q = new QuestionType1(); break;
        case 2: q = new QuestionType2(); break;
        case 3: q = new QuestionType3(); break;
        case 4: q = new QuestionType4(); break;
        default: 
            cout << "Invalid question type!" << endl;
            return;
    }

    q->input();
    questions[questionCount++] = q;

    string fileName = "type_" + to_string(type) + "_file.txt";
    ofstream ofs(fileName, ios::app);
    if (!ofs) {
        cerr << "Error opening file to save question!" << endl;
        return;
    }

    q->saveToFile(ofs);
    ofs.close();

    cout << "Question added successfully!" << endl;
}

// Function to play the game
int Game::play() {
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);
    Player player(playerName);

    int type;
    int questionIndex = 1;

    while (true) {
        type = rand() % 4 + 1;  // Random question type between 1 and 4

        try {
            Question* q = getRandomQuestion(type);
            cout << "\nQuestion " << questionIndex << ": " << endl;
            q->display();

            char playerAnswer;
            cout << "Your answer (A, B, C, D or Q to quit): ";
            cin >> playerAnswer;
            playerAnswer = toupper(playerAnswer);

            if (playerAnswer == 'Q') {
                cout << "You decided to quit the game." << endl;
                cout << "Your final score is: " << player.playerScore << endl;
                break;
            }

            if (playerAnswer == q->correctOption) {
                cout << "Correct!" << endl;
                player.playerScore += findprize(questionIndex);
                questionIndex++;
            } else {
                cout << "Incorrect! The correct answer was " << q->correctOption << "." << endl;
                cout << "Your final score is: " << player.playerScore << endl;
                break;
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
            break;
        }
    }

    savePlayer(player);
    return player.playerScore;
}

// Main function to run the game loop
void Game::run() {
    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        cout << "\n--- Welcome to the Quiz Game ---\n";
        cout << "1. Add a Question\n";
        cout << "2. Play the Game\n";
        cout << "3. View High Score\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: 
                addQuestion(); 
                break;
            case 2: 
                play(); 
                break;
            case 3: 
                displayHighScore(); 
                break;
            case 4: 
                cout << "Thanks for playing!" << endl;
                return;
            default: 
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Main function to start the program
int main() {
    Game game;
    game.run();
    return 0;
}
