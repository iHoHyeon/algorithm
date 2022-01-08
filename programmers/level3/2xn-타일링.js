// https://programmers.co.kr/learn/courses/30/lessons/12900

const solution = (n) => {
  const dp = new Array(60001).fill(0);

  dp[1] = 1;
  dp[2] = 2;
  for (let i = 3; i <= 60000; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1_000_000_007;
  }

  return dp[n];
};

/*
  쉬운 dp문제
*/
