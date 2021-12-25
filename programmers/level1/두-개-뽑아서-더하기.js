// https://programmers.co.kr/learn/courses/30/lessons/68644

const solution = (n) => {
  const res = new Set();
  for (let i = 0; i < n.length - 1; i++) for (let j = i + 1; j < n.length; j++) res.add(n[i] + n[j]);

  return [...res].sort((a, b) => a - b);
};
