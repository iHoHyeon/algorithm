// https://school.programmers.co.kr/learn/courses/30/lessons/12905

function solution(board) {
  const row_len = board.length;
  const col_len = board[0].length;

  let max = 0;

  for (let row = 0; row < row_len; row++) {
    for (let col = 0; col < col_len; col++) {
      if (!(row === 0 || col === 0 || board[row][col] === 0)) {
        board[row][col] = Math.min(board[row - 1][col], board[row][col - 1], board[row - 1][col - 1]) + 1;
      }

      max = Math.max(max, board[row][col]);
    }
  }

  return max ** 2;
}
