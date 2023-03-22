#include <vector>
#include <string>

using std::string;
using std::vector;

namespace mcsv {
	vector<string> split(string text, char delimeter);
	vector<vector<string>> read_csv(string path);
	void write_csv(string path, vector<vector<std::string>> vect);
	void append_csv(string path, vector<string> vect);
}