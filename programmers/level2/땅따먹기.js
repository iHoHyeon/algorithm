// https://school.programmers.co.kr/learn/courses/30/lessons/12913

function solution(land) {
  for (let row = 1; row < land.length; row++) {
    for (let col = 0; col < 4; col++) {
      land[row][col] = Math.max(...land[row - 1].filter((_, idx) => idx !== col)) + land[row][col];
    }
  }
  return Math.max(...land[land.length - 1]);
}

/*
    간단한 dp
*/
