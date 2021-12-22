// https://programmers.co.kr/learn/courses/30/lessons/64065

const solution = (s) => {
  const tupleMap = new Map();
  tupleMap.set(0, new Set());
  let maxLen = 0;
  const res = [];
  s.slice(0, -1)
    .split('}')
    .forEach((v) => {
      if (v === '') return;
      const nowTuple = v.slice(2).split(',');
      tupleMap.set(nowTuple.length, new Set(nowTuple));
      maxLen = Math.max(maxLen, nowTuple.length);
    });

  for (let i = 1; i <= maxLen; i++) {
    res.push(Number([...tupleMap.get(i)].filter((v) => !tupleMap.get(i - 1).has(v))[0]));
  }
  return res;
};
