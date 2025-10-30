#include "functions.h"
#include <sstream>

using namespace std;

vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (c == '"') {
            if (inQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                field += '"';
                ++i;
            } else {
                inQuotes = !inQuotes;
            }
        }
        else if (c == ',' && !inQuotes) {
            result.push_back(field);
            field.clear();
        }
        else {
            field += c;
        }
    }

    result.push_back(field);
    return result;
}

vector<vector<string>> readCSV(istream& in) {
    vector<vector<string>> rows;
    string line, fullLine;

    while (getline(in, line)) {
        fullLine += line;

        // count quotes to detect multiline record
        size_t quoteCount = 0;
        for (char c : fullLine) if (c == '"') ++quoteCount;

        if (quoteCount % 2 == 0) {
            rows.push_back(parseCSVLine(fullLine));
            fullLine.clear();
        }
    }

    if (!fullLine.empty())
        rows.push_back(parseCSVLine(fullLine));

    return rows;
}
