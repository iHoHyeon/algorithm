// https://programmers.co.kr/learn/courses/30/lessons/49191

const solution = (n, results) => {
  const graph = new Array(n).fill().map(() => new Array(n).fill(false));
  let res = 0;

  graph.forEach((arr, idx) => (arr[idx] = 0));

  results.forEach(([win, lose]) => {
    graph[win - 1][lose - 1] = 1; // 승
    graph[lose - 1][win - 1] = -1; // 패

    graph[win - 1][win - 1] = 0; // 승부가 한 번이라도 결정 된 자기 자신
    graph[lose - 1][lose - 1] = 0;
  });

  for (let mid = 0; mid < n; mid++) {
    for (let start = 0; start < n; start++) {
      for (let end = 0; end < n; end++) {
        // start가 mid를 이기고, mid가 end를 이겼다면 start는 end를 이긴다.
        if (graph[start][mid] === 1 && graph[mid][end] === 1) graph[start][end] = 1;
        else if (graph[start][mid] === -1 && graph[mid][end] === -1) graph[start][end] = -1;
      }
    }
  }

  for (let i = 0; i < n; i++) {
    let flag = true;
    for (let j = 0; j < n; j++) {
      if (graph[i][j] === false) {
        // 모두 -1,0,1 중 하나로 이루어지면 순위를 알 수 있다.
        flag = false;
        break;
      }
    }
    flag && res++;
  }

  return res;
};

/*
  플로이드 - 와샬 알고리즘을 적용했다
*/
