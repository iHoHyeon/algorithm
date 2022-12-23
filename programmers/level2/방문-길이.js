// https://school.programmers.co.kr/learn/courses/30/lessons/49994

function solution(dirs) {
  const rowMap = new Array(11).fill(0).map(() => new Array(11).fill(0));
  const colMap = new Array(11).fill(0).map(() => new Array(11).fill(0));

  let x = 5,
    y = 5;

  const tryMove = (dir) => {
    switch (dir) {
      case 'U':
        if (y < 10) {
          colMap[y][x] = 1;
          y++;
        }
        break;
      case 'D':
        if (y > 0) {
          y--;
          colMap[y][x] = 1;
        }
        break;
      case 'R':
        if (x < 10) {
          rowMap[y][x] = 1;
          x++;
        }
        break;
      case 'L':
        if (x > 0) {
          x--;
          rowMap[y][x] = 1;
        }
        break;
    }
  };

  [...dirs].forEach(tryMove);

  return rowMap.flat().reduce((acc, val) => acc + val, 0) + colMap.flat().reduce((acc, val) => acc + val, 0);
}
