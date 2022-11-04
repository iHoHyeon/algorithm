// https://school.programmers.co.kr/learn/courses/30/lessons/12907

const MOD = 1_000_000_007;

const dp = new Array(100_001).fill().map(() => 0);

function solution(n, money) {
  dp[0] = 1;

  for (const m of money) {
    for (let i = 0; i <= n; i++) {
      if (i >= m) {
        dp[i] = (dp[i] + dp[i - m]) % MOD;
      }
    }
  }

  return dp[n];
}

/*
    각 화폐 종류에 대해서 dp[i] += dp[i-m] 점화식을 적용

    중복 dp를 제거하기 위해서 for 문의 순서에 유의해야함..
*/
