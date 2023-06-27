#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Question
{ // ** Struct with question + 3 answer and a int for the correct choice  **
    string questionText;
    string answer[3];
    int correctAnswer = NULL;
};

bool correctAnswer(int correct)
{ // ** ask and check if the answer is correct or not with a bool **
    int answer;

    cout << "Choose 1-3 : ";
    cin >> answer;

    while (answer > 3 || answer < 1)
    { // Check if the user  enter a not valid number
        cout << "Invalid, Choose 1-3 : ";
        cin >> answer;
    }

    if (answer == correct)
    { // check if the answer is correct
        cout << "Correct !" << endl
             << endl;
        return true; // return 1 if valid, 0 if not
    }
    else
    {
        cout << "Not correct :(" << endl
             << endl;
        return false;
    }
}

bool question(Question questionNumber)
{ // ** List all option
    cout << questionNumber.questionText << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << questionNumber.answer[j] << endl;
    }
    return correctAnswer(questionNumber.correctAnswer); // Use the function correctAnswer for asking and checking the answer and return 1 if correct, 0 if not.
}

int main()
{
    int score = 0; // Just for counting the score.

    Question question1; // create all question with structure here, i don't think we can use a loop for that, cause of all differentes text
    question1.questionText = "What is the smallest country ?";
    question1.answer[0] = "1. USA";
    question1.answer[1] = "2. India";
    question1.answer[2] = "3. Vatican City";
    question1.correctAnswer = 3; // send the correct option to my function

    Question question2;
    question2.questionText = "What is the biggest animal in the world ?";
    question2.answer[0] = "1. Elephant";
    question2.answer[1] = "2. Blue whale";
    question2.answer[2] = "3. Great white shark";
    question2.correctAnswer = 2;

    Question question3;
    question3.questionText = "How many elements are there in the periodic table of element ?";
    question3.answer[0] = "1. 118 elements";
    question3.answer[1] = "2. 119 elements";
    question3.answer[2] = "3. 120 elements";
    question3.correctAnswer = 1;

    Question question4;
    question4.questionText = "155 % 10 ?";
    question4.answer[0] = "1. 15";
    question4.answer[1] = "2. 5";
    question4.answer[2] = "3. 15,5";
    question4.correctAnswer = 2;

    Question question5;
    question5.questionText = "Where is Bali";
    question5.answer[0] = "1. Malaysia";
    question5.answer[1] = "2. Venezuela";
    question5.answer[2] = "3. Indonesia";
    question5.correctAnswer = 3;

    score += question(question1); // if the player choose the correct option the bool function return 1 and add this to my score
    score += question(question2); // else, if the player fail, we get 0 and the score don't change
    score += question(question3);
    score += question(question4);
    score += question(question5);

    cout << "Your score is : " << score << " /5." << endl;
    cin.get();
}