// https://school.programmers.co.kr/learn/courses/30/lessons/1844

const dx = [-1, 0, 1, 0];
const dy = [0, -1, 0, 1];

function solution(maps) {
  const row = maps.length;
  const col = maps[0].length;

  const queue = [];

  queue.push([0, 0, 1]);
  maps[0][0] = 0;

  while (queue.length) {
    for (let i = 0; i < queue.length; i++) {
      const [x, y, cnt] = queue.shift();

      if (x === row - 1 && y === col - 1) return cnt;

      for (let j = 0; j < 4; j++) {
        const X = x + dx[j];
        const Y = y + dy[j];

        if (X >= 0 && X < row && Y >= 0 && Y < col && maps[X][Y] === 1) {
          maps[X][Y] = 0;
          queue.push([X, Y, cnt + 1]);
        }
      }
    }
  }

  return -1;
}
