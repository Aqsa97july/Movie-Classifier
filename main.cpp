#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Movie structure
struct Movie {
    string name;
    int action;
    int comedy;
    int horror;
};

// Function to calculate similarity score
int calculateScore(Movie movie, int userAction, int userComedy, int userHorror) {

    int score = 0;

    score += 10 - abs(movie.action - userAction);
    score += 10 - abs(movie.comedy - userComedy);
    score += 10 - abs(movie.horror - userHorror);

    return score;
}

int main() {

    // Stored movie dataset
    vector<Movie> movies = {

        {"Interstellar", 5, 1, 2},
        {"Titanic",      1, 2, 1},
        {"Avengers",     10, 5, 3},
        {"John Wick",    10, 1, 6},
        {"The Notebook", 1, 2, 1},
        {"Inception",    7, 2, 7}
    };

    // User preferences
    int userAction, userComedy, userHorror;

    cout << "Rate your interest from 1 to 10\n\n";

    cout << "Action: ";
    cin >> userAction;

    cout << "Comedy: ";
    cin >> userComedy;

    cout << "Horror: ";
    cin >> userHorror;

    // Store movie scores
    vector<pair<int, string>> recommendations;

    // Compare user with every movie
    for (int i = 0; i < movies.size(); i++) {

        int score = calculateScore(
            movies[i],
            userAction,
            userComedy,
            userHorror
        );

        recommendations.push_back({score, movies[i].name});
    }

    // Sort highest score first
    sort(recommendations.rbegin(), recommendations.rend());

    // Output recommendations
    cout << "\nTop Movie Recommendations:\n\n";

    for (int i = 0; i < recommendations.size(); i++) {

        cout << recommendations[i].second
             << " | Similarity Score: "
             << recommendations[i].first << endl;
    }

    return 0;
}