function solution(citations) {
  const n = citations.length;

  const h = citations.sort((a, b) => b - a);

  let ret = 0;

  for (let i = 0; i < n; i++) {
    if (i < h[i]) {
      ret++;
    }
  }

  return ret;
}

// 0 1 3 5 6

// 6 5 3 3 0
