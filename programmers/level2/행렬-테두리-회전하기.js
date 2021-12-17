// https://programmers.co.kr/learn/courses/30/lessons/77485

const solution = (rows, columns, queries) => {
  let matrix = new Array(rows).fill().map(() => []);
  for (let i = 0; i < rows; i++) {
    for (let j = 1; j <= columns; j++) {
      matrix[i].push(i * columns + j);
    }
  }

  const rotation = ([y1, x1, y2, x2]) => {
    const newMatrix = [...matrix].map((v) => [...v]);

    for (let i = x2 - 2; i > x1 - 1; i--) newMatrix[y1 - 1][i] = matrix[y1 - 1][i - 1];

    for (let i = x1; i < x2 - 1; i++) newMatrix[y2 - 1][i] = matrix[y2 - 1][i + 1];

    for (let j = y2 - 2; j > y1 - 1; j--) newMatrix[j][x1 - 1] = matrix[j + 1][x1 - 1];

    for (let j = y1; j < y2 - 1; j++) newMatrix[j][x2 - 1] = matrix[j - 1][x2 - 1];

    newMatrix[y1 - 1][x1 - 1] = matrix[y1][x1 - 1];
    newMatrix[y1 - 1][x2 - 1] = matrix[y1 - 1][x2 - 2];
    newMatrix[y2 - 1][x1 - 1] = matrix[y2 - 1][x1];
    newMatrix[y2 - 1][x2 - 1] = matrix[y2 - 2][x2 - 1];

    matrix = [...newMatrix].map((v) => [...v]);
  };

  const getMin = ([y1, x1, y2, x2]) => {
    const border = [];
    for (let i = x1 - 1; i < x2; i++) border.push(matrix[y1 - 1][i], matrix[y2 - 1][i]);
    for (let j = y1; j < y2 - 1; j++) border.push(matrix[j][x1 - 1], matrix[j][x2 - 1]);
    return Math.min(...border);
  };

  return queries.map((query) => {
    rotation(query);
    return getMin(query);
  });
};

/*
  단순 구현

  매번 matrix 회전을 갱신해주고, 회전된 matrix에서 주어진 범위의 최솟값을 찾는 작업을 반복했다.

  회전과 동시에 최솟값을 갱신한다면 더 효율적이니 참고하자
*/
