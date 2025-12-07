#include <iostream>
#include <vector>

struct person {
  bool mask = true; // 最初所有人都戴口罩
  bool covid;
};
const int N_MAX = 5e5 + 5; // 使用不同的名称表示最大大小
std::vector<person> a(N_MAX); // 初始化最大大小的vector

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, q;
  std::cin >> n >> q;

  // 未戴口罩的人数计数器和全局感染标志
  int num_unmasked_covid_positive = 0; // 未戴口罩且COVID阳性的人数
  int num_unmasked_covid_negative = 0; // 未戴口罩且COVID阴性的人数
  bool global_infection_active = false; // 如果一个未戴口罩的COVID阳性的人感染了所有未戴口罩的COVID阴性的人，则为真

  // 读取初始COVID状态。最初所有人都戴口罩。
  for(int i = 1; i <= n; i++){
    std::cin >> a[i].covid;
  }

  // 处理查询
  for(int i = 1; i <= q; i++){
    int x;
    std::cin >> x;

    bool was_masked = a[x].mask;
    bool was_covid = a[x].covid;

    // 根据人x的旧状态（如果他们未戴口罩）调整全局计数
    if (!was_masked) {
      if (was_covid) {
        num_unmasked_covid_positive--;
      } else {
        num_unmasked_covid_negative--;
      }
    }

    // 切换人x的口罩状态
    a[x].mask = !a[x].mask;

    // 如果人x现在未戴口罩：
    if (!a[x].mask) {
      // 检查人x是否从其他人那里感染了COVID（情景B）
      // 如果x当前为COVID阴性，并且（至少有一个其他未戴口罩的COVID阳性的人，或者全局感染事件已激活），则会发生这种情况。
      if (!a[x].covid) {
        if (num_unmasked_covid_positive > 0 || global_infection_active) {
          a[x].covid = true;
        }
      }

      // 潜在感染后，在全局计数中更新人x的状态
      if (a[x].covid) {
        num_unmasked_covid_positive++;
      } else {
        num_unmasked_covid_negative++;
      }

      // 检查人x是否引起全局感染（情景A）
      // 如果x未戴口罩且COVID阳性，并且存在未戴口罩的COVID阴性的人，则会发生这种情况。
      if (a[x].covid) { // 人x现在未戴口罩且COVID阳性
        if (num_unmasked_covid_negative > 0) {
          global_infection_active = true;
        }
      }
    }
    // 如果人x现在戴着口罩，他们的状态不会影响未戴口罩的人数或全局感染。
    // 如果他们之前未戴口罩，计数已经减少了。
  }

  // 最后遍历以应用全局感染效果并打印结果
  for(int i = 1; i <= n; i++){
    // 如果global_infection_active为真，任何未戴口罩且COVID阴性的人都会感染COVID。
    if (!a[i].mask && !a[i].covid && global_infection_active) {
      a[i].covid = true;
    }
    std::cout << a[i].covid << " ";
  }
  std::cout << std::endl; // 最后添加一个换行符

	return 0;
}
