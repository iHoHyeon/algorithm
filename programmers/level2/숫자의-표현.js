// https://school.programmers.co.kr/learn/courses/30/lessons/12924

function solution(n) {
  let cnt = 0;

  for (let i = 1; i <= n; i++) {
    const D = 4 * i * i - 4 * i + 1 + 8 * n;

    const root2 = (1 - 2 * i - Math.sqrt(D)) / 2;

    if (Number.isInteger((1 - 2 * i + Math.sqrt(D)) / 2)) cnt++;
    else if (Number.isInteger(root2) && root2 > 0) cnt++;
  }
  return cnt;
}

/*
    i부터 연속된 m개의 수의 합 = m * (i + (i + m - 1)) / 2

    i가 1 ~ n 일 경우, 위 등식을 만족시키는 자연수 m이 존재하는지 판단하면 된다.

    위 식을 m에 대한 이차방정식으로 나타내면 m^2 + (2i - 1)m - 2n = 0. (n은 주어지는 값)

    근이 자연수인지 판단해주면 된다.
    
*/
