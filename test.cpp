#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Quiz {
private:
    vector<pair<string, string>> questions;
    int correctAnswers;
    int incorrectAnswers;

public:
    explicit Quiz(const vector<pair<string, string>>& q) : questions(q), correctAnswers(0), incorrectAnswers(0) {}

    void askQuestions() {
        for (const auto& q : questions) {
            string userAnswer;
            cout << q.first << " ";
            getline(cin, userAnswer);

            if (userAnswer == q.second) {
                ++correctAnswers;
            } else {
                ++incorrectAnswers;
            }
        }
    }

    void showResults() const {
        cout << "Correct answers: " << correctAnswers << endl;
        cout << "Incorrect answers: " << incorrectAnswers << endl;
    }
};

int main() {
    vector<pair<string, string>> questions = {
            {" 1) 5*5=",    "25"},
            {"2) 6*8=",    "48"},
            {"3) 7*9=",    "63"},
            {"4) 3*4=",    "12"},
            {"5) 8*7=",    "56"},
            {"6) 9*9=",    "81"},
            {"7) 12*12=",  "144"},
            {"8) 11*11=",  "121"},
            {"9) 10*10=",  "100"},
            {"10) 4*7=",   "28"},
            {"11) 2*9=",   "18"},
            {"12) 3*6=",   "18"},
            {"13) 4*4=",   "16"},
            {"14)6*7=" ,  "42"},
            {"15) 5*6=",   "30"},
            {"16) 8*8=",   "64"},
            {"17) 9*7=",   "63"},
            {"18) 11*10=", "110"},
            {"19) 10*9=",  "90"},
            {"20) 12*11=", "132"}
    };

    Quiz quiz(questions);
    quiz.askQuestions();
    quiz.showResults();

    return 0;
}