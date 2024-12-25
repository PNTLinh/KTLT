#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& str, char delimiter) {//NguyenThuyLinh_20225031
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
double calculateTF(int termFreq, int maxFreq) {
    return 0.5 + 0.5 * ((double)termFreq / maxFreq);
}
double calculateIDF(int N, int docFreq) {
    return log2((double)N / docFreq);
}
void processDocuments(const vector<string>& documents, vector<unordered_map<string, int>>& termFreqs, unordered_map<string, int>& docFreqs) {
    for (int i = 0; i < documents.size(); ++i) {
        vector<string> words = split(documents[i], ',');
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        termFreqs.push_back(freq);
        for (const auto& pair : freq) {
            docFreqs[pair.first]++;
        }
    }
}
int findMaxFreq(const unordered_map<string, int>& freq) {
    int maxFreq = 0;
    for (const auto& pair : freq) {
        maxFreq = max(maxFreq, pair.second);
    }
    return maxFreq;
}
//NguyenThuyLinh_20225031
double calculateScore(const unordered_map<string, int>& termFreq, const unordered_map<string, int>& docFreq, const vector<string>& query, int N) {
    double score = 0.0;
    int maxFreq = findMaxFreq(termFreq);
    for (const string& term : query) {
        if (termFreq.find(term) != termFreq.end()) {
            double tf = calculateTF(termFreq.at(term), maxFreq);
            double idf = calculateIDF(N, docFreq.at(term));
            score += tf * idf;
        }
    }
    return score;
}
vector<int> search(const vector<string>& documents, const vector<string>& queries) {
    int N = documents.size();
    vector<unordered_map<string, int>> termFreqs;
    unordered_map<string, int> docFreqs;
    processDocuments(documents, termFreqs, docFreqs);
    vector<int> results;
    for (const string& queryStr : queries) {
        vector<string> query = split(queryStr, ',');
        double maxScore = -1.0;
        int bestDocIdx = -1;
        for (int i = 0; i < N; ++i) {
            double score = calculateScore(termFreqs[i], docFreqs, query, N);
            if (score > maxScore || (score == maxScore && i < bestDocIdx)) {
                maxScore = score;
                bestDocIdx = i;
            }
        }
        results.push_back(bestDocIdx);
    }
    return results;
}
int main() {//NguyenThuyLinh_20225031
    ifstream f("input4.10.txt");
    int N, Q;
    f >> N;
    vector<string> documents;
    for (int i = 0; i < N; ++i) {
        string e;
        f >> e;
        documents.push_back(e);
    }
    f >> Q;
    vector<string> queries;
    for (int i = 0; i < Q; ++i) {
        string e;
        f >> e;
        queries.push_back(e);
    }
    vector<int> results = search(documents, queries);
    for (int idx : results) {
        cout << idx + 1 << endl;
    }
    cout<<"NguyenThuyLinh_20225031";
    return 0;
}
