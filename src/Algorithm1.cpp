#include "Algorithm1.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate and recommend movies based on mutual movie interests
    vector <int> Algorithm1::recommend(DataStructure& dataStructure, int userId, int movieId) {
    unordered_map<int, int> movieRecommendationScore; // Maps movie ID to recommendation score
    unordered_map<int, int> mutualMovies; // Maps movie ID to mutual movie count
    vector <pair<int, int>> recommendations; // Vector to store recommendations
    User mainUser = dataStructure.find_user(userId); // Find the  main user
    vector <User> relevants = vector<User>(); // Vector to store relevant users
    for (User user : dataStructure.get_users()) {
        if (user.getId() == userId) {
            continue; // Skip the main user
        }
        if (user.hasWatchedMovie(movieId)) {
            relevants.push_back(user); // Add user to relevant users if they have watched the target movie
        }
    }

    // Calculate mutual movies with the main user for every relevant user

    for (User relevant : relevants) {
        for (Movie movie : relevant.getWatchedMovies()) {
            if (mainUser.hasWatchedMovie(movie.getId())) {
                mutualMovies[relevant.getId()]++;
            }
        }
    }

    relevants.erase(remove_if(relevants.begin(), relevants.end(), [&mutualMovies] (const User& user) {
        int relevantId = user.getId();
        return mutualMovies.find(relevantId) == mutualMovies.end() || mutualMovies[relevantId]  == 0;
    }), relevants.end());

    // Calculate recommendation score for each movie
    for (const User& relevant : relevants) {
        for (const Movie &movie : relevant.getWatchedMovies()) {
            if (movie.getId() == movieId || mainUser.hasWatchedMovie(movie.getId())) {
                continue; // Skip the target movie or the movied the main user has already watched
            }
            movieRecommendationScore[movie.getId()] += mutualMovies[relevant.getId()];
        }
    }

    // transferring the recommendationScore map to the recommendation vector
    for (const auto& movie_score : movieRecommendationScore) {
        recommendations.push_back(movie_score);
    }

    // Sort the recommendations based on the recommendation score, such that the movie with the highest score comes first
    sort(recommendations.begin(), recommendations.end(), [](const pair <int, int> & movie1, const pair <int, int> & movie2) {
        if (movie1.second == movie2.second) {
            return movie1.first < movie2.first;
        }
        return movie1.second > movie2.second;
    });

    // Print the first 10 recommendations
    for (int i = 0; i < 10 && i < recommendations.size(); i++) {
        cout << "Movie ID: " << recommendations[i].first << " Recommendation Score: " << recommendations[i].second << endl;
    }

    // Return the first 10 recommendations
    vector <int> finalMovies;
    for (int i = 0; i < 10 && i < recommendations.size(); i++) {
        finalMovies.push_back(recommendations[i].first);
    }
    return finalMovies;
}