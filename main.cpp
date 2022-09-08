#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// O(1) time | O(1) space
void updateScores(unordered_map<string, int> &scores, string team) {
    if(scores.find(team) == scores.end()) {
        scores[team] = 0;
    }
    scores[team] += 1;
}

// O(n) time | O(number of teams) space
string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    string currentBestTeam;
    unordered_map<string, int> scores = {{currentBestTeam, 0}};// O(number of teams) space
    for(int i = 0; i < competitions.size(); i++) {// O(n) time
        auto currentMatch = competitions[i];
        string homeTeam = currentMatch[0];
        string awayTeam = currentMatch[1];
        auto result = results[i];
        string winningTeam = (result == 1) ? homeTeam : awayTeam;
        updateScores(scores, winningTeam);// O(1) time | O(1) space
        if(scores[winningTeam] > scores[currentBestTeam]) {
            currentBestTeam = winningTeam;
        }
    }
    return currentBestTeam;
}

int main() {
    vector<vector<string>> competitions = {
            {"HTML", "C#"},
            {"C#", "Python"},
            {"Python", "HTML"}
    };
    vector<int> results = {0, 0, 1};
    cout << tournamentWinner(competitions, results);
    return 0;
}
