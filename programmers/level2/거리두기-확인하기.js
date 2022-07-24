// https://school.programmers.co.kr/learn/courses/30/lessons/81302#fn1

const dx = [0, 0, 1, -1];
const dy = [-1, 1, 0, 0];

const checkPlace = (place) => {
  const matrix = place.map((row) => [...row]);

  const isP = (i, j) => matrix[i][j] === 'P';
  const isO = (i, j) => matrix[i][j] === 'O';

  for (let i = 0; i < 5; i++) {
    for (let j = 0; j < 5; j++) {
      if (isP(i, j)) {
        for (let d = 0; d < 4; d++) {
          const I = i + dx[d];
          const J = j + dy[d];

          if (I < 0 || I > 4 || J < 0 || J > 4) {
            continue;
          }

          if (isP(I, J)) {
            return 0;
          }
          if (isO(I, J)) {
            for (let d2 = 0; d2 < 4; d2++) {
              const I2 = I + dx[d2];
              const J2 = J + dy[d2];

              if (i === I2 && j === J2) {
                continue;
              }

              if (I2 < 0 || I2 > 4 || J2 < 0 || J2 > 4) {
                continue;
              }

              if (isP(I2, J2)) {
                return 0;
              }
            }
          }
        }
      }
    }
  }

  return 1;
};

const solution = (places) => places.reduce((res, place) => [...res, checkPlace(place)], []);

console.log(
  solution([
    ['POOOP', 'OXXOX', 'OPXPX', 'OOXOX', 'POXXP'],
    ['POOPX', 'OXPXP', 'PXXXO', 'OXXXO', 'OOOPP'],
    ['PXOPX', 'OXOXP', 'OXPOX', 'OXXOP', 'PXPOX'],
    ['OOOXX', 'XOOOX', 'OOOXX', 'OXOOX', 'OOOOO'],
    ['PXPXP', 'XPXPX', 'PXPXP', 'XPXPX', 'PXPXP'],
  ])
);

/*
  거리두기를 지키고 있지 않는 경우를 생각해보는 것이 빨랐다.

  거리두기를 지키지 않는 경우는 아래 두 가지의 경우이다.
  1. 서로 인접해서 앉는 경우 -> P 와 P가 인접한 경우
  2. 서로 칸막이 없이 한 칸만 떨이진 경우 -> P, O, P 순으로 인접한 경우

  위 경우만 존재하기에 반복문으로 체크만 해주면 해결된다.
*/
