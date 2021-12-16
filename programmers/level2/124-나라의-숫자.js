// https://programmers.co.kr/learn/courses/30/lessons/12899

const solution = (n) => {
  const cases = [4, 1, 2];
  let ans = '';
  while (n) {
    ans = cases[n % 3] + ans;
    n = !(n % 3) ? n / 3 - 1 : parseInt(n / 3);
  }
  return ans;
};

/*
  3진수 표현이면서 나누어 떨어지는 경우만 조금 다르게 케이스 분류를 해주면 된다
*/
