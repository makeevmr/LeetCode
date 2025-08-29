/* Write a function that takes the binary representation of a positive integer
and returns the number of set bits it has (also known as the Hamming weight). */

class Solution {
public:
  [[nodiscard]] static int hammingWeight(int n) {
    int set_bits_counter = 0;
    for (int i = 0; i < 32; ++i) {
      set_bits_counter += (n >> i) & 1;
    }
    return set_bits_counter;
  }
};
