// https://school.programmers.co.kr/learn/courses/30/lessons/12953

const solution = (arr) => arr.reduce((acc, v) => LCM(acc, v), 1);

const GCD = (x, y) => (y ? GCD(y, x % y) : x);

const LCM = (x, y) => (x * y) / GCD(x, y);

/*
  GCD -> 유클리드 호제법
  LCM -> 최소공배수는 최대공약수로부터 구할 수 있음을 활용

  arr을 1회 순회하며 LCM를 연산해주면 된다.
*/
