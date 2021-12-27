// https://programmers.co.kr/learn/courses/30/lessons/43162

const solution = (n, computers) => {
  const visit = new Array(n).fill().map(() => false);
  let networks = 0;

  visit.forEach((v1, idx1) => {
    if (v1 === true) return;

    visit[idx1] = true;
    networks++;
    const queue = [];

    computers[idx1].forEach((v2, idx2) => {
      if (v2 && !visit[idx2]) {
        visit[idx2] = true;
        queue.push(idx2);
      }
    });
    while (queue.length) {
      computers[queue.pop()].forEach((v3, idx3) => {
        if (v3 && !visit[idx3]) {
          visit[idx3] = true;
          queue.push(idx3);
        }
      });
    }
  });
  return networks;
};

solution(3, [
  [1, 0, 0],
  [0, 1, 0],
  [0, 0, 1],
]);

/*
  queue와 visted를 이용한 탐색
*/
