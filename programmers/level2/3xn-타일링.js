// https://school.programmers.co.kr/learn/courses/30/lessons/12902

const ans = [0, 0, 3, 0, 11];

Array.prototype.sum = function () {
  return this.reduce((acc, v) => acc + v, 0);
};

for (let i = 5; i <= 5000; i++) {
  if (i % 2) ans.push(0);
  else ans.push((3 * ans[i - 2] + 2 * ans.slice(1, i - 2).sum() + 2) % 1_000_000_007);
}

function solution(n) {
  return ans[n];
}
