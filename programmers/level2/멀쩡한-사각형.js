// https://programmers.co.kr/learn/courses/30/lessons/62048

const gcd = (a, b) => (a % b ? gcd(b, a % b) : b);

const solution = (w, h) => w * h - (w + h - gcd(w, h));

/*
  기울기로 접근했지만 O(N)으로 시간초과가 계속 발생..
  대각선이 지나는 정사각형을 가로 / 세로로 이동시켰을 때 최대공약수로 구할 수 있는 방법으로 풀이
*/
