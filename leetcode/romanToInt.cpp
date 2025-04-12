#include <iostream>
#include <unordered_map>

class Solution {
public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> myMap;
    myMap['I'] = 1; // Using char literals instead of string literals
    myMap['V'] = 5;
    myMap['X'] = 10;
    myMap['L'] = 50;
    myMap['C'] = 100;
    myMap['D'] = 500;
    myMap['M'] = 1000;
    int asn = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i < s.length() - 1 && myMap[s[i]] < myMap[s[i + 1]]) {
        asn -= myMap[s[i]];
      } else {
        asn += myMap[s[i]];
      }
    }
    return asn;
  }
};

int main() {
  Solution sol;

  std::cout << "Starting program..." << std::endl;

  // Test cases
  std::string roman1 = "III";     // 3
  std::string roman2 = "IV";      // 4
  std::string roman3 = "IX";      // 9
  std::string roman4 = "LVIII";   // 58
  std::string roman5 = "MCMXCIV"; // 1994

  std::cout << "Test cases initialized..." << std::endl;

  // Calculate and print results
  std::cout << roman1 << " -> " << sol.romanToInt(roman1) << std::endl;
  std::cout << roman2 << " -> " << sol.romanToInt(roman2) << std::endl;
  std::cout << roman3 << " -> " << sol.romanToInt(roman3) << std::endl;
  std::cout << roman4 << " -> " << sol.romanToInt(roman4) << std::endl;
  std::cout << roman5 << " -> " << sol.romanToInt(roman5) << std::endl;

  std::cout << "Program finished." << std::endl;

  return 0;
}
