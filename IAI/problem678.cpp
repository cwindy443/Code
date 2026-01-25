#include <cmath>
#include <iostream>

int n;

char getChar(int i, int j, int level) {
  if (level == 0) {
    return '+';
  }

  int size = (int)std::pow(3, level - 1);

  int block_i = i / size;
  int block_j = j / size;

  int sub_i = i % size;
  int sub_j = j % size;

  if ((block_i == 1 && block_j == 1) || (block_i == 0 && block_j == 1) ||
      (block_i == 2 && block_j == 1) || (block_i == 1 && block_j == 0) ||
      (block_i == 1 && block_j == 2)) {
    return getChar(sub_i, sub_j, level - 1);
  } else {
    return '.';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;

  int size = (int)std::pow(3, n);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << getChar(i, j, n);
    }
    std::cout << '\n';
  }

  return 0;
}
