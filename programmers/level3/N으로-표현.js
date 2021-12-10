// https://programmers.co.kr/learn/courses/30/lessons/42895

const solution = (N, numbers) => {
  const dp = new Array(9).fill();
  for (let i = 1; i < 9; i++) {
    dp[i] = new Set();
    dp[i].add(N * parseInt('1'.repeat(i)));
    for (let j = 1; j < i; j++) {
      for (const first of dp[j]) {
        for (const second of dp[i - j]) {
          dp[i].add(first + second);
          dp[i].add(first - second);
          dp[i].add(first * second);
          dp[i].add(parseInt(first / second));
        }
      }
    }
    if (dp[i].has(numbers)) return i;
  }
  return -1;
};

/*
    N을 1 ~ 8 번 사용하여 만들 수 있는 모든 숫자를 기록하자
    1번부터 시작해서 8회까지 모든 경우의수를 반복문을 통해서 저장
    매 횟수에 저장이 끝났을 경우 타겟이 되는 숫자가 저장되었는지 확인하고 저장되었으면 return 아니라면 다음 횟수로 넘어간다
*/
