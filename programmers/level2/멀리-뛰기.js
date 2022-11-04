// https://school.programmers.co.kr/learn/courses/30/lessons/12914

const MOD = 1234567;
const dp = new Array(2001).fill().map(() => null);

function solution(n) {
  dp[0] = 1;
  dp[1] = 1;

  for (let i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }

  return dp[n];
}
