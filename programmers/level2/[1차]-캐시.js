// https://school.programmers.co.kr/learn/courses/30/lessons/17680

function solution(cacheSize, cities) {
  let res = 0;

  if (cacheSize === 0) return cities.length * 5;

  let cache = [];

  for (const c of cities) {
    const nowC = c.toLowerCase();

    if (cache.includes(nowC)) {
      cache.splice(cache.indexOf(nowC), 1);
      cache = [nowC, ...cache];
      res++;
    } else {
      if (cache.length >= cacheSize) cache.pop();
      cache = [nowC, ...cache];
      res += 5;
    }
  }

  return res;
}
