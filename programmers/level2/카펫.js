// https://school.programmers.co.kr/learn/courses/30/lessons/42842

function solution(brown, yellow) {
  const brownTotal = (brown + 4) / 2;

  for (let i = 1; i <= Math.floor(brownTotal / 2); i++) {
    const col = i;
    const row = brownTotal - i;

    if ((col - 2) * (row - 2) === yellow) {
      return [row, col];
    }
  }
}
