// https://school.programmers.co.kr/learn/courses/30/lessons/87946

function solution(k, dungeons) {
  let answer = 0;

  const { length: len } = dungeons;
  const visited = Array(len).fill(false);

  const dfs = (depth, now) => {
    answer = Math.max(answer, depth);

    if (depth === len) {
      return;
    }

    dungeons.forEach(([need, use], idx) => {
      if (now >= need && !visited[idx]) {
        visited[idx] = true;
        dfs(depth + 1, now - use);
        visited[idx] = false;
      }
    });
  };

  dfs(0, k);

  return answer;
}

/*
    dfs를 통한 완전 탐색
*/
